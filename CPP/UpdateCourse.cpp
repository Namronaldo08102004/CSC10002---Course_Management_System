#include "../Header/Staff.h"
#include "../Header/Design.h"

void viewUpdateCourseInformation (string username, Year* year_head, Semester* semester_head)
{
    system("cls");
    resizeConsole(1920,920);
    system("color E0");

    Create_A_Box_3(1,5,30,90);

    gotoXY(3,6);
    std::cout << "   _____ _____ _   _______  _____ _____ ___";
    gotoXY(3,7);
    std::cout << "  /  __ \\  _  | | | | ___ \\/  ___|  ___/ _ \\";
    gotoXY(3,8);
    std::cout << "  | /  \\/ | | | | | | |_/ /\\ `--.| |__/ /_\\ \\";
    gotoXY(3,9);
    std::cout << "  | |   | | | | | | |    /  `--. \\  __|  _  |";
    gotoXY(3,10);
    std::cout << "  | \\__/\\ \\_/ / |_| | |\\ \\ /\\__/ / |__| | | |";
    gotoXY(3,11);
    std::cout << "   \\____/\\___/ \\___/\\_| \\_|\\____/\\____|_| |_/";

    gotoXY(25,17);
    std::cout << "   _   _______ ________  ____   __";
    gotoXY(25,18);
    std::cout << "  | | | |  _  \\  ___|  \\/  \\ \\ / /";
    gotoXY(25,19);
    std::cout << "  | | | | | | | |__ | .  . |\\ V /";
    gotoXY(25,20);
    std::cout << "  | | | | | | |  __|| |\\/| | \\ /";
    gotoXY(25,21);
    std::cout << "  | |_| | |/ /| |___| |  | | | |";
    gotoXY(25,22);
    std::cout << "   \\___/|___/ \\____/\\_|  |_/ \\_/";

    gotoXY(50,28);
    std::cout << "   _____ _____ _   __  ___";
    gotoXY(50,29);
    std::cout << "  |_   _|  ___| | / / /   |";
    gotoXY(50,30);
    std::cout << "    | | | |__ | |/ / / /| |";
    gotoXY(50,31);
    std::cout << "    | | |  __||    \\/ /_| |";
    gotoXY(50,32);
    std::cout << "    | | | |___| |\\  \\___  |";
    gotoXY(50,33);
    std::cout << "    \\_/ \\____/\\_| \\_/   |_/";

    gotoXY(93,2);
    std::cout << " _   _____________  ___ _____ _____   _____ _____ _   _______  _____ _____";
    gotoXY(93,3);
    std::cout << "| | | | ___ \\  _  \\/ _ \\_   _|  ___| /  __ \\  _  | | | | ___ \\/  ___|  ___|";
    gotoXY(93,4);
    std::cout << "| | | | |_/ / | | / /_\\ \\| | | |__   | /  \\/ | | | | | | |_/ /\\ `--.| |__";
    gotoXY(93,5);
    std::cout << "| | | |  __/| | | |  _  || | |  __|  | |   | | | | | | |    /  `--. \\  __|";
    gotoXY(93,6);
    std::cout << "| |_| | |   | |/ /| | | || | | |___  | \\__/\\ \\_/ / |_| | |\\ \\ /\\__/ / |___";
    gotoXY(93,7);
    std::cout << " \\___/\\_|   |___/ \\_| |_/\\_/ \\____/   \\____/\\___/ \\___/\\_| \\_|\\____/\\____/";

    Course* cur = semester_head->course_head; int numCourses = 0;
    while (cur)
    {
        numCourses++;
        cur = cur->course_next;
    }

    if (numCourses == 0)
    {
        Create_A_Box_1(118,13,2,20,14,14,0,"    RETURN BACK");
        ShowConsoleCursor(false);

        bool flag = true;
        while (true)
        {
            if (flag == true)
            {
                system("color E0");
                SetColor1(15,0);
                for (int j = 119; j <= 137; ++j)
                {
                    gotoXY(j, 14);
                    std::cout << " ";
                }

                gotoXY(119, 14);
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
                        accessSemester(username, year_head, semester_head);
                        return;
                    }
                }
            }
        }
    }
    else
    {
        int pages;
        if (numCourses % 6 == 0)
            pages = numCourses/6;
        else
            pages = numCourses/6 + 1;

        Create_A_Box_1(118,37,2,20,14,14,0,"    RETURN BACK");
        ShowConsoleCursor(false);

        int curpage = 1;
        while (curpage <= pages)
        {
            for (int i = 108; i <= 170; ++i)
            {
                for (int j = 11; j <= 33; ++j)
                {
                    gotoXY(i,j);
                    std::cout << " ";
                }
            }

            for (int i = 0; i <= min(5,numCourses - 6*(curpage - 1) - 1); ++i)
            {
                Create_A_Box_3 (108,11 + 4*i,2,40);
            }

            gotoXY(126,35);
            std::cout << (char)(17) << " " << curpage << "/" << pages << " " << (char)(16);

            cur = semester_head->course_head;
            for (int i = 1; i <= 6*(curpage - 1); ++i)
            {
                cur = cur->course_next;
            }

            Course* temp = cur;
            for (int i = 0; i <= min(5,numCourses - 6*(curpage - 1) - 1); ++i)
            {
                gotoXY(111,12 + 4*i);
                std::cout << temp->course_name << "-" << temp->course_ID << "_" << temp->class_name;
                temp = temp->course_next;
            }

            int x_temp = 108; int y_temp = 11;
            bool flag = true;
            while (true)
            {
                if (flag == true)
                {
                    for (int i = 11; i <= 11 + 4*min(5,numCourses - 6*(curpage - 1) - 1); i += 4)
                    {
                        if (y_temp == i)
                        {
                            system("color E0");
                            SetColor1(15,0);
                            for (int j = x_temp + 1; j <= x_temp + 39; ++j)
                            {
                                gotoXY(j, y_temp + 1);
                                std::cout << " ";
                            }

                            gotoXY(x_temp + 3, y_temp + 1);

                            Course* tempCourse = cur;
                            for (int i = 0; i < (y_temp - 11)/4; ++i)
                            {
                                tempCourse = tempCourse->course_next;
                            } 

                            std::cout << tempCourse->course_name << "-" << tempCourse->course_ID << "_" << tempCourse->class_name;
                            ShowConsoleCursor(false);
                        }
                    }

                    if (y_temp == 37)
                    {
                        system("color E0");
                        SetColor1(15,0);
                        for (int j = 119; j <= 137; ++j)
                        {
                            gotoXY(j, 38);
                            std::cout << " ";
                        }

                        gotoXY(119, 38);
                        std::cout << "    RETURN BACK";
                        ShowConsoleCursor(false);
                    }
        
                    flag = false;
                }
                else
                {
                    if (_kbhit())
                    {
                        char c = _getch();
        
                        for (int i = 11; i <= 11 + 4*min(5,numCourses - 6*(curpage - 1) - 1); i += 4)
                        {
                            if (y_temp == i)
                            {
                                system("color E0");
                                SetColor1(14,0);
                                for (int j = x_temp + 1; j <= x_temp + 39; ++j)
                                {
                                    gotoXY(j, y_temp + 1);
                                    std::cout << " ";
                                }

                                gotoXY(x_temp + 3, y_temp + 1);

                                Course* tempCourse = cur;
                                for (int i = 0; i < (y_temp - 11)/4; ++i)
                                {
                                    tempCourse = tempCourse->course_next;
                                } 

                                std::cout << tempCourse->course_name << "-" << tempCourse->course_ID << "_" << tempCourse->class_name;
                                ShowConsoleCursor(false);
                            }
                        }

                        if (y_temp == 37)
                        {
                            system("color E0");
                            SetColor1(14,0);
                            for (int j = 119; j <= 137; ++j)
                            {
                                gotoXY(j, 38);
                                std::cout << " ";
                            }

                            gotoXY(119, 38);
                            std::cout << "    RETURN BACK";
                            ShowConsoleCursor(false);
                        }
        
                        flag = true;
        
                        if (c == UP)
                        {
                            if (y_temp == 11)
                                y_temp = 37;
                            else if (y_temp == 37)
                                y_temp = 11 + 4*min(5,numCourses - 6*(curpage - 1) - 1);
                            else
                                y_temp -= 4;
                        }
                        else if (c == DOWN)
                        {
                            if (y_temp == 37)
                                y_temp = 11;
                            else if (y_temp == 11 + 4*min(5,numCourses - 6*(curpage - 1) - 1))
                                y_temp = 37;
                            else
                                y_temp += 4;
                        }
                        else if (c == LEFT)
                        {
                            if (curpage > 1)
                                curpage--;

                            break;
                        }
                        else if (c == RIGHT)
                        {
                            if (curpage < pages)
                                curpage++;

                            break;
                        }
                        else if (c == ENTER)
                        {
                            if (y_temp == 37)
                            {
                                system("cls");
                                accessSemester(username, year_head, semester_head);
                                return;
                            }
                            else
                            {
                                Course* temp_course = cur;
                                for (int j = 0; j < (y_temp - 11)/4; ++j)
                                {
                                    temp_course = temp_course->course_next;
                                }

                                system("cls");
                                updateACourse(username, year_head, semester_head, temp_course);
                                return;
                            }
                        }
                    }
                }
            }
        }

        ShowConsoleCursor(false);
    }
}

void updateACourse (string username, Year* year_head, Semester* semester_head, Course* course_head)
{
    system("cls");
    resizeConsole(1920,920);
    system("color E0");

    gotoXY(48,2);
    std::cout << " _   _____________  ___ _____ _____   _____ _____ _   _______  _____ _____";
    gotoXY(48,3);
    std::cout << "| | | | ___ \\  _  \\/ _ \\_   _|  ___| /  __ \\  _  | | | | ___ \\/  ___|  ___|";
    gotoXY(48,4);
    std::cout << "| | | | |_/ / | | / /_\\ \\| | | |__   | /  \\/ | | | | | | |_/ /\\ `--.| |__";
    gotoXY(48,5);
    std::cout << "| | | |  __/| | | |  _  || | |  __|  | |   | | | | | | |    /  `--. \\  __|";
    gotoXY(48,6);
    std::cout << "| |_| | |   | |/ /| | | || | | |___  | \\__/\\ \\_/ / |_| | |\\ \\ /\\__/ / |___";
    gotoXY(48,7);
    std::cout << " \\___/\\_|   |___/ \\_| |_/\\_/ \\____/   \\____/\\___/ \\___/\\_| \\_|\\____/\\____/";

    Create_A_Box_1(71,10,2,30,14,14,0,"  UPDATE COURSE INFORMATION");
    Create_A_Box_1(71,14,2,30,14,14,0,"     UPLOAD STUDENT FILE");
    Create_A_Box_1(71,18,2,30,14,14,0,"        ADD A STUDENT");
    Create_A_Box_1(71,22,2,30,14,14,0,"       REMOVE A STUDENT");
    Create_A_Box_1(71,26,2,30,14,14,0,"        DELETE COURSE");
    Create_A_Box_1(71,30,2,30,14,14,0,"         RETURN BACK");
    ShowConsoleCursor(false);
    
    int x_temp = 71; int y_temp = 10;
    bool flag = true;
    while (true)
    {
        if (flag == true)
        {
            if (y_temp == 10)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "  UPDATE COURSE INFORMATION";
                ShowConsoleCursor(false);
            }
            else if (y_temp == 14)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "     UPLOAD STUDENT FILE";
                ShowConsoleCursor(false);
            }
            else if (y_temp == 18)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "        ADD A STUDENT";
                ShowConsoleCursor(false);
            }
            else if (y_temp == 22)
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "       REMOVE A STUDENT";
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
                std::cout << "        DELETE COURSE";
                ShowConsoleCursor(false);
            }
            else
            {
                system("color E0");
                SetColor1(15,0);
                for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                {
                    gotoXY(i, y_temp + 1);
                    std::cout << " ";
                }

                gotoXY(x_temp + 1, y_temp + 1);
                std::cout << "         RETURN BACK";
                ShowConsoleCursor(false);
            }

            flag = false;
        }
        else
        {
            if (_kbhit())
            {
                char c = _getch();
                flag = true;
                
                if (y_temp == 10)
                {
                    system("color E0");
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "  UPDATE COURSE INFORMATION";
                    ShowConsoleCursor(false);
                }
                else if (y_temp == 14)
                {
                    system("color E0");
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "     UPLOAD STUDENT FILE";
                    ShowConsoleCursor(false);
                }
                else if (y_temp == 18)
                {
                    system("color E0");
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "        ADD A STUDENT";
                    ShowConsoleCursor(false);
                }
                else if (y_temp == 22)
                {
                    system("color E0");
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "       REMOVE A STUDENT";
                    ShowConsoleCursor(false);
                }
                else if (y_temp == 26)
                {
                    system("color E0");
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "        DELETE COURSE";
                    ShowConsoleCursor(false);
                }
                else
                {
                    system("color E0");
                    SetColor1(14,0);
                    for (int i = x_temp + 1; i <= x_temp + 29; ++i)
                    {
                        gotoXY(i, y_temp + 1);
                        std::cout << " ";
                    }

                    gotoXY(x_temp + 1, y_temp + 1);
                    std::cout << "         RETURN BACK";
                    ShowConsoleCursor(false);
                }

                if (c == UP)
                {
                    if (y_temp == 10)
                        y_temp = 30;
                    else
                        y_temp -= 4;
                }
                else if (c == DOWN)
                {
                    if (y_temp == 30)
                        y_temp = 10;
                    else
                        y_temp += 4;
                }
                else if (c == ENTER)
                {
                    ShowConsoleCursor(true);
                    if (y_temp == 10)
                    {
                        system("cls");
                        updateInformationOfCourse(username, year_head, semester_head, course_head);
                        return;
                    }
                    else if (y_temp == 14)
                    {
                        system ("cls");
                        uploadStudentFileToCourse(username, year_head, semester_head, course_head);
                        return;
                    }
                    else if (y_temp == 18)
                    {
                        system("cls");
                        addStudentToCourse(username, course_head, year_head, semester_head);
                        return;
                    }
                    else if (y_temp == 22)
                    {
                        system("cls");
                        removeStudentFromCourse(username, course_head, year_head, semester_head);
                        return;
                    }
                    else if (y_temp == 26)
                    {
                        system("cls");
                        deleteCourse(username, course_head ,year_head , semester_head);
                        return; 
                    }
                    else
                    {
                        system("cls");
                        viewUpdateCourseInformation(username, year_head, semester_head);
                        return;
                    }

                    break;
                }
            }
        }
    }
}