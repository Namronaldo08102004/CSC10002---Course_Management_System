#include "../Header/Staff.h"
#include "../Header/Student.h"
#include "../Header/Design.h"

void addNewStudentToClass(string username, Year* &year_head, Class* cur)
{
    resizeConsole(1920,920);
    system("color E0");

    gotoXY(28,2);
    std::cout << "  ___ ____________   _____ _____ _   _______ _____ _   _ _____   _____ _____   _____  _       ___   _____ _____";
    gotoXY(28,3);
    std::cout << " / _ \\|  _  \\  _  \\ /  ___|_   _| | | |  _  \\  ___| \\ | |_   _| |_   _|  _  | /  __ \\| |     / _ \\ /  ___/  ___|";
    gotoXY(28,4);
    std::cout << "/ /_\\ \\ | | | | | | \\ `--.  | | | | | | | | | |__ |  \\| | | |     | | | | | | | /  \\/| |    / /_\\ \\\\ `--.\\ `--.";
    gotoXY(28,5);
    std::cout << "|  _  | | | | | | |  `--. \\ | | | | | | | | |  __|| . ` | | |     | | | | | | | |    | |    |  _  | `--. \\`--. \\";
    gotoXY(28,6);
    std::cout << "| | | | |/ /| |/ /  /\\__/ / | | | |_| | |/ /| |___| |\\  | | |     | | \\ \\_/ / | \\__/\\| |____| | | |/\\__/ /\\__/ /";
    gotoXY(28,7);
    std::cout << "\\_| |_/___/ |___/   \\____/  \\_/  \\___/|___/ \\____/\\_| \\_/ \\_/     \\_/  \\___/   \\____/\\_____/\\_| |_/\\____/\\____/";

    Create_A_Box_2(72,11,2,20,14,14,0,"STUDENT'S ID");
    Create_A_Box_1(62,19,2,20,14,14,0,"    RETURN BACK");
    ShowConsoleCursor(false);

    std::string studentID = "";
    int count = 0;
    int x_temp = 72; int y_temp = 11; int y_old; int xp = x_temp; int yp = y_temp; int pos = 0;
    while (count < 1)
    {
        system("color E0");

        if (y_temp == 11)
        {
            gotoXY(xp + 2, yp + 1);
            ShowConsoleCursor(true);

            char c;
            while (true)
            {
                c = _getch();

                if (c == ENTER)
                {
                    if (studentID != "")
                        count++;

                    xp = 72;
                    yp = y_temp;
                    break;
                }
                else if (c == DOWN)
                {
                    ShowConsoleCursor(false);
                    y_old = y_temp;
                    y_temp = 19;
                    xp = x_temp + studentID.size();
                    yp = y_old;
                    break;
                }
                else if (c == BACKSPACE)
                {
                    if (studentID != "" && pos > 0)
                    {
                        std::cout << "\b \b";
                        studentID.pop_back();
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
                    int len = studentID.size();

                    if (pos < len)
                    {
                        pos++;
                        gotoXY(x_temp + pos + 2, y_temp + 1);
                    }

                    continue;
                }
                else
                {
                    int len = studentID.size();

                    if (c >= '0' && c <= '9' && len < 10)
                    {
                        pos++;
                        studentID += c;
                        std::cout << c;
                    }
                }
            }
        }
        else
        {
            SetColor1(15,0);
            for (int i = 63; i <= 81; ++i)
            {
                gotoXY(i, y_temp + 1);
                std::cout << " ";
            }

            gotoXY(63, y_temp + 1);
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
                {
                    system("cls");
                    accessClass(username, year_head, cur);
                    return;
                }
            }
        }
    }

    ifstream ifs;
    ifs.open("../Txt_Csv/student_info.csv");
    if (!ifs.is_open()) 
    {
        Create_A_Box_1(1, 1, 2, 40, 14, 14, 0, "Error: Unable to open file for writing");
        ifs.close();
        return;
    }

    int check = 0;
    string dummy;
    getline(ifs, dummy);
    string line;
    while (getline(ifs, line))
    {
        string tmp;
        stringstream ss(line);

        getline(ss, tmp, ',');
        if (tmp == studentID)
        {
            Student* new_student = new Student;
            new_student->student_ID = tmp;
            getline(ss, tmp, ',');
            new_student->student_socialID = tmp;
            getline(ss, tmp, ',');
            new_student->student_fisrtname = tmp;
            getline(ss, tmp, ',');
            new_student->student_lastname = tmp;
            getline(ss, tmp, ',');
            new_student->gender = stoi(tmp);
            getline(ss, tmp, ',');
            new_student->student_class.class_name = tmp;
            getline(ss, tmp, '\n');
            getDate(new_student, tmp);
            new_student->course_head = nullptr;
            new_student->student_next = nullptr;

            addTail(cur->student_head, new_student);
            
            std::ofstream ofs;
            string filename = cur->class_name + "-" + year_head->year_name + ".txt";
            filename = "../Txt_Csv/" + filename;

            ofs.open(filename, ios::app);
            if (!ofs.is_open())
            {
                ofs.close();
                return;
            }
            
            ofs << new_student->student_ID << "," << new_student->student_socialID << ","
                << new_student->student_fisrtname << "," << new_student->student_lastname << ","
                << new_student->gender << "," << new_student->student_class.class_name << ","
                << new_student->DOB.day << "/" << new_student->DOB.month << "/" << new_student->DOB.year << "\n";

            ofs.close();

            check = 1;
            break;
        }
    }

    if (!check)
    {
        system("cls");
        Create_A_Box_1(67,15,2,30,14,14,0," STUDENT ID IS NOT AVAILABLE");
        addNewStudentToClass(username, year_head, cur);
        return;
    }

    ifs.close();

    Create_A_Box_1(67,23,2,30,14,14,0,"    ADDED SUCCESSFULLY");
    for (int i = 0; i < 3; ++i)
    {
        gotoXY(91 + i,24);
        ShowConsoleCursor(false);
        std::cout << "." << flush;
        Sleep(500);
    }
    accessClass(username, year_head, cur);
}