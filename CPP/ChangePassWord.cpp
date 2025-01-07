#include "../Header/Staff.h"
#include "../Header/Student.h"
#include "../Header/Design.h"

/*
Password Change Function: The user should be able to change their password after logging in. 
This function should allow the user to enter their current password and a new password, 
and then update the password in the database.
*/

void changePass(string username, bool isStudent, int& opt)
{
    ifstream ifs;
    ofstream ofs;
    //choose which file to read
    if (isStudent == true)
        ifs.open("../Txt_Csv/acc_student.csv");
    else
        ifs.open("../Txt_Csv/acc_staff.csv");
    if (!ifs)
    {
        cerr << "Error: Unable to open file for reading\n";
        return;
    }

    string line;
    bool found = false; vector<string> User; vector<string> Pass; string password;

    //read input form file and change password in the temporary file
    while (getline(ifs, line))
    {
        string tmp;
        stringstream ss(line);

        getline(ss, tmp, ',');
        User.push_back(tmp);
        getline(ss, tmp, '\n');
        Pass.push_back(tmp);

        int len = User.size();
        if (User[len - 1] == username) //Found username
        {
            password = Pass[len - 1];
            found = true;
        }
    }
    ifs.close();

    if (found == false)
    {
        cerr << "Error: Username not found\n";
        return;
    }

    resizeConsole(1920,920);
    system("color E0");

    gotoXY(40,2);
    std::cout << "   _____ _   _  ___  _   _ _____ _____  ______  ___  _____ _____ _    _ _________________";
    gotoXY(40,3);
    std::cout << "  /  __ \\ | | |/ _ \\| \\ | |  __ \\  ___| | ___ \\/ _ \\/  ___/  ___| |  | |  _  | ___ \\  _  \\";
    gotoXY(40,4);
    std::cout << "  | /  \\/ |_| / /_\\ \\  \\| | |  \\/ |__   | |_/ / /_\\ \\ `--.\\ `--.| |  | | | | | |_/ / | | |";
    gotoXY(40,5);
    std::cout << "  | |   |  _  |  _  | . ` | | __|  __|  |  __/|  _  |`--. \\`--. \\ |/\\| | | | |    /| | | |";
    gotoXY(40,6);
    std::cout << "  | \\__/\\ | | | | | | |\\  | |_\\ \\ |___  | |   | | | /\\__/ /\\__/ |  /\\  | \\_/ / |\\ \\| |/ /";
    gotoXY(40,7);
    std::cout << "   \\____|_| |_|_| |_|_| \\_/\\____|____/  \\_|   \\_| |_|____/\\____/ \\/  \\/ \\___/\\_| \\_|___/";

    std::string oldpass = ""; std::string newpass = ""; std::string confirmpass = ""; int count = 0;

    Create_A_Box_2(68,11,2,30,14,14,0,"OLD PASSWORD");
    Create_A_Box_2(68,16,2,30,14,14,0,"NEW PASSWORD");
    Create_A_Box_2(68,21,2,30,14,14,0,"CONFIRM NEW PASSWORD");

    Create_A_Box_1(40,26,2,20,14,14,0,"    RETURN BACK");
    ShowConsoleCursor(false);

    int x_temp = 68; int y_temp = 11; int y_old; int xp = x_temp; int yp = y_temp; int pos_old = 0; int pos_new = 0; int pos_confirm = 0;
    while (count < 3)
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
                    if (oldpass != password)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 11);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 13);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 11; i <= 13; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 11); std::cout << (char)(218); //top left
                    gotoXY(98, 11); std::cout << (char)(191); //Top right
                    gotoXY(98, 13); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 13); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    if (confirmpass != newpass)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 21);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 23);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 21; i <= 23; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 21); std::cout << (char)(218); //top left
                    gotoXY(98, 21); std::cout << (char)(191); //Top right
                    gotoXY(98, 23); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 23); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    if (oldpass != "" && oldpass == password)
                        count++;

                    if (newpass == "")
                    {
                        xp = 68 + newpass.size();
                        y_temp = 16;
                    }
                    else if (confirmpass == "" || confirmpass != newpass)
                    {
                        xp = 68 + confirmpass.size();
                        y_temp = 21;
                    }

                    yp = y_temp;
                    break;
                }
                else if (c == DOWN)
                {
                    ShowConsoleCursor(false);

                    if (oldpass != password)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 11);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 13);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 11; i <= 13; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 11); std::cout << (char)(218); //top left
                    gotoXY(98, 11); std::cout << (char)(191); //Top right
                    gotoXY(98, 13); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 13); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    if (confirmpass != newpass)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 21);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 23);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 21; i <= 23; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 21); std::cout << (char)(218); //top left
                    gotoXY(98, 21); std::cout << (char)(191); //Top right
                    gotoXY(98, 23); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 23); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    y_old = y_temp;
                    y_temp = 26;
                    xp = x_temp + oldpass.size();
                    yp = y_old;
                    break;
                }
                else if (c == BACKSPACE)
                {
                    if (oldpass != "" && pos_old > 0)
                    {
                        std::cout << "\b \b";
                        oldpass.pop_back();
                    }

                    if (oldpass != password)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 11);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 13);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 11; i <= 13; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 11); std::cout << (char)(218); //top left
                    gotoXY(98, 11); std::cout << (char)(191); //Top right
                    gotoXY(98, 13); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 13); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    if (confirmpass != newpass)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 21);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 23);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 21; i <= 23; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 21); std::cout << (char)(218); //top left
                    gotoXY(98, 21); std::cout << (char)(191); //Top right
                    gotoXY(98, 23); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 23); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    int len = oldpass.size();
                    gotoXY(70 + len, 12);
                    SetColor1(14,0);
                }
                else if (c == LEFT)
                {
                    if (pos_old > 0)
                    {
                        pos_old--;
                        gotoXY(x_temp + pos_old + 2, y_temp + 1);
                    }

                    if (oldpass != password)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 11);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 13);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 11; i <= 13; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 11); std::cout << (char)(218); //top left
                    gotoXY(98, 11); std::cout << (char)(191); //Top right
                    gotoXY(98, 13); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 13); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    if (confirmpass != newpass)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 21);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 23);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 21; i <= 23; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 21); std::cout << (char)(218); //top left
                    gotoXY(98, 21); std::cout << (char)(191); //Top right
                    gotoXY(98, 23); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 23); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    gotoXY(x_temp + pos_old + 2, y_temp + 1);
                    SetColor1(14,0);

                    continue;
                }
                else if (c == RIGHT)
                {
                    int len = oldpass.size();

                    if (pos_old < len)
                    {
                        pos_old++;
                        gotoXY(x_temp + pos_old + 2, y_temp + 1);
                    }

                    if (oldpass != password)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 11);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 13);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 11; i <= 13; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 11); std::cout << (char)(218); //top left
                    gotoXY(98, 11); std::cout << (char)(191); //Top right
                    gotoXY(98, 13); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 13); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    if (confirmpass != newpass)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 21);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 23);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 21; i <= 23; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 21); std::cout << (char)(218); //top left
                    gotoXY(98, 21); std::cout << (char)(191); //Top right
                    gotoXY(98, 23); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 23); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    gotoXY(x_temp + pos_old + 2, y_temp + 1);
                    SetColor1(14,0);

                    continue;
                }
                else
                {
                    int len = oldpass.size();

                    if (c >= 32 && c <= 126 && len < 26)
                    {
                        pos_old++;
                        oldpass += c;
                        std::cout << c;
                    }

                    if (oldpass != password)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 11);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 13);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 11; i <= 13; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 11); std::cout << (char)(218); //top left
                    gotoXY(98, 11); std::cout << (char)(191); //Top right
                    gotoXY(98, 13); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 13); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    if (confirmpass != newpass)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 21);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 23);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 21; i <= 23; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 21); std::cout << (char)(218); //top left
                    gotoXY(98, 21); std::cout << (char)(191); //Top right
                    gotoXY(98, 23); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 23); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    len = oldpass.size();
                    gotoXY(70 + len, 12);
                    SetColor1(14,0);
                }
            }
        }
        else if (y_temp == 16)
        {
            gotoXY(xp + 2, yp + 1);
            ShowConsoleCursor(true);

            char c;
            while (true)
            {
                c = _getch();

                if (c == ENTER)
                {
                    if (newpass != "")
                        count++;

                    if (oldpass == "" || oldpass != password)
                    {
                        xp = 68 + oldpass.size();
                        y_temp = 11;
                    }
                    else if (confirmpass == "" || confirmpass != newpass)
                    {
                        xp = 68 + confirmpass.size();
                        y_temp = 21;
                    }

                    yp = y_temp;
                    break;
                }
                else if (c == DOWN)
                {
                    ShowConsoleCursor(false);

                    y_old = y_temp;
                    y_temp = 26;
                    xp = x_temp + newpass.size();
                    yp = y_old;
                    break;
                }
                else if (c == BACKSPACE)
                {
                    if (newpass != "" && pos_new > 0)
                    {
                        std::cout << "\b \b";
                        newpass.pop_back();
                    }

                    if (oldpass != password)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 11);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 13);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 11; i <= 13; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 11); std::cout << (char)(218); //top left
                    gotoXY(98, 11); std::cout << (char)(191); //Top right
                    gotoXY(98, 13); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 13); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    if (confirmpass != newpass)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 21);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 23);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 21; i <= 23; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 21); std::cout << (char)(218); //top left
                    gotoXY(98, 21); std::cout << (char)(191); //Top right
                    gotoXY(98, 23); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 23); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    int len = newpass.size();
                    gotoXY(70 + len, 17);
                    SetColor1(14,0);
                }
                else if (c == LEFT)
                {
                    if (pos_new > 0)
                    {
                        pos_new--;
                        gotoXY(x_temp + pos_new + 2, y_temp + 1);
                    }

                    if (oldpass != password)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 11);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 13);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 11; i <= 13; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 11); std::cout << (char)(218); //top left
                    gotoXY(98, 11); std::cout << (char)(191); //Top right
                    gotoXY(98, 13); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 13); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    if (confirmpass != newpass)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 21);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 23);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 21; i <= 23; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 21); std::cout << (char)(218); //top left
                    gotoXY(98, 21); std::cout << (char)(191); //Top right
                    gotoXY(98, 23); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 23); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    gotoXY(x_temp + pos_new + 2, y_temp + 1);

                    continue;
                }
                else if (c == RIGHT)
                {
                    int len = newpass.size();

                    if (pos_new < len)
                    {
                        pos_new++;
                        gotoXY(x_temp + pos_new + 2, y_temp + 1);
                    }

                    if (oldpass != password)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 11);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 13);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 11; i <= 13; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 11); std::cout << (char)(218); //top left
                    gotoXY(98, 11); std::cout << (char)(191); //Top right
                    gotoXY(98, 13); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 13); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    if (confirmpass != newpass)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 21);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 23);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 21; i <= 23; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 21); std::cout << (char)(218); //top left
                    gotoXY(98, 21); std::cout << (char)(191); //Top right
                    gotoXY(98, 23); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 23); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    gotoXY(x_temp + pos_new + 2, y_temp + 1);

                    continue;
                }
                else
                {
                    int len = newpass.size();

                    if (c >= 32 && c <= 126 && len < 26)
                    {
                        pos_new++;
                        newpass += c;
                        std::cout << c;
                    }

                    if (oldpass != password)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 11);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 13);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 11; i <= 13; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 11); std::cout << (char)(218); //top left
                    gotoXY(98, 11); std::cout << (char)(191); //Top right
                    gotoXY(98, 13); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 13); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    if (confirmpass != newpass)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 21);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 23);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 21; i <= 23; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 21); std::cout << (char)(218); //top left
                    gotoXY(98, 21); std::cout << (char)(191); //Top right
                    gotoXY(98, 23); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 23); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    len = newpass.size();
                    gotoXY(70 + len, 17);
                    SetColor1(14,0);
                }
            }
        }
        else if (y_temp == 21)
        {
            gotoXY(xp + 2, yp + 1);
            ShowConsoleCursor(true);

            char c;
            while (true)
            {
                c = _getch();

                if (c == ENTER)
                {
                    if (oldpass != password)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 11);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 13);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 11; i <= 13; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 11); std::cout << (char)(218); //top left
                    gotoXY(98, 11); std::cout << (char)(191); //Top right
                    gotoXY(98, 13); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 13); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    if (confirmpass != newpass)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 21);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 23);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 21; i <= 23; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 21); std::cout << (char)(218); //top left
                    gotoXY(98, 21); std::cout << (char)(191); //Top right
                    gotoXY(98, 23); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 23); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    if (confirmpass != "" && confirmpass == newpass)
                        count++;

                    if (oldpass == "" || oldpass != password)
                    {
                        xp = 68 + oldpass.size();
                        y_temp = 11;
                    }
                    else if (newpass == "")
                    {
                        xp = 68 + newpass.size();
                        y_temp = 16;
                    }
                    yp = y_temp;
                    break;
                }
                else if (c == DOWN)
                {
                    ShowConsoleCursor(false);

                    if (oldpass != password)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 11);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 13);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 11; i <= 13; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 11); std::cout << (char)(218); //top left
                    gotoXY(98, 11); std::cout << (char)(191); //Top right
                    gotoXY(98, 13); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 13); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    if (confirmpass != newpass)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 21);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 23);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 21; i <= 23; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 21); std::cout << (char)(218); //top left
                    gotoXY(98, 21); std::cout << (char)(191); //Top right
                    gotoXY(98, 23); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 23); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    y_old = y_temp;
                    y_temp = 26;
                    xp = x_temp + confirmpass.size();
                    yp = y_old;
                    break;
                }
                else if (c == BACKSPACE)
                {
                    if (confirmpass != "" && pos_confirm > 0)
                    {
                        std::cout << "\b \b";
                        confirmpass.pop_back();
                    }

                    if (confirmpass != newpass)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 21);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 23);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 21; i <= 23; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 21); std::cout << (char)(218); //top left
                    gotoXY(98, 21); std::cout << (char)(191); //Top right
                    gotoXY(98, 23); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 23); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    int len = confirmpass.size();
                    gotoXY(70 + len, 22);
                    SetColor1(14,0);
                }
                else if (c == LEFT)
                {
                    if (pos_confirm > 0)
                    {
                        pos_confirm--;
                        gotoXY(x_temp + pos_confirm + 2, y_temp + 1);
                    }

                    if (oldpass != password)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 11);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 13);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 11; i <= 13; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 11); std::cout << (char)(218); //top left
                    gotoXY(98, 11); std::cout << (char)(191); //Top right
                    gotoXY(98, 13); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 13); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    if (confirmpass != newpass)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 21);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 23);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 21; i <= 23; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 21); std::cout << (char)(218); //top left
                    gotoXY(98, 21); std::cout << (char)(191); //Top right
                    gotoXY(98, 23); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 23); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    gotoXY(x_temp + pos_confirm + 2, y_temp + 1);
                    SetColor1(14,0);

                    continue;
                }
                else if (c == RIGHT)
                {
                    int len = confirmpass.size();

                    if (pos_confirm < len)
                    {
                        pos_confirm++;
                        gotoXY(x_temp + pos_confirm + 2, y_temp + 1);
                    }

                    if (oldpass != password)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 11);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 13);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 11; i <= 13; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 11); std::cout << (char)(218); //top left
                    gotoXY(98, 11); std::cout << (char)(191); //Top right
                    gotoXY(98, 13); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 13); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    if (confirmpass != newpass)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 21);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 23);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 21; i <= 23; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 21); std::cout << (char)(218); //top left
                    gotoXY(98, 21); std::cout << (char)(191); //Top right
                    gotoXY(98, 23); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 23); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    gotoXY(x_temp + pos_confirm + 2, y_temp + 1);
                    SetColor1(14,0);

                    continue;
                }
                else
                {
                    int len = confirmpass.size();

                    if (c >= 32 && c <= 126 && len < 26)
                    {
                        pos_confirm++;
                        confirmpass += c;
                        std::cout << c;
                    }

                    if (confirmpass != newpass)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 21);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 23);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 21; i <= 23; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 21); std::cout << (char)(218); //top left
                    gotoXY(98, 21); std::cout << (char)(191); //Top right
                    gotoXY(98, 23); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 23); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    len = confirmpass.size();
                    gotoXY(70 + len, 22);
                    SetColor1(14,0);
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
            ShowConsoleCursor(false);

            if (oldpass != password)
                SetColor1(14,4);
            else
                SetColor1(14,0);

            //Create two horizontal lines
            for (int i = 68; i <= 98; ++i)
            {
                gotoXY(i, 11);
                std::cout << (char)(196); //196 is -
                gotoXY(i, 13);
                std::cout << (char)(196);
            }

            //Create two vertical lines
            for (int i = 11; i <= 13; ++i)
            {
                gotoXY(68, i);
                std::cout << (char)(179); //179 is |
                gotoXY(98, i);
                std::cout << (char)(179);
            }

            //Create 4 corners
            gotoXY(68, 11); std::cout << (char)(218); //top left
            gotoXY(98, 11); std::cout << (char)(191); //Top right
            gotoXY(98, 13); std::cout << (char)(217); //Bottom right
            gotoXY(68, 13); std::cout << (char)(192); //Bottom left
            ShowConsoleCursor(false);

            gotoXY(xp + 2, yp + 1);

            if (confirmpass != newpass)
                SetColor1(14,4);
            else
                SetColor1(14,0);

            //Create two horizontal lines
            for (int i = 68; i <= 98; ++i)
            {
                gotoXY(i, 21);
                std::cout << (char)(196); //196 is -
                gotoXY(i, 23);
                std::cout << (char)(196);
            }

            //Create two vertical lines
            for (int i = 21; i <= 23; ++i)
            {
                gotoXY(68, i);
                std::cout << (char)(179); //179 is |
                gotoXY(98, i);
                std::cout << (char)(179);
            }

            //Create 4 corners
            gotoXY(68, 21); std::cout << (char)(218); //top left
            gotoXY(98, 21); std::cout << (char)(191); //Top right
            gotoXY(98, 23); std::cout << (char)(217); //Bottom right
            gotoXY(68, 23); std::cout << (char)(192); //Bottom left
            ShowConsoleCursor(false);

            gotoXY(xp + 2, yp + 1);

            if (_kbhit())
            {
                char c = _getch();

                if (c == UP)
                {
                    ShowConsoleCursor(true);
                    y_temp = y_old;

                    if (oldpass != password)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 11);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 13);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 11; i <= 13; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 11); std::cout << (char)(218); //top left
                    gotoXY(98, 11); std::cout << (char)(191); //Top right
                    gotoXY(98, 13); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 13); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    gotoXY(xp + 2, yp + 1);

                    if (confirmpass != newpass)
                        SetColor1(14,4);
                    else
                        SetColor1(14,0);

                    //Create two horizontal lines
                    for (int i = 68; i <= 98; ++i)
                    {
                        gotoXY(i, 21);
                        std::cout << (char)(196); //196 is -
                        gotoXY(i, 23);
                        std::cout << (char)(196);
                    }

                    //Create two vertical lines
                    for (int i = 21; i <= 23; ++i)
                    {
                        gotoXY(68, i);
                        std::cout << (char)(179); //179 is |
                        gotoXY(98, i);
                        std::cout << (char)(179);
                    }

                    //Create 4 corners
                    gotoXY(68, 21); std::cout << (char)(218); //top left
                    gotoXY(98, 21); std::cout << (char)(191); //Top right
                    gotoXY(98, 23); std::cout << (char)(217); //Bottom right
                    gotoXY(68, 23); std::cout << (char)(192); //Bottom left
                    ShowConsoleCursor(false);

                    gotoXY(xp + 2, yp + 1);
                }
                else if (c == ENTER)
                {
                    opt = 0;
                    return;
                }
            }
        }
    }

    ofs.open("../Txt_Csv/temp.csv");
    if (!ofs)
    {
        cerr << "Error: Unable to open file for writing\n";
        return;
    }
    
    int len = User.size();
    for (int i = 0; i < len - 1; ++i)
    {
        if (User[i] != username)
            ofs << User[i] << "," << Pass[i] << "\n";
        else
            ofs << User[i] << "," << newpass << "\n";
    }
    if (User[len - 1] != username)
        ofs << User[len - 1] << "," << Pass[len - 1];
    else
        ofs << User[len - 1] << "," << newpass;

    ofs.close();

    //delete old file and rename temporary file to old file
    if (isStudent == true)
    {
        remove("../Txt_Csv/acc_student.csv");
        rename("../Txt_Csv/temp.csv", "../Txt_Csv/acc_student.csv");
    }
    else
    {
        remove("../Txt_Csv/acc_staff.csv");
        rename("../Txt_Csv/temp.csv", "../Txt_Csv/acc_staff.csv");
    }

    Create_A_Box_1(68,26,2,30,14,14,0,"   Change successfully ");
    for (int i = 0; i < 3; ++i)
    {
        gotoXY(92 + i,27);
        ShowConsoleCursor(false);
        std::cout << "." << flush;
        Sleep(500);
    }
}