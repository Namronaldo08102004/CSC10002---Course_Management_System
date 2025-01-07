#ifndef Design_h
#define Design_h

#include "../Header/Structures.h"

#define UP 72
#define DOWN 80
#define ENTER 13
#define LEFT 75
#define RIGHT 77
#define BACKSPACE 8
#define ESC 27

void resizeConsole(int width, int height);
void gotoXY (int x, int y);
void SetColor1(int backgound_color, int text_color);
void Create_A_Box_1(int x_coord, int y_coord, int height, int width, int highlight_color_1, int highlight_color_2, int text_color, std::string content);
void Create_A_Box_2 (int x_coord, int y_coord, int height, int width, int highlight_color_1, int highlight_color_2, int text_color, std::string keyword);
void Create_A_Box_3 (int x_coord, int y_coord, int height, int width);
void Create_A_Box_4 (int x_coord, int y_coord, int height, int width, int highlight_color_1, int highlight_color_2, int text_color, std::string keyword, std::string content);
void ShowConsoleCursor(bool visible);

#endif