#include "../Header/Staff.h"
#include "../Header/Design.h"

/*
School Year Creation Function: This function allows academic staff members to create 
a new school year in the system.
*/

bool checkSyntaxOfSchoolYear (string year_name)
{
    //Get start year in string year_name
    int startyear = 0; int indexstring = 0; int len_year = year_name.size();

    while (indexstring < len_year && year_name[indexstring] >= '0' && year_name[indexstring] <= '9')
    {
        startyear = startyear * 10 + (int)year_name[indexstring] - 48;
        indexstring++;
    }

    if (indexstring == len_year) //when year_name includes only number letters
        return false;
    else
    {
        if (year_name[indexstring] != '-') //Violate the first and third principles
            return false;

        indexstring++;
    }

    int endyear = 0;

    while (indexstring < len_year && year_name[indexstring] >= '0' && year_name[indexstring] <= '9')
    {
        endyear = endyear * 10 + (int)year_name[indexstring] - 48; // '0' = 48
        indexstring++;
    }

    if (indexstring == len_year) 
    {
        if (endyear - startyear == 1)
            return true;
        else //Violate the first principle
            return false;
    }
    else //Violate the first and third principles
        return false;
}

bool checkExistingYear (Year* &year_head, string year_name) //Check violation the second principle
{
    if (!year_head)
        return true;

    Year* temp_year = year_head;
    while (temp_year)
    {
        if (year_name == temp_year->year_name)
            return false;

        temp_year = temp_year->year_next;
    }

    return true;
}

void addNewSchoolYear (Year* &year_head)
{
    resizeConsole(1920,920);
    system("color E0");

    gotoXY(40,2);
    std::cout << "    ___ ____________   _____ _____ _   _ _____ _____ _      __   _______ ___ ______";
    gotoXY(40,3);
    std::cout << "   / _ \\|  _  \\  _  \\ /  ___/  __ \\ | | |  _  |  _  | |     \\ \\ / /  ___/ _ \\| ___ \\";
    gotoXY(40,4);
    std::cout << "  / /_\\ \\ | | | | | | \\ `--.| /  \\/ |_| | | | | | | | |      \\ V /| |__/ /_\\ \\ |_/ /";
    gotoXY(40,5);
    std::cout << "  |  _  | | | | | | |  `--. \\ |   |  _  | | | | | | | |       \\ / |  __|  _  |    /";
    gotoXY(40,6);
    std::cout << "  | | | | |/ /| |/ /  /\\__/ / \\__/\\ | | \\ \\_/ | \\_/ / |____   | | | |__| | | | |\\ \\";
    gotoXY(40,7);
    std::cout << "  \\_| |_/___/ |___/   \\____/ \\____|_| |_/\\___/ \\___/\\_____/   \\_/ \\____|_| |_|_| \\_|";

    Create_A_Box_2(70,15,2,30,14,14,0,"NEW SCHOOL YEAR");
    Create_A_Box_1(55,20,2,20,14,14,0,"    RETURN BACK");

    Create_A_Box_3(17,32,6,134);

    gotoXY(19,33);
    std::cout << "1. Please follow the syntax startyear-endyear, the end year will after the start year exactly 1 year, for instance: 2019-2020";
    gotoXY(19,35);
    std::cout << "2. Don't input an available school year!";
    gotoXY(19,37);
    std::cout << "3. Your input will be false if it includes another letter that is not number and a hyphen between 2 years";
    ShowConsoleCursor(false);

    ofstream ofs;

    //Create new node for linked list year_head
    Year* new_year = new Year;
    int count = 0; new_year->year_name = "";

    int x_temp = 70; int y_temp = 15; int y_old; int xp = x_temp; int yp = y_temp; int pos = 0;
    while (count < 1)
    {
        system("color E0");

        if (y_temp == 15)
        {
            gotoXY(xp + 2, yp + 1);
            ShowConsoleCursor(true);

            char c;
            while (true)
            {
                c = _getch();

                if (c == ENTER)
                {
                    if (new_year->year_name != "")
                        count++;

                    xp = 70;
                    yp = y_temp;
                    break;
                }
                else if (c == DOWN)
                {
                    ShowConsoleCursor(false);
                    y_old = y_temp;
                    y_temp = 20;
                    xp = x_temp + new_year->year_name.size();
                    yp = y_old;
                    break;
                }
                else if (c == BACKSPACE)
                {
                    if (new_year->year_name != "" && pos > 0)
                    {
                        std::cout << "\b \b";
                        new_year->year_name.pop_back();
                    }
                }
                else if (c == LEFT)
                {
                    if (pos > 0)
                    {
                        pos--;
                        gotoXY(x_temp + pos + 2, y_temp + 1);
                    }

                    continue;
                }
                else if (c == RIGHT)
                {
                    int len = new_year->year_name.size();

                    if (pos < len)
                    {
                        pos++;
                        gotoXY(x_temp + pos + 2, y_temp + 1);
                    }

                    continue;
                }
                else
                {
                    int len = new_year->year_name.size();

                    if (c == 45 || (c >= '0' && c <= '9') && len < 26)
                    {
                        pos++;
                        new_year->year_name += c;
                        std::cout << c;
                    }
                }
            }
        }
        else
        {
            SetColor1(15,0);
            for (int i = 56; i <= 74; ++i)
            {
                gotoXY(i, y_temp + 1);
                std::cout << " ";
            }

            gotoXY(56, y_temp + 1);
            std::cout << "    RETURN BACK";
            ShowConsoleCursor(false);

            if (_kbhit())
            {
                char c = _getch();

                if (c == UP)
                {
                    ShowConsoleCursor(true);
                    y_temp = y_old;
                }
               else if (c == ENTER)
                   return;
            }
        }
    }

    while (!checkSyntaxOfSchoolYear(new_year->year_name) || !checkExistingYear(year_head, new_year->year_name))
    {
        if (!checkSyntaxOfSchoolYear(new_year->year_name))
        {
            system("cls");
            Create_A_Box_1(65,24,2,40,14,14,0,"       Please follow our syntax");
            addNewSchoolYear(year_head);
            return;
        }
        else
        {
            system("cls");
            Create_A_Box_1(65,24,2,40,14,14,0,"       The school year is existed");
            addNewSchoolYear(year_head);
            return;
        }
    }

    new_year->class_head = nullptr;
    new_year->semester_head = nullptr;
    new_year->year_next = nullptr;

    //Add new_year node at the end of year list
    if (!year_head)
        year_head = new_year;
    else
    {
        Year* temp = year_head;

        while (temp->year_next)
            temp = temp->year_next;
    
        temp->year_next = new_year;
    }

    //Print year list after changed out file schoolyear.txt
    ofs.open("../Txt_Csv/schoolyear.txt");
    if (!ofs.is_open())
    {
        cerr << "Error: Unable to open file for writing\n";
        return;
    }

    Year* temp_year = year_head;
    while (temp_year->year_next)
    {
        ofs << temp_year->year_name << "\n";
        temp_year = temp_year->year_next;
    }
    ofs << temp_year->year_name;

    ofs.close();

    //Create file including semesters of created year
    string name_file = new_year->year_name + "_semester.txt";
    name_file = "../Txt_Csv/" + name_file;
    ofs.open(name_file);
    if (!ofs.is_open())
    {
        cerr << "Error: Unable to open file for writing\n";
        return;
    }
    ofs.close();

    string filename = "class_" + new_year->year_name + ".txt";
    filename = "../Txt_Csv/" + filename;
    ofs.open(filename);
    if (!ofs.is_open())
    {
        cerr << "Error: Unable to open file for writing\n";
        return;
    }
    ofs.close();

    //Announce for user
    Create_A_Box_1(70,28,2,30,14,14,0,"  Created successfully ");

    for (int i = 0; i < 3; ++i)
    {
        gotoXY(94 + i,29);
        ShowConsoleCursor(false);
        std::cout << "." << flush;
        Sleep(500);
    }

    return;
}