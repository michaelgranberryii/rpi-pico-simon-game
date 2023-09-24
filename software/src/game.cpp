#include "inc/game.hpp"

bool game_over = false;
bool is_playing_led = true;
bool is_guessing = false;
uint8_t button_value = 0;
std::vector<int> pattern;
int pattern_index = 0;
int high_scores[5] = {0, 0, 0, 0, 0,};

int rand_gen() {
	// Providing a seed value
	srand((unsigned) time(NULL));

	// Loop to get 5 random numbers
    // Retrieve a random number between 100 and 200
    // Offset = 100
    // Range = 101
    int random = 12 + (rand() % 4);

    // Print the random number
    return random;
	
}


void play_led_pattern(Led *leds) {
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

void guessing_pattern() {
    
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

void gameover() {
    uint score = pattern.size()-1;
     if (compare_sore(high_scores, 5, score)) {
             insertionSort(high_scores, 5);
     }
    print_score_board();
    printf("Game over!, Score: %d\n", score);
    set_game_over(true);
}

void reset_game() {
    pattern.clear();
    pattern_index=0;
    sleep_ms(1000);
    toggle_is_playing_led();
    set_game_over(false);
}

bool set_game_over(bool gameover) {
    game_over = gameover;
    return game_over;
}

bool get_game_over() {
    return game_over;
}


void toggle_is_playing_led() {
    is_playing_led = (is_playing_led == true) ? false : true;
}

bool get_is_playing_led() {
    return is_playing_led;
}

void map_btn_to_led(uint8_t btn_to_led) {
    switch (btn_to_led)
    {
    case 0:
        button_pressed(LED0_PIN);

        break;

    case 1:
        button_pressed(LED1_PIN);
        break;
    case 2:
        button_pressed(LED2_PIN);
        break;
    case 3:
        button_pressed(LED3_PIN);
        break;
    default:
        break;
    }
}

void button_pressed(uint8_t btn_pressed) {
    // printf("btn val: %d\n", btn_pressed);
    button_value = btn_pressed;
}

void print_score_board() {
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

bool compare_sore(int *arr, int size, int score) {
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < score) {
            arr[i] = score;
            return true;
        }
    }
    return false;
}

// Descending Order
void insertionSort(int *arr, int size) {
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