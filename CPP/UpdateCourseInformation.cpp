#include "../Header/Staff.h"
#include "../Header/Design.h"

void updateInformationOfCourse (string username, Year* year_head, Semester* semester_head, Course* accessed_course)
{
    resizeConsole(1920,920);
    system("color E0");

    gotoXY(49,2);
    std::cout << " _   _____________  ___ _____ _____   _____ _____ _   _______  _____ _____";
    gotoXY(49,3);
    std::cout << "| | | | ___ \\  _  \\/ _ \\_   _|  ___| /  __ \\  _  | | | | ___ \\/  ___|  ___|";
    gotoXY(49,4);
    std::cout << "| | | | |_/ / | | / /_\\ \\| | | |__   | /  \\/ | | | | | | |_/ /\\ `--.| |__";
    gotoXY(49,5);
    std::cout << "| | | |  __/| | | |  _  || | |  __|  | |   | | | | | | |    /  `--. \\  __|";
    gotoXY(49,6);
    std::cout << "| |_| | |   | |/ /| | | || | | |___  | \\__/\\ \\_/ / |_| | |\\ \\ /\\__/ / |___";
    gotoXY(49,7);
    std::cout << " \\___/\\_|   |___/ \\_| |_/\\_/ \\____/   \\____/\\___/ \\___/\\_| \\_|\\____/\\____/";

    Create_A_Box_2(55,10,2,15,14,14,0,"COURSE ID");
    Create_A_Box_2(72,10,2,40,14,14,0,"COURSE NAME");
    Create_A_Box_2(55,15,2,15,14,14,0,"CLASS NAME");
    Create_A_Box_2(72,15,2,30,14,14,0,"TEACHER NAME");

    Create_A_Box_2(55,20,2,25,14,14,0,"NUMBER OF CREDITS");
    Create_A_Box_2(87,20,2,25,14,14,0,"MAXIMUM STUDENT");
    Create_A_Box_2(55,25,2,25,14,14,0,"DAY IN WEEK");
    Create_A_Box_2(87,25,2,25,14,14,0,"SESSION");

    Create_A_Box_1(125,19,2,10,14,14,0,"  UPDATE");
    gotoXY(15,10);
    std::cout << "Press ESC to return back";

    int x_temp = 55; int y_temp = 10; int countinfo = 8;

    int pos_Course_ID = accessed_course->course_ID.size(); int pos_Course_Name = accessed_course->course_name.size(); int pos_Class_Name = accessed_course->class_name.size();
    int pos_Teacher_Name = accessed_course->teacher_name.size(); 
    string temp = std::to_string(accessed_course->numCredits);
    int pos_Credit = temp.size(); 
    temp = std::to_string(accessed_course->maxNumStudents);
    int pos_Max_Student = temp.size();

    gotoXY(57,11);
    std::cout << accessed_course->course_ID;
    gotoXY(74,11);
    std::cout << accessed_course->course_name;
    gotoXY(57,16);
    std::cout << accessed_course->class_name;
    gotoXY(74,16);
    std::cout << accessed_course->teacher_name;
    gotoXY(67,21);
    std::cout << accessed_course->numCredits;
    gotoXY(98,21);
    std::cout << accessed_course->maxNumStudents;
    gotoXY(64,26);
    std::cout << accessed_course->dayInWeek;
    gotoXY(98,26);
    std::cout << accessed_course->Session;

    bool flag = true;
    while (true)
    {
        if (flag == true)
        {
            if (y_temp == 10)
            {
                if (x_temp == 55)
                {
                    system("color E0");
                    SetColor1(15,0);
                    for (int i = x_temp + 1; i <= x_temp + 14; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    if (accessed_course->course_ID != "")
                    {
                        gotoXY(57,11);
                        std::cout << accessed_course->course_ID;
                    }
                    ShowConsoleCursor(false);
                }
                else
                {
                    system("color E0");
                    SetColor1(15,0);
                    for (int i = x_temp + 1; i <= x_temp + 39; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    if (accessed_course->course_name != "")
                    {
                        gotoXY(74,11);
                        std::cout << accessed_course->course_name;
                    }
                    ShowConsoleCursor(false);
                }
            }
            else if (y_temp == 15)
            {
                if (x_temp == 55)
                {
                    system("color E0");
                    SetColor1(15,0);
                    for (int i = x_temp + 1; i <= x_temp + 14; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    if (accessed_course->class_name != "")
                    {
                        gotoXY(57,16);
                        std::cout << accessed_course->class_name;
                    }
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

                    if (accessed_course->teacher_name != "")
                    {
                        gotoXY(74,16);
                        std::cout << accessed_course->teacher_name;
                    }
                    ShowConsoleCursor(false);
                }
            }
            else if (y_temp == 20)
            {
                if (x_temp == 55)
                {
                    system("color E0");
                    SetColor1(15,0);
                    for (int i = x_temp + 1; i <= x_temp + 24; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    if (accessed_course->numCredits != 0)
                    {
                        gotoXY(67,21);
                        std::cout << accessed_course->numCredits;
                    }

                    ShowConsoleCursor(false);
                }
                else
                {
                    system("color E0");
                    SetColor1(15,0);
                    for (int i = x_temp + 1; i <= x_temp + 24; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    if (accessed_course->maxNumStudents != 0)
                    {
                        gotoXY(98,21);
                        std::cout << accessed_course->maxNumStudents;
                    }

                    ShowConsoleCursor(false);
                }
            }
            else
            {
                if (x_temp == 55)
                {
                    system("color E0");
                    SetColor1(15,0);
                    for (int i = x_temp + 1; i <= x_temp + 24; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    if (accessed_course->dayInWeek != "")
                    {
                        gotoXY(64,26);
                        std::cout << accessed_course->dayInWeek;
                    }
                    else
                    {
                        gotoXY(57,26);
                        std::cout << "Select Option";
                        gotoXY(78,26);
                        std::cout << (char)(31);
                    }

                    ShowConsoleCursor(false);
                }
                else if (x_temp == 87)
                {
                    system("color E0");
                    SetColor1(15,0);
                    for (int i = x_temp + 1; i <= x_temp + 24; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    if (accessed_course->Session != "")
                    {
                        gotoXY(98,26);
                        std::cout << accessed_course->Session;
                    }
                    else
                    {
                        gotoXY(89,26);
                        std::cout << "Select Option";
                        gotoXY(110,26);
                        std::cout << (char)(31);
                    }

                    ShowConsoleCursor(false);
                }
                else
                {
                    system("color E0");
                    SetColor1(15,0);
                    for (int i = x_temp + 1; i <= x_temp + 9; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(126,20);
                    std::cout << "  UPDATE";

                    ShowConsoleCursor(false);
                }
            }

            flag = false;
        }
        else
        {
            if (_kbhit())//keyboardhit
            {
                char c = _getch();
                system("color E0");
                flag = true;

                if (y_temp == 10)
                {
                    if (x_temp == 55)
                    {
                        system("color E0");
                        SetColor1(14,0);
                        for (int i = x_temp + 1; i <= x_temp + 14; ++i)
                        {
                            gotoXY(i, y_temp + 1);
                            std::cout << " ";
                        }

                        if (accessed_course->course_ID != "")
                        {
                            gotoXY(57,11);
                            std::cout << accessed_course->course_ID;
                        }
                        ShowConsoleCursor(false);
                    }
                    else
                    {
                        system("color E0");
                        SetColor1(14,0);
                        for (int i = x_temp + 1; i <= x_temp + 39; ++i)
                        {
                            gotoXY(i, y_temp + 1);
                            std::cout << " ";
                        }

                        if (accessed_course->course_name != "")
                        {
                            gotoXY(74,11);
                            std::cout << accessed_course->course_name;
                        }
                        ShowConsoleCursor(false);
                    }
                }
                else if (y_temp == 15)
                {
                    if (x_temp == 55)
                    {
                        system("color E0");
                        SetColor1(14,0);
                        for (int i = x_temp + 1; i <= x_temp + 14; ++i)
                        {
                            gotoXY(i, y_temp + 1);
                            std::cout << " ";
                        }

                        if (accessed_course->class_name != "")
                        {
                            gotoXY(57,16);
                            std::cout << accessed_course->class_name;
                        }
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

                        if (accessed_course->teacher_name != "")
                        {
                            gotoXY(74,16);
                            std::cout << accessed_course->teacher_name;
                        }
                        ShowConsoleCursor(false);
                    }
                }
                else if (y_temp == 20)
                {
                    if (x_temp == 55)
                    {
                        system("color E0");
                        SetColor1(14,0);
                        for (int i = x_temp + 1; i <= x_temp + 24; ++i)
                        {
                            gotoXY(i, y_temp + 1);
                            std::cout << " ";
                        }

                        if (accessed_course->numCredits != 0)
                        {
                            gotoXY(67,21);
                            std::cout << accessed_course->numCredits;
                        }

                        ShowConsoleCursor(false);
                    }
                    else
                    {
                        system("color E0");
                        SetColor1(14,0);
                        for (int i = x_temp + 1; i <= x_temp + 24; ++i)
                        {
                            gotoXY(i, y_temp + 1);
                            std::cout << " ";
                        }

                        if (accessed_course->maxNumStudents != 0)
                        {
                            gotoXY(98,21);
                            std::cout << accessed_course->maxNumStudents;
                        }

                        ShowConsoleCursor(false);
                    }
                }
                else
                {
                    if (x_temp == 55)
                    {
                        system("color E0");
                        SetColor1(14,0);
                        for (int i = x_temp + 1; i <= x_temp + 24; ++i)
                        {
                            gotoXY(i, y_temp + 1);
                            std::cout << " ";
                        }

                        if (accessed_course->dayInWeek != "")
                        {
                            gotoXY(64,26);
                            std::cout << accessed_course->dayInWeek;
                        }
                        else
                        {
                            gotoXY(57,26);
                            std::cout << "Select Option";
                            gotoXY(78,26);
                            std::cout << (char)(31);
                        }

                        ShowConsoleCursor(false);
                    }
                    else if (x_temp == 87)
                    {
                        system("color E0");
                        SetColor1(14,0);
                        for (int i = x_temp + 1; i <= x_temp + 24; ++i)
                        {
                            gotoXY(i, y_temp + 1);
                            std::cout << " ";
                        }

                        if (accessed_course->Session != "")
                        {
                            gotoXY(98,26);
                            std::cout << accessed_course->Session;
                        }
                        else
                        {
                            gotoXY(89,26);
                            std::cout << "Select Option";
                            gotoXY(110,26);
                            std::cout << (char)(31);
                        }

                        ShowConsoleCursor(false);
                    }
                    else
                    {
                        system("color E0");
                        SetColor1(14,0);
                        for (int i = x_temp + 1; i <= x_temp + 9; ++i)
                        {
                            gotoXY(i, y_temp + 1);
                            std::cout << " ";
                        }

                        gotoXY(126,20);
                        std::cout << "  UPDATE";

                        ShowConsoleCursor(false);
                    }
                }

                if (c == ESC)
                {
                    system("cls");
                    updateACourse(username, year_head, semester_head, accessed_course);
                    return;
                }
                else if (c == LEFT)
                {
                    if (x_temp == 72 || x_temp == 87)
                        x_temp = 55;
                    else if (x_temp == 125)
                    {
                        gotoXY(115,22);
                        std::cout << "                                     ";

                        x_temp = 72;
                        y_temp = 10;
                    }
                }
                else if (c == RIGHT)
                {
                    if (x_temp == 55)
                    {
                        if (y_temp == 10 || y_temp == 15)
                            x_temp = 72;
                        else
                            x_temp = 87;
                    }
                    else if (x_temp == 72 || x_temp == 87)
                    {
                        x_temp = 125;
                        y_temp = 19;
                    }
                }
                else if (c == DOWN)
                {
                    if (y_temp == 10)
                        y_temp += 5;
                    else if (y_temp == 15)
                    {
                        y_temp += 5;
                        if (x_temp == 72)
                            x_temp = 87;
                    }
                    else if (y_temp == 20)
                        y_temp += 5;
                    else
                    {
                        y_temp = 10;
                        if (x_temp == 87)
                            x_temp = 72;
                    }
                }
                else if (c == UP)
                {
                    if (y_temp == 25)
                        y_temp -= 5;
                    else if (y_temp == 20)
                    {
                        y_temp -= 5;
                        if (x_temp == 87)
                            x_temp = 72;
                    }
                    else if (y_temp == 15)
                        y_temp -= 5;
                    else
                    {
                        y_temp = 25;
                        if (x_temp == 72)
                            x_temp = 87;
                    }
                }
                else if (c == ENTER)
                {
                    if (y_temp == 10)
                    {
                        if (x_temp == 55)
                        {
                            if (accessed_course->course_ID != "")
                                countinfo--;

                            gotoXY(57 + accessed_course->course_ID.size(), 11);
                            ShowConsoleCursor(true);

                            char c;
                            while (true)
                            {
                                c = _getch();

                                if (c == ENTER)
                                {
                                    if (accessed_course->course_ID != "")
                                        countinfo++;
                                    ShowConsoleCursor(false);
                                    break;
                                }
                                else if (c == BACKSPACE)
                                {
                                    if (accessed_course->course_ID != "" && pos_Course_ID > 0)
                                    {
                                        std::cout << "\b \b";
                                        accessed_course->course_ID.pop_back();
                                    }
                                }
                                else if (c == LEFT)
                                {
                                    if (pos_Course_ID > 0)
                                    {
                                        pos_Course_ID--;
                                        gotoXY(57 + pos_Course_ID, 11);
                                    }

                                    continue;
                                }
                                else if (c == RIGHT)
                                {
                                    int len = accessed_course->course_ID.size();

                                    if (pos_Course_ID < len)
                                    {
                                        pos_Course_ID++;
                                        gotoXY(57 + pos_Course_ID, 11);
                                    }

                                    continue;
                                }
                                else
                                {
                                    int len = accessed_course->course_ID.size();

                                    if (((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)) && len < 13)
                                    {
                                        pos_Course_ID++;
                                        accessed_course->course_ID += c;
                                        std::cout << c;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (accessed_course->course_name != "")
                                countinfo--;

                            gotoXY(74 + accessed_course->course_name.size(), 11);
                            ShowConsoleCursor(true);

                            char c;
                            while (true)
                            {
                                c = _getch();

                                if (c == ENTER)
                                {
                                    if (accessed_course->course_name != "")
                                        countinfo++;
                                    ShowConsoleCursor(false);
                                    break;
                                }
                                else if (c == BACKSPACE)
                                {
                                    if (accessed_course->course_name != "" && pos_Course_Name > 0)
                                    {
                                        std::cout << "\b \b";
                                        accessed_course->course_name.pop_back();
                                    }
                                }
                                else if (c == LEFT)
                                {
                                    if (pos_Course_Name > 0)
                                    {
                                        pos_Course_Name--;
                                        gotoXY(74 + pos_Course_Name, 11);
                                    }

                                    continue;
                                }
                                else if (c == RIGHT)
                                {
                                    int len = accessed_course->course_name.size();

                                    if (pos_Course_Name < len)
                                    {
                                        pos_Course_Name++;
                                        gotoXY(74 + pos_Course_Name, 11);
                                    }

                                    continue;
                                }
                                else
                                {
                                    int len = accessed_course->course_name.size();

                                    if (c >= 32 && c <= 126 && len < 37)
                                    {
                                        pos_Course_Name++;
                                        accessed_course->course_name += c;
                                        std::cout << c;
                                    }
                                }
                            }
                        }
                    }
                    else if (y_temp == 15)
                    {
                        if (x_temp == 55)
                        {
                            if (accessed_course->class_name != "")
                                countinfo--;

                            gotoXY(57 + accessed_course->class_name.size(), 16);
                            ShowConsoleCursor(true);

                            char c;
                            while (true)
                            {
                                c = _getch();

                                if (c == ENTER)
                                {
                                    if (accessed_course->class_name != "")
                                        countinfo++;
                                    ShowConsoleCursor(false);
                                    break;
                                }
                                else if (c == BACKSPACE)
                                {
                                    if (accessed_course->class_name != "" && pos_Class_Name > 0)
                                    {
                                        std::cout << "\b \b";
                                        accessed_course->class_name.pop_back();
                                    }
                                }
                                else if (c == LEFT)
                                {
                                    if (pos_Class_Name > 0)
                                    {
                                        pos_Class_Name--;
                                        gotoXY(57 + pos_Class_Name, 16);
                                    }

                                    continue;
                                }
                                else if (c == RIGHT)
                                {
                                    int len = accessed_course->class_name.size();

                                    if (pos_Class_Name < len)
                                    {
                                        pos_Class_Name++;
                                        gotoXY(57 + pos_Class_Name, 16);
                                    }

                                    continue;
                                }
                                else
                                {
                                    int len = accessed_course->class_name.size();

                                    if (((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)) && len < 13)
                                    {
                                        pos_Class_Name++;
                                        accessed_course->class_name += c;
                                        std::cout << c;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (accessed_course->teacher_name != "")
                                countinfo--;

                            gotoXY(74 + accessed_course->teacher_name.size(), 16);
                            ShowConsoleCursor(true);

                            char c;
                            while (true)
                            {
                                c = _getch();

                                if (c == ENTER)
                                {
                                    if (accessed_course->teacher_name != "")
                                        countinfo++;
                                    ShowConsoleCursor(false);
                                    break;
                                }
                                else if (c == BACKSPACE)
                                {
                                    if (accessed_course->teacher_name != "" && pos_Teacher_Name > 0)
                                    {
                                        std::cout << "\b \b";
                                        accessed_course->teacher_name.pop_back();
                                    }
                                }
                                else if (c == LEFT)
                                {
                                    if (pos_Teacher_Name > 0)
                                    {
                                        pos_Teacher_Name--;
                                        gotoXY(74 + pos_Teacher_Name, 16);
                                    }

                                    continue;
                                }
                                else if (c == RIGHT)
                                {
                                    int len = accessed_course->teacher_name.size();

                                    if (pos_Teacher_Name < len)
                                    {
                                        pos_Teacher_Name++;
                                        gotoXY(74 + pos_Teacher_Name, 16);
                                    }

                                    continue;
                                }
                                else
                                {
                                    int len = accessed_course->teacher_name.size();

                                    if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 32) && len < 27)
                                    {
                                        pos_Teacher_Name++;
                                        accessed_course->teacher_name += c;
                                        std::cout << c;
                                    }
                                }
                            }
                        }
                    }
                    else if (y_temp == 20)
                    {
                        if (x_temp == 55)
                        {
                            if (accessed_course->numCredits != 0)
                                countinfo--;

                            std::string tempCredit = std::to_string(accessed_course->numCredits);

                            gotoXY(67 + tempCredit.size(), 21);
                            ShowConsoleCursor(true);

                            char c;
                            while (true)
                            {
                                c = _getch();

                                if (c == ENTER)
                                {
                                    if (tempCredit != "")
                                        countinfo++;

                                    if (tempCredit != "")
                                        accessed_course->numCredits = std::stoi(tempCredit);
                                    else
                                        accessed_course->numCredits = 0;

                                    ShowConsoleCursor(false);
                                    break;
                                }
                                else if (c == BACKSPACE)
                                {
                                    if (tempCredit != "" && pos_Credit > 0)
                                    {
                                        std::cout << "\b \b";
                                        tempCredit.pop_back();
                                    }
                                }
                                else if (c == LEFT)
                                {
                                    if (pos_Credit > 0)
                                    {
                                        pos_Credit--;
                                        gotoXY(67 + pos_Credit, 21);
                                    }

                                    continue;
                                }
                                else if (c == RIGHT)
                                {
                                    int len = tempCredit.size();

                                    if (pos_Credit < len)
                                    {
                                        pos_Credit++;
                                        gotoXY(67 + pos_Credit, 21);
                                    }

                                    continue;
                                }
                                else
                                {
                                    int len = tempCredit.size();

                                    if (c >= 48 && c <= 57 && len < 3)
                                    {
                                        pos_Credit++;
                                        tempCredit += c;
                                        std::cout << c;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (accessed_course->maxNumStudents != 0)
                                countinfo--;

                            std::string tempMS = std::to_string(accessed_course->maxNumStudents);
                            if (accessed_course->maxNumStudents == 0)
                                tempMS = "";

                            gotoXY(98 + tempMS.size(), 21);
                            ShowConsoleCursor(true);

                            char c;
                            while (true)
                            {
                                c = _getch();

                                if (c == ENTER)
                                {
                                    if (tempMS != "")
                                        countinfo++;

                                    if (tempMS != "")
                                        accessed_course->maxNumStudents = std::stoi(tempMS);
                                    else
                                        accessed_course->maxNumStudents = 0;

                                    ShowConsoleCursor(false);
                                    break;
                                }
                                else if (c == BACKSPACE)
                                {
                                    if (tempMS != "" && pos_Max_Student > 0)
                                    {
                                        std::cout << "\b \b";
                                        tempMS.pop_back();
                                    }
                                }
                                else if (c == LEFT)
                                {
                                    if (pos_Max_Student > 0)
                                    {
                                        pos_Max_Student--;
                                        gotoXY(98 + pos_Credit, 21);
                                    }

                                    continue;
                                }
                                else if (c == RIGHT)
                                {
                                    int len = tempMS.size();

                                    if (pos_Max_Student < len)
                                    {
                                        pos_Max_Student++;
                                        gotoXY(98 + pos_Max_Student, 21);
                                    }

                                    continue;
                                }
                                else
                                {
                                    int len = tempMS.size();

                                    if (c >= 48 && c <= 57 && len < 4)
                                    {
                                        pos_Max_Student++;
                                        tempMS += c;
                                        std::cout << c;
                                    }
                                }
                            }
                        }
                    }
                    else if (y_temp == 25)
                    {
                        if (x_temp == 55)
                        {
                            if (accessed_course->dayInWeek != "")
                                countinfo--;

                            Create_A_Box_1(60,28,2,15,14,14,0,"    MONDAY");
                            Create_A_Box_1(60,30,2,15,14,14,0,"    TUESDAY");
                            gotoXY(60,30); std::cout << (char)(195);
                            gotoXY(75,30); std::cout << (char)(180);
                            Create_A_Box_1(60,32,2,15,14,14,0,"   WEDNESDAY");
                            gotoXY(60,32); std::cout << (char)(195);
                            gotoXY(75,32); std::cout << (char)(180);
                            Create_A_Box_1(60,34,2,15,14,14,0,"   THURSDAY");
                            gotoXY(60,34); std::cout << (char)(195);
                            gotoXY(75,34); std::cout << (char)(180);
                            Create_A_Box_1(60,36,2,15,14,14,0,"    FRIDAY");
                            gotoXY(60,36); std::cout << (char)(195);
                            gotoXY(75,36); std::cout << (char)(180);
                            Create_A_Box_1(60,38,2,15,14,14,0,"   SATURDAY");
                            gotoXY(60,38); std::cout << (char)(195);
                            gotoXY(75,38); std::cout << (char)(180);

                            system("color E0");
                            SetColor1(15,0);
                            for (int i = 61; i <= 74; ++i)
                            {
                                gotoXY(i, 29);
                                std::cout << " ";
                            }
                            ShowConsoleCursor(false);

                            int x_cur = 60; int y_cur = 28;
                            bool flag = true;
                            while (true)
                            {
                                if (flag == true)
                                {
                                    if (y_cur == 28)
                                    {
                                        system("color E0");
                                        SetColor1(15,0);
                                        for (int i = x_cur + 1; i <= x_cur + 14; ++i)
                                        {
                                            gotoXY(i, y_cur + 1);
                                            std::cout << " ";
                                        }

                                        gotoXY(x_cur + 1, y_cur + 1);
                                        std::cout << "    MONDAY";
                                        ShowConsoleCursor(false);
                                    }
                                    else if (y_cur == 30)
                                    {
                                        system("color E0");
                                        SetColor1(15,0);
                                        for (int i = x_cur + 1; i <= x_cur + 14; ++i)
                                        {
                                            gotoXY(i, y_cur + 1);
                                            std::cout << " ";
                                        }

                                        gotoXY(x_cur + 1, y_cur + 1);
                                        std::cout << "    TUESDAY";
                                        ShowConsoleCursor(false);
                                    }
                                    else if (y_cur == 32)
                                    {
                                        system("color E0");
                                        SetColor1(15,0);
                                        for (int i = x_cur + 1; i <= x_cur + 14; ++i)
                                        {
                                            gotoXY(i, y_cur + 1);
                                            std::cout << " ";
                                        }

                                        gotoXY(x_cur + 1, y_cur + 1);
                                        std::cout << "   WEDNESDAY";
                                        ShowConsoleCursor(false);
                                    }
                                    else if (y_cur == 34)
                                    {
                                        system("color E0");
                                        SetColor1(15,0);
                                        for (int i = x_cur + 1; i <= x_cur + 14; ++i)
                                        {
                                            gotoXY(i, y_cur + 1);
                                            std::cout << " ";
                                        }

                                        gotoXY(x_cur + 1, y_cur + 1);
                                        std::cout << "   THURSDAY";
                                        ShowConsoleCursor(false);
                                    }
                                    else if (y_cur == 36)
                                    {
                                        system("color E0");
                                        SetColor1(15,0);
                                        for (int i = x_cur + 1; i <= x_cur + 14; ++i)
                                        {
                                            gotoXY(i, y_cur + 1);
                                            std::cout << " ";
                                        }

                                        gotoXY(x_cur + 1, y_cur + 1);
                                        std::cout << "    FRIDAY";
                                        ShowConsoleCursor(false);
                                    }
                                    else
                                    {
                                        system("color E0");
                                        SetColor1(15,0);
                                        for (int i = x_cur + 1; i <= x_cur + 14; ++i)
                                        {
                                            gotoXY(i, y_cur + 1);
                                            std::cout << " ";
                                        }

                                        gotoXY(x_cur + 1, y_cur + 1);
                                        std::cout << "   SATURDAY";
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
                                        flag = true;

                                        if (y_cur == 28)
                                        {
                                            system("color E0");
                                            SetColor1(14,0);
                                            for (int i = x_cur + 1; i <= x_cur + 14; ++i)
                                            {
                                                gotoXY(i, y_cur + 1);
                                                std::cout << " ";
                                            }

                                            gotoXY(x_cur + 1, y_cur + 1);
                                            std::cout << "    MONDAY";
                                            ShowConsoleCursor(false);
                                        }
                                        else if (y_cur == 30)
                                        {
                                            system("color E0");
                                            SetColor1(14,0);
                                            for (int i = x_cur + 1; i <= x_cur + 14; ++i)
                                            {
                                                gotoXY(i, y_cur + 1);
                                                std::cout << " ";
                                            }

                                            gotoXY(x_cur + 1, y_cur + 1);
                                            std::cout << "    TUESDAY";
                                            ShowConsoleCursor(false);
                                        }
                                        else if (y_cur == 32)
                                        {
                                            system("color E0");
                                            SetColor1(14,0);
                                            for (int i = x_cur + 1; i <= x_cur + 14; ++i)
                                            {
                                                gotoXY(i, y_cur + 1);
                                                std::cout << " ";
                                            }

                                            gotoXY(x_cur + 1, y_cur + 1);
                                            std::cout << "   WEDNESDAY";
                                            ShowConsoleCursor(false);
                                        }
                                        else if (y_cur == 34)
                                        {
                                            system("color E0");
                                            SetColor1(14,0);
                                            for (int i = x_cur + 1; i <= x_cur + 14; ++i)
                                            {
                                                gotoXY(i, y_cur + 1);
                                                std::cout << " ";
                                            }

                                            gotoXY(x_cur + 1, y_cur + 1);
                                            std::cout << "   THURSDAY";
                                            ShowConsoleCursor(false);
                                        }
                                        else if (y_cur == 36)
                                        {
                                            system("color E0");
                                            SetColor1(14,0);
                                            for (int i = x_cur + 1; i <= x_cur + 14; ++i)
                                            {
                                                gotoXY(i, y_cur + 1);
                                                std::cout << " ";
                                            }

                                            gotoXY(x_cur + 1, y_cur + 1);
                                            std::cout << "    FRIDAY";
                                            ShowConsoleCursor(false);
                                        }
                                        else
                                        {
                                            system("color E0");
                                            SetColor1(14,0);
                                            for (int i = x_cur + 1; i <= x_cur + 14; ++i)
                                            {
                                                gotoXY(i, y_cur + 1);
                                                std::cout << " ";
                                            }

                                            gotoXY(x_cur + 1, y_cur + 1);
                                            std::cout << "   SATURDAY";
                                            ShowConsoleCursor(false);
                                        }

                                        if (c == UP)
                                        {
                                            if (y_cur == 28)
                                                y_cur = 38;
                                            else
                                                y_cur -= 2;
                                        }
                                        else if (c == DOWN)
                                        {
                                            if (y_cur == 38)
                                                y_cur = 28;
                                            else
                                                y_cur += 2;
                                        }
                                        else if (c == ENTER)
                                        {
                                            system("color E0");
                                            SetColor1(14,0);
                                            for (int i = 60; i <= 75; ++i)
                                            {
                                                for (int j = 28; j <= 40; ++j)
                                                {
                                                    gotoXY(i,j);
                                                    std::cout << " ";
                                                }
                                            }

                                            SetColor1(15,0);
                                            for (int i = 61; i <= 74; ++i)
                                            {
                                                gotoXY(i,26);
                                                std::cout << " ";
                                            }

                                            gotoXY(61,26);
                                            if (y_cur == 28)
                                            {
                                                std::cout << "    MONDAY";
                                                accessed_course->dayInWeek = "MONDAY";
                                            }
                                            else if (y_cur == 30)
                                            {
                                                std::cout << "    TUESDAY";
                                                accessed_course->dayInWeek = "TUESDAY";
                                            }
                                            else if (y_cur == 32)
                                            {
                                                std::cout << "   WEDNESDAY";
                                                accessed_course->dayInWeek = "WEDNESDAY";
                                            }
                                            else if (y_cur == 34)
                                            {
                                                std::cout << "   THURSDAY";
                                                accessed_course->dayInWeek = "THURSDAY";
                                            }
                                            else if (y_cur == 36)
                                            {
                                                std::cout << "    FRIDAY";
                                                accessed_course->dayInWeek = "FRIDAY";
                                            }
                                            else
                                            {
                                                std::cout << "   SATURDAY";
                                                accessed_course->dayInWeek = "SATURDAY";
                                            }

                                            ShowConsoleCursor(false);
                                            break;
                                        }
                                    }
                                }
                            }

                            if (accessed_course->dayInWeek != "")
                                countinfo++;
                        }
                        else
                        {
                            if (accessed_course->Session != "")
                                countinfo--;

                            Create_A_Box_1(92,28,2,15,14,14,0,"     7:30");
                            Create_A_Box_1(92,31,2,15,14,14,0,"     9:30");
                            Create_A_Box_1(92,34,2,15,14,14,0,"    13:30");
                            Create_A_Box_1(92,37,2,15,14,14,0,"    15:30");

                            system("color E0");
                            SetColor1(15,0);
                            for (int i = 93; i <= 106; ++i)
                            {
                                gotoXY(i, 29);
                                std::cout << " ";
                            }
                            ShowConsoleCursor(false);

                            int x_cur = 92; int y_cur = 28;
                            bool flag = true;
                            while (true)
                            {
                                if (flag == true)
                                {
                                    if (y_cur == 28)
                                    {
                                        system("color E0");
                                        SetColor1(15,0);
                                        for (int i = x_cur + 1; i <= x_cur + 14; ++i)
                                        {
                                            gotoXY(i, y_cur + 1);
                                            std::cout << " ";
                                        }

                                        gotoXY(x_cur + 1, y_cur + 1);
                                        std::cout << "     7:30";
                                        ShowConsoleCursor(false);
                                    }
                                    else if (y_cur == 31)
                                    {
                                        system("color E0");
                                        SetColor1(15,0);
                                        for (int i = x_cur + 1; i <= x_cur + 14; ++i)
                                        {
                                            gotoXY(i, y_cur + 1);
                                            std::cout << " ";
                                        }

                                        gotoXY(x_cur + 1, y_cur + 1);
                                        std::cout << "     9:30";
                                        ShowConsoleCursor(false);
                                    }
                                    else if (y_cur == 34)
                                    {
                                        system("color E0");
                                        SetColor1(15,0);
                                        for (int i = x_cur + 1; i <= x_cur + 14; ++i)
                                        {
                                            gotoXY(i, y_cur + 1);
                                            std::cout << " ";
                                        }

                                        gotoXY(x_cur + 1, y_cur + 1);
                                        std::cout << "    13:30";
                                        ShowConsoleCursor(false);
                                    }
                                    else
                                    {
                                        system("color E0");
                                        SetColor1(15,0);
                                        for (int i = x_cur + 1; i <= x_cur + 14; ++i)
                                        {
                                            gotoXY(i, y_cur + 1);
                                            std::cout << " ";
                                        }

                                        gotoXY(x_cur + 1, y_cur + 1);
                                        std::cout << "    15:30";
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
                                        flag = true;

                                        if (y_cur == 28)
                                        {
                                            system("color E0");
                                            SetColor1(14,0);
                                            for (int i = x_cur + 1; i <= x_cur + 14; ++i)
                                            {
                                                gotoXY(i, y_cur + 1);
                                                std::cout << " ";
                                            }

                                            gotoXY(x_cur + 1, y_cur + 1);
                                            std::cout << "     7:30";
                                            ShowConsoleCursor(false);
                                        }
                                        else if (y_cur == 31)
                                        {
                                            system("color E0");
                                            SetColor1(14,0);
                                            for (int i = x_cur + 1; i <= x_cur + 14; ++i)
                                            {
                                                gotoXY(i, y_cur + 1);
                                                std::cout << " ";
                                            }

                                            gotoXY(x_cur + 1, y_cur + 1);
                                            std::cout << "     9:30";
                                            ShowConsoleCursor(false);
                                        }
                                        else if (y_cur == 34)
                                        {
                                            system("color E0");
                                            SetColor1(14,0);
                                            for (int i = x_cur + 1; i <= x_cur + 14; ++i)
                                            {
                                                gotoXY(i, y_cur + 1);
                                                std::cout << " ";
                                            }

                                            gotoXY(x_cur + 1, y_cur + 1);
                                            std::cout << "    13:30";
                                            ShowConsoleCursor(false);
                                        }
                                        else
                                        {
                                            system("color E0");
                                            SetColor1(14,0);
                                            for (int i = x_cur + 1; i <= x_cur + 14; ++i)
                                            {
                                                gotoXY(i, y_cur + 1);
                                                std::cout << " ";
                                            }

                                            gotoXY(x_cur + 1, y_cur + 1);
                                            std::cout << "    15:30";
                                            ShowConsoleCursor(false);
                                        }

                                        if (c == UP)
                                        {
                                            if (y_cur == 28)
                                                y_cur = 37;
                                            else
                                                y_cur -= 3;
                                        }
                                        else if (c == DOWN)
                                        {
                                            if (y_cur == 37)
                                                y_cur = 28;
                                            else
                                                y_cur += 3;
                                        }
                                        else if (c == ENTER)
                                        {
                                            system("color E0");
                                            SetColor1(14,0);
                                            for (int i = 92; i <= 107; ++i)
                                            {
                                                for (int j = 28; j <= 40; ++j)
                                                {
                                                    gotoXY(i,j);
                                                    std::cout << " ";
                                                }
                                            }

                                            SetColor1(15,0);
                                            for (int i = 88; i <= 111; ++i)
                                            {
                                                gotoXY(i,26);
                                                std::cout << " ";
                                            }

                                            gotoXY(93,26);
                                            if (y_cur == 28)
                                            {
                                                std::cout << "     7:30";
                                                accessed_course->Session = "7:30";
                                            }
                                            else if (y_cur == 31)
                                            {
                                                std::cout << "     9:30";
                                                accessed_course->Session = "9:30";
                                            }
                                            else if (y_cur == 34)
                                            {
                                                std::cout << "    13:30";
                                                accessed_course->Session = "13:30";
                                            }
                                            else
                                            {
                                                std::cout << "    15:30";
                                                accessed_course->Session = "15:30";
                                            }

                                            ShowConsoleCursor(false);
                                            break;
                                        }
                                    }
                                }
                            }

                            if (accessed_course->Session != "")
                                countinfo++;
                        }

                    }
                    else
                    {
                        if (countinfo < 8)
                        {
                            gotoXY(120,22);
                            std::cout << "Please fulfill your adding";
                        }
                        else
                        {
                            accessed_course->course_ID = NormalizeCourseID(accessed_course->course_ID);
                            accessed_course->course_name = Normalization(accessed_course->course_name);
                            accessed_course->class_name = NormalizeClassName(accessed_course->class_name);
                            accessed_course->teacher_name = Normalization(accessed_course->teacher_name);

                            // Open file for updating information
                            ofstream ofs;
                            ofstream ofs1;
                            string file_name = year_head->year_name + "_semester" + (char)(semester_head->Semester_Ord + 48) + "_course.csv";
                            file_name = "../Txt_Csv/" + file_name;
                            // string file_name1 = accessed_course->class_name + "_semester" + (char)(semester_head->Semester_Ord + 48) + "_" + year_head->year_name + "_courses.csv";
                            // file_name1 = "../Txt_Csv/" + file_name1;
                            // ofs1.open(file_name1);
                            ofs.open(file_name);
                            if (!ofs.is_open())
                            {
                                cerr << "Error: Unable to open file for reading\n";
                                return;
                            }

                            Course* temp = semester_head->course_head;

                            //Clear all file
                            while (temp)
                            {
                                string file_name1 = temp->class_name + "_semester" + (char)(semester_head->Semester_Ord + 48) + "_" + year_head->year_name + "_courses.csv";
                                file_name1 = "../Txt_Csv/" + file_name1;
                                ofs1.open(file_name1);
                                ofs1.close();
                                temp = temp->course_next;
                            }
                            temp = semester_head->course_head;
                            while (temp)
                            {
                                ofs << temp->course_ID << "," << temp->course_name << "," << temp->class_name << "," 
                                    << temp->teacher_name << "," << temp->numCredits << "," << temp->maxNumStudents 
                                    << "," << temp->dayInWeek << "," << temp->Session << "\n";
                                string file_name1 = temp->class_name + "_semester" + (char)(semester_head->Semester_Ord + 48) + "_" + year_head->year_name + "_courses.csv";
                                file_name1 = "../Txt_Csv/" + file_name1;
                                ofs1.open(file_name1, ios::app);
                                ofs1 << temp->course_ID << "," << temp->course_name << "," << temp->class_name << "," 
                                    << temp->teacher_name << "," << temp->numCredits << "," << temp->maxNumStudents 
                                    << "," << temp->dayInWeek << "," << temp->Session << "\n";
                                ofs1.close();
                                temp = temp->course_next;
                            }
                            ofs.close();
                            gotoXY(122,22);
                            std::cout << "Updated successfully";

                            for (int i = 0; i < 3; ++i)
                            {
                                gotoXY(143 + i,22);
                                ShowConsoleCursor(false);
                                std::cout << "." << flush;
                                Sleep(500);
                            }

                            system("cls");
                            updateACourse(username, year_head, semester_head, accessed_course);
                            return;
                        }
                    }
                }
            }
        }
    }
}