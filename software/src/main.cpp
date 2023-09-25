/** 
 * @file main.hpp
 * @brief Main file for Simon game
 * @author Michael Granberry
*/

#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "hardware/timer.h"
#include "hardware/gpio.h"
#include "inc/game.hpp"

Game game; // Global object. Is this bad? 

uint PushButton::db_counter = 0;

PushButton btns[PushButton::number_of_buttons] = {
    PushButton(PushButton::BTN0_PIN),
    PushButton(PushButton::BTN1_PIN),
    PushButton(PushButton::BTN2_PIN),
    PushButton(PushButton::BTN3_PIN),
    PushButton(PushButton::BTN4_PIN)
};

Led leds[Led::number_of_leds] = {
    Led(Led::LED0_PIN),
    Led(Led::LED1_PIN),
    Led(Led::LED2_PIN),
    Led(Led::LED3_PIN)
};

bool repeating_timer_callback(struct repeating_timer *t) {
    PushButton::db_counter++;
    return PushButton::db_counter;
}

void button_callback(uint gpio, uint32_t events) {
    if (PushButton::db_counter >= PushButton::DEBOUNCE_TIME) {
        if (gpio < PushButton::BTN4_PIN) {
            leds[gpio-PushButton::BTN0_PIN].toggle_led();
            game.map_btn_to_led(gpio-PushButton::BTN0_PIN);
            game.guessing_pattern();
        } 
        else if (game.get_game_over()) {
            game.reset_game();
        }
        PushButton::db_counter = 0;
    } 
}

// core1
void core1_entry() {
    uint8_t irq_event = 0x8;
    gpio_set_irq_enabled_with_callback(btns[0].get_pin(), irq_event, true, button_callback);
    gpio_set_irq_enabled_with_callback(btns[1].get_pin(), irq_event, true, button_callback);
    gpio_set_irq_enabled_with_callback(btns[2].get_pin(), irq_event, true, button_callback);
    gpio_set_irq_enabled_with_callback(btns[3].get_pin(), irq_event, true, button_callback);
    gpio_set_irq_enabled_with_callback(btns[4].get_pin(), irq_event, true, button_callback);
    struct repeating_timer timer;
    add_repeating_timer_ms(1, repeating_timer_callback, nullptr, &timer);
    

    // super loop
    while (true)
    {     
       tight_loop_contents();
    }
}


// core0
int main() {
    stdio_init_all();
    multicore_launch_core1(core1_entry);
    sleep_ms(1000);

    // super loop
    while (true) {
        if(!game.get_game_over()) {
            if(game.get_is_playing_led()) {
                game.play_led_pattern(leds);
            }
        } 
        tight_loop_contents();
    }
}
