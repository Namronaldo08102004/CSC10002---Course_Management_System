#include "../Header/Staff.h"
#include "../Header/Student.h"
#include "../Header/Design.h"

void viewStudentInCourse(string username, Year* &year_head, Semester* &semester_head, Course* &course_head)
{
    system("cls");
    SetColor1(14,0);
    gotoXY(40,2); std::cout << "     _____ ____  _    _ _____   _____ ______   _____  ______ _______       _____ _      ";
    gotoXY(40,3); std::cout << "    / ____/ __ \\| |  | |  __ \\ / ____|  ____| |  __ \\|  ____|__   __|/\\   |_   _| |     ";
    gotoXY(40,4); std::cout << "   | |   | |  | | |  | | |__) | (___ | |__    | |  | | |__     | |  /  \\    | | | |     ";
    gotoXY(40,5); std::cout << "   | |   | |  | | |  | |  _  / \\___ \\|  __|   | |  | |  __|    | | / /\\ \\   | | | |     ";
    gotoXY(40,6); std::cout << "   | |___| |__| | |__| | | \\ \\ ____) | |____  | |__| | |____   | |/ ____ \\ _| |_| |____ ";
    gotoXY(40,7); std::cout << "    \\_____\\____/ \\____/|_|  \\_\\_____/|______| |_____/|______|  |_/_/    \\_\\_____|______|";
    gotoXY(40,9); std::cout << "--------------------------------" << course_head->course_name << "--" << course_head->class_name << "-----------------------------";
    //Show list of students the staff has added before
    int numStudents = 0;
    if (course_head->student_head == nullptr) //Data is empty
    {
        gotoXY(40,11); std::cout << "THERE IS NO STUDENT IN THIS COURSE";
    }
    else
    {   
        Student* cur = course_head->student_head;
        gotoXY(40,11);
        while (cur)
        {
            cur = cur->student_next;
            numStudents += 2;
        }
        cur = course_head->student_head;
        Create_A_Box_1(60,13,numStudents,50,14,14,0,"");
        int i = 0;
        int count = 0;
        while(cur)
        {
            gotoXY(62,14 + i); cout << count + 1 << "." << setw(2) << right << cur->student_fisrtname << " " << cur->student_lastname;
            cur = cur->student_next;
            count++;
            i = i+2;
        }
    }

    gotoXY(60, 15);
    Create_A_Box_1(60, 15 + numStudents, 2, 30, 14, 14, 0, "          RETURN BACK");
    SetColor1(15, 0);
    for (int i = 61; i <= 89; ++i)
    {
        gotoXY(i, 16 + numStudents);
        std::cout << " ";
    }
    gotoXY(61,15 + numStudents + 1); 
    std::cout << "          RETURN BACK";
    ShowConsoleCursor(false);

    while (true)
    {
        if (_kbhit())
            {
                char c = _getch();
                system("color E0");
                SetColor1(15,0);

                for (int i = 61; i <= 89; ++i)
                {
                    gotoXY(i, 16 + numStudents);
                    std::cout << " ";
                }
                gotoXY(61,15 + numStudents + 1); 
                std::cout << "          RETURN BACK";
                
                if (c == 13)
                {
                    system("cls");
                    accessCourse(username, year_head, semester_head, course_head);
                    return;
                }
            }
    }
}