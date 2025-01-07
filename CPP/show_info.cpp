#include "../Header/Staff.h"
#include "../Header/Student.h"
#include "../Header/Design.h"

void staff_info(string username, Year* &year_head)
{
    ifstream ifs;
    ifs.open("../Txt_Csv/staff_info.csv");
    if (!ifs.is_open())
    {
        cout << "Cannot open file";
        return;
    }

    string ignore_line;
    getline(ifs, ignore_line);
    string username_staff; string fullname; string gmail; string phonenumber; string DOB;

    while (getline(ifs, ignore_line))
    {
        //find the username
        size_t pos = ignore_line.find(',');
        string first_column = ignore_line.substr(0, pos);

        if (username == first_column)
        {
            stringstream ss(ignore_line);
            string field;
            int count = 1;
            while (getline(ss, field, ','))
            {
                if (count == 1)
                {
                    username_staff = field;
                    count++;
                }
                else if (count == 2)
                {
                    fullname = field;
                    count++;
                }
                else if (count == 3)
                {
                    gmail = field;
                    count++;
                }
                else if (count == 4)
                {
                    phonenumber = field;
                    count++;
                }
                else if (count == 5)
                {
                    DOB = field;
                    count++;
                }
            }
        }
    }
    ifs.close();

    resizeConsole(1920,920);
    system("color E0");

    Create_A_Box_3(1,1,40,83);
    ShowConsoleCursor(false);

    gotoXY(2,2);
    std::cout << "                                      ......";
    gotoXY(2,3);
    std::cout << "                              .:^~!!!77777777!!~^:.";
    gotoXY(2,4);
    std::cout << "                           :^!77?????7777777??????7!~:.";
    gotoXY(2,5);
    std::cout << "                        .^!7??777777777777777777777???7~:";
    gotoXY(2,6);
    std::cout << "                       ^7??7777777777777777777777777777?7!:'";
    gotoXY(2,7);
    std::cout << "                     :7?777777777777777777777777777777777?7~'";
    gotoXY(2,8);
    std::cout << "                    ^??777777777777777777777777777777777777?!";
    gotoXY(2,9);
    std::cout << "                   :?777777777777777777777777777777777777777?!";
    gotoXY(2,10);
    std::cout << "                   !?7777777777777777777777777777777777777777?^";
    gotoXY(2,11);
    std::cout << "                  :777777777777777777777777777777777777777777?!";
    gotoXY(2,12);
    std::cout << "                  :?77777777777777777777777777777777777777777?!";
    gotoXY(2,13);
    std::cout << "                  .777777777777777777777777777777777777777777?~";
    gotoXY(2,14);
    std::cout << "                   !?7777777777777777777777777777777777777777?:";
    gotoXY(2,15);
    std::cout << "                   .7?77777777777777777777777777777777777777?~";
    gotoXY(2,16);
    std::cout << "                    :7?77777777777777777777777777777777777??~";
    gotoXY(2,17);
    std::cout << "                     .~7?7777777777777777777777777777777??7:";
    gotoXY(2,18);
    std::cout << "                       :!7??77777777777777777777777777??7^";
    gotoXY(2,19);
    std::cout << "                         .^!7???777777777777777777???7!:";
    gotoXY(2,20);
    std::cout << "            .:^^~~!!!^:     .^!77???????????????77!~:.    .^~!!~~~^:.";
    gotoXY(2,21);
    std::cout << "         .^!7??????????7~^.     .:^^~~!!!!!!~~^:..    .:~!7?????????77~:.";
    gotoXY(2,22);
    std::cout << "       :!7??777777777777??7!~^:.                 ..:~!7???77777777777???7~.";
    gotoXY(2,23);
    std::cout << "     .!??777777777777777777????77!!~^^^^:^^^^~~!!77???7777777777777777777?7^";
    gotoXY(2,24);
    std::cout << "    :7?77777777777777777777777777????????????????77777777777777777777777777?!.";
    gotoXY(2,25);
    std::cout << "   ^7?7777777777777777777777777777777777777777777777777777777777777777777777?!.";
    gotoXY(2,26);
    std::cout << "  :77777777777777777777777777777777777777777777777777777777777777777777777777?!";
    gotoXY(2,27);
    std::cout << "  !?77777777777777777777777777777777777777777777777777777777777777777777777777?:";
    gotoXY(2,28);
    std::cout << "  :77777777777777777777777777777777777777777777777777777777777777777777777777?~";
    gotoXY(2,29);
    std::cout << "   ^?77777777777777777777777777777777777777777777777777777777777777777777777?!";
    gotoXY(2,30);
    std::cout << "    ^7?77777777777777777777777777777777777777777777777777777777777777777777?~";
    gotoXY(2,31);
    std::cout << "     :7?77777777777777777777777777777777777777777777777777777777777777777?7~";
    gotoXY(2,32);
    std::cout << "      .!??77777777777777777777777777777777777777777777777777777777777777?7:";
    gotoXY(2,33);
    std::cout << "        :7??7777777777777777777777777777777777777777777777777777777777?7~.";
    gotoXY(2,34);
    std::cout << "          ^7??777777777777777777777777777777777777777777777777777777?7~.";
    gotoXY(2,35);
    std::cout << "           .^!??7777777777777777777777777777777777777777777777777??7~.";
    gotoXY(2,36);
    std::cout << "              :~7???777777777777777777777777777777777777777777??7!^.";
    gotoXY(2,37);
    std::cout << "                .:~77??77777777777777777777777777777777777???7!^.";
    gotoXY(2,38);
    std::cout << "                    :^!77????77777777777777777777777????77!~:.";
    gotoXY(2,39);
    std::cout << "                        .:~!!77???????????????????777!~^:.";
    gotoXY(2,40);
    std::cout << "                             ..::^^~~~~~~~~~~~^^^:..";

    gotoXY(103,1);
    std::cout << "  ____________ ___________ _____ _     _____";
    gotoXY(103,2);
    std::cout << "  | ___ \\ ___ \\  _  |  ___|_   _| |   |  ___|";
    gotoXY(103,3);
    std::cout << "  | |_/ / |_/ / | | | |_    | | | |   | |__";
    gotoXY(103,4);
    std::cout << "  |  __/|    /| | | |  _|   | | | |   |  __|";
    gotoXY(103,5);
    std::cout << "  | |   | |\\ \\\\ \\_/ / |    _| |_| |___| |___";
    gotoXY(103,6);
    std::cout << "  \\_|   \\_| \\_|\\___/\\_|    \\___/\\_____|____/";

    Create_A_Box_4(111,10,2,30,14,14,0,"USERNAME",username_staff);
    Create_A_Box_4(111,15,2,30,14,14,0,"FULL NAME",fullname);
    Create_A_Box_4(111,20,2,30,14,14,0,"GMAIL",gmail);
    Create_A_Box_4(111,25,2,30,14,14,0,"PHONE NUMBER",phonenumber);
    Create_A_Box_4(111,30,2,30,14,14,0,"DATE OF BIRTH",DOB);
    ShowConsoleCursor(false);

    Create_A_Box_1(135,35,2,20,15,14,0,"    RETURN BACK");

    bool flag = true;
    
    while (true)
    {
        if (flag)
        {
            SetColor1(15,0);
            for (int i = 136; i <= 154; ++i)
            {
                gotoXY(i, 36);
                std::cout << " ";
            }

            gotoXY(136, 36);
            std::cout << "    RETURN BACK";
            ShowConsoleCursor(false);
            flag = false;
        }
        else
        {
            if (_kbhit())
            {
                char c = _getch();
                flag = true;

                if (c == ENTER)
                {
                    system("cls");
                    Main_Staff_Screen(username, year_head);
                    return;
                }
            }
        }
    }
}

void student_info(string username)
{
    ifstream ifs;
    ifs.open("../Txt_Csv/student_info.csv");
    if(!ifs.is_open())
    {
        cout << "Cannot open file";
        return;
    }

    //Ignore the first line
    string ignore_line;
    getline(ifs, ignore_line);
    string id, social, fullname, gender, dob, class_room;

    while(getline(ifs, ignore_line))
    {
        //find the username
        size_t pos = ignore_line.find(',');
        string first_column = ignore_line.substr(0, pos);
    

        if(username == first_column)
        {
            stringstream ss(ignore_line);
            string field;
            int count = 1;
            while(getline(ss, field, ','))
            {
                if(count == 1)
                {
                    id = field;
                    count++;
                }
                else if(count == 2)
                {
                    social = field;
                    count++;
                }
                else if(count == 3)
                {
                    fullname = field;
                    getline(ss, field, ',');
                    fullname += " " + field;
                    count++;
                }
                else if(count == 4)
                {
                    cout << "\nGender: ";
                    if(field == "0")
                    {
                        gender = "Male";
                    }
                    else
                    {
                        gender = "Female";
                    }   
                    count++;
                }
                else if(count == 5)
                {
                    class_room = field;
                    count++;
                }
                else if(count == 6)
                {
                    dob = field;
                    count++;
                }
            }
        }
    }
    ifs.close();
    resizeConsole(1920,920);
    system("color E0");

    Create_A_Box_3(1,1,40,83);
    ShowConsoleCursor(false);

    gotoXY(2,2);
    std::cout << "                                      ......";
    gotoXY(2,3);
    std::cout << "                              .:^~!!!77777777!!~^:.";
    gotoXY(2,4);
    std::cout << "                           :^!77?????7777777??????7!~:.";
    gotoXY(2,5);
    std::cout << "                        .^!7??777777777777777777777???7~:";
    gotoXY(2,6);
    std::cout << "                       ^7??7777777777777777777777777777?7!:'";
    gotoXY(2,7);
    std::cout << "                     :7?777777777777777777777777777777777?7~'";
    gotoXY(2,8);
    std::cout << "                    ^??777777777777777777777777777777777777?!";
    gotoXY(2,9);
    std::cout << "                   :?777777777777777777777777777777777777777?!";
    gotoXY(2,10);
    std::cout << "                   !?7777777777777777777777777777777777777777?^";
    gotoXY(2,11);
    std::cout << "                  :777777777777777777777777777777777777777777?!";
    gotoXY(2,12);
    std::cout << "                  :?77777777777777777777777777777777777777777?!";
    gotoXY(2,13);
    std::cout << "                  .777777777777777777777777777777777777777777?~";
    gotoXY(2,14);
    std::cout << "                   !?7777777777777777777777777777777777777777?:";
    gotoXY(2,15);
    std::cout << "                   .7?77777777777777777777777777777777777777?~";
    gotoXY(2,16);
    std::cout << "                    :7?77777777777777777777777777777777777??~";
    gotoXY(2,17);
    std::cout << "                     .~7?7777777777777777777777777777777??7:";
    gotoXY(2,18);
    std::cout << "                       :!7??77777777777777777777777777??7^";
    gotoXY(2,19);
    std::cout << "                         .^!7???777777777777777777???7!:";
    gotoXY(2,20);
    std::cout << "            .:^^~~!!!^:     .^!77???????????????77!~:.    .^~!!~~~^:.";
    gotoXY(2,21);
    std::cout << "         .^!7??????????7~^.     .:^^~~!!!!!!~~^:..    .:~!7?????????77~:.";
    gotoXY(2,22);
    std::cout << "       :!7??777777777777??7!~^:.                 ..:~!7???77777777777???7~.";
    gotoXY(2,23);
    std::cout << "     .!??777777777777777777????77!!~^^^^:^^^^~~!!77???7777777777777777777?7^";
    gotoXY(2,24);
    std::cout << "    :7?77777777777777777777777777????????????????77777777777777777777777777?!.";
    gotoXY(2,25);
    std::cout << "   ^7?7777777777777777777777777777777777777777777777777777777777777777777777?!.";
    gotoXY(2,26);
    std::cout << "  :77777777777777777777777777777777777777777777777777777777777777777777777777?!";
    gotoXY(2,27);
    std::cout << "  !?77777777777777777777777777777777777777777777777777777777777777777777777777?:";
    gotoXY(2,28);
    std::cout << "  :77777777777777777777777777777777777777777777777777777777777777777777777777?~";
    gotoXY(2,29);
    std::cout << "   ^?77777777777777777777777777777777777777777777777777777777777777777777777?!";
    gotoXY(2,30);
    std::cout << "    ^7?77777777777777777777777777777777777777777777777777777777777777777777?~";
    gotoXY(2,31);
    std::cout << "     :7?77777777777777777777777777777777777777777777777777777777777777777?7~";
    gotoXY(2,32);
    std::cout << "      .!??77777777777777777777777777777777777777777777777777777777777777?7:";
    gotoXY(2,33);
    std::cout << "        :7??7777777777777777777777777777777777777777777777777777777777?7~.";
    gotoXY(2,34);
    std::cout << "          ^7??777777777777777777777777777777777777777777777777777777?7~.";
    gotoXY(2,35);
    std::cout << "           .^!??7777777777777777777777777777777777777777777777777??7~.";
    gotoXY(2,36);
    std::cout << "              :~7???777777777777777777777777777777777777777777??7!^.";
    gotoXY(2,37);
    std::cout << "                .:~77??77777777777777777777777777777777777???7!^.";
    gotoXY(2,38);
    std::cout << "                    :^!77????77777777777777777777777????77!~:.";
    gotoXY(2,39);
    std::cout << "                        .:~!!77???????????????????777!~^:.";
    gotoXY(2,40);
    std::cout << "                             ..::^^~~~~~~~~~~~^^^:..";

    gotoXY(103,1);
    std::cout << "  ____________ ___________ _____ _     _____";
    gotoXY(103,2);
    std::cout << "  | ___ \\ ___ \\  _  |  ___|_   _| |   |  ___|";
    gotoXY(103,3);
    std::cout << "  | |_/ / |_/ / | | | |_    | | | |   | |__";
    gotoXY(103,4);
    std::cout << "  |  __/|    /| | | |  _|   | | | |   |  __|";
    gotoXY(103,5);
    std::cout << "  | |   | |\\ \\\\ \\_/ / |    _| |_| |___| |___";
    gotoXY(103,6);
    std::cout << "  \\_|   \\_| \\_|\\___/\\_|    \\___/\\_____|____/";

    Create_A_Box_4(111,10,2,30,14,14,0,"STUDENT ID",id);
    Create_A_Box_4(111,15,2,30,14,14,0,"FULL NAME",fullname);
    Create_A_Box_4(111,20,2,30,14,14,0,"SOCIAL ID",social);
    Create_A_Box_4(111,25,2,15,14,14,0,"CLASS",class_room);
    Create_A_Box_4(130,25,2,11,14,14,0,"GENDER",gender);
    Create_A_Box_4(111,30,2,30,14,14,0,"DATE OF BIRTH",dob);
    ShowConsoleCursor(false);

    Create_A_Box_1(135,35,2,20,15,14,0,"    RETURN BACK");

    bool flag = true;
    
    while (true)
    {
        if (flag)
        {
            SetColor1(15,0);
            for (int i = 136; i <= 154; ++i)
            {
                gotoXY(i, 36);
                std::cout << " ";
            }

            gotoXY(136, 36);
            std::cout << "    RETURN BACK";
            ShowConsoleCursor(false);
            flag = false;
        }
        else
        {
            if (_kbhit())
            {
                char c = _getch();
                flag = true;

                if (c == ENTER)
                {
                    system("cls");
                    Main_Student_Screen(username);
                    return;
                }
            }
        }
    }
}