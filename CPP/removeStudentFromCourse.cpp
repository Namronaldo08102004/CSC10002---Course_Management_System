#include "../Header/Staff.h"
#include "../Header/Student.h"
#include "../Header/Design.h"

string printDate(Date a)
{
    string tmp;
    if (a.day < 10)
        tmp += "0" + to_string(a.day) + "/";
    else
        tmp += to_string(a.day) + "/";      
    if (a.month < 10)
        tmp += "0" + to_string(a.month) + "/";
    else
        tmp += to_string(a.month) + '/';
    tmp += to_string(a.year);
    return tmp;
}

void deleteStudent(Student* &student_head, string studentID)
{
    // Find the student with the given studentID
    Student *current = student_head;
    Student *previous = nullptr;
    while (current != nullptr && current->student_ID != studentID) 
    {
        previous = current;
        current = current->student_next;
    }

    // If the student is found, delete it
    if (current != nullptr) 
    {
        // If the student is the first in the list
        if (previous == nullptr) 
            student_head = current->student_next;
        else
            previous->student_next = current->student_next;
        delete current;
    }
}

Student* getListStuFromFile(string filename)
{
    ifstream ifs;
    ifs.open(filename);
    if (!ifs.is_open())
    {
        cerr << "Error: Unable to open file for reading\n";
        return nullptr;
    }
    Student* student_head = nullptr;
    string dummy;
    getline(ifs, dummy);
    
    string line;
    while (getline(ifs, line))
    {
        string tmp;
        stringstream ss(line);

        Student* new_student = new Student;
        getline(ss, tmp, ',');
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

        addTail(student_head, new_student);
    }

    ifs.close();
    return student_head;
}

void removeStudent(string filename, string studentID) 
{
    ifstream fin(filename); // Open the file for reading
    ofstream fout("temp.txt"); // Open a temporary file for writing

    Student* tmp = getListStuFromFile(filename);
    deleteStudent(tmp, studentID);
    fout << "student ID,student_socialID,student_fisrtname,student_lastname,gender,class_name,DOB\n";
    while (tmp != nullptr) 
    {
        fout << tmp->student_ID << "," << tmp->student_socialID << ","
             << tmp->student_fisrtname << "," << tmp->student_lastname << ","
             << tmp->gender << "," << tmp->student_class.class_name << "," << printDate(tmp->DOB) << "\n";
        tmp = tmp->student_next;
    }
    
    fin.close(); // Close the input file
    fout.close(); // Close the temporary file
    
    remove(filename.c_str()); // Delete the original file
    rename("temp.txt", filename.c_str()); // Rename the temporary file to the original filename

    while (tmp)
    {
        Student* temp = tmp;
        tmp = tmp->student_next;
        delete temp;
    }
}

void removeStudentFromScoreboardfile(string filename, string studentID) 
{
    ifstream fin(filename); // Open the file for reading
    ofstream fout("temp.txt"); // Open a temporary file for writing

    fout << "StudentID,Fullname,Midterm Mark,Final Mark,Other Mark,Total Mark\n";

    if (!fin.is_open())
    {
        cerr << "Error! Unable to open file to read";
        return;
    }

    string ignore_line; getline(fin, ignore_line);
    string line;

    while (getline(fin, line))
    {
        string tmp;
        stringstream ss(line);

        getline(ss, tmp, ',');
        if (tmp == studentID)
            continue;
        else
        {
            fout << tmp << ",";
            getline(ss, tmp, ',');
            fout << tmp << ",";
            getline(ss, tmp, ',');
            fout << stof(tmp) << ",";
            getline(ss, tmp, ',');
            fout << stof(tmp) << ",";
            getline(ss, tmp, ',');
            fout << stof(tmp) << ",";
            getline(ss, tmp, '\n');
            fout << stof(tmp) << "\n";
        }
    }
    
    fin.close(); // Close the input file
    fout.close(); // Close the temporary file
    
    remove(filename.c_str()); // Delete the original file
    rename("temp.txt", filename.c_str()); // Rename the temporary file to the original filename
}

void removeCourseToStudent(Student* &student, Course* course)
{
    Course* currentCourse = student->course_head;
    Course* previousCourse = nullptr;
    while (currentCourse != nullptr) 
    {
        if (currentCourse->course_ID == course->course_ID) 
        {
            if (previousCourse == nullptr) 
                student->course_head = currentCourse->course_next;
            else 
                previousCourse->course_next = currentCourse->course_next;
            // delete currentCourse;
            return;
        }
        previousCourse = currentCourse;
        currentCourse = currentCourse->course_next;
    }
}

void removeStudentFromCourse(string username, Course* &course, Year* &year_head, Semester* semester_head) 
{
    resizeConsole(1920,920);
    system("color E0");
    gotoXY(40,2); 
    std::cout << "      ______ ________  ________  _   _ _____   _____ _____ _   _______ _____ _   _ _____      ";
    gotoXY(40,3);
    std::cout << "      | ___ \\  ___|  \\/  |  _  || | | |  ___| /  ___|_   _| | | |  _  \\  ___| \\ | |_   _|";
    gotoXY(40,4);
    std::cout << "      | |_/ / |__ | .  . | | | || | | | |__   \\ `--.  | | | | | | | | | |__ |  \\| | | |";
    gotoXY(40,5);
    std::cout << "      |    /|  __|| |\\/| | | | || | | |  __|   `--. \\ | | | | | | | | |  __|| . ` | | |";
    gotoXY(40,6);
    std::cout << "      | |\\ \\| |___| |  | \\ \\_/ /\\ \\_/ / |___  /\\__/ / | | | |_| | |/ /| |___| |\\  | | |";
    gotoXY(40,7);
    std::cout << "      \\_| \\_\\____/\\_|  |_/\\___/  \\___/\\____/  \\____/  \\_/  \\___/|___/ \\____/\\_| \\_/ \\_/";

    string studentID = "";
    Create_A_Box_2(70,15,2,30,14,14,0,"INPUT STUDENT_ID");
    Create_A_Box_1(55,20,2,20,14,14,0,"    RETURN BACK");
    ShowConsoleCursor(false);
    int count = 0;
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
                    if (studentID != "")
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
                {
                    pos = 0;
                    system("cls");
                    updateACourse(username, year_head, semester_head, course);
                    return;
                }
            }
        }
    }

    Student* student = findStudentInClass(year_head->class_head , studentID);

    if (student == nullptr)
    {
        Create_A_Box_1(68,29,2,36,14,14,0,"   This studentID is not exist!");
        Sleep(1000);
        Create_A_Box_1(68,33,2,30,14,14,0,"   Out program ");
        for (int i = 0; i < 3; ++i)
        {
            gotoXY(68 + 16 + i,34);
            ShowConsoleCursor(false);
            std::cout << "." << flush;
            Sleep(500);
        }
        system ("cls");
        updateACourse(username, year_head, semester_head, course);
        return;
    }

    // Remove the course to the student's list of courses
    removeCourseToStudent(student, course);

    // Remove the student to the course's list of students
    Student* currentStudent = course->student_head;
    Student* previousStudent = nullptr;
    while (currentStudent != nullptr) 
    {
        if (currentStudent->student_ID == student->student_ID) 
        {
            if (previousStudent == nullptr) 
                course->student_head = currentStudent->student_next;
            else 
                previousStudent->student_next = currentStudent->student_next;
            break;
        }
        previousStudent = currentStudent;
        currentStudent = currentStudent->student_next;
    }

    // Remove student infomation from file
    string file_name1 = course->course_ID + "_Semester" + (char)(semester_head->Semester_Ord + 48) + "_" + course->class_name + "_" + year_head->year_name + "_student.csv";
    file_name1 = "../Txt_Csv/" + file_name1;
    removeStudent(file_name1, studentID);

    // Remove student information from scoreboard file
    string file_name2 = course->course_ID + "_Semester" + (char)(semester_head->Semester_Ord + 48) + "_" + course->class_name + "_" + year_head->year_name + "_Scoreboard.csv";
    file_name2 = "../Txt_Csv/" + file_name2;
    removeStudentFromScoreboardfile(file_name2, studentID);

    Create_A_Box_1(68,29,2,30,14,14,0,"    Remove successfully ");
    for (int i = 0; i < 3; ++i)
    {
        gotoXY(68 + 25 + i,30);
        ShowConsoleCursor(false);
        std::cout << "." << flush;
        Sleep(500);
    }

    system("cls");
    updateACourse(username, year_head, semester_head, course);
    return;
}
