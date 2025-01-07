#include "../Header/Staff.h"
#include "../Header/Design.h"

bool checkExistingSemester (Semester* &semester_head, int semester_ord)
{   
    if (!semester_head)
        return true;
    
    Semester* temp_semester = semester_head;

    while (temp_semester)
    {
        if (temp_semester->Semester_Ord == semester_ord)
            return false;

        temp_semester = temp_semester->semester_next;
    }

    return true;
}

bool checkInvalidDayOfDate (int year, int month, int day)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        switch (month)
        {
            case 1:
            {
                if (day <= 0 || day > 31)
                    return false;
            }
            case 2:
            {
                if (day <= 0 || day > 29)
                    return false;
            }
            case 3:
            {
                if (day <= 0 || day > 31)
                    return false;
            }
            case 4:
            {
                if (day <= 0 || day > 30)
                    return false;
            }
            case 5:
            {
                if (day <= 0 || day > 31)
                    return false;
            }
            case 6:
            {
                if (day <= 0 || day > 30)
                    return false;
            }
            case 7:
            {
                if (day <= 0 || day > 31)
                    return false;
            }
            case 8:
            {
                if (day <= 0 || day > 31)
                    return false;
            }
            case 9:
            {
                if (day <= 0 || day > 30)
                    return false;
            }
            case 10:
            {
                if (day <= 0 || day > 31)
                    return false;
            }
            case 11:
            {
                if (day <= 0 || day > 30)
                    return false;
            }
            case 12:
            {
                if (day <= 0 || day > 31)
                    return false;
            }
        }
    }
    else
    {
        switch (month)
        {
            case 1:
            {
                if (day <= 0 || day > 31)
                    return false;
            }
            case 2:
            {
                if (day <= 0 || day > 28)
                    return false;
            }
            case 3:
            {
                if (day <= 0 || day > 31)
                    return false;
            }
            case 4:
            {
                if (day <= 0 || day > 30)
                    return false;
            }
            case 5:
            {
                if (day <= 0 || day > 31)
                    return false;
            }
            case 6:
            {
                if (day <= 0 || day > 30)
                    return false;
            }
            case 7:
            {
                if (day <= 0 || day > 31)
                    return false;
            }
            case 8:
            {
                if (day <= 0 || day > 31)
                    return false;
            }
            case 9:
            {
                if (day <= 0 || day > 30)
                    return false;
            }
            case 10:
            {
                if (day <= 0 || day > 31)
                    return false;
            }
            case 11:
            {
                if (day <= 0 || day > 30)
                    return false;
            }
            case 12:
            {
                if (day <= 0 || day > 31)
                    return false;
            }
        }
    }

    return true;
}

bool checkStartDateAndEndDate (int startyear, int startmonth, int startday, int endyear, int endmonth, int endday)
{
    if (startyear > endyear)
        return false;
    
    if (startyear == endyear)
    {
        if (startmonth > endmonth)
            return false;

        if (startmonth == endmonth)
        {
            if (startday >= endday)
                return false;
        }
    }

    return true;
}

void addNewSemester (string username, Year* &year_head) //Now, year_head is the school year you are accessing
{
    resizeConsole(1920,920);
    system("color E0");

    gotoXY(48,2);
    std::cout << "    ___ ____________   _____ ________  ________ _____ _____ ___________";
    gotoXY(48,3);
    std::cout << "   / _ \\|  _  \\  _  \\ /  ___|  ___|  \\/  |  ___/  ___|_   _|  ___| ___ \\";
    gotoXY(48,4);
    std::cout << "  / /_\\ \\ | | | | | | \\ `--.| |__ | .  . | |__ \\ `--.  | | | |__ | |_/ /";
    gotoXY(48,5);
    std::cout << "  |  _  | | | | | | |  `--. \\  __|| |\\/| |  __| `--. \\ | | |  __||    /";
    gotoXY(48,6);
    std::cout << "  | | | | |/ /| |/ /  /\\__/ / |___| |  | | |___/\\__/ / | | | |___| |\\ \\";
    gotoXY(48,7);
    std::cout << "  \\_| |_/___/ |___/   \\____/\\____/\\_|  |_|____/\\____/  \\_/ \\____/\\_| \\_|";

    Create_A_Box_4(40,11,2,20,14,14,0,"SEMESTER","Select option");
    gotoXY(58,12); std::cout << (char)(31);
    Create_A_Box_2(74,11,2,20,14,14,0,"START DATE");
    Create_A_Box_2(108,11,2,20,14,14,0,"END DATE");

    Create_A_Box_1(9,11,2,20,14,14,0,"    RETURN BACK");
    Create_A_Box_3(33,33,4,100);

    gotoXY(35,34);
    std::cout << "1. You must input a number from 1 to 3 because there are at most 3 semesters in a school year";
    gotoXY(35,36);
    std::cout << "2. Don't input an available semester in your chosen school year!";

    int x_temp = 40; int y_temp = 11; int semester_ord = 0; int countinfo = 0;
    std::string startday = ""; std::string startmonth; std::string startyear = "";
    std::string endday = ""; std::string endmonth; std::string endyear = "";

    bool flag = true;
    while (countinfo < 4)
    {
        if (countinfo == 3)
        {
            gotoXY(79,12);
            std::cout << std::setw(2) << std::setfill('0') << std::stoi(startday) << "/" << std::setw(2) << std::setfill('0') << std::stoi(startmonth) << "/" << std::stoi(startyear);

            gotoXY(50,12);
            std::cout << semester_ord;

            gotoXY(113,12);
            std::cout << std::setw(2) << std::setfill('0') << std::stoi(endday) << "/" << std::setw(2) << std::setfill('0') << std::stoi(endmonth) << "/" << std::stoi(endyear);

            gotoXY(73,15);
            std::cout << "Confirm your information?";
            Create_A_Box_1(79,16,2,10,14,14,0,"   YES");
            Create_A_Box_1(79,20,2,10,14,14,0,"   NO");

            int x_cur = 79; int y_cur = 16;
            bool tempflag = true;
            while (true)
            {
                if (tempflag == true)
                {
                    if (y_cur == 16)
                    {
                        system("color E0");
                        SetColor1(15,0);
                        for (int i = x_cur + 1; i <= x_cur + 9; ++i)
                        {
                            gotoXY(i, y_cur + 1);
                            std::cout << " ";
                        }

                        gotoXY(x_cur + 1, y_cur + 1);
                        std::cout << "   YES";
                        ShowConsoleCursor(false);
                    }
                    else
                    {
                        system("color E0");
                        SetColor1(15,0);
                        for (int i = x_cur + 1; i <= x_cur + 9; ++i)
                        {
                            gotoXY(i, y_cur + 1);
                            std::cout << " ";
                        }

                        gotoXY(x_cur + 1, y_cur + 1);
                        std::cout << "   NO";
                        ShowConsoleCursor(false);
                    }

                    tempflag = false;
                }
                else
                {
                    if (_kbhit())//keyboardhit
                    {
                        char c = _getch();

                        system("color E0");
                        if (y_cur == 16)
                        {
                            system("color E0");
                            SetColor1(14,0);
                            for (int i = x_cur + 1; i <= x_cur + 9; ++i)
                            {
                                gotoXY(i, y_cur + 1);
                                std::cout << " ";
                            }

                            gotoXY(x_cur + 1, y_cur + 1);
                            std::cout << "   YES";
                            ShowConsoleCursor(false);
                        }
                        else
                        {
                            system("color E0");
                            SetColor1(14,0);
                            for (int i = x_cur + 1; i <= x_cur + 9; ++i)
                            {
                                gotoXY(i, y_cur + 1);
                                std::cout << " ";
                            }

                            gotoXY(x_cur + 1, y_cur + 1);
                            std::cout << "   NO";
                            ShowConsoleCursor(false);
                        }

                        tempflag = true;

                        if (c == UP)
                        {
                            if (y_cur == 16)
                                y_cur = 20;
                            else
                                y_cur -= 4;
                        }
                        else if (c == DOWN)
                        {
                            if (y_cur == 20)
                                y_cur = 16;
                            else
                                y_cur += 4;
                        }
                        else if (c == ENTER)
                        {
                            if (y_cur == 20)
                            {
                                countinfo = 0;
                                startday = ""; startmonth; startyear = "";
                                endday = ""; endmonth; endyear = "";
                                semester_ord = 0;

                                SetColor1(14,0);
                                for (int i = 75; i <= 93; ++i)
                                {
                                    gotoXY(i, 12);
                                    std::cout << " ";
                                }
                                for (int i = 41; i <= 59; ++i)
                                {
                                    gotoXY(i, 12);
                                    std::cout << " ";
                                }
                                for (int i = 109; i <= 127; ++i)
                                {
                                    gotoXY(i, 12);
                                    std::cout << " ";
                                }

                                for (int i = 70; i <= 100; ++i)
                                {
                                    for (int j = 15; j <= 22; ++j)
                                    {
                                        gotoXY(i,j);
                                        std::cout << " ";
                                    }
                                }

                                gotoXY(41,12);
                                std::cout << "Select option";
                                gotoXY(58,12);
                                std::cout << (char)(31);

                                break;
                            }
                            else
                            {
                                if (!checkExistingSemester(year_head->semester_head, semester_ord))
                                {
                                    system("cls");

                                    Create_A_Box_1(65,27,2,40,14,14,0,"");
                                    gotoXY(67,28);
                                    std::cout << "  Your inputed semester was existed!";
                                    ShowConsoleCursor(false);

                                    addNewSemester(username, year_head);
                                    return;
                                }
                                else if (std::stoi(startmonth) <= 0 || std::stoi(startmonth) > 12 || !checkInvalidDayOfDate(std::stoi(startyear), std::stoi(startmonth),std::stoi(startday))
                                        || std::stoi(endmonth) <= 0 || std::stoi(endmonth) > 12 || !checkInvalidDayOfDate(std::stoi(endyear), std::stoi(endmonth),std::stoi(endday)))
                                {
                                    system("cls");

                                    Create_A_Box_1(55,27,2,60,14,14,0,"");
                                    gotoXY(57,28);
                                    std::cout << "   Your inputed start date or end date is not existed";
                                    ShowConsoleCursor(false);
                                    
                                    addNewSemester(username, year_head);
                                    return;
                                }

                                //Create new semester
                                Semester* new_semester = new Semester;
                                new_semester->Semester_Ord = semester_ord;

                                new_semester->start_date.day = stoi(startday);
                                new_semester->start_date.month = stoi(startmonth);
                                new_semester->start_date.year = stoi(startyear);

                                new_semester->end_date.day = stoi(endday);
                                new_semester->end_date.month = stoi(endmonth);
                                new_semester->end_date.year = stoi(endyear);


                                new_semester->course_head = nullptr;
                                new_semester->semester_next = nullptr;

                                //Add new semester at the end of semester list of corresponding year
                                if (!year_head->semester_head)
                                    year_head->semester_head = new_semester;
                                else
                                {
                                    Semester* temp_semester = year_head->semester_head;

                                    while (temp_semester->semester_next)
                                        temp_semester = temp_semester->semester_next;

                                    temp_semester->semester_next = new_semester;
                                }

                                std::ofstream ofs;    
                                //Print semester list after changed out file txt corresponding with the semester
                                string file_name = year_head->year_name + "_semester.txt";
                                file_name = "../Txt_Csv/" + file_name;
                                ofs.open(file_name);
                                if (!ofs.is_open())
                                {
                                    cerr << "Error: Unable to open file for writing\n";
                                    return;
                                }

                                Semester* temp_semester = year_head->semester_head;
                                while (temp_semester->semester_next)
                                {
                                    ofs << temp_semester->Semester_Ord << "," << setw(2) << setfill('0') << temp_semester->start_date.day
                                        << "/" << setw(2) << setfill('0') << temp_semester->start_date.month << "/" << setw(4) << setfill('0') 
                                        << temp_semester->start_date.year << "," << setw(2) << setfill('0') << temp_semester->end_date.day
                                        << "/" << setw(2) << setfill('0') << temp_semester->end_date.month << "/" << setw(4) << setfill('0') << temp_semester->end_date.year << "\n";

                                    temp_semester = temp_semester->semester_next;
                                }
                                ofs << temp_semester->Semester_Ord << "," << setw(2) << setfill('0') << temp_semester->start_date.day
                                    << "/" << setw(2) << setfill('0') << temp_semester->start_date.month << "/" << setw(4) << setfill('0') 
                                    << temp_semester->start_date.year << "," << setw(2) << setfill('0') << temp_semester->end_date.day
                                    << "/" << setw(2) << setfill('0') << temp_semester->end_date.month << "/" << setw(4) << setfill('0') << temp_semester->end_date.year;
                                ofs.close();

                                //Create file including courses of created semester
                                Semester* temp_semester1 = year_head->semester_head;

                                while (temp_semester1->semester_next)
                                    temp_semester1 = temp_semester1->semester_next;

                                string name_file = year_head->year_name + "_semester" + (char)(temp_semester1->Semester_Ord + 48) + "_course.csv";
                                name_file = "../Txt_Csv/" + name_file;
                                ofs.open(name_file);
                                if (!ofs.is_open())
                                {
                                    cerr << "Error: Unable to open file for writing\n";
                                    return;
                                }
                                ofs.close();

                                Create_A_Box_1(64,30,2,40,14,14,0,"   Add Semester successfully ");
                                for (int i = 0; i < 3; ++i)
                                {
                                    gotoXY(94 + i,31);
                                    ShowConsoleCursor(false);
                                    std::cout << "." << flush;
                                    Sleep(500);
                                }

                                system ("cls");
                                accessSchoolYear(username, year_head);
                                return;
                            }
                        }
                    }
                }
            }

            ShowConsoleCursor(false);
        }

        if (flag == true)
        {
            if (x_temp == 9)
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
            else if (x_temp == 40)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 19; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                if (semester_ord == 0)
                {
                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "Select option";
                    gotoXY(58,12); std::cout << (char)(31);
                }
                else
                {
                    gotoXY(50,12);
                    std::cout << semester_ord;
                }
                ShowConsoleCursor(false);
            }
            else if (x_temp == 74)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 19; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                if (startday != "")
                {
                    gotoXY(79,12);
                    std::cout << std::setw(2) << std::setfill('0') << std::stoi(startday) << "/" << std::setw(2) << std::setfill('0') << std::stoi(startmonth) << "/" << std::stoi(startyear);
                }

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

                if (endday != "")
                {
                    gotoXY(113,12);
                    std::cout << std::setw(2) << std::setfill('0') << std::stoi(endday) << "/" << std::setw(2) << std::setfill('0') << std::stoi(endmonth) << "/" << std::stoi(endyear);
                }

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
                if (x_temp == 9)
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
                else if (x_temp == 40)
                {
                    system("color E0");
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 19; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    if (semester_ord == 0)
                    {
                        gotoXY(x_temp + 1, y_temp + 1);
                        std::cout << "Select option";
                        gotoXY(58,12); std::cout << (char)(31);
                    }
                    else
                    {
                        gotoXY(50,12);
                        std::cout << semester_ord;
                    }
                    ShowConsoleCursor(false);
                }
                else if (x_temp == 74)
                {
                    system("color E0");
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 19; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    if (startday != "")
                    {
                        gotoXY(79,12);
                        std::cout << std::setw(2) << std::setfill('0') << std::stoi(startday) << "/" << std::setw(2) << std::setfill('0') << std::stoi(startmonth) << "/" << std::stoi(startyear);
                    }

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

                    if (endday != "")
                    {
                        gotoXY(113,12);
                        std::cout << std::setw(2) << std::setfill('0') << std::stoi(endday) << "/" << std::setw(2) << std::setfill('0') << std::stoi(endmonth) << "/" << std::stoi(endyear);
                    }

                    ShowConsoleCursor(false);
                }

                flag = true;

                if (c == LEFT)
                {
                    if (x_temp == 9)
                        x_temp = 108;
                    else if (x_temp == 40)
                        x_temp = 9;
                    else
                        x_temp -= 34;
                }
                else if (c == RIGHT)
                {
                    if (x_temp == 108)
                        x_temp = 9;
                    else if (x_temp == 9)
                        x_temp = 40;
                    else
                        x_temp += 34;
                }
                else if (c == ENTER)
                {
                    if (x_temp == 9)
                    {
                        system ("cls");
                        accessSchoolYear(username, year_head);
                        return;
                    }
                    else if (x_temp == 40)
                    {
                        if (semester_ord != 0)
                            countinfo--;

                        Create_A_Box_1(45,15,2,10,14,14,0,"    1");
                        Create_A_Box_1(45,19,2,10,14,14,0,"    2");
                        Create_A_Box_1(45,23,2,10,14,14,0,"    3");

                        system("color E0");
                        SetColor1(15,0);
                        for (int i = 46; i <= 54; ++i)
                        {
                            gotoXY(i, 16);
                            std::cout << " ";
                        }
                        ShowConsoleCursor(false);

                        int x_cur = 45; int y_cur = 15;
                        bool flag = true;
                        while (true)
                        {
                            if (flag == true)
                            {
                                if (y_cur == 15)
                                {
                                    system("color E0");
                                    SetColor1(15,0);
                                    for (int i = x_cur + 1; i <= x_cur + 9; ++i)
                                    {
                                        gotoXY(i, y_cur + 1);
                                        std::cout << " ";
                                    }

                                    gotoXY(x_cur + 1, y_cur + 1);
                                    std::cout << "    1";
                                    ShowConsoleCursor(false);
                                }
                                else if (y_cur == 19)
                                {
                                    system("color E0");
                                    SetColor1(15,0);
                                    for (int i = x_cur + 1; i <= x_cur + 9; ++i)
                                    {
                                        gotoXY(i, y_cur + 1);
                                        std::cout << " ";
                                    }

                                    gotoXY(x_cur + 1, y_cur + 1);
                                    std::cout << "    2";
                                    ShowConsoleCursor(false);
                                }
                                else
                                {
                                    system("color E0");
                                    SetColor1(15,0);
                                    for (int i = x_cur + 1; i <= x_cur + 9; ++i)
                                    {
                                        gotoXY(i, y_cur + 1);
                                        std::cout << " ";
                                    }

                                    gotoXY(x_cur + 1, y_cur + 1);
                                    std::cout << "    3";
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
                                    if (y_cur == 15)
                                    {
                                        system("color E0");
                                        SetColor1(14,0);
                                        for (int i = x_cur + 1; i <= x_cur + 9; ++i)
                                        {
                                            gotoXY(i, y_cur + 1);
                                            std::cout << " ";
                                        }

                                        gotoXY(x_cur + 1, y_cur + 1);
                                        std::cout << "    1";
                                        ShowConsoleCursor(false);
                                    }
                                    else if (y_cur == 19)
                                    {
                                        system("color E0");
                                        SetColor1(14,0);
                                        for (int i = x_cur + 1; i <= x_cur + 9; ++i)
                                        {
                                            gotoXY(i, y_cur + 1);
                                            std::cout << " ";
                                        }

                                        gotoXY(x_cur + 1, y_cur + 1);
                                        std::cout << "    2";
                                        ShowConsoleCursor(false);
                                    }
                                    else
                                    {
                                        system("color E0");
                                        SetColor1(14,0);
                                        for (int i = x_cur + 1; i <= x_cur + 9; ++i)
                                        {
                                            gotoXY(i, y_cur + 1);
                                            std::cout << " ";
                                        }

                                        gotoXY(x_cur + 1, y_cur + 1);
                                        std::cout << "    3";
                                        ShowConsoleCursor(false);
                                    }

                                    flag = true;

                                    if (c == UP)
                                    {
                                        if (y_cur == 15)
                                            y_cur = 23;
                                        else
                                            y_cur -= 4;
                                    }
                                    else if (c == DOWN)
                                    {
                                        if (y_cur == 23)
                                            y_cur = 15;
                                        else
                                            y_cur += 4;
                                    }
                                    else if (c == ENTER)
                                    {
                                        system("color E0");
                                        SetColor1(14,0);
                                        for (int i = 45; i <= 55; ++i)
                                        {
                                            for (int j = 15; j <= 25; ++j)
                                            {
                                                gotoXY(i,j);
                                                std::cout << " ";
                                            }
                                        }

                                        SetColor1(15,0);
                                        for (int i = 41; i <= 59; ++i)
                                        {
                                            gotoXY(i,12);
                                            std::cout << " ";
                                        }

                                        gotoXY(50,12);
                                        std::cout << (y_cur - 15)/4 + 1;
                                        semester_ord = (y_cur - 15)/4 + 1;

                                        ShowConsoleCursor(false);
                                        break;
                                    }
                                }
                            }
                        }

                        if (semester_ord != 0)
                            countinfo++;
                    }
                    else if (x_temp == 74)
                    {
                        if (startday != "")
                            countinfo--;

                        Create_A_Box_2(78,15,2,12,14,14,0,"DAY");
                        Create_A_Box_2(78,19,2,12,14,14,0,"MONTH");
                        Create_A_Box_2(78,23,2,12,14,14,0,"YEAR");

                        std::string day = ""; std::string month = ""; std::string year = ""; int count = 0;

                        int x_cur = 78; int y_cur = 15; int y_old; int xp = x_cur; int yp = y_cur; int pos_day = 0; int pos_month = 0; int pos_year = 0;
                        while (count < 3)
                        {
                            system("color E0");

                            if (y_cur == 15)
                            {
                                gotoXY(xp + 5, yp + 1);
                                ShowConsoleCursor(true);

                                char c;
                                while (true)
                                {
                                    c = _getch();

                                    if (c == ENTER)
                                    {
                                        if (day != "")
                                            count++;

                                        if (month == "")
                                            y_cur = 19;
                                        else if (year == "")
                                            y_cur = 23;

                                        xp = 78;
                                        yp = y_cur;
                                        break;
                                    }
                                    else if (c == BACKSPACE)
                                    {
                                        if (day != "" && pos_day > 0)
                                        {
                                            std::cout << "\b \b";
                                            day.pop_back();
                                        }
                                    }
                                    else if (c == LEFT)
                                    {
                                        if (pos_day > 0)
                                        {
                                            pos_day--;
                                            gotoXY(x_cur + pos_day + 2, y_cur + 1);
                                        }

                                        continue;
                                    }
                                    else if (c == RIGHT)
                                    {
                                        int len = day.size();

                                        if (pos_day < len)
                                        {
                                            pos_day++;
                                            gotoXY(x_cur + pos_day + 2, y_cur + 1);
                                        }

                                        continue;
                                    }
                                    else
                                    {
                                        int len = day.size();

                                        if (c >= 48 && c <= 57 && len < 2)
                                        {
                                            pos_day++;
                                            day += c;
                                            std::cout << c;
                                        }
                                    }
                                }
                            }
                            else if (y_cur == 19)
                            {
                                gotoXY(xp + 5, yp + 1);
                                ShowConsoleCursor(true);

                                char c;
                                while (true)
                                {
                                    c = _getch();

                                    if (c == ENTER)
                                    {
                                        if (month != "")
                                            count++;

                                        if (day == "")
                                            y_cur = 15;
                                        else if (year == "")
                                            y_cur = 23;

                                        xp = 78;
                                        yp = y_cur;
                                        break;
                                    }
                                    else if (c == BACKSPACE)
                                    {
                                        if (month != "" && pos_month > 0)
                                        {
                                            std::cout << "\b \b";
                                            month.pop_back();
                                        }
                                    }
                                    else if (c == LEFT)
                                    {
                                        if (pos_month > 0)
                                        {
                                            pos_month--;
                                            gotoXY(x_cur + pos_month + 2, y_cur + 1);
                                        }

                                        continue;
                                    }
                                    else if (c == RIGHT)
                                    {
                                        int len = month.size();

                                        if (pos_month < len)
                                        {
                                            pos_month++;
                                            gotoXY(x_cur + pos_month + 2, y_cur + 1);
                                        }

                                        continue;
                                    }
                                    else
                                    {
                                        int len = month.size();

                                        if (c >= 48 && c <= 57 && len < 2)
                                        {
                                            pos_month++;
                                            month += c;
                                            std::cout << c;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                gotoXY(xp + 4, yp + 1);
                                ShowConsoleCursor(true);

                                char c;
                                while (true)
                                {
                                    c = _getch();

                                    if (c == ENTER)
                                    {
                                        if (year != "")
                                            count++;

                                        if (day == "")
                                            y_cur = 15;
                                        else if (month == "")
                                            y_cur = 19;

                                        xp = 78;
                                        yp = y_cur;
                                        break;
                                    }
                                    else if (c == BACKSPACE)
                                    {
                                        if (year != "" && pos_year > 0)
                                        {
                                            std::cout << "\b \b";
                                            year.pop_back();
                                        }
                                    }
                                    else if (c == LEFT)
                                    {
                                        if (pos_year > 0)
                                        {
                                            pos_year--;
                                            gotoXY(x_cur + pos_year + 2, y_cur + 1);
                                        }

                                        continue;
                                    }
                                    else if (c == RIGHT)
                                    {
                                        int len = year.size();

                                        if (pos_year < len)
                                        {
                                            pos_year++;
                                            gotoXY(x_cur + pos_year + 2, y_cur + 1);
                                        }

                                        continue;
                                    }
                                    else
                                    {
                                        int len = year.size();

                                        if (c >= 48 && c <= 57 && len < 4)
                                        {
                                            pos_year++;
                                            year += c;
                                            std::cout << c;
                                        }
                                    }
                                }
                            }
                        }

                        startday = day; startmonth = month; startyear = year;
                        for (int i = 78; i <= 90; ++i)
                        {
                            for (int j = 14; j <= 25; ++j)
                            {
                                gotoXY(i,j);
                                std::cout << " ";
                            }
                        }

                        if (startday != "")
                            countinfo++;

                        ShowConsoleCursor(false);
                    }
                    else
                    {
                        if (endday != "")
                            countinfo--;

                        Create_A_Box_2(112,15,2,12,14,14,0,"DAY");
                        Create_A_Box_2(112,19,2,12,14,14,0,"MONTH");
                        Create_A_Box_2(112,23,2,12,14,14,0,"YEAR");

                        std::string day = ""; std::string month = ""; std::string year = ""; int count = 0;

                        int x_cur = 112; int y_cur = 15; int y_old; int xp = x_cur; int yp = y_cur; int pos_day = 0; int pos_month = 0; int pos_year = 0;
                        while (count < 3)
                        {
                            system("color E0");

                            if (y_cur == 15)
                            {
                                gotoXY(xp + 5, yp + 1);
                                ShowConsoleCursor(true);

                                char c;
                                while (true)
                                {
                                    c = _getch();

                                    if (c == ENTER)
                                    {
                                        if (day != "")
                                            count++;

                                        if (month == "")
                                            y_cur = 19;
                                        else if (year == "")
                                            y_cur = 23;

                                        xp = 112;
                                        yp = y_cur;
                                        break;
                                    }
                                    else if (c == BACKSPACE)
                                    {
                                        if (day != "" && pos_day > 0)
                                        {
                                            std::cout << "\b \b";
                                            day.pop_back();
                                        }
                                    }
                                    else if (c == LEFT)
                                    {
                                        if (pos_day > 0)
                                        {
                                            pos_day--;
                                            gotoXY(x_cur + pos_day + 2, y_cur + 1);
                                        }

                                        continue;
                                    }
                                    else if (c == RIGHT)
                                    {
                                        int len = day.size();

                                        if (pos_day < len)
                                        {
                                            pos_day++;
                                            gotoXY(x_cur + pos_day + 2, y_cur + 1);
                                        }

                                        continue;
                                    }
                                    else
                                    {
                                        int len = day.size();

                                        if (c >= 48 && c <= 57 && len < 2)
                                        {
                                            pos_day++;
                                            day += c;
                                            std::cout << c;
                                        }
                                    }
                                }
                            }
                            else if (y_cur == 19)
                            {
                                gotoXY(xp + 5, yp + 1);
                                ShowConsoleCursor(true);

                                char c;
                                while (true)
                                {
                                    c = _getch();

                                    if (c == ENTER)
                                    {
                                        if (month != "")
                                            count++;

                                        if (day == "")
                                            y_cur = 15;
                                        else if (year == "")
                                            y_cur = 23;

                                        xp = 112;
                                        yp = y_cur;
                                        break;
                                    }
                                    else if (c == BACKSPACE)
                                    {
                                        if (month != "" && pos_month > 0)
                                        {
                                            std::cout << "\b \b";
                                            month.pop_back();
                                        }
                                    }
                                    else if (c == LEFT)
                                    {
                                        if (pos_month > 0)
                                        {
                                            pos_month--;
                                            gotoXY(x_cur + pos_month + 2, y_cur + 1);
                                        }

                                        continue;
                                    }
                                    else if (c == RIGHT)
                                    {
                                        int len = month.size();

                                        if (pos_month < len)
                                        {
                                            pos_month++;
                                            gotoXY(x_cur + pos_month + 2, y_cur + 1);
                                        }

                                        continue;
                                    }
                                    else
                                    {
                                        int len = month.size();

                                        if (c >= 48 && c <= 57 && len < 2)
                                        {
                                            pos_month++;
                                            month += c;
                                            std::cout << c;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                gotoXY(xp + 4, yp + 1);
                                ShowConsoleCursor(true);

                                char c;
                                while (true)
                                {
                                    c = _getch();

                                    if (c == ENTER)
                                    {
                                        if (year != "")
                                            count++;

                                        if (day == "")
                                            y_cur = 15;
                                        else if (month == "")
                                            y_cur = 19;

                                        xp = 112;
                                        yp = y_cur;
                                        break;
                                    }
                                    else if (c == BACKSPACE)
                                    {
                                        if (year != "" && pos_year > 0)
                                        {
                                            std::cout << "\b \b";
                                            year.pop_back();
                                        }
                                    }
                                    else if (c == LEFT)
                                    {
                                        if (pos_year > 0)
                                        {
                                            pos_year--;
                                            gotoXY(x_cur + pos_year + 2, y_cur + 1);
                                        }

                                        continue;
                                    }
                                    else if (c == RIGHT)
                                    {
                                        int len = year.size();

                                        if (pos_year < len)
                                        {
                                            pos_year++;
                                            gotoXY(x_cur + pos_year + 2, y_cur + 1);
                                        }

                                        continue;
                                    }
                                    else
                                    {
                                        int len = year.size();

                                        if (c >= 48 && c <= 57 && len < 4)
                                        {
                                            pos_year++;
                                            year += c;
                                            std::cout << c;
                                        }
                                    }
                                }
                            }
                        }

                        endday = day; endmonth = month; endyear = year;
                        for (int i = 112; i <= 124; ++i)
                        {
                            for (int j = 14; j <= 25; ++j)
                            {
                                gotoXY(i,j);
                                std::cout << " ";
                            }
                        }

                        if (endday != "")
                            countinfo++;

                        ShowConsoleCursor(false);
                    }
                }
            }
        }
    }
    ShowConsoleCursor(false);
}