/** 
 * @file led.hpp
 * @brief Provides fuctions that control LEDs.
 * @author Michael Granberry
*/

#ifndef LED_HPP
#define LED_HPP

#include "pico/stdlib.h"
#include "pico/multicore.h"

class Led {
    public:
        static const uint8_t number_of_leds = 4;
        static const uint8_t LED3_PIN = 15;
        static const uint8_t LED2_PIN = 14;
        static const uint8_t LED1_PIN = 13;
        static const uint8_t LED0_PIN = 12;
        /**
         * @brief Constructor for LED
         * @param led_pin selects a GPIO pin for LED
        */
        Led(uint8_t led_pin);

        /**
         * @brief Turns on LED
        */
        void turn_on_led();

        /**
         * @brief Turns off LED
        */
        void turn_off_led();

        void toggle_led();

        uint8_t get_pin();
    private:
        const uint8_t LED_PIN;
        const uint16_t LED_SLEEP_TIME_mSec = 300;
       
};
#endif