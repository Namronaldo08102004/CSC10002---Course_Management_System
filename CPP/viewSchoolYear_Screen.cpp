#include "../Header/Staff.h"
#include "../Header/Design.h"

void viewSchoolYear_Screen(string username, Year* &year_head)
{
    deletedata(year_head);
    getdata(year_head);

    system("cls");
    resizeConsole(1920,920);
    system("color E0");

    Create_A_Box_3(86,4,32,79);
    ShowConsoleCursor(false);

    gotoXY(87,5);
    std::cout << "                                      ~7:  ";
    gotoXY(87,6);
    std::cout << "                                   .7G@@&Y~   ";
    gotoXY(87,7);
    std::cout << "                                 ^Y#@@@@@@@G7.  ";
    gotoXY(87,8);
    std::cout << "                              .7G@@@@@@@@@@@@#J^  ";
    gotoXY(87,9);
    std::cout << "                            ^J#@@@@@@@@@@@@@@@@&5~.  ";
    gotoXY(87,10);
    std::cout << "                         .!P&@@@@@@@@@@@@@@@@@@@@@B?:  ";
    gotoXY(87,11);
    std::cout << "                       ^JB@@@@@@@@BY!~:^~!YB@@@@@@@@#Y~";
    gotoXY(87,12);
    std::cout << "                      ^GG@@@@@@@&7.   ~^   .?&@@@@@@@GG~ ";
    gotoXY(87,13);
    std::cout << "                        7@@@@@@@! .. :@G:^:. 7@@@@@@@? ";
    gotoXY(87,14);
    std::cout << "                        7@@@@@@&: .. :PGPPP^ :&@@@@@@J ";
    gotoXY(87,15);
    std::cout << "                        7@@@@@@@J  ...  ..   J@@@@@@@J ";
    gotoXY(87,16);
    std::cout << "                        7@@@@@@@@5^.      .^5@@@@@@@@J ";
    gotoXY(87,17);
    std::cout << "                        7@@@@@@@@@@GY?77?5B@@@@@@@@@@J ";
    gotoXY(87,18);
    std::cout << "                        7@@@@@@@@@@@@@@@@@@@@@@@@@@@@J ";
    gotoXY(87,19);
    std::cout << " .::::::::::::::::::::::~????????????????????????????~::::::::::::::::::::::.";
    gotoXY(87,20);
    std::cout << " 7&&&&&&&&&&&&&&&&&&&&&&##############################&&&&&&&&&&&&&&&&&&&&&&J ";
    gotoXY(87,21);
    std::cout << " ?@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Y ";
    gotoXY(87,22);
    std::cout << " ?@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Y ";
    gotoXY(87,23);
    std::cout << " ?@@@@@@GJJJJYG@@@@&5JJJJY#@@@@@@@@@@@@@@@@@@@@@@@@&5JJJJ5&@@@@BYJJJJG@@@@@@Y ";
    gotoXY(87,24);
    std::cout << " ?@@@@@#.     :&@@@5      7@@@@@@@@@@@@@@@@@@@@@@@@J      J@@@@^     .B@@@@@Y ";
    gotoXY(87,25);
    std::cout << " ?@@@@@#.     .#@@@Y      !@@@@@@@@@@@@@@@@@@@@@@@@?      ?@@@&:      B@@@@@Y ";
    gotoXY(87,26);
    std::cout << " ?@@@@@@?^^^^^?@@@@B!^^^^~P@@@@@@@@@@@@@@@@@@@@@@@@G~^^^^~G@@@@J^^^^^7&@@@@@Y ";
    gotoXY(87,27);
    std::cout << " ?@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@&BGGB&@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Y ";
    gotoXY(87,28);
    std::cout << " ?@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@P!:.  .:~5@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Y ";
    gotoXY(87,29);
    std::cout << " ?@@@@@@57!!!75@@@@#J!!!!7B@@@@@&!   ....   ~#@@@@@#?!!!!?#@@@@P7!!!!Y@@@@@@Y ";
    gotoXY(87,30);
    std::cout << " ?@@@@@#.     .&@@@Y      7@@@@@5 .......... J@@@@@?      J@@@&:      B@@@@@Y ";
    gotoXY(87,31);
    std::cout << " ?@@@@@#.     .&@@@Y      7@@@@@J .......... ?@@@@@?      J@@@&:      B@@@@@Y ";
    gotoXY(87,32);
    std::cout << " ?@@@@@@5!!!!!5@@@@#?!!!!7B@@@@@J .......... ?@@@@@B?!!!!?#@@@@P7!!!!Y@@@@@@Y ";
    gotoXY(87,33);
    std::cout << " ?@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@J .......... ?@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Y ";
    gotoXY(87,34);
    std::cout << " ?@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Y .......... ?@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@Y ";
    gotoXY(87,35);
    std::cout << " ~YYYYYYYYYYYYYYYYYYYYYYYYYYYYYY! .......... ~YYYYYYYYYYYYYYYYYYYYYYYYYYYYYY! ";

    gotoXY(10,2);
    std::cout << "   _____ _____ _   _ _____ _____ _      __   _______ ___ ______";
    gotoXY(10,3);
    std::cout << "  /  ___/  __ \\ | | |  _  |  _  | |     \\ \\ / /  ___/ _ \\| ___ \\";
    gotoXY(10,4);
    std::cout << "  \\ `--.| /  \\/ |_| | | | | | | | |      \\ V /| |__/ /_\\ \\ |_/ /";
    gotoXY(10,5);
    std::cout << "   `--. \\ |   |  _  | | | | | | | |       \\ / |  __|  _  |    /";
    gotoXY(10,6);
    std::cout << "  /\\__/ / \\__/\\ | | \\ \\_/ | \\_/ / |____   | | | |__| | | | |\\ \\";
    gotoXY(10,7);
    std::cout << "  \\____/ \\____|_| |_/\\___/ \\___/\\_____/   \\_/ \\____|_| |_|_| \\_|";

    Year* cur = year_head; int numYears = 0;

    //Show list of years the staff has created before
    if (cur == nullptr) //Data is empty
    {
        Create_A_Box_1(32,15,2,20,14,14,0,"    RETURN BACK");
        ShowConsoleCursor(false);
    }
    else
    {
        while (cur)
        {
            std::string name_year = "          " + cur->year_name;
            Create_A_Box_1(27,11 + numYears * 4 ,2,30,14,14,0, name_year);
            cur = cur->year_next;
            numYears++;
        }

        Create_A_Box_1(12,11 + 4 * numYears,2,20,14,14,0,"    RETURN BACK");
        ShowConsoleCursor(false);
    }

    //Move the pointer cur to the pointer year_head again
    cur = year_head;

    if (cur)
    {
        int x_temp = 27; int y_temp = 11;
        bool flag = true;
        while (true)
        {
            if (flag == true)
            {
                for (int i = 11; i < 11 + 4*numYears; ++i)
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

                        Year* temp = year_head;
                        for (int j = 0; j < (y_temp - 11)/4; ++j)
                        {
                            temp = temp->year_next;
                        }  

                        std::string name_year = "          " + temp->year_name;
                        std::cout << name_year;
                        ShowConsoleCursor(false);
                    }
                }

                if (y_temp == 11 + 4*numYears)
                {
                    system("color E0");
                    SetColor1(15,0);
                    for (int j = 13; j <= 31; ++j)
                    {
                        gotoXY(j, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(13, y_temp + 1);
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
    
                    for (int i = 11; i < 11 + 4*numYears; ++i)
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

                            Year* temp = year_head;
                            for (int j = 0; j < (y_temp - 11)/4; ++j)
                            {
                                temp = temp->year_next;
                            }  

                            std::string name_year = "          " + temp->year_name;
                            std::cout << name_year;
                            ShowConsoleCursor(false);
                        }
                    }

                    if (y_temp == 11 + 4*numYears)
                    {
                        system("color E0");
                        SetColor1(14,0);
                        for (int j = 13; j <= 31; ++j)
                        {
                            gotoXY(j, y_temp + 1);
                            std::cout << " ";
                        }

                        gotoXY(13, y_temp + 1);
                        std::cout << "    RETURN BACK";
                        ShowConsoleCursor(false);
                    }
    
                    flag = true;
    
                    if (c == UP)
                    {
                        if (y_temp == 11)
                            y_temp = 11 + 4*numYears;
                        else
                            y_temp -= 4;
                    }
                    else if (c == DOWN)
                    {
                        if (y_temp == 11 + 4*numYears)
                            y_temp = 11;
                        else
                            y_temp += 4;
                    }
                    else if (c == ENTER)
                    {
                        if (y_temp == 11 + 4*numYears)
                        {
                            system("cls");
                            Main_Staff_Screen(username, year_head);
                            return;
                        }
                        else
                        {
                            Year* temp_year = year_head;
                            for (int j = 0; j < (y_temp - 11)/4; ++j)
                            {
                                if (temp_year->semester_head)
                                {
                                    Semester* temp_semester = temp_year->semester_head;
                                    while (temp_semester)
                                    {
                                        if (temp_semester->course_head)
                                        {
                                            Course* temp_course = temp_semester->course_head;
                                            while (temp_course)
                                            {
                                                deallocateStudents(temp_course->student_head);
                                                temp_course = temp_course->course_next;
                                            }
                                            deallocateCourses(temp_semester->course_head);
                                        }

                                        temp_semester = temp_semester->semester_next;
                                    }
                                    deallocateSemesters(temp_year->semester_head);
                                }

                                if (temp_year->class_head)
                                {
                                    Class* temp_class = temp_year->class_head;
                                    while (temp_class)
                                    {
                                        deallocateStudents(temp_class->student_head);
                                        temp_class = temp_class->next_class;
                                    }
                                    deallocateClasses(temp_year->class_head);
                                }

                                Year* temp = temp_year;
                                temp_year = temp_year->year_next;
                                delete temp;
                            }

                            system("cls");
                            accessSchoolYear(username, temp_year);
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
            for (int j = 33; j <= 51; ++j)
            {
                gotoXY(j, 16);
                std::cout << " ";
            }

            gotoXY(33, 16);
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
                    Main_Staff_Screen(username, year_head);
                    return;
                }
            }
        }
    }
}