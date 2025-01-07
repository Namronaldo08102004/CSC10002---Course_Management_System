#include "../Header/Staff.h"
#include "../Header/Student.h"
#include "../Header/Design.h"

string getYearStr(string username)
{
    resizeConsole(1920,920);
    system("color E0");
    // SetColor1(14, 0);
    // gotoXY(24, 1); cout <<"   _____  _____  _____ ______  _____ ______  _____   ___  ______ ______";
    // gotoXY(24, 2); cout <<"  /  ___|/  __ \\|  _  || ___ \\|  ___|| ___ \\|  _  | / _ \\ | ___ \\|  _  \\";
    // gotoXY(24, 3); cout <<"  \\ `--. | /  \\/| | | || |_/ /| |__  | |_/ /| | | |/ /_\\ \\| |_/ /| | | |";
    // gotoXY(24, 4); cout <<"   `--. \\| |    | | | ||    / |  __| | ___ \\| | | ||  _  ||    / | | | |";
    // gotoXY(24, 5); cout <<"  /\\__/ /| \\__/\\\\ \\_/ /| |\\ \\ | |___ | |_/ /\\ \\_/ /| | | || |\\ \\ | |/ /";
    // gotoXY(24, 6); cout <<"  \\____/  \\____/ \\___/ \\_| \\_|\\____/ \\____/  \\___/ \\_| |_/\\_| \\_||___/";
    Create_A_Box_2(1, 11, 2, 30, 14, 14, 0, "INPUT A YEAR(0000-0000)");
    Create_A_Box_1(1, 14, 2, 14, 14, 14, 0, " RETURN BACK");
    ShowConsoleCursor(false);
    int counter=0;
    string year="";
    int x_temp = 1; int y_temp = 11; int y_old; int xp = x_temp; int yp = y_temp; int pos_year = 0;
    while (counter < 1)
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
                    if (year != "")
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
                    xp = x_temp + year.size();
                    yp = y_old;
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
                    int len = year.size();

                    if (pos_year > 0)
                    {
                        pos_year--;
                        gotoXY(x_temp + pos_year + 2, y_temp + 1);
                    }

                    continue;
                }
                else if (c == RIGHT)
                {
                    int len = year.size();

                    if (pos_year < len)
                    {
                        pos_year++;
                        gotoXY(x_temp + pos_year + 2, y_temp + 1);
                    }

                    continue;
                }
                else
                {
                    int len = year.size();

                    if (c >= 32 && c <= 126 && len < 26)
                    {
                        pos_year++;
                        year += c;
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
                    Main_Student_Screen(username);
                    return "";
                }
            }
        }
    }
    system("cls");
    return year;
}

void viewScoreBoard_Student(string username)
{
    system("cls");
    system("color E0");
    SetColor1(14, 0);
    string year;
    Student *user = new Student();
    ifstream ifs;
    ifs.open("../Txt_Csv/student_info.csv");
    string dummy;
    getline(ifs, dummy);

    string first_line;
    while (getline(ifs, first_line))
    {
        string temp;
        stringstream ss(first_line);

        getline(ss, temp, ',');
        if (temp == username)
        {
            user->student_ID = temp;
            getline(ss, temp, ',');
            user->student_socialID = temp;
            getline(ss, temp, ',');
            user->student_fisrtname = temp;
            getline(ss, temp, ',');
            user->student_lastname = temp;
            getline(ss, temp, ',');
            user->gender = stoi(temp);
            getline(ss, temp, ',');
            user->student_class.class_name = temp;
            getline(ss, temp, '\n');
            getDate(user, temp);
            break;
        }
    }
    ifs.close();

    year = getYearStr(username);
    int semester = getSemesterNum();

    char ch_semester = static_cast<char>(semester + 48);
    string filename = user->student_class.class_name + "_Semester" + ch_semester + "_" + year +  "_courses.csv";
    filename = "../Txt_Csv/" + filename;
    Course *class_course = nullptr;
    Course *temp = nullptr;
    ifs.open(filename);
    if (!ifs.is_open())
    {
        system("cls");
        system("color E0");
        Create_A_Box_1(1, 7, 2, 35, 14, 14, 0, "INPUT INVALID! PLEASE INPUT AGAIN!");
        year = getYearStr(username);
        int semester = getSemesterNum();
        ch_semester = static_cast<char>(semester + 48);
        filename = user->student_class.class_name + "_Semester" + ch_semester + "_" + year +  "_courses.csv";
        filename = "../Txt_Csv/" + filename;
        ifs.open(filename);
    }
    string second_line;
    while (getline(ifs, second_line))
    {
        Course* new_course = new Course;
        string tmp;
        stringstream ss(second_line);
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

    gotoXY(24, 1); cout << "   _____  _____  _____ ______  _____ ______  _____   ___  ______ ______";
    gotoXY(24, 2); cout << "  /  ___|/  __ \\|  _  || ___ \\|  ___|| ___ \\|  _  | / _ \\ | ___ \\|  _  \\";
    gotoXY(24, 3); cout << "  \\ `--. | /  \\/| | | || |_/ /| |__  | |_/ /| | | |/ /_\\ \\| |_/ /| | | |";
    gotoXY(24, 4); cout << "   `--. \\| |    | | | ||    / |  __| | ___ \\| | | ||  _  ||    / | | | |";
    gotoXY(24, 5); cout << "  /\\__/ /| \\__/\\\\ \\_/ /| |\\ \\ | |___ | |_/ /\\ \\_/ /| | | || |\\ \\ | |/ /";
    gotoXY(24, 6); cout << "  \\____/  \\____/ \\___/ \\_| \\_|\\____/ \\____/  \\___/ \\_| |_/\\_| \\_||___/";
 
    Course *check = class_course;
    int y = 8;
    int y_coord = 1;
    while (check != nullptr)
    {
        string filename1;
        filename1 = check->course_ID + "_Semester" + ch_semester + "_" + check->class_name + "_" + year + "_student.csv";
        filename1 = "../Txt_Csv/" + filename1;
        ifstream ifs;
        string student_id;
        ifs.open(filename1);
        getline(ifs, dummy);
        
        string third_line; int check_close = 0;
        while (getline(ifs, third_line))
        {
            stringstream ss(third_line);
            getline(ss, student_id, ',');

            if (student_id == username)
            {
                check_close = 1;
                ifs.close();

                string filename2;
                filename2 = check->course_ID + "_Semester" + ch_semester + "_" + check->class_name + "_" + year + "_Scoreboard.csv";
                filename2 = "../Txt_Csv/" + filename2;
                ifstream ifs;
                ifs.open(filename2);
                Create_A_Box_1(1, y, 2, check->course_name.size() + 1, 14, 14, 0, check->course_name);

                int counter = 0; int check_empty = 0;
                string student_id_scoreboard, fullname;
                float total, final1, midterm, other;
                getline(ifs, dummy);
                string check2ndLine;
                getline(ifs, check2ndLine);
                if (check2ndLine == "")
                {
                    Create_A_Box_1(1, y_coord + 10, 2, 30, 14, 14, 0, "THERE IS NO AVAILABLE VALUE!");
                    y_coord = y_coord + 3;
                    check_empty = 1;
                }
                ifs.close();

                ifs.open(filename2);
                getline(ifs, dummy);

                bool checkAvailable = false;
                string fourth_line;
                while (getline(ifs, fourth_line))
                {
                    string temp;
                    stringstream ss1(fourth_line);

                    getline(ss1, temp, ',');
                    student_id_scoreboard = temp;
                    if (student_id_scoreboard == username)
                    {
                        checkAvailable = true;
                        getline(ss1, temp, ',');
                        fullname = temp;
                        getline(ss1, temp, ',');
                        midterm = stof(temp);
                        getline(ss1, temp, ',');
                        final1 = stof(temp);
                        getline(ss1, temp, ',');
                        other = stof(temp);
                        getline(ss1, temp, '\n');
                        total = stof(temp);
                        printStudentInfo(y_coord ,counter, student_id_scoreboard, fullname, midterm, final1, other, total);
                        counter++;
                        y_coord = y_coord + 3;
                        break;
                    }
                }
                if (!check_empty && checkAvailable == false)
                {
                    Create_A_Box_1(1, y_coord + 10, 2, 30, 14, 14, 0, "THERE IS NO AVAILABLE VALUE!");
                    y_coord = y_coord + 3;
                }
                y = y_coord + 13;
                y_coord = y_coord + 6;
                ifs.close();

                break;
            }
        }

        if (!check_close)
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
    Main_Student_Screen(username);
}