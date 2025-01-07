#include "../Header/Staff.h"
#include "../Header/Design.h"

/*Class Creation Function: Academic staff members will be able to create new classes for a school year.*/

void addNewClass (Year* &year_head, string username)
{
    system("cls");
    resizeConsole(1920,920);
    system("color E0");

    ofstream ofs;
    Class* new_class = new Class();
    new_class->class_name = "";

    // Keep asking for input until a valid class name is provided
    bool valid_class_name = false;
    int counter = 0;
    Create_A_Box_2(1, 3, 2, 30, 14, 14, 0, "INPUT NEW CLASS");
    Create_A_Box_1(1, 14, 2, 14, 14, 14, 0, " RETURN BACK");
    ShowConsoleCursor(false);

    while (valid_class_name != true) 
    {
        gotoXY(1 + 2, 3 + 1);
        ShowConsoleCursor(true);

        int x_temp = 1; int y_temp = 3; int y_old; int xp = x_temp; int yp = y_temp; int pos_class = 0;
        while (counter < 1)
        {
            system("color E0");

            if (y_temp == 3)
            {
                gotoXY(xp + 2, yp + 1);
                ShowConsoleCursor(true);

                char c;
                while (true)
                {
                    c = _getch();

                    if (c == ENTER)
                    {
                        if (new_class->class_name != "")
                            counter++;
                        xp = 1;
                        yp = y_temp;
                        break;
                    }
                    else if (c == DOWN)
                    {
                        ShowConsoleCursor(false);
                        y_old = y_temp;
                        y_temp = 14;
                        xp = x_temp + new_class->class_name.size();
                        yp = y_old;
                        break;
                    }
                    else if (c == BACKSPACE)
                    {
                        if (new_class->class_name != "" && pos_class > 0)
                        {
                            std::cout << "\b \b";
                            new_class->class_name.pop_back();
                        }
                    }
                    else if (c == LEFT)
                    {
                        int len = new_class->class_name.size();

                        if (pos_class > 0)
                        {
                            pos_class--;
                            gotoXY(x_temp + pos_class + 2, y_temp + 1);
                        }

                        continue;
                    }
                    else if (c == RIGHT)
                    {
                        int len = new_class->class_name.size();

                        if (pos_class < len)
                        {
                            pos_class++;
                            gotoXY(x_temp + pos_class + 2, y_temp + 1);
                        }

                        continue;
                    }
                    else
                    {
                        int len = new_class->class_name.size();

                        if (c >= 32 && c <= 126 && len < 26)
                        {
                            pos_class++;
                            new_class->class_name += c;
                            std::cout << c;
                        }
                    }
                }
            }
            else
            {
                SetColor1(15,0);
                for (int i = 1 + 1; i <= 14; ++i)
                {
                    gotoXY(i, 15);
                    std::cout << " ";
                }
                gotoXY(1 + 1, 15);
                std::cout << " RETURN BACK";
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
                    {
                        system("cls");
                        accessSchoolYear(username, year_head);
                        return;
                    }
                }
            }
        }

        // Check if class already exists in class.txt file
        ifstream ifs("../Txt_Csv/class.txt");
        bool check = true;
        if (ifs.is_open()) 
        {
            string line;
            while (getline(ifs, line)) 
            {
                if (line == new_class->class_name) 
                {
                    check = false;
                    break; // exit inner loop
                }
            }
        }
        ifs.close();

        if (check == true)
            valid_class_name = true; // class name is valid, exit outer loop
        else if (check == false)
        {
            Create_A_Box_2(1, 3, 2, 30, 14, 14, 0, "CLASS ALREADY EXISTS! PLEASE INPUT AGAIN");
            new_class->class_name = "";
            counter--;
        }
    }

    // Class name input is valid
    new_class->class_name = NormalizeClassName(new_class->class_name);
    new_class->student_head = nullptr;
    new_class->next_class = nullptr;
    if (year_head->class_head == nullptr) 
    {
        year_head->class_head = new_class;
    }
    else 
    {
        Class *temp = year_head->class_head;
        while (temp->next_class != nullptr) 
        {
            temp = temp->next_class;
        }
        temp->next_class = new_class;
    }

    // Append new class to class.txt file
    ofs.open("../Txt_Csv/class.txt", ios::app);
    if (!ofs.is_open()) {
        // cerr << "Error: Unable to open file for writing\n";
        Create_A_Box_1(1, 8, 2, 41, 14, 14, 0, "Error: Unable to open file for writing");
        return;
    }
    ofs << new_class->class_name << "\n";
    // Append new class to a specific class year
    ofs.close();

    string filename = "class_" + year_head->year_name + ".txt";
    filename = "../Txt_Csv/" + filename;
    ofs.open(filename, ios::app);
    if (!ofs.is_open())
    {
        // cerr << "Error: Unable to open file for writing\n";
        Create_A_Box_1(1, 8, 2, 41, 14, 14, 0, "Error: Unable to open file for writing");
        return;
    }
    ifstream checkEmpty;
    checkEmpty.open(filename);
    if (checkEmpty.peek() == ifstream::traits_type::eof())
        ofs << new_class->class_name;
    else
        ofs << "\n" << new_class->class_name;
    ofs.close();
    checkEmpty.close();

    Create_A_Box_1(1, 8, 2, 42, 14, 14, 0, "You created a new class successfully!");
    for (int i = 0; i < 3; ++i)
    {
        gotoXY(39 + i,9);
        ShowConsoleCursor(false);
        std::cout << "." << flush;
        Sleep(500);
    }
    string name_file = new_class->class_name + "-" + year_head->year_name + ".txt";
    name_file = "../Txt_Csv/" + name_file;
    ofs.open(name_file);
    if (!ofs.is_open()) 
    {
        Create_A_Box_1(1, 14, 2, 41, 14, 14, 0, "Error: Unable to open file for writing");
        return;
    }
    ofs << "student ID,student_socialID,student_fisrtname,student_lastname,gender,class_name,DOB\n";
    ofs.close();

    new_class->student_head = getStudentListFromFile(year_head, new_class);

    system("color E0");
    system("cls");
    accessSchoolYear(username, year_head);
    return;
}