#include "../Header/Staff.h"
#include "../Header/Design.h"


int COURSE_Interface(string username, Year* &year_head, Semester* &semester_head, Course* &course_head){
    gotoXY(60,2); std::cout <<"     _____ ____  _    _ _____   _____ ______ ";
    gotoXY(60,3); std::cout <<"    / ____/ __ \\| |  | |  __ \\ / ____|  ____|";
    gotoXY(60,4); std::cout <<"   | |   | |  | | |  | | |__) | (___ | |__   ";
    gotoXY(60,4); std::cout <<"   | |   | |  | | |  | |  _  / \\___ \\|  __|  ";
    gotoXY(60,5); std::cout <<"   | |___| |__| | |__| | | \\ \\ ____) | |____ ";
    gotoXY(60,6); std::cout <<"    \\_____\\____/ \\____/|_|  \\_\\_____/|______|";
    gotoXY(60,8); std::cout << "---------------------" << course_head->course_ID << "---------------------";
    Create_A_Box_1(60,10,2,50,14,14,0,"          VIEW ALL STUDENTS IN THIS COURSE");
    Create_A_Box_1(60,12,2,50,14,14,0,"          VIEW SCOREBOARD FOR THIS COURSE");
    gotoXY(60,12); std::cout << (char)(195);
    gotoXY(110,12); std::cout << (char)(180);
    Create_A_Box_1(60,14,2,50,14,14,0,"          UPDATE SCOREBOARD FOR THIS COURSE");
    gotoXY(60,14); std::cout << (char)(195);
    gotoXY(110,14); std::cout << (char)(180);
    Create_A_Box_1(60,16,2,50,14,14,0,"          EXPORT SCOREBOARD.CSV FOR TEACHER");
    gotoXY(60,16); std::cout << (char)(195);
    gotoXY(110,16); std::cout << (char)(180);
    Create_A_Box_1(60,18,2,50,14,14,0,"         IMPORT SCOREBOARD.CSV TO THIS SYSTEM");
    gotoXY(60,18); std::cout << (char)(195);
    gotoXY(110,18); std::cout << (char)(180);
    Create_A_Box_1(60,20,2,50,14,14,0,"                    RETURN BACK");
    gotoXY(60,20); std::cout << (char)(195);
    gotoXY(110,20); std::cout << (char)(180);

    ShowConsoleCursor(false);
    int x_temp = 60, y_temp = 10;
    bool flag = true;
    while (true)
    {
        if (flag == true)
        {
            if (y_temp == 10)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 49; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "          VIEW ALL STUDENTS IN THIS COURSE";
                ShowConsoleCursor(false);
            }
            else if (y_temp == 12)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 49; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "          VIEW SCOREBOARD FOR THIS COURSE";
                ShowConsoleCursor(false);
            }
            else if(y_temp == 14)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 49; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "          UPDATE SCOREBOARD FOR THIS COURSE";
                ShowConsoleCursor(false);
            }
            else if(y_temp == 16)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 49; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "          EXPORT SCOREBOARD.CSV FOR TEACHER";
                ShowConsoleCursor(false);
            }
            else if(y_temp == 18)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 49; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "         IMPORT SCOREBOARD.CSV TO THIS SYSTEM";
                ShowConsoleCursor(false);
            }
            else
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 49; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "                    RETURN BACK";
                ShowConsoleCursor(false);
            }

            flag = false;
        }
        else
        {
            if (_kbhit())
            {
                char c = _getch();
                system("color E0");
                flag = true;

                 if (y_temp == 10)
                {
                    system("color E0");
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 49; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "          VIEW ALL STUDENTS IN THIS COURSE";
                    ShowConsoleCursor(false);
                }
                else if (y_temp == 12)
                {
                    system("color E0");
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 49; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "          VIEW SCOREBOARD FOR THIS COURSE";
                    ShowConsoleCursor(false);
                }
                else if(y_temp == 14)
                {
                    system("color E0");
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 49; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "          UPDATE SCOREBOARD FOR THIS COURSE";
                    ShowConsoleCursor(false);
                }
                else if(y_temp == 16)
                {
                    system("color E0");
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 49; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "          EXPORT SCOREBOARD.CSV FOR TEACHER";
                    ShowConsoleCursor(false);
                }
                else if(y_temp == 18)
                {
                    system("color E0");
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 49; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "         IMPORT SCOREBOARD.CSV TO THIS SYSTEM";
                    ShowConsoleCursor(false);
                }
                else
                {
                    system("color E0");
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 49; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "                    RETURN BACK";
                    ShowConsoleCursor(false);
                }

                if (c == 72)
                {
                    if (y_temp == 10)
                    {
                        y_temp = 20;
                    }
                    else
                    {
                        y_temp -= 2;
                    }
                }
                else if (c == 80)
                {
                    if (y_temp == 20)
                    {
                        y_temp = 10;
                    }
                    else
                    {
                        y_temp += 2;
                    }
                }
                else if (c == 13)
                {
                    if (y_temp == 10)
                    {
                        system("cls");
                        return 1;
                    }
                    else if (y_temp == 12)
                    {
                        system("cls");
                        return 2;
                    }
                    else if (y_temp == 14)
                    {
                        system("cls");
                        return 3;
                    }
                    else if (y_temp == 16)
                    {
                        system("cls");
                        return 4;
                    }
                    else if (y_temp == 18)
                    {
                        system("cls");
                        return 5;
                    }
                    else
                    {
                        system("cls");
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}

void accessCourse(string username, Year* &year_head, Semester* &semester_head, Course* &course_head)
{
    system("cls");
    int option = COURSE_Interface(username, year_head, semester_head, course_head);

    if (option == 0)
    {
        system("cls");
        viewCourse_Screen(username, year_head, semester_head);
        return;
    }
    else if (option == 1)
    {
        system ("cls");
        viewStudentInCourse(username, year_head, semester_head, course_head);
        return;
    }
    else if (option == 2)
    {
        system("cls");
        string filename;
        char ch_semester = static_cast<char>(semester_head->Semester_Ord + 48);
        filename = course_head->course_ID + "_" + "Semester" + ch_semester + "_" + course_head->class_name + "_" + year_head->year_name + "_Scoreboard.csv";
        filename = "../Txt_Csv/" + filename;
        viewScoreBoard_Course(filename, username, year_head, semester_head, course_head);
        return;
    }
    else if (option == 3)
    {
        system("cls");
        string filename;
        char ch_semester = static_cast<char>(semester_head->Semester_Ord + 48);
        filename = course_head->course_ID + "_" + "Semester" + ch_semester + "_" + course_head->class_name + "_" + year_head->year_name + "_Scoreboard.csv";
        filename = "../Txt_Csv/" + filename;
        updateStudentsScore(filename, username, year_head, semester_head, course_head);
        return;
    }
    else if (option == 4)
    {
        system("cls");
        string filename;
        char ch_semester = static_cast<char>(semester_head->Semester_Ord + 48);
        filename = course_head->course_ID + "_" + "Semester" + ch_semester + "_" + course_head->class_name + "_" + year_head->year_name + + "_Scoreboard.csv";
        filename = "../Txt_Csv/" + filename;
        export_scoreboard(filename, username, year_head, semester_head, course_head);
        return;
    }
    else
    {
        system("cls");
        char ch_semester = static_cast<char>(semester_head->Semester_Ord + 48);
        string filename = course_head->course_ID + "_" + "Semester" + ch_semester + "_" + course_head->class_name + "_" + year_head->year_name + "_Scoreboard.csv";
        filename = "../Txt_Csv/" + filename;
        update_scoreBoard(filename, username, year_head, semester_head, course_head);
        return;
    }
}