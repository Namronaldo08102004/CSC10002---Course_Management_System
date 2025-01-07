#include "../Header/Staff.h"
#include "../Header/Design.h"

//Normalize course ID
string NormalizeCourseID (string Course_ID)
{
    int len = Course_ID.size();

    for (int i = 0; i < len; ++i)
    {
        if (Course_ID[i] >= 'a' && Course_ID[i] <= 'z')
        {
            Course_ID[i] = (char)((int)Course_ID[i] - 32);
        }
    }

    return Course_ID;
}

//Normalization With Course Name and Teacher Name
string Normalization (string input)
{
    int len = input.size();

    int index = 0;
    while (index < len && input[index] == ' ')
    {
        index++;
    }

    if (index == len)
        return "";

    string output = "";
    while (index < len)
    {
        if (output == "")
        {
            output += toupper(input[index]);
            index++;
        }
        else if (input[index - 1] == ' ')
        {
            output += toupper(input[index]);
            index++;
        }
        else
        {
            if (input[index] >= 'A' && input[index] <= 'Z')
            {
                output += (input[index] + 32);
                index++;
            }
            else if (input[index] == ' ')
            {
                output += input[index];

                while (index < len && input[index] == ' ')
                {
                    index++;
                }
            }
            else
            {
                output += input[index];
                index++;
            }
        }
    }

    return output;
}

//Normalize Class Name
string NormalizeClassName (string Class_Name)
{
    int len = Class_Name.size();

    for (int i = 0; i < len; ++i)
    {
        if (Class_Name[i] >= 'a' && Class_Name[i] <= 'z')
        {
            Class_Name[i] = (char)((int)Class_Name[i] - 32);
        }
    }

    return Class_Name;
}

void addNewCourse (string username, Year* year_head, Semester* semester_head)
{
    resizeConsole(1920,920);
    system("color E0");

    gotoXY(55,2);
    std::cout << "  ___ ____________   _____ _____ _   _______  _____ _____";
    gotoXY(55,3);
    std::cout << " / _ \\|  _  \\  _  \\ /  __ \\  _  | | | | ___ \\/  ___|  ___|";
    gotoXY(55,4);
    std::cout << "/ /_\\ \\ | | | | | | | /  \\/ | | | | | | |_/ /\\ `--.| |__";
    gotoXY(55,5);
    std::cout << "|  _  | | | | | | | | |   | | | | | | |    /  `--. \\  __|";
    gotoXY(55,6);
    std::cout << "| | | | |/ /| |/ /  | \\__/\\ \\_/ / |_| | |\\ \\ /\\__/ / |___";
    gotoXY(55,7);
    std::cout << "\\_| |_/___/ |___/    \\____/\\___/ \\___/\\_| \\_|\\____/\\____/";

    Create_A_Box_2(55,10,2,15,14,14,0,"COURSE ID");
    Create_A_Box_2(72,10,2,40,14,14,0,"COURSE NAME");
    Create_A_Box_2(55,15,2,15,14,14,0,"CLASS NAME");
    Create_A_Box_2(72,15,2,30,14,14,0,"TEACHER NAME");

    Create_A_Box_2(55,20,2,25,14,14,0,"NUMBER OF CREDITS");
    Create_A_Box_2(87,20,2,25,14,14,0,"MAXIMUM STUDENT");
    Create_A_Box_2(55,25,2,25,14,14,0,"DAY IN WEEK");
    Create_A_Box_2(87,25,2,25,14,14,0,"SESSION");

    gotoXY(57,26);
    std::cout << "Select Option";
    gotoXY(78,26);
    std::cout << (char)(31);

    gotoXY(89,26);
    std::cout << "Select Option";
    gotoXY(110,26);
    std::cout << (char)(31);

    Create_A_Box_1(125,19,2,10,14,14,0,"   ADD");
    gotoXY(15,10);
    std::cout << "Press ESC to return back";

    int x_temp = 55; int y_temp = 10; int NumCredits = 0; int MaxStudents = 0; int countinfo = 0;
    std::string CourseID = ""; std::string CourseName = ""; std::string ClassName = "";
    std::string TeacherName = ""; std::string DayInWeek = ""; std::string Session = "";

    int pos_Course_ID = 0; int pos_Course_Name = 0; int pos_Class_Name = 0;
    int pos_Teacher_Name = 0; int pos_Credit = 0; int pos_Max_Student = 0;

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

                    if (CourseID != "")
                    {
                        gotoXY(57,11);
                        std::cout << CourseID;
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

                    if (CourseName != "")
                    {
                        gotoXY(74,11);
                        std::cout << CourseName;
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

                    if (ClassName != "")
                    {
                        gotoXY(57,16);
                        std::cout << ClassName;
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

                    if (TeacherName != "")
                    {
                        gotoXY(74,16);
                        std::cout << TeacherName;
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

                    if (NumCredits != 0)
                    {
                        gotoXY(67,21);
                        std::cout << NumCredits;
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

                    if (MaxStudents != 0)
                    {
                        gotoXY(98,21);
                        std::cout << MaxStudents;
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

                    if (DayInWeek != "")
                    {
                        gotoXY(64,26);
                        std::cout << DayInWeek;
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
                else if (y_temp == 25)
                {
                    system("color E0");
                    SetColor1(15,0);
                    for (int i = x_temp + 1; i <= x_temp + 24; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    if (Session != "")
                    {
                        gotoXY(98,26);
                        std::cout << Session;
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
                    std::cout << "   ADD";

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

                        if (CourseID != "")
                        {
                            gotoXY(57,11);
                            std::cout << CourseID;
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

                        if (CourseName != "")
                        {
                            gotoXY(74,11);
                            std::cout << CourseName;
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

                        if (ClassName != "")
                        {
                            gotoXY(57,16);
                            std::cout << ClassName;
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

                        if (TeacherName != "")
                        {
                            gotoXY(74,16);
                            std::cout << TeacherName;
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

                        if (NumCredits != 0)
                        {
                            gotoXY(67,21);
                            std::cout << NumCredits;
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

                        if (MaxStudents != 0)
                        {
                            gotoXY(98,21);
                            std::cout << MaxStudents;
                        }

                        ShowConsoleCursor(false);
                    }
                }
                else if (y_temp == 25)
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

                        if (DayInWeek != "")
                        {
                            gotoXY(64,26);
                            std::cout << DayInWeek;
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
                    else
                    {
                        system("color E0");
                        SetColor1(14,0);
                        for (int i = x_temp + 1; i <= x_temp + 24; ++i)
                        {
                            gotoXY(i, y_temp + 1);
                            std::cout << " ";
                        }

                        if (Session != "")
                        {
                            gotoXY(98,26);
                            std::cout << Session;
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
                    std::cout << "   ADD";

                    ShowConsoleCursor(false);
                }

                if (c == ESC)
                {
                    system("cls");
                    accessSemester(username, year_head, semester_head);
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
                            if (CourseID != "")
                                countinfo--;

                            gotoXY(57 + CourseID.size(), 11);
                            ShowConsoleCursor(true);

                            char c;
                            while (true)
                            {
                                c = _getch();

                                if (c == ENTER)
                                {
                                    if (CourseID != "")
                                        countinfo++;
                                    ShowConsoleCursor(false);
                                    break;
                                }
                                else if (c == BACKSPACE)
                                {
                                    if (CourseID != "" && pos_Course_ID > 0)
                                    {
                                        std::cout << "\b \b";
                                        CourseID.pop_back();
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
                                    int len = CourseID.size();

                                    if (pos_Course_ID < len)
                                    {
                                        pos_Course_ID++;
                                        gotoXY(57 + pos_Course_ID, 11);
                                    }

                                    continue;
                                }
                                else
                                {
                                    int len = CourseID.size();

                                    if (((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)) && len < 13)
                                    {
                                        pos_Course_ID++;
                                        CourseID += c;
                                        std::cout << c;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (CourseName != "")
                                countinfo--;

                            gotoXY(74 + CourseName.size(), 11);
                            ShowConsoleCursor(true);

                            char c;
                            while (true)
                            {
                                c = _getch();

                                if (c == ENTER)
                                {
                                    if (CourseName != "")
                                        countinfo++;
                                    ShowConsoleCursor(false);
                                    break;
                                }
                                else if (c == BACKSPACE)
                                {
                                    if (CourseName != "" && pos_Course_Name > 0)
                                    {
                                        std::cout << "\b \b";
                                        CourseName.pop_back();
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
                                    int len = CourseName.size();

                                    if (pos_Course_Name < len)
                                    {
                                        pos_Course_Name++;
                                        gotoXY(74 + pos_Course_Name, 11);
                                    }

                                    continue;
                                }
                                else
                                {
                                    int len = CourseName.size();

                                    if (c >= 32 && c <= 126 && len < 37)
                                    {
                                        pos_Course_Name++;
                                        CourseName += c;
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
                            if (ClassName != "")
                                countinfo--;

                            gotoXY(57 + ClassName.size(), 16);
                            ShowConsoleCursor(true);

                            char c;
                            while (true)
                            {
                                c = _getch();

                                if (c == ENTER)
                                {
                                    if (ClassName != "")
                                        countinfo++;
                                    ShowConsoleCursor(false);
                                    break;
                                }
                                else if (c == BACKSPACE)
                                {
                                    if (ClassName != "" && pos_Class_Name > 0)
                                    {
                                        std::cout << "\b \b";
                                        ClassName.pop_back();
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
                                    int len = ClassName.size();

                                    if (pos_Class_Name < len)
                                    {
                                        pos_Class_Name++;
                                        gotoXY(57 + pos_Class_Name, 16);
                                    }

                                    continue;
                                }
                                else
                                {
                                    int len = ClassName.size();

                                    if (((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122)) && len < 13)
                                    {
                                        pos_Class_Name++;
                                        ClassName += c;
                                        std::cout << c;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (TeacherName != "")
                                countinfo--;

                            gotoXY(74 + TeacherName.size(), 16);
                            ShowConsoleCursor(true);

                            char c;
                            while (true)
                            {
                                c = _getch();

                                if (c == ENTER)
                                {
                                    if (TeacherName != "")
                                        countinfo++;
                                    ShowConsoleCursor(false);
                                    break;
                                }
                                else if (c == BACKSPACE)
                                {
                                    if (TeacherName != "" && pos_Teacher_Name > 0)
                                    {
                                        std::cout << "\b \b";
                                        TeacherName.pop_back();
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
                                    int len = TeacherName.size();

                                    if (pos_Teacher_Name < len)
                                    {
                                        pos_Teacher_Name++;
                                        gotoXY(74 + pos_Teacher_Name, 16);
                                    }

                                    continue;
                                }
                                else
                                {
                                    int len = TeacherName.size();

                                    if (((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || c == 32) && len < 27)
                                    {
                                        pos_Teacher_Name++;
                                        TeacherName += c;
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
                            if (NumCredits != 0)
                                countinfo--;

                            std::string tempCredit = std::to_string(NumCredits);
                            if (NumCredits == 0)
                                tempCredit = "";

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
                                        NumCredits = std::stoi(tempCredit);
                                    else
                                        NumCredits = 0;

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
                            if (MaxStudents != 0)
                                countinfo--;

                            std::string tempMS = std::to_string(MaxStudents);
                            if (MaxStudents == 0)
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
                                        MaxStudents = std::stoi(tempMS);
                                    else
                                        MaxStudents = 0;

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
                            if (DayInWeek != "")
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
                                                DayInWeek = "MONDAY";
                                            }
                                            else if (y_cur == 30)
                                            {
                                                std::cout << "    TUESDAY";
                                                DayInWeek = "TUESDAY";
                                            }
                                            else if (y_cur == 32)
                                            {
                                                std::cout << "   WEDNESDAY";
                                                DayInWeek = "WEDNESDAY";
                                            }
                                            else if (y_cur == 34)
                                            {
                                                std::cout << "   THURSDAY";
                                                DayInWeek = "THURSDAY";
                                            }
                                            else if (y_cur == 36)
                                            {
                                                std::cout << "    FRIDAY";
                                                DayInWeek = "FRIDAY";
                                            }
                                            else
                                            {
                                                std::cout << "   SATURDAY";
                                                DayInWeek = "SATURDAY";
                                            }

                                            ShowConsoleCursor(false);
                                            break;
                                        }
                                    }
                                }
                            }

                            if (DayInWeek != "")
                                countinfo++;
                        }
                        else
                        {
                            if (Session != "")
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
                                                Session = "7:30";
                                            }
                                            else if (y_cur == 31)
                                            {
                                                std::cout << "     9:30";
                                                Session = "9:30";
                                            }
                                            else if (y_cur == 34)
                                            {
                                                std::cout << "    13:30";
                                                Session = "13:30";
                                            }
                                            else
                                            {
                                                std::cout << "    15:30";
                                                Session = "15:30";
                                            }

                                            ShowConsoleCursor(false);
                                            break;
                                        }
                                    }
                                }
                            }

                            if (Session != "")
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
                            CourseID = NormalizeCourseID(CourseID);
                            CourseName = Normalization(CourseName);
                            ClassName = NormalizeClassName(ClassName);
                            TeacherName = Normalization(TeacherName);

                            int check = 1; Course* tempcourse = semester_head->course_head;

                            while (tempcourse)
                            {
                                if ((tempcourse->course_ID == CourseID && tempcourse->course_name != CourseName) || 
                                    (tempcourse->course_ID != CourseID && tempcourse->course_name == CourseName) || 
                                    (tempcourse->course_ID == CourseID && tempcourse->course_name == CourseName && tempcourse->class_name == ClassName))
                                {
                                    check = 0;
                                    break;
                                }

                                tempcourse = tempcourse->course_next;
                            }

                            if (!check)
                            {
                                gotoXY(116,22);
                                std::cout << "The course has been created before!";
                            }
                            else
                            {
                                // Create new course
                                Course* new_course = new Course;
                                new_course->course_ID = CourseID;
                                new_course->course_name = CourseName;
                                new_course->class_name = ClassName;
                                new_course->teacher_name = TeacherName;
                                new_course->numCredits = NumCredits;
                                new_course->maxNumStudents = MaxStudents;

                                if (DayInWeek == "MONDAY")
                                    new_course->dayInWeek = "Monday";
                                else if (DayInWeek == "TUESDAY")
                                    new_course->dayInWeek = "Tuesday";
                                else if (DayInWeek == "WEDNESDAY")
                                    new_course->dayInWeek = "Wednesday";
                                else if (DayInWeek == "THURSDAY")
                                    new_course->dayInWeek = "Thursday";
                                else if (DayInWeek == "FRIDAY")
                                    new_course->dayInWeek = "Friday";
                                else if (DayInWeek == "SATURDAY")
                                    new_course->dayInWeek = "Saturday";

                                if (Session == "7:30")
                                    new_course->Session = "7:30";
                                else if (Session == "9:30")
                                    new_course->Session = "9:30";
                                else if (Session == "13:30")
                                    new_course->Session = "13:30";
                                else if (Session == "15:30")
                                    new_course->Session = "15:30";

                                new_course->scoreboard_head = nullptr;
                                new_course->student_head = nullptr;
                                new_course->course_next = nullptr;

                                //Add new course at the end of course list of corresponding year
                                if (!semester_head->course_head)
                                    semester_head->course_head = new_course;
                                else
                                {
                                    Course* temp_course = semester_head->course_head;

                                    while (temp_course->course_next)
                                        temp_course = temp_course->course_next;

                                    temp_course->course_next = new_course;
                                }

                                std::ofstream ofs;
                                //Print course list after changed out file txt corresponding with the year and the semester including courses
                                string file_name = year_head->year_name + "_semester" + (char)(semester_head->Semester_Ord + 48) + "_course.csv";
                                file_name = "../Txt_Csv/" + file_name;
                                ofs.open(file_name);
                                if (!ofs.is_open())
                                {
                                    cerr << "Error: Unable to open file for writing\n";
                                    return;
                                }

                                Course* temp_course = semester_head->course_head;
                                while (temp_course->course_next)
                                {
                                    ofs << temp_course->course_ID << "," << temp_course->course_name << "," << temp_course->class_name << "," 
                                        << temp_course->teacher_name << "," << temp_course->numCredits << "," << temp_course->maxNumStudents 
                                        << "," << temp_course->dayInWeek << "," << temp_course->Session << "\n";
                                    
                                    temp_course = temp_course->course_next;
                                }
                                ofs << temp_course->course_ID << "," << temp_course->course_name << "," << temp_course->class_name << "," 
                                    << temp_course->teacher_name << "," << temp_course->numCredits << "," << temp_course->maxNumStudents 
                                    << "," << temp_course->dayInWeek << "," << temp_course->Session;
                                ofs.close();
                                
                                // Create files for each classes
                                Course *current_course = semester_head->course_head;
                                while (current_course != nullptr)
                                {
                                    string Class_name = current_course->class_name;
                                    char char_semester = static_cast<char>(semester_head->Semester_Ord + 48);
                                    string filename = Class_name + "_" + "Semester" + char_semester + "_" + year_head->year_name + "_courses.csv";
                                    filename = "../Txt_Csv/" + filename;
                                    ofstream ofs;
                                    ofs.open(filename);
                                    ofs.close();
                                    current_course = current_course->course_next;
                                }
                                current_course = semester_head->course_head;
                                while (current_course != nullptr)
                                {
                                    string Class_name = current_course->class_name;
                                    char char_semester = static_cast<char>(semester_head->Semester_Ord + 48);
                                    string filename = Class_name + "_" + "Semester" + char_semester + "_" + year_head->year_name + "_courses.csv";
                                    filename = "../Txt_Csv/" + filename;
                                    ofstream ofs(filename, ios::app);
                                    if (!ofs.is_open())
                                    {
                                        cerr << "Error: Unable to open file " << filename << " for writing\n";
                                        return;
                                    }
                                    if (current_course->class_name == Class_name)
                                    {
                                        ofs << current_course->course_ID << "," << current_course->course_name << "," 
                                        << current_course->class_name << "," << current_course->teacher_name << "," 
                                        << current_course->numCredits << "," << current_course->maxNumStudents << "," 
                                        << current_course->dayInWeek << "," << current_course->Session << "\n";
                                    }
                                    ofs.close();
                                    current_course = current_course->course_next;
                                }

                                //Create file including students of created course
                                Course* temp_course1 = semester_head->course_head;

                                while (temp_course1->course_next)
                                    temp_course1 = temp_course1->course_next;

                                string name_file = temp_course1->course_ID + "_Semester" + (char)(semester_head->Semester_Ord + 48) + "_" + ClassName + "_" + year_head->year_name + "_Scoreboard.csv";
                                name_file = "../Txt_Csv/" + name_file;
                                ofs.open(name_file, ios::app);
                                if (!ofs.is_open())
                                {
                                    cerr << "Error: Unable to open file for writing\n";
                                    return;
                                }
                                ofs << "ID,FullName,Midterm,Final,Other,Total";
                                ofs.close();

                                name_file = temp_course1->course_ID + "_Semester" + (char)(semester_head->Semester_Ord + 48) + "_" + ClassName + "_" + year_head->year_name + "_student.csv";
                                name_file = "../Txt_Csv/" + name_file;
                                ofs.open(name_file);
                                if (!ofs.is_open())
                                {
                                    cerr << "Error: Unable to open file for writing\n";
                                    return;
                                }
                                ofs << "student ID,student_socialID,student_fisrtname,student_lastname,gender,class_name,DOB";
                                ofs.close();

                                gotoXY(122,22);
                                std::cout << "Created successfully";

                                for (int i = 0; i < 3; ++i)
                                {
                                    gotoXY(143 + i,22);
                                    ShowConsoleCursor(false);
                                    std::cout << "." << flush;
                                    Sleep(500);
                                }

                                system("cls");
                                accessSemester(username, year_head, semester_head);
                                return;
                            }
                        }
                    }
                }
            }
        }
    }
}