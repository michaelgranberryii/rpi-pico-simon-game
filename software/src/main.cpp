/** 
 * @file main.hpp
 * @brief 
 * @author Michael Granberry
*/

#include "pico/stdlib.h"
#include "pico/multicore.h"
#include "hardware/timer.h"
#include "hardware/gpio.h"
#include "inc/game.hpp"

uint db_counter = 0;

PushButton btns[number_of_buttons] = {
    PushButton(BTN0_PIN),
    PushButton(BTN1_PIN),
    PushButton(BTN2_PIN),
    PushButton(BTN3_PIN),
    PushButton(BTN4_PIN)
};

Led leds[number_of_leds] = {
    Led(LED0_PIN),
    Led(LED1_PIN),
    Led(LED2_PIN),
    Led(LED3_PIN)
};

bool repeating_timer_callback(struct repeating_timer *t) {
    db_counter++;
    return db_counter;
}

void button_callback(uint gpio, uint32_t events) {
    if (db_counter >= bounce_time) {
        if (gpio < BTN4_PIN) {
            leds[gpio-BTN0_PIN].toggle_led();
            map_btn_to_led(gpio-BTN0_PIN);
            guessing_pattern();
        } 
        else if (get_game_over()) {
            reset_game();
        }
        db_counter = 0;
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

    while (true) {
        if(!get_game_over()) {
            if(get_is_playing_led()) {
                play_led_pattern(leds);
            }
        } 
        tight_loop_contents();
    }
}
