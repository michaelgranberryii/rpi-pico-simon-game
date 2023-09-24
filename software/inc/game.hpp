#ifndef GAME_HPP
#define GAME_HPP

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <vector>
#include "inc/led.hpp"
#include "inc/push_button.hpp"

const uint8_t number_of_buttons = 5;
const uint8_t BTN0_PIN = 16;
const uint8_t BTN1_PIN = 17;
const uint8_t BTN2_PIN = 18;
const uint8_t BTN3_PIN = 19;
const uint8_t BTN4_PIN = 20;

const uint8_t number_of_leds = 4;
const uint8_t LED3_PIN = 15;
const uint8_t LED2_PIN = 14;
const uint8_t LED1_PIN = 13;
const uint8_t LED0_PIN = 12;

const uint16_t bounce_time = 150;

int rand_gen();
void reset_game();
void gameover();
void play_led_pattern(Led *leds);
void guessing_pattern();
bool set_game_over(bool gameover);
bool get_game_over();
void toggle_is_playing_led();
bool get_is_playing_led();
bool toggle_is_guessing();
bool get_is_guessing();
void map_btn_to_led(uint8_t led);
void button_pressed(uint8_t btn_pressed);
void print_score_board();
bool compare_sore(int *arr, int size, int score);
void insertionSort(int *arr, int size);
#endif