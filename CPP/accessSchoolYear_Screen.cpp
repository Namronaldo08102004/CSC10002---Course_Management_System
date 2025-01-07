#include "../Header/Staff.h"
#include "../Header/Design.h"

void accessSchoolYear(string username, Year* &year_head)
{
    resizeConsole(1920,920);
    system("color E0");

    gotoXY(13,2);
    std::cout << "   _____ ________  ________ _____ _____ ___________";
    gotoXY(13,3);
    std::cout << "  /  ___|  ___|  \\/  |  ___/  ___|_   _|  ___| ___ \\";
    gotoXY(13,4);
    std::cout << "  \\ `--.| |__ | .  . | |__ \\ `--.  | | | |__ | |_/ /";
    gotoXY(13,5);
    std::cout << "   `--. \\  __|| |\\/| |  __| `--. \\ | | |  __||    /";
    gotoXY(13,6);
    std::cout << "  /\\__/ / |___| |  | | |___/\\__/ / | | | |___| |\\ \\";
    gotoXY(13,7);
    std::cout << "  \\____/\\____/\\_|  |_|____/\\____/  \\_/ \\____/\\_| \\_|";

    gotoXY(111,2);
    std::cout << "   _____ _      ___  _____ _____";
    gotoXY(111,3);
    std::cout << "  /  __ \\ |    / _ \\/  ___/  ___|";
    gotoXY(111,4);
    std::cout << "  | /  \\/ |   / /_\\ \\ `--.\\ `--.";
    gotoXY(111,5);
    std::cout << "  | |   | |   |  _  |`--. \\`--. \\";
    gotoXY(111,6);
    std::cout << "  | \\__/\\ |___| | | /\\__/ /\\__/ /";
    gotoXY(111,7);
    std::cout << "   \\____|_____|_| |_|____/\\____/";

    for (int i = 1; i <= 40; ++i)
    {
        gotoXY(84,i);
        std::cout << (char)(179);
    }

    Create_A_Box_1(24,10,2,30,14,14,0,"         ADD SEMESTER");
    Create_A_Box_1(24,12,2,30,14,14,0,"       ACCESS SEMESTER");
    gotoXY(24,12); std::cout << (char)(195);
    gotoXY(54,12); std::cout << (char)(180);
    Create_A_Box_1(24,14,2,30,14,14,0,"         RETURN BACK");
    gotoXY(24,14); std::cout << (char)(195);
    gotoXY(54,14); std::cout << (char)(180);

    Create_A_Box_1(114,10,2,30,14,14,0,"          ADD CLASS");
    Create_A_Box_1(114,12,2,30,14,14,0,"        ACCESS CLASS");
    gotoXY(114,12); std::cout << (char)(195);
    gotoXY(144,12); std::cout << (char)(180);
    Create_A_Box_1(114,14,2,30,14,14,0,"         RETURN BACK");
    gotoXY(114,14); std::cout << (char)(195);
    gotoXY(144,14); std::cout << (char)(180);

    ShowConsoleCursor(false);

    int x_temp = 24; int y_temp = 10;
    bool flag = true;
    while (true)
    {
        if (flag == true)
        {
            if (y_temp == 10)
            {
                if (x_temp == 24)
                {
                    system("color E0");
                    SetColor1(15,0);
                    for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "         ADD SEMESTER";
                    ShowConsoleCursor(false);
                }
                else
                {
                    system("color E0");
                    SetColor1(15,0);
                    for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "          ADD CLASS";
                    ShowConsoleCursor(false);
                }
            }
            else if (y_temp == 12)
            {
                if (x_temp == 24)
                {
                    system("color E0");
                    SetColor1(15,0);
                    for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "       ACCESS SEMESTER";
                    ShowConsoleCursor(false);
                }
                else
                {
                    system("color E0");
                    SetColor1(15,0);
                    for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "        ACCESS CLASS";
                    ShowConsoleCursor(false);
                }
            }
            else
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "         RETURN BACK";
                ShowConsoleCursor(false);
            }

            flag = false;
        }
        else
        {
            if (_kbhit())//keyboardhit
            {
                char c = _getch();
                flag = true;

                if (y_temp == 10)
                {
                    if (x_temp == 24)
                    {
                        system("color E0");
                        SetColor1(14,0);
                        for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                        {
                            gotoXY(i, y_temp + 1);
                            std::cout << " ";
                        }

                        gotoXY(x_temp + 1, y_temp + 1);
                        std::cout << "         ADD SEMESTER";
                        ShowConsoleCursor(false);
                    }
                    else
                    {
                        system("color E0");
                        SetColor1(14,0);
                        for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                        {
                            gotoXY(i, y_temp + 1);
                            std::cout << " ";
                        }

                        gotoXY(x_temp + 1, y_temp + 1);
                        std::cout << "          ADD CLASS";
                        ShowConsoleCursor(false);
                    }
                }
                else if (y_temp == 12)
                {
                    if (x_temp == 24)
                    {
                        system("color E0");
                        SetColor1(14,0);
                        for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                        {
                            gotoXY(i, y_temp + 1);
                            std::cout << " ";
                        }

                        gotoXY(x_temp + 1, y_temp + 1);
                        std::cout << "       ACCESS SEMESTER";
                        ShowConsoleCursor(false);
                    }
                    else
                    {
                        system("color E0");
                        SetColor1(14,0);
                        for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                        {
                            gotoXY(i, y_temp + 1);
                            std::cout << " ";
                        }

                        gotoXY(x_temp + 1, y_temp + 1);
                        std::cout << "        ACCESS CLASS";
                        ShowConsoleCursor(false);
                    }
                }
                else
                {
                    system("color E0");
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "         RETURN BACK";
                    ShowConsoleCursor(false);
                }

                if (c == UP)
                {
                    if (y_temp == 10)
                        y_temp = 14;
                    else
                        y_temp -= 2;
                }
                else if (c == DOWN)
                {
                    if (y_temp == 14)
                        y_temp = 10;
                    else
                        y_temp += 2;
                }
                else if (c == LEFT)
                {
                    if (x_temp == 114)
                        x_temp = 24;
                }
                else if (c == RIGHT)
                {
                    if (x_temp == 24)
                        x_temp = 114;
                }
               else if (c == ENTER)
               {
                    if (y_temp == 14)
                    {
                        system("cls");
                        viewSchoolYear_Screen(username, year_head);
                        return;
                    }
                    else if (y_temp == 12)
                    {
                        if (x_temp == 24)
                        {
                            system("cls");
                            viewSemester_Screen(username, year_head);
                            return;
                        }
                        else
                        {
                            system("cls");
                            viewClass_Screen(username, year_head);
                            return;
                        }
                    }
                    else
                    {
                        if (x_temp == 24)
                        {
                            system("cls");
                            addNewSemester(username, year_head);
                            return;
                        }
                        else
                        {
                            system("cls");
                            addNewClass(year_head, username);
                            return;
                        }
                    }
               }
            }
        }
    }
}