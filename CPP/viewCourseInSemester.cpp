#include "../Header/Staff.h"
#include "../Header/Student.h"
#include "../Header/Design.h"

void viewCoursesInSemester(string username)
{
    system("cls");
    resizeConsole(1920,920);
    system("color E0");

    string year;
    Student *user = new Student();
    
    // get Student* from file
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

    // Access file course
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

    gotoXY(60,2); std::cout <<"     _____ ____  _    _ _____   _____ ______ ";
    gotoXY(60,3); std::cout <<"    / ____/ __ \\| |  | |  __ \\ / ____|  ____|";
    gotoXY(60,4); std::cout <<"   | |   | |  | | |  | | |__) | (___ | |__   ";
    gotoXY(60,5); std::cout <<"   | |   | |  | | |  | |  _  / \\___ \\|  __|  ";
    gotoXY(60,6); std::cout <<"   | |___| |__| | |__| | | \\ \\ ____) | |____ ";
    gotoXY(60,7); std::cout <<"    \\_____\\____/ \\____/|_|  \\_\\_____/|______|";
    
    Course *check = class_course;
    int counter = 1;
    int i = 0;
    int numCourses = 0;

    // access all file and find student
    while (check != nullptr)
    {
        string filename1;
        filename1 = check->course_ID + "_Semester" + ch_semester + "_" + check->class_name + "_" + year + "_student.csv";
        filename1 = "../Txt_Csv/" + filename1;
        ifstream ifs;
        string student_id;
        ifs.open(filename1);
        getline(ifs, dummy);
        
        string third_line;
        while (getline(ifs, third_line))
        {
            stringstream ss(third_line);
            getline(ss, student_id, ',');

            if (student_id == username)
            {
                gotoXY(52,11 + numCourses);
                std::cout << counter << ". " << check->course_ID << " - " << check->course_name;
                counter++;

                numCourses += 2;
                break;
            }
        }
        ifs.close();
        check = check->course_next;
    }

    if (numCourses == 0)
    {
        Create_A_Box_1(60,12,2,30,14,14,0,"    There are no course!");
    }
    else
    {
        Create_A_Box_3(50,10, numCourses, 70);
    }

    Create_A_Box_1(50, 12 + numCourses, 2, 14, 14, 14, 0, " RETURN BACK");
    SetColor1(15,0);
    for (int i = 51; i <= 63; ++i)
    {
        gotoXY(i, 13 + numCourses);
        std::cout << " ";
    }
    gotoXY(51, 13 + numCourses);
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
