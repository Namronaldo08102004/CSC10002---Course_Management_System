#include "../Header/Design.h"

void resizeConsole(int width, int height)//Resize console
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);
    MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void gotoXY (int x, int y)//Move Mouse Pointer to (x;y) coordinator
{
    COORD coordinator;

    coordinator.X = x;
    coordinator.Y = y;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinator);
}

//Set color (function 1)
void SetColor1(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}

void Create_A_Box_1 (int x_coord, int y_coord, int height, int width, int highlight_color_1, int highlight_color_2, int text_color, std::string content)
{
    SetColor1(highlight_color_1,text_color);
    for (int i = x_coord + 1; i <= x_coord + width - 1; ++i)
    {
        for (int j = y_coord + 1; j <= y_coord + height - 1; ++j)
        {
            gotoXY(i,j);
            std::cout << " ";
        }
    }

    SetColor1(highlight_color_1,text_color);
    gotoXY(x_coord + 1,y_coord + 1);
    std::cout << content;

    SetColor1(highlight_color_2,0);
    if (height <= 1 || width <= 2)
        return;

    //Create two horizontal lines
    for (int i = x_coord; i <= x_coord + width; ++i)
    {
        gotoXY(i, y_coord);
        std::cout << (char)(196); //196 is -
        gotoXY(i, y_coord + height);
        std::cout << (char)(196);
    }

    //Create two vertical lines
    for (int i = y_coord; i <= y_coord + height; ++i)
    {
        gotoXY(x_coord, i);
        std::cout << (char)(179); //179 is |
        gotoXY(x_coord + width, i);
        std::cout << (char)(179);
    }

    //Create 4 corners
    gotoXY(x_coord,y_coord); std::cout << (char)(218); //top left
    gotoXY(x_coord + width, y_coord); std::cout << (char)(191); //Top right
    gotoXY(x_coord + width, y_coord + height); std::cout << (char)(217); //Bottom right
    gotoXY(x_coord, y_coord + height); std::cout << (char)(192); //Bottom left
}
//Create a box with given content

void Create_A_Box_2 (int x_coord, int y_coord, int height, int width, int highlight_color_1, int highlight_color_2, int text_color, std::string keyword)
{
    SetColor1(highlight_color_1,text_color);
    for (int i = x_coord + 1; i <= x_coord + width - 1; ++i)
    {
        for (int j = y_coord + 1; j <= y_coord + height - 1; ++j)
        {
            gotoXY(i,j);
            std::cout << " ";
        }
    }

    SetColor1(highlight_color_2,0);
    if (height <= 1 || width <= 2)
        return;

    //Create two horizontal lines
    for (int i = x_coord; i <= x_coord + width; ++i)
    {
        gotoXY(i, y_coord);
        std::cout << (char)(196); //196 is -
        gotoXY(i, y_coord + height);
        std::cout << (char)(196);
    }

    //Create two vertical lines
    for (int i = y_coord; i <= y_coord + height; ++i)
    {
        gotoXY(x_coord, i);
        std::cout << (char)(179); //179 is |
        gotoXY(x_coord + width, i);
        std::cout << (char)(179);
    }

    //Create 4 corners
    gotoXY(x_coord,y_coord); std::cout << (char)(218); //top left
    gotoXY(x_coord + width, y_coord); std::cout << (char)(191); //Top right
    gotoXY(x_coord + width, y_coord + height); std::cout << (char)(217); //Bottom right
    gotoXY(x_coord, y_coord + height); std::cout << (char)(192); //Bottom left

    gotoXY(x_coord + 2, y_coord - 1);
    std::cout << keyword;
}
//Create a box with the content was above

void Create_A_Box_3 (int x_coord, int y_coord, int height, int width)
//Create an empty box
{
    //Create two horizontal lines
    for (int i = x_coord; i <= x_coord + width; ++i)
    {
        gotoXY(i, y_coord);
        std::cout << (char)(196); //196 is -
        gotoXY(i, y_coord + height);
        std::cout << (char)(196);
    }

    //Create two vertical lines
    for (int i = y_coord; i <= y_coord + height; ++i)
    {
        gotoXY(x_coord, i);
        std::cout << (char)(179); //179 is |
        gotoXY(x_coord + width, i);
        std::cout << (char)(179);
    }

    //Create 4 corners
    gotoXY(x_coord,y_coord); std::cout << (char)(218); //top left
    gotoXY(x_coord + width, y_coord); std::cout << (char)(191); //Top right
    gotoXY(x_coord + width, y_coord + height); std::cout << (char)(217); //Bottom right
    gotoXY(x_coord, y_coord + height); std::cout << (char)(192); //Bottom left
}
//Create a box in console

void Create_A_Box_4 (int x_coord, int y_coord, int height, int width, int highlight_color_1, int highlight_color_2, int text_color, std::string keyword, std::string content)
{
    SetColor1(highlight_color_1,text_color);
    for (int i = x_coord + 1; i <= x_coord + width - 1; ++i)
    {
        for (int j = y_coord + 1; j <= y_coord + height - 1; ++j)
        {
            gotoXY(i,j);
            std::cout << " ";
        }
    }

    SetColor1(highlight_color_1,text_color);
    gotoXY(x_coord + 1,y_coord + 1);
    std::cout << content;

    SetColor1(highlight_color_2,0);
    if (height <= 1 || width <= 2)
        return;

    //Create two horizontal lines
    for (int i = x_coord; i <= x_coord + width; ++i)
    {
        gotoXY(i, y_coord);
        std::cout << (char)(196); //196 is -
        gotoXY(i, y_coord + height);
        std::cout << (char)(196);
    }

    //Create two vertical lines
    for (int i = y_coord; i <= y_coord + height; ++i)
    {
        gotoXY(x_coord, i);
        std::cout << (char)(179); //179 is |
        gotoXY(x_coord + width, i);
        std::cout << (char)(179);
    }

    //Create 4 corners
    gotoXY(x_coord,y_coord); std::cout << (char)(218); //top left
    gotoXY(x_coord + width, y_coord); std::cout << (char)(191); //Top right
    gotoXY(x_coord + width, y_coord + height); std::cout << (char)(217); //Bottom right
    gotoXY(x_coord, y_coord + height); std::cout << (char)(192); //Bottom left

    gotoXY(x_coord + 2, y_coord - 1);
    std::cout << keyword;
}
//Create a box with above content and the given content 

//Hide/Unhide cursor
void ShowConsoleCursor(bool visible)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO lpCursor;
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;
    SetConsoleCursorInfo(console, &lpCursor);
}