#include "../Header/Staff.h"
#include "../Header/Design.h"

void addTailCourse(Course* &course_head, Course* tmp)
{
    if (course_head == nullptr)
        course_head = tmp;
    else
    {
        Course* cur = course_head;
        while (cur->course_next != nullptr)
            cur = cur->course_next;
        cur->course_next = tmp; 
    }
}

void removeCourseFromList(Course* &course_head, Course* tmp)
{
    Course* cur = course_head;
    Course* pre = nullptr;
    while (cur != nullptr && (cur->course_ID != tmp->course_ID || cur->class_name != tmp->class_name))
    {
        pre = cur;
        cur = cur->course_next;
    }
    if (cur ==  nullptr)
        return;
    else
    {
        if (pre == nullptr)
            course_head = cur->course_next;
        else
            pre->course_next = cur->course_next;
        delete cur;
    }
}

Course* getCourseFromFile(string filename)
{
    ifstream ifs;
    ifs.open(filename);
    if (!ifs.is_open())
    {
        // cerr << "Error: Unable to open file for reading\n";
        Create_A_Box_1(1, 1, 2, 41, 14, 14, 0, "Error: Unable to open file for reading");
        return nullptr;
    }

    Course* course_head = nullptr;
    string line;

    // Get data from file
    while (getline(ifs,line))
    {
        Course* new_course = new Course;
        stringstream ss(line);
        getline(ss, new_course->course_ID, ',');
        getline(ss, new_course->course_name, ',');
        getline(ss, new_course->class_name, ',');
        getline(ss, new_course->teacher_name, ',');
        string numCre, maxStu;
        getline(ss, numCre, ',');
        getline(ss, maxStu, ',');
        new_course->numCredits = stoi(numCre);
        new_course->maxNumStudents = stoi(maxStu);
        getline(ss, new_course->dayInWeek, ',');
        getline(ss, new_course->Session, '\n');
        new_course->scoreboard_head = nullptr;
        new_course->student_head = nullptr;
        new_course->course_next = nullptr;

        addTailCourse(course_head, new_course);
    }
    
    ifs.close();
    return course_head;
}

void deleteCoursefromFile(string filename, Course* course_head) 
{
    ifstream fin(filename); // Open the file for reading
    ofstream fout("temp.txt"); // Open a temporary file for writing

    Course* tmp = getCourseFromFile(filename);
    removeCourseFromList(tmp, course_head);

    while (tmp != nullptr) 
    {
        fout << tmp->course_ID << "," << tmp->course_name << ","
             << tmp->class_name << "," << tmp->teacher_name << ","
             << tmp->numCredits << "," << tmp->maxNumStudents << "," 
             << tmp->dayInWeek << "," << tmp->Session << "\n";
        tmp = tmp->course_next;
    }

    fin.close(); // Close the input file
    fout.close(); // Close the temporary file
    
    remove(filename.c_str()); // Delete the original file
    rename("temp.txt", filename.c_str()); // Rename the temporary file to the original filename

    deallocateCourses(tmp);
}

void deleteCourse(string username,Course* course_head ,Year* year_head, Semester *semester_head) 
{
    int option;
    Create_A_Box_1(67, 11, 2, 34, 14, 14, 0, "ARE YOU SURE YOU WANT TO DELETE?");
    Create_A_Box_1(82, 14, 2, 4, 14, 14, 0, "YES");
    Create_A_Box_1(82, 18, 2, 3, 14, 14, 0, "NO");
    
    int x_temp = 82; int y_temp = 14;
    bool flag = true;
    while (true)
    {
        if (flag == true)
        {
            if (y_temp == 14)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 3; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "YES";
                ShowConsoleCursor(false);
            }
            else if (y_temp == 18)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 2; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                cout << "NO";
                ShowConsoleCursor(false);
            }
        }
        if (_kbhit())
        {
            char c = _getch();
            system("color E0");
            flag = true;

            if (y_temp == 14)
            {
                system("color E0");
                SetColor1(14,0);
                for (int i = x_temp + 1; i <= x_temp + 3; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "YES";
                ShowConsoleCursor(false);
            }
            else if (y_temp == 18)
            {
                system("color E0");
                SetColor1(14,0);
                for (int i = x_temp + 1; i <= x_temp + 2; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                cout << "NO";
                ShowConsoleCursor(false);
            }

            if (c == UP)
            {
                if (y_temp == 14)
                    y_temp = 18;
                else
                    y_temp -= 4;
            }
            else if (c == DOWN)
            {
                if (y_temp == 18)
                    y_temp == 14;
                else
                    y_temp += 4;
            }
            else if (c == ENTER)
            {
                ShowConsoleCursor(true);
                if (y_temp == 14)
                    option = 1;
                else if (y_temp == 18)
                    option = 0;
                break;
            }
        }
    }
    if (option == 0)
    {
        system("cls");
        updateACourse (username, year_head, semester_head, course_head);
        return;
    }

    // Delete Course in Student
    Student* tempStudent = course_head->student_head;
    while (tempStudent)
    {
        Course* currentCourse = tempStudent->course_head;
        Course* previousCourse = nullptr;
        while (currentCourse != nullptr) 
        {
            if (currentCourse->course_ID == course_head->course_ID) 
            {
                if (previousCourse == nullptr) 
                    tempStudent->course_head = currentCourse->course_next;
                else 
                    previousCourse->course_next = currentCourse->course_next;
                // delete currentCourse;
                return;
            }
            previousCourse = currentCourse;
            currentCourse = currentCourse->course_next;
        }

        tempStudent = tempStudent->student_next;
    }

    // Delete Course in Semester
    Course *cur = semester_head->course_head;
    Course *pre = nullptr;
    while (cur != course_head)
    {
        pre = cur;
        cur = cur->course_next;
    }
    if (pre == nullptr)
        semester_head->course_head = semester_head->course_head->course_next;
    else 
        pre->course_next = cur->course_next;

    // Delete course from file
    string file_name1 = year_head->year_name + "_semester" + (char)(semester_head->Semester_Ord + 48) + "_course.csv";
    file_name1 = "../Txt_Csv/" + file_name1;
    deleteCoursefromFile(file_name1, course_head);

    // Remove file Student of Course
    string file_name2 = course_head->course_ID + "_Semester" + (char)(semester_head->Semester_Ord + 48) + "_" + course_head->class_name + "_" + year_head->year_name + "_student.csv";
    file_name2 = "../Txt_Csv/" + file_name2;
    remove(file_name2.c_str());

    // Remove file Scoreboard of Course
    string file_name3 = course_head->course_ID + "_Semester" + (char)(semester_head->Semester_Ord + 48) + "_" + course_head->class_name + "_" + year_head->year_name + "_Scoreboard.csv";
    file_name3 = "../Txt_Csv/" + file_name3;
    remove(file_name3.c_str());

    //Delete course from course_head->class_name
    string file_name4 = course_head->class_name + "_Semester" + (char)(semester_head->Semester_Ord + 48) + "_" + year_head->year_name + "_courses.csv";
    file_name4 = "../Txt_Csv/" + file_name4;
    deleteCoursefromFile(file_name4, course_head);
    
    //Announce for user
    Create_A_Box_1(70,28,2,30,14,14,0,"   Delete successfully ");

    for (int i = 0; i < 3; ++i)
    {
        gotoXY(94 + i,29);
        ShowConsoleCursor(false);
        std::cout << "." << flush;
        Sleep(500);
    }
    system("cls");
    viewUpdateCourseInformation (username, year_head, semester_head);
    delete course_head;
    return;
}