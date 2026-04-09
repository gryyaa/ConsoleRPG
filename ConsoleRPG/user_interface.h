#pragma once
#include <cstdlib>
#include <thread>
#include <chrono>
#include <string>
#include <iostream>
using namespace std;
#define TOP_BORDER "======================================="
#define SEPARATOR_LINE "---------------------------------------"
#define PAUSE_5_SECONDS this_thread::sleep_for(chrono::seconds(5))
#define PAUSE_1_SECONDS this_thread::sleep_for(chrono::seconds(1))

// Стандартные (объектоподобные) макросы:
#define GAME_TITLE_TEXT "-----CPlusPlus Console RPG!-----"
#define MENU_PROMPT_SYMBOL ">> "
#define STANDARD_CLEAR_COMMAND "cls"

// Функциональные (function-like) макросы:
#define PRINT_SECTION_TITLE(title) cout << TOP_BORDER << endl << title << endl << TOP_BORDER << endl
#define CLAMP_TO_NON_NEGATIVE(value) ((value) < 0 ? 0 : (value))
#define PERCENT_OF(value, percent) ((value) * (percent) / 100)

void ShowProgressBar(double progressLevel, int time, const string& message, char symbol);

void ShowLoadingDots(chrono::milliseconds pauseTime, int duration);
