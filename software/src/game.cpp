/**
 * @file game.cpp
 * @brief Provides fuctions for handling general game logic.
 * @author Michael Granberry
*/

#include "inc/game.hpp"

Game::Game() {
        game_over = false;
        is_playing_led = true;
        is_guessing = false;
        button_value = 0;
        pattern_index = 0;
}

int Game::rand_gen() {
	// Providing a seed value
	srand((unsigned) time(NULL));
    int offset = 12;
    int random = offset + (rand() % 4);

    // return the random number
    return random;
	
}


void Game::play_led_pattern(Led *leds) {
    pattern.push_back(rand_gen());
    print_score_board();
    // printf("size: %d\n", pattern.size());
    printf("Level %d!\n", pattern.size());
   
    for(auto p : pattern) {
        // printf("p: %d\n", p);
        leds[p-12].toggle_led();
    }
    toggle_is_playing_led();
}

void Game::guessing_pattern() {
    
    if (!get_is_playing_led()) {
        // printf("button_value: %d == %d :pattern[pattern_index]\n", button_value, pattern[pattern_index]);
        // printf("pattern_index_o: %d\n", pattern_index);
        if (button_value == pattern[pattern_index]) {
            // printf("hey\n");
            pattern_index++;
            // printf("pattern_index_i: %d\n", pattern_index);
            if ((pattern_index) == pattern.size()) {
                pattern_index = 0;
                sleep_ms(1000);
                toggle_is_playing_led();
            }
        } else {
            gameover();
        }
    }
}

void Game::gameover() {
    uint score = pattern.size()-1;
     if (compare_sore(high_scores, 5, score)) {
             insertionSort(high_scores, 5);
     }
    print_score_board();
    printf("Game over!, Score: %d\n", score);
    set_game_over(true);
}

void Game::reset_game() {
    pattern.clear();
    pattern_index=0;
    sleep_ms(1000);
    toggle_is_playing_led();
    set_game_over(false);
}

bool Game::set_game_over(bool gameover) {
    game_over = gameover;
    return game_over;
}

bool Game::get_game_over() {
    return game_over;
}


void Game::toggle_is_playing_led() {
    is_playing_led = (is_playing_led == true) ? false : true;
}

bool Game::get_is_playing_led() {
    return is_playing_led;
}

void Game::map_btn_to_led(uint8_t btn_to_led) {
    switch (btn_to_led)
    {
    case 0:
        button_pressed(Led::LED0_PIN);
        break;

    case 1:
        button_pressed(Led::LED1_PIN);
        break;
    case 2:
        button_pressed(Led::LED2_PIN);
        break;
    case 3:
        button_pressed(Led::LED3_PIN);
        break;
    default:
        break;
    }
}

void Game::button_pressed(uint8_t btn_pressed) {
    // printf("btn val: %d\n", btn_pressed);
    button_value = btn_pressed;
}

void Game::print_score_board() {
    printf("\033[H\033[J");
    printf("-------------------\n");
    printf("|   High Scores   |\n");
    printf("-------------------\n");
    printf("|  Rank  |  Score |\n");
    printf("-------------------\n");
    printf("|   1    |   %d    |\n", high_scores[0]);
    printf("-------------------\n");
    printf("|   2    |   %d    |\n", high_scores[1]);
    printf("-------------------\n");
    printf("|   3    |   %d    |\n", high_scores[2]);
    printf("-------------------\n");
    printf("|   4    |   %d    |\n", high_scores[3]);
    printf("-------------------\n");
    printf("|   5    |   %d    |\n", high_scores[4]);
    printf("-------------------\n");
    printf("\n");

}

bool Game::compare_sore(int *arr, int size, int score) {
    bool flag = false;
    int min_index = 0; 
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < score) {
            min_index = i;
            flag = true;
        }
    }
    if(flag) {
        arr[min_index] = score;
        return true;
    } else {
        return false;
    }
}

// Descending Order
void Game::insertionSort(int *arr, int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}