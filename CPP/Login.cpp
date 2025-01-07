#include "../Header/Staff.h"
#include "../Header/Student.h"
#include "../Header/Design.h"

bool isLoggedIn() {
    // Check whether the user is currently logged in by checking the isLoggedIn.txt file
    ifstream file("../Txt_Csv/isLoggedIn.txt");
    string line;
    getline(file, line);
    file.close();
    return (line == "1");
}

void login(bool isStudent, string &username, bool &opt) 
{
    ShowConsoleCursor(true);
    // Check whether the login information is correct by comparing it with the acc_student.csv file or acc_staf.csv
    if (isStudent)
    {   
        opt = 1;
        resizeConsole(1920,920);
        system("color E0");

        gotoXY(43,2);
        std::cout << "   _____ _____ _   _______ _____ _   _ _____      _     _____ _____     _____ _   _";
        gotoXY(43,3);
        std::cout << "  /  ___|_   _| | | |  _  \\  ___| \\ | |_   _|    | |   |  _  |  __ \\   |_   _| \\ | |";
        gotoXY(43,4);
        std::cout << "  \\ `--.  | | | | | | | | | |__ |  \\| | | |______| |   | | | | |  \\/_____| | |  \\| |";
        gotoXY(43,5);
        std::cout << "   `--. \\ | | | | | | | | |  __|| . ` | | |______| |   | | | | | _|______| | | . ` |";
        gotoXY(43,6);
        std::cout << "  /\\__/ / | | | |_| | |/ /| |___| |\\  | | |      | |___\\ \\_/ / |_\\ \\    _| |_| |\\  |";
        gotoXY(43,7);
        std::cout << "  \\____/  \\_/  \\___/|___/ \\____/\\_| \\_/ \\_/      \\_____/\\___/ \\____/    \\___/\\_| \\_/";

        username = ""; std::string password = ""; int count = 0;

        Create_A_Box_2(68,11,2,30,14,14,0,"USERNAME");
        Create_A_Box_2(68,16,2,30,14,14,0,"PASSWORD");

        Create_A_Box_1(40,20,2,20,14,14,0,"    RETURN BACK");
        ShowConsoleCursor(false);

        int x_temp = 68; int y_temp = 11; int y_old; int xp = x_temp; int yp = y_temp; int pos_user = 0; int pos_pass = 0;
        while (count < 2)
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
                        if (username != "")
                            count++;

                        if (password == "")
                            y_temp = 16;
                        xp = 68;
                        yp = y_temp;
                        break;
                    }
                    else if (c == DOWN)
                    {
                        ShowConsoleCursor(false);
                        y_old = y_temp;
                        y_temp = 20;
                        xp = x_temp + username.size();
                        yp = y_old;
                        break;
                    }
                    else if (c == BACKSPACE)
                    {
                        if (username != "" && pos_user > 0)
                        {
                            std::cout << "\b \b";
                            username.pop_back();
                        }
                    }
                    else if (c == LEFT)
                    {
                        if (pos_user > 0)
                        {
                            pos_user--;
                            gotoXY(x_temp + pos_user + 2, y_temp + 1);
                        }

                        continue;
                    }
                    else if (c == RIGHT)
                    {
                        int len = username.size();

                        if (pos_user < len)
                        {
                            pos_user++;
                            gotoXY(x_temp + pos_user + 2, y_temp + 1);
                        }

                        continue;
                    }
                    else
                    {
                        int len = username.size();

                        if (c >= 32 && c <= 126 && len < 26)
                        {
                            pos_user++;
                            username += c;
                            std::cout << c;
                        }
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
                        if (password != "")
                            count++;

                        if (username == "")
                            y_temp = 11;

                        xp = 68;
                        yp = y_temp;
                        break;
                    }
                    else if (c == DOWN)
                    {
                        ShowConsoleCursor(false);
                        y_old = y_temp;
                        y_temp = 20;
                        xp = x_temp + password.size();
                        yp = y_old;
                        break;
                    }
                    else if (c == BACKSPACE)
                    {
                        if (password != "" && pos_pass > 0)
                        {
                            std::cout << "\b \b";
                            password.pop_back();
                        }
                    }
                    else if (c == LEFT)
                    {
                        if (pos_pass > 0)
                        {
                            pos_pass--;
                            gotoXY(x_temp + pos_pass + 2, y_temp + 1);
                        }

                        continue;
                    }
                    else if (c == RIGHT)
                    {
                        int len = password.size();

                        if (pos_pass < len)
                        {
                            pos_pass++;
                            gotoXY(x_temp + pos_pass + 2, y_temp + 1);
                        }

                        continue;
                    }
                    else
                    {
                        int len = password.size();

                        if (c >= 32 && c <= 126 && len < 26)
                        {
                            pos_pass++;
                            password += c;
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
                        opt = 0; bool check = false;
                        system("cls");
                        main();
                        return;

                    }
                }
            }
        }

        fstream file("../Txt_Csv/acc_student.csv");
        string line;
        getline(file, line);  // Skip the first line of the file as it is a header
        while (getline(file, line)) 
        {
            if (line.substr(0, line.find(',')) == username) {
                string passwordFromFile = line.substr(line.find(',') + 1);
                if (password == passwordFromFile) {
                    // If the login is successful, write the login status to the isLoggedIn.txt file and exit the function
                    ofstream file("../Txt_Csv/isLoggedIn.txt");
                    file << "1";
                    file.close();

                    Create_A_Box_1(68,24,2,30,14,14,0,"   Log in successfully ");
                    for (int i = 0; i < 3; ++i)
                    {
                        gotoXY(92 + i,25);
                        ShowConsoleCursor(false);
                        std::cout << "." << flush;
                        Sleep(500);
                    }

                    return;
                }
            }
        }
    }
    else
    {
        opt = 1;
        resizeConsole(1920,920);
        system("color E0");

        gotoXY(48,2);
        std::cout << "   _____ _____ ___ ____________      _     _____ _____     _____ _   _";
        gotoXY(48,3);
        std::cout << "  /  ___|_   _/ _ \\|  ___|  ___|    | |   |  _  |  __ \\   |_   _| \\ | |";
        gotoXY(48,4);
        std::cout << "  \\ `--.  | |/ /_\\ \\ |_  | |_ ______| |   | | | | |  \\/_____| | |  \\| |";
        gotoXY(48,5);
        std::cout << "   `--. \\ | ||  _  |  _| |  _|______| |   | | | | | _|______| | | . ` |";
        gotoXY(48,6);
        std::cout << "  /\\__/ / | || | | | |   | |        | |___\\ \\_/ / |_\\ \\    _| |_| |\\  |";
        gotoXY(48,7);
        std::cout << "  \\____/  \\_/\\_| |_|_|   \\_|        \\_____/\\___/ \\____/    \\___/\\_| \\_/";

        username = ""; std::string password = ""; int count = 0;

        Create_A_Box_2(68,11,2,30,14,14,0,"USERNAME");
        Create_A_Box_2(68,16,2,30,14,14,0,"PASSWORD");

        Create_A_Box_1(40,20,2,20,14,14,0,"    RETURN BACK");
        ShowConsoleCursor(false);

        int x_temp = 68; int y_temp = 11; int y_old; int xp = x_temp; int yp = y_temp; int pos_user = 0; int pos_pass = 0;
        while (count < 2)
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
                        if (username != "")
                            count++;

                        if (password == "")
                            y_temp = 16;

                        xp = 68;
                        yp = y_temp;
                        break;
                    }
                    else if (c == DOWN)
                    {
                        ShowConsoleCursor(false);
                        y_old = y_temp;
                        y_temp = 20;
                        xp = x_temp + username.size();
                        yp = y_old;
                        break;
                    }
                    else if (c == BACKSPACE)
                    {
                        if (username != "" && pos_user > 0)
                        {
                            std::cout << "\b \b";
                            username.pop_back();
                        }
                    }
                    else if (c == LEFT)
                    {
                        int len = username.size();

                        if (pos_user > 0)
                        {
                            pos_user--;
                            gotoXY(x_temp + pos_user + 2, y_temp + 1);
                        }

                        continue;
                    }
                    else if (c == RIGHT)
                    {
                        int len = username.size();

                        if (pos_user < len)
                        {
                            pos_user++;
                            gotoXY(x_temp + pos_user + 2, y_temp + 1);
                        }

                        continue;
                    }
                    else
                    {
                        int len = username.size();

                        if (c >= 32 && c <= 126 && len < 26)
                        {
                            pos_user++;
                            username += c;
                            std::cout << c;
                        }
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
                        if (password != "")
                            count++;

                        if (username == "")
                            y_temp = 11;
                        
                        xp = 68;
                        yp = y_temp;
                        break;
                    }
                    else if (c == DOWN)
                    {
                        ShowConsoleCursor(false);
                        y_old = y_temp;
                        y_temp = 20;
                        xp = x_temp + password.size();
                        yp = y_old;
                        break;
                    }
                    else if (c == BACKSPACE)
                    {
                        if (password != "" && pos_pass > 0)
                        {
                            std::cout << "\b \b";
                            password.pop_back();
                        }
                    }
                    else if (c == LEFT)
                    {
                        int len = password.size();

                        if (pos_pass > 0)
                        {
                            pos_pass--;
                            gotoXY(x_temp + pos_pass + 2, y_temp + 1);
                        }

                        continue;
                    }
                    else if (c == RIGHT)
                    {
                        int len = password.size();

                        if (pos_pass < len)
                        {
                            pos_pass++;
                            gotoXY(x_temp + pos_pass + 2, y_temp + 1);
                        }

                        continue;
                    }
                    else
                    {
                        int len = password.size();

                        if (c >= 32 && c <= 126 && len < 26)
                        {
                            pos_pass++;
                            password += c;
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
                        opt = 0; bool check = false;
                        system("cls");
                        main();
                        return;
                    }
                }
            }
        }

        fstream file("../Txt_Csv/acc_staff.csv");
        string line;
        getline(file, line);  // Skip the first line of the file as it is a header
        while (getline(file, line)) 
        {
            if (line.substr(0, line.find(',')) == username) 
            {
                string passwordFromFile = line.substr(line.find(',') + 1);
                if (password == passwordFromFile) {
                    // If the login is successful, write the login status to the isLoggedIn.txt file and exit the function
                    ofstream file("../Txt_Csv/isLoggedIn.txt");
                    file << "1";
                    file.close();

                    Create_A_Box_1(68,24,2,30,14,14,0,"   Log in successfully ");
                    for (int i = 0; i < 3; ++i)
                    {
                        gotoXY(92 + i,25);
                        ShowConsoleCursor(false);
                        std::cout << "." << flush;
                        Sleep(500);
                    }

                    return;
                }
            }
        }
    }   

    // If the login is unsuccessful, display an error message and request the user to login again
    system("cls");
    Create_A_Box_1(64,20,2,38,14,14,4,"     Incorrect login information!");
    ShowConsoleCursor(false);
	login(isStudent, username, opt);
}

void logout() 
{
    // Write the logout status to the isLoggedIn.txt file
    ofstream file("../Txt_Csv/isLoggedIn.txt");
    file << "0";
    file.close();
}