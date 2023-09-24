/** 
 * @file push_button.hpp
 * @brief Provides fuctions that initialize, debounce, and poll the push button.
 * @author Michael Granberry
*/

#ifndef PUSHBUTTON_HPP
#define PUSHBUTTON_HPP

#include "pico/stdlib.h"
#include <iostream>

class PushButton {
    private:
        const uint8_t BTN_PIN;

    public:
        /**
         * @brief Constructor for push button
         * @param btn_pin selects a gpio pin for push button
        */
        PushButton(uint8_t btn_pin);

        uint8_t get_pin();
};

#endif