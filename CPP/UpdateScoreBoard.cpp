#include "../Header/Staff.h"
#include "../Header/Student.h"
#include "../Header/Design.h"

void updateStudentsScore(string filename, string username, Year* &year_head, Semester* &semester_head, Course* &course_head)
{
    system("cls");
    gotoXY(30, 1); cout <<"    _    _ _____  _____       _______ ______    _____  _____ ____  _____  ______ ____   ____          _____  _____  ";
    gotoXY(30, 2); cout <<"   | |  | |  __ \\|  __ \\   /\\|__   __|  ____|  / ____|/ ____/ __ \\|  __ \\|  ____|  _ \\ / __ \\   /\\   |  __ \\|  __ \\ ";
    gotoXY(30, 3); cout <<"   | |  | | |__) | |  | | /  \\  | |  | |__    | (___ | |   | |  | | |__) | |__  | |_) | |  | | /  \\  | |__) | |  | |";
    gotoXY(30, 4); cout <<"   | |  | |  ___/| |  | |/ /\\ \\ | |  |  __|    \\___ \\| |   | |  | |  _  /|  __| |  _ <| |  | |/ /\\ \\ |  _  /| |  | |";
    gotoXY(30, 5); cout <<"   | |__| | |    | |__| / ____ \\| |  | |____   ____) | |___| |__| | | \\ \\| |____| |_) | |__| / ____ \\| | \\ \\| |__| |";
    gotoXY(30, 6); cout <<"    \\____/|_|    |_____/_/    \\_\\_|  |______| |_____/ \\_____\\____/|_|  \\_\\______|____/ \\____/_/    \\_\\_|  \\_\\_____/ ";
    gotoXY(36, 9); cout << "------------------------------"<< course_head->course_name <<"--------------------------\n";
    int option = 0;
    Create_A_Box_2(70,17,2,20,14,14,0,"ENTER STUDENT'S ID:");
    Create_A_Box_1(40,24,2,20,14,14,0,"    RETURN BACK");
    ShowConsoleCursor(false);
    string id;
    ifstream ifs;
    int x_temp = 70; int y_temp = 17; int y_old; int xp = x_temp; int yp = y_temp; int pos_user = 0; int pos_pass = 0;
    int count = 0;
    while (count < 1)
    {
        system("color E0");

        if (y_temp == 17)
        {
            gotoXY(xp + 2, yp + 1);
            ShowConsoleCursor(true);

            char c;
            while (true)
            {
                c = _getch();

                if (c == ENTER)
                {
                    if (id != "")
                        count++;
                    xp = 70;
                    yp = y_temp;
                    break;
                }
                else if (c == DOWN)
                {
                    ShowConsoleCursor(false);
                    y_old = y_temp;
                    y_temp = 24;
                    xp = x_temp + id.size();
                    yp = y_old;
                    break;
                }
                else if (c == BACKSPACE)
                {
                    if (id != "" && pos_user > 0)
                    {
                        std::cout << "\b \b";
                        id.pop_back();
                    }
                }
                else if (c == LEFT)
                {
                    int len = id.size();

                    if (pos_user > 0)
                    {
                        pos_user--;
                        gotoXY(x_temp + pos_user + 2, y_temp + 1);
                    }

                    continue;
                }
                else if (c == RIGHT)
                {
                    int len = id.size();

                    if (pos_user < len)
                    {
                        pos_user++;
                        gotoXY(x_temp + pos_user + 2, y_temp + 1);
                    }

                    continue;
                }
                else
                {
                    int len = id.size();
                    //only number
                    if (c >= 32 && c <= 126 && len < 9)
                    {
                        pos_user++;
                        id += c;
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

    int counter = 1;
    string student_id, fullname;
    float total, final1, midterm, other;
    //Read File
    ifs.open(filename);
    if (!ifs.is_open())
    {
        gotoXY(71, 11); cout << "ERROR: UNABLE TO OPEN FILE FOR READING\n";
        return;
    }
    ofstream ofs;
    ofs.open("../Txt_Csv/temp.csv");
    if (!ofs.is_open())
    {
        gotoXY(71, 12); cout << "ERROR: UNABLE TO OPEN FILE FOR WRITING\n";
        return;
    }
    string temp;
    string dummy;
    getline(ifs, dummy);
    ofs << dummy << "\n";
    if (check_is_it(filename, id))
    {
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
            
            if (id == student_id)
            {
                ofs << student_id << "," << fullname << ",";
                Create_A_Box_2(105,17,2,11,14,14,0,"MIDTERM:");
                gotoXY(101 + 5,18); cin >> midterm;
                Create_A_Box_2(120,17,2,11,14,14,0,"FINAL:");
                gotoXY(111 + 10,18); cin >> final1;
                Create_A_Box_2(135,17,2,11,14,14,0,"OTHER:");
                gotoXY(121 + 15,18); cin >> other;
                total = (midterm + final1 + other)/3.0;
                ofs << fixed << setprecision(1) << midterm << ","
                    << fixed << setprecision(1) << final1 << ","
                    << fixed << setprecision(1) << other << ","
                    << fixed << setprecision(1) << total << "\n";
            }
            else
            {
                ofs << student_id << "," << fullname << ",";
                ofs << fixed << setprecision(1) << midterm << ","
                    << fixed << setprecision(1) << final1 << ","
                    << fixed << setprecision(1) << other << ","
                    << fixed << setprecision(1) << total << "\n";
            }
            counter++;
        }
    }
    else
    {
        ifs.close();
        ofs.close();
        int a = 14;
        gotoXY(33 + 8,8 + a + 1); cout << "STUDENT ID NOT FOUND";
        Create_A_Box_1(33,10 + a,2,35,14,14,0,"   CONTINUE UPDATING SCOREBOARD");
        Create_A_Box_1(33,12 + a,2,35,14,14,0,"          RETURN BACK");
        gotoXY(33,12 + a); std::cout << (char)(195);
        gotoXY(68,12 + a); std::cout << (char)(180);

        ShowConsoleCursor(false);
        int x_temp = 33, y_temp = 24;
        bool flag = true;
        while (true)
        {
            if (flag == true)
            {
                if (y_temp == 24)
                {
                    system("color E0");
                    SetColor1(15,0);
                    for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "   CONTINUE UPDATING SCOREBOARD";
                    ShowConsoleCursor(false);
                }
                else if (y_temp == 26)
                {
                    system("color E0");
                    SetColor1(15,0);
                    for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "          RETURN BACK";
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
                    if (y_temp == 24)
                    {
                        SetColor1(14,0);
                        for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                        {
                            gotoXY(i, y_temp + 1);
                            std::cout << " ";
                        }

                        gotoXY(x_temp + 1, y_temp + 1);
                        std::cout << "   CONTINUE UPDATING SCOREBOARD";
                        ShowConsoleCursor(false);
                    }
                    else if (y_temp == 26)
                    {
                        SetColor1(14,0);
                        for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                        {
                            gotoXY(i, y_temp + 1);
                            std::cout << " ";
                        }

                        gotoXY(x_temp + 1, y_temp + 1);
                        std::cout << "          RETURN BACK";
                        ShowConsoleCursor(false);
                    }
                    flag = true;

                    if (c == UP)
                    {
                        if (y_temp == 24)
                        {
                            y_temp = 26;
                        }
                        else
                        {
                            y_temp -= 2;
                        }
                    }
                    else if (c == 80)
                    {
                        if (y_temp == 26)
                        {
                            y_temp = 24;
                        }
                        else
                        {
                            y_temp += 2;
                        }
                    }
                    else if (c == 13)
                    {
                        if (y_temp == 24)
                        {
                            system("cls");
                            updateStudentsScore(filename, username, year_head, semester_head, course_head);
                            return;
                        }
                        else if (y_temp == 26)
                        {
                            system("cls");
                            accessCourse(username, year_head, semester_head, course_head);
                            return;
                        }
                    }
                }
            }
        }
    }
    ifs.close();
    ofs.close();
    const char* newfilename = filename.c_str();
    remove(newfilename);
    rename("../Txt_Csv/temp.csv", newfilename);
    option = choose_option(filename, username, year_head, semester_head, course_head);
    system("cls");
    if(option == 1)
        accessCourse(username, year_head, semester_head, course_head);
    else if(option == 0)
        updateStudentsScore(newfilename, username, year_head, semester_head, course_head);
}

int choose_option(string filename, string username, Year* &year_head, Semester* &semester_head, Course* &course_head){
    int a = 14;
    gotoXY(33 + 9,8 + a + 1); cout << "UPDATE SUCCESSFUL!";
    Create_A_Box_1(33,10 + a,2,35,14,14,0,"   CONTINUE UPDATING SCOREBOARD");
    Create_A_Box_1(33,12 + a,2,35,14,14,0,"          RETURN BACK");
    gotoXY(33,12 + a); std::cout << (char)(195);
    gotoXY(68,12 + a); std::cout << (char)(180);

    ShowConsoleCursor(false);
    int x_temp = 33, y_temp = 24;
    bool flag = true;
    while (true)
    {
        if (flag == true)
        {
            if (y_temp == 24)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 34; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "   CONTINUE UPDATING SCOREBOARD";
                ShowConsoleCursor(false);
            }
            else if (y_temp == 26)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 34; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "          RETURN BACK";
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
                if (y_temp == 24)
                {
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 34; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "   CONTINUE UPDATING SCOREBOARD";
                    ShowConsoleCursor(false);
                }
                else if (y_temp == 26)
                {
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 34; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "          RETURN BACK";
                    ShowConsoleCursor(false);
                }
                flag = true;

                if (c == UP)
                {
                    if (y_temp == 24)
                    {
                        y_temp = 26;
                    }
                    else
                    {
                        y_temp -= 2;
                    }
                }
                else if (c == 80)
                {
                    if (y_temp == 26)
                    {
                        y_temp = 24;
                    }
                    else
                    {
                        y_temp += 2;
                    }
                }
                else if (c == 13)
                {
                    if (y_temp == 24)
                    {
                        system("cls");
                        return 0;
                    }
                    else if (y_temp == 26)
                    {
                        system("cls");
                        return 1;
                    }
                }
            }
        }
    }
}

bool check_is_it(string filename, string student_id){
    ifstream file;
    file.open(filename);
    string dummy;
    getline(file, dummy);
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string temp;
        getline(ss, temp, ',');
        if (temp == student_id)
        {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}