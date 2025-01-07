#include "../Header/Staff.h"

Semester* getSemesterListFromFile(Year* &year_head)
{
    ifstream ifs;

    //Open file
    string file_name = year_head->year_name + "_semester.txt";
    file_name = "../Txt_Csv/" + file_name;
    ifs.open(file_name);
    if (!ifs.is_open())
    {
        //cerr << "Error: Unable to open file for reading\n";
        return nullptr;
    }

    //Get semester list from file
    year_head->semester_head = nullptr; Semester* temp = nullptr;
    string line;

    while (getline(ifs, line))
    {
        Semester* new_semester = new Semester;
        string tmp;
        stringstream ss(line);

        getline(ss, tmp, ',');
        new_semester->Semester_Ord = stoi(tmp);

        getline(ss, tmp, '/');
        new_semester->start_date.day = stoi(tmp);
        getline(ss, tmp, '/');
        new_semester->start_date.month = stoi(tmp);
        getline(ss, tmp, ',');
        new_semester->start_date.year = stoi(tmp);

        getline(ss, tmp, '/');
        new_semester->end_date.day = stoi(tmp);
        getline(ss, tmp, '/');
        new_semester->end_date.month = stoi(tmp);
        getline(ss, tmp, '/');
        new_semester->end_date.year = stoi(tmp);

        new_semester->course_head = nullptr;
        new_semester->semester_next = nullptr;

        if (!year_head->semester_head)
        {
            year_head->semester_head = new_semester;
            temp = year_head->semester_head;
        }
        else
        {
            temp->semester_next = new_semester;
            temp = temp->semester_next;
        }
    }

    //Close file and return created list
    ifs.close();
    return year_head->semester_head;
}