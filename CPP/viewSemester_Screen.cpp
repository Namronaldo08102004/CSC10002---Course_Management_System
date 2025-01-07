#include "../Header/Staff.h"
#include "../Header/Design.h"

void viewSemester_Screen(string username, Year* year_head)
{
    system("cls");
    resizeConsole(1920,920);
    system("color E0");

    Create_A_Box_3(1,5,33,97);

    gotoXY(2,7);
    std::cout << "   ^7YPBBBGGGBBBGPGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGGBBGGPGBBG5J!:";
    gotoXY(2,8);
    std::cout << "  ?GBPY?7777777777777777777777777777777777777777777777777777777777777777?YGBP!";
    gotoXY(2,9);
    std::cout << " JBBJ                                                                     ^5BG!";
    gotoXY(2,10);
    std::cout << " PBP^                                                                      !GBJ";
    gotoXY(2,11);
    std::cout << " PBG55555555555555555555555555555555555555555555555555555555555555555555555PGBJ";
    gotoXY(2,12);
    std::cout << " PBGYJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ5GBJ";
    gotoXY(2,13);
    std::cout << " 5BP:                                                                      !GBJ";
    gotoXY(2,14);
    std::cout << " 5BP^                                                                      !GBJ";
    gotoXY(2,15);
    std::cout << " 5BP^.:.7BBGGGGGGGGGGGGBBBGGGGGGGGGGGGGBBGGGGGGGGGGGGGBBGGGGGGGGGGGGGBP~.:.!GBJ";
    gotoXY(2,16);
    std::cout << " 5BP^.:.?BB?           JBB?           JBG7           YBG7           5BG~.:.!GBJ";
    gotoXY(2,17);
    std::cout << " 5BP^.:.7BB7           ?BB!           JBB!           JBG~           YBG~.:.!GBJ";
    gotoXY(2,18);
    std::cout << " 5BP^.:.7BB7           ?BB!           JBG!           JBG~           YBG~.:.!GBJ";
    gotoXY(2,19);
    std::cout << " 5BP^.:.7BBY77777777777YBBJ777777777775BBJ777777777775BGJ777777777775BG~.:.!GBJ";
    gotoXY(2,20);
    std::cout << " 5BP^.:.7BBGGGGGGGGGGGGGBGGGGGGGGGGGGGGBGGGGGGGGGGGGGGBGGGGGGGGGGGGGGBG~.:.!GBJ";
    gotoXY(2,21);
    std::cout << " 5BP^.:.7BB?           JBB7           JBG!           YBG!           YBG~.:.!GBJ";
    gotoXY(2,22);
    std::cout << " 5BP^.:.7BB7           ?BB!           JBG!           JBG~           YBG~.:.!GBJ";
    gotoXY(2,23);
    std::cout << " 5BP^.:.7BB7           ?BB!           JBB!           JBG~           YBG~.:.!GBJ";
    gotoXY(2,24);
    std::cout << " 5BP^.:.7BB5777777777775BBY777777777775BBY77777777777PBGY77777777:.:^7!....:!7^";
    gotoXY(2,25);
    std::cout << " 5BP^.:.7BBGPPPPPPPPPPPGBBPPPPPPPPPPPPGBBPPPPPPPPPPPPGBBPPPPPPPPY:...:^!7777!~::";
    gotoXY(2,26);
    std::cout << " 5BP^.:.7BB?           ?BB7           JBB!           JBG~.::...::^!J5PBBGPPPGBG5J7~^";
    gotoXY(2,27);
    std::cout << " 5BP^.:.7BB7           ?BB7           JBB!           :~^...:^!?5PBGG5J        ?YPGBG5J7~";
    gotoXY(2,28);
    std::cout << " 5BP^.:.7BB7           ?BB!           JBB!.........::..^!?5PBBG5J7~              ^!?YPGBG5J7~";
    gotoXY(2,29);
    std::cout << " 5BP^.:.?BBPYYYYYYYYYYYPBB5YYYYYYYYYYYPBB5JYYYYYY?^.:.?GBG5?!^                        ^~7YPBB5^";
    gotoXY(2,30);
    std::cout << " PBP^.:.~YY5555555555555YY5555555555555YY55555555J^..:JBBPY7~                          ^!J5GBP^";
    gotoXY(2,31);
    std::cout << " PBP^.::                                               ~7YPGBG5J7~^               ~7J5PGGPPBB?";
    gotoXY(2,32);
    std::cout << " ?BBJ:                                                    :^7GBGGBGPY7~^:..::~7J5GBGGBBY^";
    gotoXY(2,33);
    std::cout << "  ?GBGY77777777777777777777777777777777777777777777777777^..~GBY^~7YPGBGP55PGBBP5?!^7GB?";
    gotoXY(2,34);
    std::cout << "   ^7J5PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPGP7..~GBY    :^~7JJYJ?!^:    !GBJ";
    gotoXY(2,35);
    std::cout << "                                                             PBP                    JBB";
    gotoXY(2,36);
    std::cout << "                                                              5BG5YYYYYYYYYYYYYYYY5GBG?";
    gotoXY(2,37);
    std::cout << "                                                                ?Y5555555555555555YJ";

    gotoXY(108,2);
    std::cout << "   _____ ________  ________ _____ _____ ___________";
    gotoXY(108,3);
    std::cout << "  /  ___|  ___|  \\/  |  ___/  ___|_   _|  ___| ___ \\";
    gotoXY(108,4);
    std::cout << "  \\ `--.| |__ | .  . | |__ \\ `--.  | | | |__ | |_/ /";
    gotoXY(108,5);
    std::cout << "   `--. \\  __|| |\\/| |  __| `--. \\ | | |  __||    /";
    gotoXY(108,6);
    std::cout << "  /\\__/ / |___| |  | | |___/\\__/ / | | | |___| |\\ \\";
    gotoXY(108,7);
    std::cout << "  \\____/\\____/\\_|  |_|____/\\____/  \\_/ \\____/\\_| \\_|";

    Semester* cur = year_head->semester_head; int numSemesters = 0;

    //Show list of years the staff has created before
    if (cur == nullptr) //Data is empty
    {
        Create_A_Box_1(124,13,2,20,14,14,0,"    RETURN BACK");
        ShowConsoleCursor(false);
    }
    else
    {
        while (cur)
        {
            Create_A_Box_1(108,12 + 4*numSemesters,2,15,14,14,0,"");
            gotoXY(116,13 + 4*numSemesters);
            std::cout << cur->Semester_Ord;

            std::string startdate = "     ";
            if (cur->start_date.day < 10)
                startdate += '0';
            startdate += to_string(cur->start_date.day);

            startdate += '/';

            if (cur->start_date.month < 10)
                startdate += '0';
            startdate += to_string(cur->start_date.month);

            startdate += '/';
            startdate += to_string(cur->start_date.year);

            std::string enddate = "     ";
            if (cur->end_date.day < 10)
                enddate += '0';
            enddate += to_string(cur->end_date.day);

            enddate += '/';

            if (cur->end_date.month < 10)
                enddate += '0';
            enddate += to_string(cur->end_date.month);

            enddate += '/';
            enddate += to_string(cur->end_date.year);

            Create_A_Box_1(123,12 + 4*numSemesters,2,20,14,14,0,startdate);
            gotoXY(123,12 + 4*numSemesters); std::cout << (char)(194);
            gotoXY(123,14 + 4*numSemesters); std::cout << (char)(193);

            Create_A_Box_1(143,12 + 4*numSemesters,2,20,14,14,0,enddate);
            gotoXY(143,12 + 4*numSemesters); std::cout << (char)(194);
            gotoXY(143,14 + 4*numSemesters); std::cout << (char)(193);

            cur = cur->semester_next;
            numSemesters++;
        }

        Create_A_Box_1(132,14 + 4*numSemesters,2,20,14,14,0,"    RETURN BACK");
        ShowConsoleCursor(false);
    }

    //Move the pointer cur to the pointer semester_head again
    cur = year_head->semester_head;

    if (cur)
    {
        int x_temp = 108; int y_temp = 12;
        bool flag = true;
        while (true)
        {
            if (flag == true)
            {
                for (int i = 12; i < 12 + 4*numSemesters; ++i)
                {
                    if (y_temp == i)
                    {
                        system("color E0");
                        SetColor1(15,0);
                        for (int j = x_temp + 1; j <= x_temp + 14; ++j)
                        {
                            gotoXY(j, y_temp + 1);
                            std::cout << " ";
                        }

                        gotoXY(x_temp + 1, y_temp + 1);

                        Semester* temp = year_head->semester_head;
                        for (int j = 0; j < (y_temp - 12)/4; ++j)
                        {
                            temp = temp->semester_next;
                        }  

                        std::cout << "       " << temp->Semester_Ord;
                        ShowConsoleCursor(false);
                    }
                }

                if (y_temp == 14 + 4*numSemesters)
                {
                    system("color E0");
                    SetColor1(15,0);
                    for (int j = 133; j <= 151; ++j)
                    {
                        gotoXY(j, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(133, y_temp + 1);
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
    
                    for (int i = 12; i < 12 + 4*numSemesters; ++i)
                    {
                        if (y_temp == i)
                        {
                            system("color E0");
                            SetColor1(14,0);
                            for (int j = x_temp + 1; j <= x_temp + 14; ++j)
                            {
                                gotoXY(j, y_temp + 1);
                                std::cout << " ";
                            }

                            gotoXY(x_temp + 1, y_temp + 1);

                            Semester* temp = year_head->semester_head;
                            for (int j = 0; j < (y_temp - 12)/4; ++j)
                            {
                                temp = temp->semester_next;
                            }  

                            std::cout << "       " << temp->Semester_Ord;
                            ShowConsoleCursor(false);
                        }
                    }

                    if (y_temp == 14 + 4*numSemesters)
                    {
                        system("color E0");
                        SetColor1(14,0);
                        for (int j = 133; j <= 151; ++j)
                        {
                            gotoXY(j, y_temp + 1);
                            std::cout << " ";
                        }

                        gotoXY(133, y_temp + 1);
                        std::cout << "    RETURN BACK";
                        ShowConsoleCursor(false);
                    }
    
                    flag = true;
    
                    if (c == UP)
                    {
                        if (y_temp == 12)
                            y_temp = 14 + 4*numSemesters;
                        else if (y_temp == 14 + 4*numSemesters)
                            y_temp -= 6;
                        else
                            y_temp -= 4;
                    }
                    else if (c == DOWN)
                    {
                        if (y_temp == 14 + 4*numSemesters)
                            y_temp = 12;
                        else if (y_temp == 8 + 4*numSemesters)
                            y_temp += 6;
                        else
                            y_temp += 4;
                    }
                    else if (c == ENTER)
                    {
                        if (y_temp == 14 + 4*numSemesters)
                        {
                            system("cls");
                            accessSchoolYear(username, year_head);
                            return;
                        }
                        else
                        {
                            Semester* temp_semester = year_head->semester_head;
                            for (int j = 0; j < (y_temp - 12)/4; ++j)
                            {
                                temp_semester = temp_semester->semester_next;
                            }

                            system("cls");
                            accessSemester(username, year_head, temp_semester);
                            return;
                        }
                    }
                }
            }
        }
    }

    bool flag = true;
    while (true)
    {
        if (flag == true)
        {
            system("color E0");
            SetColor1(15,0);
            for (int j = 125; j <= 143; ++j)
            {
                gotoXY(j, 14);
                std::cout << " ";
            }

            gotoXY(125, 14);
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