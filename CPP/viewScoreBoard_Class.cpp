#include "../Header/Staff.h"
#include "../Header/Student.h"
#include "../Header/Design.h"

int getSemesterNum()
{
    resizeConsole(1920,920);
    system("color E0");
    SetColor1(14, 0);
    // gotoXY(24, 1); cout <<"   _____  _____  _____ ______  _____ ______  _____   ___  ______ ______";
    // gotoXY(24, 2); cout <<"  /  ___|/  __ \\|  _  || ___ \\|  ___|| ___ \\|  _  | / _ \\ | ___ \\|  _  \\";
    // gotoXY(24, 3); cout <<"  \\ `--. | /  \\/| | | || |_/ /| |__  | |_/ /| | | |/ /_\\ \\| |_/ /| | | |";
    // gotoXY(24, 4); cout <<"   `--. \\| |    | | | ||    / |  __| | ___ \\| | | ||  _  ||    / | | | |";
    // gotoXY(24, 5); cout <<"  /\\__/ /| \\__/\\\\ \\_/ /| |\\ \\ | |___ | |_/ /\\ \\_/ /| | | || |\\ \\ | |/ /";
    // gotoXY(24, 6); cout <<"  \\____/  \\____/ \\___/ \\_| \\_|\\____/ \\____/  \\___/ \\_| |_/\\_| \\_||___/";
    Create_A_Box_1(50, 8, 2, 20, 14, 14, 0, " CHOOSE A SEMESTER");
    Create_A_Box_1(57, 11, 2, 6, 14, 14, 0, "  1");
    Create_A_Box_1(57, 14, 2, 6, 14, 14, 0, "  2");
    Create_A_Box_1(57, 17, 2, 6, 14, 14, 0, "  3");
    int semester;
    int x_temp = 57; int y_temp = 11;
    bool flag=true;
    while (true)
    {
        if (flag == true)
        {
            if (y_temp == 11)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 5; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "  1";
                ShowConsoleCursor(false);
            }
            else if (y_temp == 14)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 5; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                cout << "  2";
                ShowConsoleCursor(false);
            }
            else if (y_temp == 17)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 5; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                cout << "  3";
                ShowConsoleCursor(false);
            }
        }
        if (_kbhit())
        {
            char c=_getch();
            system("color E0");
            if (y_temp == 11)
            {
                system("color E0");
                SetColor1(14,0);
                for (int i = x_temp + 1; i <= x_temp + 5; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "  1";
                ShowConsoleCursor(false);
            }
            else if (y_temp == 14)
            {
                system("color E0");
                SetColor1(14,0);
                for (int i = x_temp + 1; i <= x_temp + 5; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                cout << "  2";
                ShowConsoleCursor(false);
            }
            else if (y_temp == 17)
            {
                system("color E0");
                SetColor1(14,0);
                for (int i = x_temp + 1; i <= x_temp + 5; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                cout << "  3";
                ShowConsoleCursor(false);
            }
            flag=true;
            if (c == UP)
            {
                if (y_temp == 11)
                    y_temp = 17;
                else
                    y_temp -= 3;
            }
            else if (c == DOWN)
            {
                if (y_temp == 17)
                    y_temp == 11;
                else
                    y_temp += 3;
            }
            else if (c == ENTER)
            {
                ShowConsoleCursor(true);
                if (y_temp == 11)
                    semester = 1;
                else if (y_temp == 14)
                    semester = 2;
                else if (y_temp == 17)
                    semester = 3;
                break;
            }
        }
    }
    system("cls");
    return semester;
}

void viewScoreBoard_Class(string username, Year *&year_head, Class *class_head)
{
    int semester=getSemesterNum();
    system("color E0");
    SetColor1(14, 0);
    gotoXY(24, 1); cout <<"   _____  _____  _____ ______  _____ ______  _____   ___  ______ ______";
    gotoXY(24, 2); cout <<"  /  ___|/  __ \\|  _  || ___ \\|  ___|| ___ \\|  _  | / _ \\ | ___ \\|  _  \\";
    gotoXY(24, 3); cout <<"  \\ `--. | /  \\/| | | || |_/ /| |__  | |_/ /| | | |/ /_\\ \\| |_/ /| | | |";
    gotoXY(24, 4); cout <<"   `--. \\| |    | | | ||    / |  __| | ___ \\| | | ||  _  ||    / | | | |";
    gotoXY(24, 5); cout <<"  /\\__/ /| \\__/\\\\ \\_/ /| |\\ \\ | |___ | |_/ /\\ \\_/ /| | | || |\\ \\ | |/ /";
    gotoXY(24, 6); cout <<"  \\____/  \\____/ \\___/ \\_| \\_|\\____/ \\____/  \\___/ \\_| |_/\\_| \\_||___/";
    gotoXY(40, 7); cout << "------------"<< class_head->class_name << "_" << year_head->year_name <<"--------------\n";
    string filename;
    // int semester;
    // cout << "Choose a semester (1->3): ";
    // cin >> semester;
    // while (semester < 1 && semester > 3)
    // {
    //     cout << "Invalid input!";
    //     cout << "Please input again: ";
    //     cin >> semester;
    // }
    char char_semester = static_cast<char>(semester + 48);
    filename = class_head->class_name+ "_" + "Semester" + char_semester + "_" + year_head->year_name + "_courses.csv";
    filename = "../Txt_Csv/" + filename;
    Course *class_course = nullptr;
    Course *temp = nullptr;
    ifstream ifs;
    ifs.open(filename);
    string line;
    while (getline(ifs, line))
    {
        Course* new_course = new Course;
        string tmp;
        stringstream ss(line);
        getline(ss, tmp, ',');
        new_course->course_ID = tmp;
        getline(ss, tmp, ',');
        new_course->course_name = tmp; 
        getline(ss, tmp, ','); 
        new_course->class_name = tmp;
        getline(ss, tmp, ',');
        new_course->teacher_name = tmp;
        getline(ss, tmp, ',');
        new_course->numCredits = stoi(tmp);
        getline(ss, tmp, ',');
        new_course->maxNumStudents = stoi(tmp);
        getline(ss, tmp, ',');
        new_course->dayInWeek = tmp;
        getline(ss, tmp, '\n');

        new_course->Session = tmp;
        new_course->student_head = nullptr;
        new_course->scoreboard_head = nullptr;
        new_course->course_next = nullptr;

        if (!class_course)
        {
            class_course = new_course;
            temp = class_course;
        }
        else
        {
            temp->course_next = new_course;
            temp = temp->course_next;
        }
    }
    ifs.close();
    Course *check = class_course;
    int y=8;
    int y_coord=1;
    while (check != nullptr)
    {
        string filename1;
        filename1 = check->course_ID + "_Semester" + char_semester + "_" + check->class_name + "_" + year_head->year_name + "_Scoreboard.csv";
        filename1 = "../Txt_Csv/" + filename1;
        ifstream ifs;
        ifs.open(filename1);
        Create_A_Box_1(1, y, 2, check->course_name.size()+1, 14, 14, 0, check->course_name);
        // cout << "------------"<< check->course_name <<"--------------\n";
        int counter = 0;
        string student_id, fullname;
        float total, final1, midterm, other;
        string dummy;
        getline(ifs,dummy);
        string check2ndLine;
        getline(ifs, check2ndLine);
        if (check2ndLine == "")
        {
            
            Create_A_Box_1(1, y_coord+10, 2, 30, 14, 14, 0, "THERE IS NO AVAILABLE VALUE!");
            y_coord=y_coord+3;
        }
        ifs.close();
        ifs.open(filename1);
        getline(ifs, dummy);
        string line;
        while (getline(ifs, line))
        {
            string temp;
            stringstream ss(line);

            getline(ss, temp, ',');
            student_id = temp;
            getline(ss, temp, ',');
            fullname = temp;
            getline(ss, temp, ',');
            midterm = stof(temp);
            getline(ss, temp, ',');
            final1 = stof(temp);
            getline(ss, temp, ',');
            other = stof(temp);
            getline(ss, temp, '\n');
            total = stof(temp);
            printStudentInfo(y_coord ,counter, student_id, fullname, midterm, final1, other, total);
            counter++;
            y_coord=y_coord+3;
        }
        y=y_coord + 13;
        y_coord = y_coord + 6;
        // cout << "\n";
        ifs.close();
        check = check->course_next;
    }
    
    Create_A_Box_1(1, y, 2, 14, 14, 14, 0, " RETURN BACK");
    SetColor1(15,0);
    for (int i = 1 + 1; i <= 14; ++i)
    {
        gotoXY(i, y + 1);
        std::cout << " ";
    }
    gotoXY(1 + 1, y + 1);
    std::cout << " RETURN BACK";
    ShowConsoleCursor(false);
    while (true)
    {
        if (_kbhit())
        {
            char c = _getch();
            if (c == ENTER)
            {
                break;
            }
        }
    }
    system("cls");
    deallocateCourses(class_course);
    accessClass(username, year_head, class_head);
}