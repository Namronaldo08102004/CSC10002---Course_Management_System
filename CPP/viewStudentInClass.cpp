#include "../Header/Staff.h"
#include "../Header/Design.h"


void viewStudentInClass(string username, Year* &year_head, Class *class_head)
{
    system("cls");
    SetColor1(14,0);
    gotoXY(48,2); std::cout << "     _____ _                _____ _____   _____   ____   ____  __  __ ";
    gotoXY(48,3); std::cout << "    / ____| |        /\\    / ____/ ____| |  __ \\ / __ \\ / __ \\|  \\/  |";
    gotoXY(48,4); std::cout << "   | |    | |       /  \\  | (___| (___   | |__) | |  | | |  | | \\  / |";
    gotoXY(48,5); std::cout << "   | |    | |      / /\\ \\   \\___ \\___ \\  |  _  /| |  | | |  | | |\\/| |";
    gotoXY(48,6); std::cout << "   | |____| |____ / ____ \\ ____) |___) | | | \\ \\| |__| | |__| | |  | |";
    gotoXY(48,7); std::cout << "    \\_____|______/_/    \\_\\_____/_____/  |_|  \\_\\\\____/ \\____/|_|  |_|";
    gotoXY(48,9); std::cout << "----------------------------CLASS-" << class_head->class_name << "-----------------------------";
    //Show list of students the staff has added before
    int numStudents = 0;
    if (class_head->student_head == nullptr) //Data is empty
    {
        gotoXY(60,11); std::cout << "There is no student in this class";
    }
    else
    {   
        Student* cur = class_head->student_head;
        gotoXY(60,11);
        while (cur)
        {
            cur = cur->student_next;
            numStudents += 2;
        }
        cur = class_head->student_head;
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

    Create_A_Box_3(60,15 + numStudents,2,30);
    SetColor1(15,0);
    for (int i = 61; i <= 89; ++i)
    {
        gotoXY(i, 16 + numStudents);
        std::cout << " ";
    }
    gotoXY(61, 16 + numStudents);
    std::cout << "          RETURN BACK";

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
                accessClass(username, year_head, class_head);
                return;
            }
        }
    }
}