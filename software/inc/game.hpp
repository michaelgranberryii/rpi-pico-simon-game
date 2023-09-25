/**
 * @file game.hpp
 * @brief Provides fuctions for handling general game logic.
 * @author Michael Granberry
*/

#ifndef GAME_HPP
#define GAME_HPP

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include "inc/led.hpp"
#include "inc/push_button.hpp"

class Game {
    public:

        /**
         * @brief Constructor
        */
        Game();
        
        /**
         * @brief Generate a random number
        */
        int rand_gen();

        /**
         * @brief Reset the game
        */
        void reset_game();

        /**
         * @brief Checks if score is a high score. Print score board. Prints game over text
        */
        void gameover();

        /**
         * @brief 
         * @param leds 
        */
        void play_led_pattern(Led *leds);

        /**
         * @brief
        */
        void guessing_pattern();

        /**
         * @brief
         * @param gameover
        */
        bool set_game_over(bool gameover);

        /**
         * @brief
        */
        bool get_game_over();

        /**
         * @brief
        */
        void toggle_is_playing_led();

        /**
         * @brief
        */
        bool get_is_playing_led();

        /**
         * @brief
        */
        bool toggle_is_guessing();

        /**
         * @brief
        */
        bool get_is_guessing();

        /**
         * @brief
         * @param led
        */
        void map_btn_to_led(uint8_t led);

        /**
         * @brief
         * @param 
        */
        void button_pressed(uint8_t btn_pressed);

        /**
         * @brief
        */
        void print_score_board();

        /**
         * @brief
         * @param
         * @param
         * @param
        */
        bool compare_sore(int *arr, int size, int score);

        /**
         * @brief
         * @param
         * @param
        */
        void insertionSort(int *arr, int size);

        
    private:
        bool game_over;
        bool is_playing_led;
        bool is_guessing;
        uint8_t button_value;
        std::vector<int> pattern;
        int pattern_index;
        int high_scores[5];
};


#endif