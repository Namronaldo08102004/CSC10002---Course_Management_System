#include "../Header/Staff.h"
#include "../Header/Design.h"
void viewClass_Screen(string username, Year* &year_head)
{                                                      
    system("cls");
    resizeConsole(1920,920);
    system("color E0");

    int y = -3;
    gotoXY(70, y + 5);
    std::cout << "                                                                                                    ";
    gotoXY(70, y + 6);
    std::cout << "       .!?YY55555555555555555555555555555555555555555555555555555555555555PPPPP55555YJ7:            ";
    gotoXY(70, y + 7);
    std::cout << "      :PGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGB#&&&&&&&&##BGGGGG~           ";
    gotoXY(70, y + 8);
    std::cout << "      :PGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGB#&&&&&&&&##BGGGGG~           ";
    gotoXY(70, y + 9);
    std::cout << "      ~GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGB#BGP5P55B###GGGGG?           ";
    gotoXY(70, y + 10);
    std::cout << "      ~GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG5PPJJ5P5YB#BGGGGG?           ";
    gotoXY(70, y + 11);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPYP555P5YGBPGGGGG?           ";
    gotoXY(70, y + 12);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPYY55555JPGYGGGGG?           ";
    gotoXY(70, y + 13);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBP5J?JJ5B#BGGGGGG?           ";
    gotoXY(70, y + 14);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBGPGGPGB#BGGGGGGG?     :^:   ";
    gotoXY(70, y + 15);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBBBBPYYGGGGGGGGG?    .7J?^  ";
    gotoXY(70, y + 16);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGPYJJY?!?~7JJJJ5GGG?    ^JY?.  ";
    gotoXY(70, y + 17);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGJ~^^^^^~!^^^^^^^?GG?    .?7.   ";
    gotoXY(70, y + 18);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG5^^^^^^^!7^^^^^^^^5B?    ^^     ";
    gotoXY(70, y + 19);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGP7^^~^^^^77~^^^^~^^~PJ  .^~:     ";
    gotoXY(70, y + 20);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG5~^^!?^^^~77~^^^~Y~^^!? :^~^      ";
    gotoXY(70, y + 21);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGY~^^^5?^^^!77~^^^^5Y^^^~:~~^       ";
    gotoXY(70, y + 22);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG5~^^!5G7^^^!77~^^^^YGJ^^^~^:        ";
    gotoXY(70, y + 23);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGY^^~PGG!^^^~!!^^^^^?GGY7~:.         ";
    gotoXY(70, y + 24);
    std::cout << "      !GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGG5!^!PG!^^^^^^^^^^^7GGGB?           ";
    gotoXY(70, y + 25);
    std::cout << "      ^GGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGJ~~5~^^^^^^^^^^^!GGGG!           ";
    gotoXY(70, y + 26);
    std::cout << "       ^?Y5PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP5?JJ?JYYYYYYYYYYP5J~            ";
    gotoXY(70, y + 27);
    std::cout << "          ...........................................................:?BGGGGGGGGGGBG^               ";
    gotoXY(70, y + 28);
    std::cout << "                                                                       5GGGGGGGGGGGB~               ";
    gotoXY(70, y + 29);
    std::cout << "                                                                       YBGGGGGGGGGGB?               ";
    gotoXY(70, y + 30);
    std::cout << "                                                                       YBGGGG55GGGGGY               ";
    gotoXY(70, y + 31);
    std::cout << "           .^!~~~!~:^~~^                         ...                   JBGGGB?~GBB###P5?^           ";
    gotoXY(70, y + 32);
    std::cout << "         7YY5PPPPPP55PP5J~.                 :~7??JJJ?7~.               JBGGGGPP&@@@@@@@@@7          ";
    gotoXY(70, y + 33);
    std::cout << "        ~5555555555555555Y:                !JYYYYJJJYYYJ~              JBGGGG@@@@@@@@@@@@@P.        ";
    gotoXY(70, y + 34);
    std::cout << "       :555555555555555!.                 ^YJJJJJJJJJJJJY:             ?BGGG&@@@@@@@@@@@@@@:        ";
    gotoXY(70, y + 35);
    std::cout << "       ?P55555555555555:                  ~YJJJJJJJJJJJJY^             ?BGGG#@@@@@@@@@@@@@@!        ";
    gotoXY(70, y + 36);
    std::cout << "       ^J55555555555P5^       .^!PBBJ^.   ^YJJJJJJJJJJJY?              7BGGGG&@@@@@@@@@@@@#~        ";
    gotoXY(70, y + 37);
    std::cout << "         !555PP555PPY:     ~5G#@@@@@@@#P~ :JJJJJJJJJJJJYJ:      .:^~~!~7JYPGP^B@@#GGGB@@&?.         ";
    gotoXY(70, y + 38);
    std::cout << "          .^^~?JJJ!^     .P@@@@@@@@@@@@@@BP5JJJJJJJJJJJJYJ:   .~77777777!!7J5 ^#@@@@@@@@!           ";
    gotoXY(70, y + 39);
    std::cout << "    .:^^^^^^^^^~~~^^^^^^^7@@@@@@@@@@@@@@@@@GJJJJJJJJJJJJJYJ?7~!777777777777!7^!&@@@@@@@&7^~~^^:.    ";
    gotoXY(70, y + 40);
    std::cout << " .^!!!!!!!!!!!!!!!!!!!!!!7#@@@@@@@@@@@@@@@@&YJJJJJJJJJJJJGB##Y!777777777777777?#@@@@@@@&57777777!:  ";
    gotoXY(70, y + 41);
    std::cout << ".~!!!!!!!!!!!!!!!!!!!!!!!G@@@@@@@@@@@@@@@@@&YYYJJYYYJJY55BBBBP7!77777777777777775@@@@@@@@5!7777777^ ";
    gotoXY(70, y + 42);
    std::cout << "^!!!!!77?????????????????&@@@@@@@@@@@@@@@@@GPGGPPGGPPPGGGGGGGB57!77777777777?????G@@@@@@@5????77777.";
    gotoXY(70, y + 43);
    std::cout << "~!!!!!Y5555555555555555PJ:YGB&@@@@@@@@@@##G555555555555555555GBB5?7!!!!777^JP55555#@@@&GP5555577777:";
    gotoXY(70, y + 44);
    std::cout << "~!!!!!YP5555555555555555J.~!!?PB&@@@###B7?5555555555555555555GGG577777777!.?555555PGBGP55555P5?7???:";
    gotoXY(70, y + 45);
    std::cout << ":^^^::~??????????????JYYYJJJJJJJYY5YJYYYJYYYYYYYY???????J?77!777!77777777!!!!!7?J??????????????????^";

    gotoXY(25,2);
    std::cout << " _____ _";
    gotoXY(25,3);
    std::cout << "/  __ \\ |";
    gotoXY(25,4);
    std::cout << "| /  \\/ | __ _ ___ ___";
    gotoXY(25,5);
    std::cout << "| |   | |/ _` / __/ __|";
    gotoXY(25,6);
    std::cout << "| \\__/\\ | (_| \\__ \\__ \\";
    gotoXY(25,7);
    std::cout << " \\____/_|\\__,_|___/___/";

    Class* cur = year_head->class_head; int numClasses = 0;
    while (cur)
    {
        numClasses++;
        cur = cur->next_class;
    }

    if (numClasses == 0)
    {
        Create_A_Box_1(25,15,2,20,14,14,0,"    RETURN BACK");
        ShowConsoleCursor(false);

        bool flag = true;
        while (true)
        {
            if (flag == true)
            {
                system("color E0");
                SetColor1(15,0);
                for (int j = 26; j <= 44; ++j)
                {
                    gotoXY(j, 16);
                    std::cout << " ";
                }

                gotoXY(26, 16);
                std::cout << "    RETURN BACK";
                ShowConsoleCursor(false);

                flag = false;
            }
            else
            {
                if (_kbhit())
                {
                    char c = _getch();
                    flag = true;

                    if (c == ENTER)
                    {
                        system("cls");
                        accessSchoolYear(username, year_head);
                        return;
                    }
                }
            }
        }
    }
    else
    {
        int pages;
        if (numClasses % 6 == 0)
            pages = numClasses/6;
        else
            pages = numClasses/6 + 1;

        Create_A_Box_1(25,37,2,20,14,14,0,"    RETURN BACK");
        ShowConsoleCursor(false);

        int curpage = 1;
        while (curpage <= pages)
        {
            for (int i = 2; i <= 60; ++i)
            {
                for (int j = 11; j <= 33; ++j)
                {
                    gotoXY(i,j);
                    std::cout << " ";
                }
            }

            for (int i = 0; i <= min(5,numClasses - 6*(curpage - 1) - 1); ++i)
                Create_A_Box_3(20,11 + 4*i,2,30);

            gotoXY(33,35);
            std::cout << (char)(17) << " " << curpage << "/" << pages << " " << (char)(16);

            cur = year_head->class_head;
            for (int i = 1; i <= 6*(curpage - 1); ++i)
            {
                cur = cur->next_class;
            }

            Class* temp = cur;
            for (int i = 0; i <= min(5,numClasses - 6*(curpage - 1) - 1); ++i)
            {
                gotoXY(21,12 + 4*i);
                std::string name_class = "          " + temp->class_name;
                std::cout << name_class;
                temp = temp->next_class;
            }

            int x_temp = 20; int y_temp = 11;
            bool flag = true;
            while (true)
            {
                if (flag == true)
                {
                    for (int i = 11; i <= 11 + 4*min(5,numClasses - 6*(curpage - 1) - 1); i += 4)
                    {
                        if (y_temp == i)
                        {
                            system("color E0");
                            SetColor1(15,0);
                            for (int j = x_temp + 1; j <= x_temp + 29; ++j)
                            {
                                gotoXY(j, y_temp + 1);
                                std::cout << " ";
                            }

                            gotoXY(x_temp + 1, y_temp + 1);

                            Class* tempClass = cur;
                            for (int i = 0; i < (y_temp - 11)/4; ++i)
                            {
                                tempClass = tempClass->next_class;
                            } 

                            std::string name_class = "          " + tempClass->class_name;
                            std::cout << name_class;
                            ShowConsoleCursor(false);
                        }
                    }

                    if (y_temp == 37)
                    {
                        system("color E0");
                        SetColor1(15,0);
                        for (int j = 26; j <= 44; ++j)
                        {
                            gotoXY(j, 38);
                            std::cout << " ";
                        }

                        gotoXY(26, 38);
                        std::cout << "    RETURN BACK";
                        ShowConsoleCursor(false);
                    }
        
                    flag = false;
                }
                else
                {
                    if (_kbhit())
                    {
                        char c = _getch();
        
                        for (int i = 11; i <= 11 + 4*min(5,numClasses - 6*(curpage - 1) - 1); i += 4)
                        {
                            if (y_temp == i)
                            {
                                system("color E0");
                                SetColor1(14,0);
                                for (int j = x_temp + 1; j <= x_temp + 29; ++j)
                                {
                                    gotoXY(j, y_temp + 1);
                                    std::cout << " ";
                                }

                                gotoXY(x_temp + 1, y_temp + 1);

                                Class* tempClass = cur;
                                for (int i = 0; i < (y_temp - 11)/4; ++i)
                                {
                                    tempClass = tempClass->next_class;
                                } 

                                std::string name_class = "          " + tempClass->class_name;
                                std::cout << name_class;
                                ShowConsoleCursor(false);
                            }
                        }

                        if (y_temp == 37)
                        {
                            system("color E0");
                            SetColor1(14,0);
                            for (int j = 26; j <= 44; ++j)
                            {
                                gotoXY(j, 38);
                                std::cout << " ";
                            }

                            gotoXY(26, 38);
                            std::cout << "    RETURN BACK";
                            ShowConsoleCursor(false);
                        }
        
                        flag = true;
        
                        if (c == UP)
                        {
                            if (y_temp == 11)
                                y_temp = 37;
                            else if (y_temp == 37)
                                y_temp = 11 + 4*min(5,numClasses - 6*(curpage - 1) - 1);
                            else
                                y_temp -= 4;
                        }
                        else if (c == DOWN)
                        {
                            if (y_temp == 37)
                                y_temp = 11;
                            else if (y_temp == 11 + 4*min(5,numClasses - 6*(curpage - 1) - 1))
                                y_temp = 37;
                            else
                                y_temp += 4;
                        }
                        else if (c == LEFT)
                        {
                            if (curpage > 1)
                                curpage--;

                            break;
                        }
                        else if (c == RIGHT)
                        {
                            if (curpage < pages)
                                curpage++;

                            break;
                        }
                        else if (c == ENTER)
                        {
                            if (y_temp == 37)
                            {
                                system("cls");
                                accessSchoolYear(username, year_head);
                                return;
                            }
                            else
                            {
                                Class* temp_class = cur;
                                for (int j = 0; j < (y_temp - 11)/4; ++j)
                                {
                                    temp_class = temp_class->next_class;
                                }

                                system("cls");
                                accessClass(username, year_head, temp_class);
                                return;
                            }
                        }
                    }
                }
            }
        }

        ShowConsoleCursor(false);
    }
}
