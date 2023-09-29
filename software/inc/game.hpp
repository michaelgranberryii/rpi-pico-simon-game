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
         * @brief Plays the random pattern on LEDs
         * @param leds An array of Led ojects
        */
        void play_led_pattern(Led *leds);

        /**
         * @brief Compares button presses to pattern
        */
        void guessing_pattern();

        /**
         * @brief Set the gameoover bool if user loses
         * @param gameover boolean
        */
        bool set_game_over(bool gameover);

        /**
         * @brief Gets the value of gameover
        */
        bool get_game_over();

        /**
         * @brief Toggles is_playing_led boolean
        */
        void toggle_is_playing_led();

        /**
         * @brief Gets value of is_playing_led
        */
        bool get_is_playing_led();

        /**
         * @brief Toggles is_guessing boolean
        */
        bool toggle_is_guessing();

        /**
         * @brief Gets the value of is_guessing
        */
        bool get_is_guessing();

        /**
         * @brief Maps a button press to it's corresponding LED
         * @param btn_to_led Index value
        */
        void map_btn_to_led(uint8_t btn_to_led);

        /**
         * @brief Sets the LED gpio value to button_value
         * @param btn_pressed Set's the value of button_value
        */
        void button_pressed(uint8_t btn_pressed);

        /**
         * @brief Prints score baord
        */
        void print_score_board();

        /**
         * @brief Compares new score with current high scores
         * @param arr array of high scores
         * @param size size of high score array
         * @param score current score
        */
        bool compare_sore(int *arr, int size, int score);

        /**
         * @brief Sorts high score array
         * @param arr high score array
         * @param size size of high score array
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