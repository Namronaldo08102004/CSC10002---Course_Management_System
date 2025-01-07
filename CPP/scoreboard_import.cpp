#include "../Header/Staff.h"
#include "../Header/Student.h"
#include "../Header/Design.h"

void export_scoreboard(string filename, string username, Year* &year_head, Semester* &semester_head, Course* &course_head)
{    
    gotoXY(48, 1); cout <<"   _____  _____  _____ ______  _____ ______  _____   ___  ______ ______";
    gotoXY(48, 2); cout <<"  /  ___|/  __ \\|  _  || ___ \\|  ___|| ___ \\|  _  | / _ \\ | ___ \\|  _  \\";
    gotoXY(48, 3); cout <<"  \\ `--. | /  \\/| | | || |_/ /| |__  | |_/ /| | | |/ /_\\ \\| |_/ /| | | |";
    gotoXY(48, 4); cout <<"   `--. \\| |    | | | ||    / |  __| | ___ \\| | | ||  _  ||    / | | | |";
    gotoXY(48, 5); cout <<"  /\\__/ /| \\__/\\\\ \\_/ /| |\\ \\ | |___ | |_/ /\\ \\_/ /| | | || |\\ \\ | |/ /";
    gotoXY(48, 6); cout <<"  \\____/  \\____/ \\___/ \\_| \\_|\\____/ \\____/  \\___/ \\_| |_/\\_| \\_||___/";
    gotoXY(48, 8); cout << "        ------------"<< course_head->course_ID << "_" << "Semester" << semester_head->Semester_Ord << "_" << year_head->year_name  <<"--------------\n";
    //Check if any students existed
    course_head->student_head = getStudentCourseFromFile(year_head, semester_head, course_head);
    if(!course_head->student_head)
    {
        gotoXY(67, 10); cout << "THERE IS NO STUDENT IN THIS COURSE.";
        Create_A_Box_1(50, 15, 2, 14, 14, 14, 0, " RETURN BACK");
        SetColor1(15,0);
        for (int i = 51; i <= 63; ++i)
        {
            gotoXY(i, 16);
            std::cout << " ";
        }
        gotoXY(51, 16);
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
        //Return to the access course screen
        accessCourse(username, year_head, semester_head, course_head);
        return;
    }
    //Ask the staff if they want to continue
    gotoXY(52, 10); cout << "IF THE FILE HAS BEEN CREATED BEFORE. YOU WILL REWRITE THE FILE\n";
    gotoXY(52, 11); cout << "DO YOU WANT TO CONTINUE\n";
    Create_A_Box_1(50, 15, 2, 14, 14, 14, 0, " CONTINUE");
    Create_A_Box_1(50, 17, 2, 14, 14, 14, 0, " RETURN BACK");
    gotoXY(50,17); std::cout << (char)(195);
    gotoXY(50+14,17); std::cout << (char)(180);
    int choice = 2;
    int x_temp = 50, y_temp = 15;
    bool flag = true;
    while (true)
    {
        if (flag == true)
        {
            if (y_temp == 15)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 13; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << " CONTINUE";
                ShowConsoleCursor(false);
            }
            else if (y_temp == 17)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 13; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << " RETURN BACK";
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
                if (y_temp == 15)
                {
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 13; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << " CONTINUE";
                    ShowConsoleCursor(false);
                }
                else if (y_temp == 17)
                {
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 13; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << " RETURN BACK";
                    ShowConsoleCursor(false);
                }
                flag = true;

                if (c == UP)
                {
                    if (y_temp == 15)
                    {
                        y_temp = 17;
                    }
                    else
                    {
                        y_temp -= 2;
                    }
                }
                else if (c == 80)
                {
                    if (y_temp == 17)
                    {
                        y_temp = 15;
                    }
                    else
                    {
                        y_temp += 2;
                    }
                }
                else if (c == 13)
                {
                    if (y_temp == 15)
                    {
                        choice = 1;
                        break;
                        
                    }
                    else if (y_temp == 17)
                    {
                        choice = 0;
                        break;
                    }
                }
            }
        }
    }
    
    if(choice == 0)
    {
        accessCourse(username, year_head, semester_head, course_head);
        return;
    }
    system("cls");
    gotoXY(48, 1); cout <<"   _____  _____  _____ ______  _____ ______  _____   ___  ______ ______";
    gotoXY(48, 2); cout <<"  /  ___|/  __ \\|  _  || ___ \\|  ___|| ___ \\|  _  | / _ \\ | ___ \\|  _  \\";
    gotoXY(48, 3); cout <<"  \\ `--. | /  \\/| | | || |_/ /| |__  | |_/ /| | | |/ /_\\ \\| |_/ /| | | |";
    gotoXY(48, 4); cout <<"   `--. \\| |    | | | ||    / |  __| | ___ \\| | | ||  _  ||    / | | | |";
    gotoXY(48, 5); cout <<"  /\\__/ /| \\__/\\\\ \\_/ /| |\\ \\ | |___ | |_/ /\\ \\_/ /| | | || |\\ \\ | |/ /";
    gotoXY(48, 6); cout <<"  \\____/  \\____/ \\___/ \\_| \\_|\\____/ \\____/  \\___/ \\_| |_/\\_| \\_||___/";
    gotoXY(48, 8); cout << "------------"<< course_head->course_ID << "_" << "Semester" << semester_head->Semester_Ord << "_" << year_head->year_name  <<"--------------\n";
    gotoXY(33, 10); cout << "The name of this file will be CourseID_SemesterOrd_Year_Scoreboard.csv (eg: CSC10002_Semester2_2019-2020_Scoreboard.csv)\n";
    //Create a CSV file
    ofstream ofs (filename);
    ofs << "StudentID,Fullname,Midterm Mark,Final Mark,Other Mark,Total Mark" << "\n";

    Student *cur = course_head->student_head;
    while (cur)
    {
        ofs << cur->student_ID << ",";
        ofs << cur->student_fisrtname << " " << cur->student_lastname << ",";
        ofs << ",,," << endl;
        cur = cur->student_next;
    }
    cout << endl;
    gotoXY(33, 12); cout << "The file " << filename << " has been created successfully.\n";

    system("color E0");

    // SetColor1(15,0);
    // Create_A_Box_3(67,15,2,30);

    // for (int i = 68; i <= 96; ++i)
    // {
    //     gotoXY(i, 16);
    //     std::cout << " ";
    // }
    // gotoXY(68,16);
    // std::cout << "          RETURN BACK";

    Create_A_Box_1(67, 15, 2, 30, 14, 14, 0, "          RETURN BACK");
    SetColor1(15, 0);
    for (int i = 68; i <= 96; ++i)
    {
        gotoXY(i, 16);
        std::cout << " ";
    }
    gotoXY(68,16); 
    std::cout << "          RETURN BACK";
    ShowConsoleCursor(false);

    while (true)
    {
        if (_kbhit())
            {
                char c = _getch();
                system("color E0");
                SetColor1(15,0);

                for (int i = 68; i <= 96; ++i)
                {
                    gotoXY(i, 16);
                    std::cout << " ";
                }

                gotoXY(68,16); 
                std::cout << "          RETURN BACK";
                if (c == 13)
                {
                    system("cls");
                    accessCourse(username, year_head, semester_head, course_head);
                    return;
                }
            }
    }
    accessCourse(username, year_head, semester_head, course_head);
    ofs.close();
}

void update_scoreBoard(string filename, string username, Year* &year_head, Semester* &semester_head, Course* &course_head)
{
    gotoXY(50, 1); cout <<"   _____  _____  _____ ______  _____ ______  _____   ___  ______ ______";
    gotoXY(50, 2); cout <<"  /  ___|/  __ \\|  _  || ___ \\|  ___|| ___ \\|  _  | / _ \\ | ___ \\|  _  \\";
    gotoXY(50, 3); cout <<"  \\ `--. | /  \\/| | | || |_/ /| |__  | |_/ /| | | |/ /_\\ \\| |_/ /| | | |";
    gotoXY(50, 4); cout <<"   `--. \\| |    | | | ||    / |  __| | ___ \\| | | ||  _  ||    / | | | |";
    gotoXY(50, 5); cout <<"  /\\__/ /| \\__/\\\\ \\_/ /| |\\ \\ | |___ | |_/ /\\ \\_/ /| | | || |\\ \\ | |/ /";
    gotoXY(50, 6); cout <<"  \\____/  \\____/ \\___/ \\_| \\_|\\____/ \\____/  \\___/ \\_| |_/\\_| \\_||___/";
    gotoXY(50, 8); cout << "------------"<< course_head->course_name << "_" << "Semester" << semester_head->Semester_Ord << "_" << year_head->year_name  <<"--------------\n";

    gotoXY(56, 10); cout << "PLEASE INPUT THE NAME OF THE FILE YOU WANT TO UPDATE.";
    gotoXY(40, 11); cout << "THE NAME OF THE FILE SHOULD BE CourseID_SemesterOrd_Year (CSC10002_Semester2_2019-2020_Scoreboard.csv)"; 
    Create_A_Box_2(56,15,2,60,14,14,0,"ENTER FILE NAME:  ");
    Create_A_Box_1(40,20,2,20,14,14,0,"    RETURN BACK");
    ShowConsoleCursor(false);
    string file_name = "";
    int x_temp = 56; int y_temp = 15; int y_old; int xp = x_temp; int yp = y_temp; int pos_user = 0; int pos_pass = 0;
    int count = 0;
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
                    if (file_name != "")
                        count++;
                    xp = 56;
                    yp = y_temp;
                    break;
                }
                else if (c == DOWN)
                {
                    ShowConsoleCursor(false);
                    y_old = y_temp;
                    y_temp = 20;
                    xp = x_temp + file_name.size();
                    yp = y_old;
                    break;
                }
                else if (c == BACKSPACE)
                {
                    if (file_name != "" && pos_user > 0)
                    {
                        std::cout << "\b \b";
                        file_name.pop_back();
                    }
                }
                else if (c == LEFT)
                {
                    int len = file_name.size();

                    if (pos_user > 0)
                    {
                        pos_user--;
                        gotoXY(x_temp + pos_user + 2, y_temp + 1);
                    }

                    continue;
                }
                else if (c == RIGHT)
                {
                    int len = file_name.size();

                    if (pos_user < len)
                    {
                        pos_user++;
                        gotoXY(x_temp + pos_user + 2, y_temp + 1);
                    }

                    continue;
                }
                else
                {
                    int len = file_name.size();

                    if (c >= 32 && c <= 126 && len < 56)
                    {
                        pos_user++;
                        file_name += c;
                        std::cout << c;
                    }
                }
            }
        }
        else
        {
            SetColor1(15,0);
            for (int i = 41; i <= 59; ++i)
            {
                gotoXY(i, y_temp + 1);
                std::cout << " ";
            }

            gotoXY(41, y_temp + 1);
            std::cout << "    RETURN BACK";


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
                    accessCourse(username, year_head, semester_head, course_head);
                    return;
                }
            }
        }
    }

    char ch_semester = static_cast<char>(semester_head->Semester_Ord + 48);
    string namefile = course_head->course_ID + "_" + "Semester" + ch_semester + "_" + course_head->class_name + "_" + year_head->year_name + + "_Scoreboard.csv";
    namefile = "../Txt_Csv/" + namefile;

    file_name = "../Txt_Csv/" + file_name;
    ifstream ifs;
    ifs.open(file_name);
    while (!ifs.is_open())
    {
        gotoXY(56, 12); cout << "ERROR: UNABLE TO OPEN FILE FOR READING";
        update_scoreBoard(filename, username, year_head, semester_head, course_head);
        return;
    }
    
    ifs.close();

    if (namefile != file_name)
    {
        
        const char* newnamefile = namefile.c_str();
        const char* newfilename = file_name.c_str();

        remove(newnamefile);
        rename(newfilename, newnamefile);
    }

    int opt = choose_interface(filename, username, year_head, semester_head, course_head);

    if (opt == 0)
        accessCourse(username, year_head, semester_head, course_head);
    else
        viewScoreBoard_Course(filename, username, year_head, semester_head, course_head);
}

int choose_interface(string filename, string username, Year* &year_head, Semester* &semester_head, Course* &course_head)
{
    Create_A_Box_1(33,19,2,50,14,14,0,"                VIEW SCOREBOARD");
    Create_A_Box_1(33,21,2,50,14,14,0,"                  RETURN BACK");
    gotoXY(33,21); std::cout << (char)(195);
    gotoXY(83,21); std::cout << (char)(180);

    ShowConsoleCursor(false);
    int x_temp = 33, y_temp = 19;
    bool flag = true;
    while (true)
    {
        if (flag == true)
        {
            if (y_temp == 19)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 49; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "                VIEW SCOREBOARD";
                ShowConsoleCursor(false);
            }
            else if (y_temp == 21)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 49; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "                  RETURN BACK";
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

                if (y_temp == 19)
                {
                    system("color E0");
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 49; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "                VIEW SCOREBOARD";
                    ShowConsoleCursor(false);
                }
                else if (y_temp == 21)
                {
                    system("color E0");
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 49; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "                  RETURN BACK";
                    ShowConsoleCursor(false);
                }

                if (c == UP)
                {
                    if (y_temp == 19)
                    {
                        y_temp = 21;
                    }
                    else
                    {
                        y_temp -= 2;
                    }
                }
                else if (c == 80)
                {
                    if (y_temp == 21)
                    {
                        y_temp = 19;
                    }
                    else
                    {
                        y_temp += 2;
                    }
                }
                else if (c == 13)
                {
                    if (y_temp == 19)
                    {
                        system("cls");
                        return 1;
                    }
                    else if (y_temp == 21)
                    {
                        system("cls");
                        return 0;
                    }
                }
            }
        }
    }
}