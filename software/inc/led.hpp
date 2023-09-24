/** 
 * @file led.hpp
 * @brief Provides fuctions that initialize leds and turns them on/off.
 * @author Michael Granberry
*/

#ifndef LED_HPP
#define LED_HPP

#include "pico/stdlib.h"
#include "pico/multicore.h"

class Led {
    private:
        const uint8_t LED_PIN;
    
    public:
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

       
};
#endif