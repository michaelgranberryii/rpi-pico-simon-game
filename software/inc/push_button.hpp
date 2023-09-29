/** 
 * @file push_button.hpp
 * @brief Provides fuctions for push button.
 * @author Michael Granberry
*/

#ifndef PUSHBUTTON_HPP
#define PUSHBUTTON_HPP

#include "pico/stdlib.h"
#include <iostream>

class PushButton {
    public:
        static const uint8_t number_of_buttons = 5;
        static const uint8_t BTN0_PIN = 16;
        static const uint8_t BTN1_PIN = 17;
        static const uint8_t BTN2_PIN = 18;
        static const uint8_t BTN3_PIN = 19;
        static const uint8_t BTN4_PIN = 20;
        static const uint16_t DEBOUNCE_TIME = 150;
        static uint db_counter;

        /**
         * @brief Constructor for push button
         * @param btn_pin selects a gpio pin for push button
        */
        PushButton(uint8_t btn_pin);

        /**
         * @brief Returns the button GPIO pin number
        */
        uint8_t get_pin();

    private:
        const uint8_t BTN_PIN;
};

#endif