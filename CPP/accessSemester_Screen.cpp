#include "../Header/Staff.h"
#include "../Header/Design.h"

void accessSemester(string username, Year* &year_head, Semester* &semester_head)
{
    system("cls");
    resizeConsole(1920,920);
    system("color E0");

    gotoXY(60,2);
    std::cout << "   _____ _____ _   _______  _____ _____";
    gotoXY(60,3);
    std::cout << "  /  __ \\  _  | | | | ___ \\/  ___|  ___|";
    gotoXY(60,4);
    std::cout << "  | /  \\/ | | | | | | |_/ /\\ `--.| |__";
    gotoXY(60,5);
    std::cout << "  | |   | | | | | | |    /  `--. \\  __|";
    gotoXY(60,6);
    std::cout << "  | \\__/\\ \\_/ / |_| | |\\ \\ /\\__/ / |___";
    gotoXY(60,7);
    std::cout << "   \\____/\\___/ \\___/\\_| \\_|\\____/\\____/";

    Create_A_Box_1(30,13,2,20,14,14,0,"    ADD A COURSE");
    Create_A_Box_1(70,13,2,20,14,14,0,"  ACCESS A COURSE");
    Create_A_Box_1(110,13,2,20,14,14,0,"  UPDATE A COURSE");
    Create_A_Box_1(70,20,2,20,14,14,0,"    RETURN BACK");
    ShowConsoleCursor(false);

    int x_temp = 30; int y_temp = 13;
    bool flag = true;
    while (true)
    {
        if (flag == true)
        {
            if (x_temp == 30)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 19; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "    ADD A COURSE";
                ShowConsoleCursor(false);
            }
            else if (x_temp == 70)
            {
                if (y_temp == 13)
                {
                    system("color E0");
                    SetColor1(15,0);
                    for (int i = x_temp + 1; i <= x_temp + 19; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "  ACCESS A COURSE";
                    ShowConsoleCursor(false);
                }
                else
                {
                    system("color E0");
                    SetColor1(15,0);
                    for (int i = x_temp + 1; i <= x_temp + 19; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "    RETURN BACK";
                    ShowConsoleCursor(false);
                }
            }
            else
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 19; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "  UPDATE A COURSE";
                ShowConsoleCursor(false);
            }

            flag = false;
        }
        else
        {
            if (_kbhit())//keyboardhit
            {
                char c = _getch();

                system("color E0");
                if (x_temp == 30)
                {
                    system("color E0");
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 19; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "    ADD A COURSE";
                    ShowConsoleCursor(false);
                }
                else if (x_temp == 70)
                {
                    if (y_temp == 13)
                    {
                        system("color E0");
                        SetColor1(14,0);
                        for (int i = x_temp + 1; i <= x_temp + 19; ++i)
                        {
                            gotoXY(i, y_temp + 1);
                            std::cout << " ";
                        }

                        gotoXY(x_temp + 1, y_temp + 1);
                        std::cout << "  ACCESS A COURSE";
                        ShowConsoleCursor(false);
                    }
                    else
                    {
                        system("color E0");
                        SetColor1(14,0);
                        for (int i = x_temp + 1; i <= x_temp + 19; ++i)
                        {
                            gotoXY(i, y_temp + 1);
                            std::cout << " ";
                        }

                        gotoXY(x_temp + 1, y_temp + 1);
                        std::cout << "    RETURN BACK";
                        ShowConsoleCursor(false);
                    }
                }
                else
                {
                    system("color E0");
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 19; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "  UPDATE A COURSE";
                    ShowConsoleCursor(false);
                }

                flag = true;

                if (c == LEFT)
                {
                    if (x_temp == 30)
                        x_temp = 110;
                    else
                        x_temp -= 40;
                }
                else if (c == RIGHT)
                {
                    if (x_temp == 110)
                        x_temp = 30;
                    else
                        x_temp += 40;
                }
                else if (c == UP)
                {
                    if (y_temp == 20)
                    {
                        x_temp = 30;
                        y_temp = 13;
                    }
                }
                else if (c == DOWN)
                {
                    if (y_temp == 13)
                    {
                        x_temp = 70;
                        y_temp = 20;
                    }
                }
                else if (c == ENTER)
                {
                    if (y_temp == 20)
                    {
                        system("cls");
                        viewSemester_Screen(username, year_head);
                        return;
                    }
                    else
                    {
                        if (x_temp == 30)
                        {
                            system ("cls");
                            addNewCourse(username, year_head, semester_head);
                            return;
                        }
                        else if (x_temp == 70)
                        {
                            system("cls");
                            viewCourse_Screen(username, year_head, semester_head);
                            return;
                        }
                        else
                        {
                            system("cls");
                            viewUpdateCourseInformation(username, year_head, semester_head);
                            return;
                        }
                    }
                }
            }
        }
    }
}