#include "../Header/Staff.h"

Year* getYearListFromFile()
{
    ifstream ifs;

    //Open file
    ifs.open("../Txt_Csv/schoolyear.txt");
    if (!ifs.is_open())
    {
        //cerr << "Error: Unable to open file for reading\n";
        return nullptr;
    }

    Year* year_head = nullptr; Year* temp = nullptr;
    string year_name;

    while (getline(ifs, year_name))
    {
        Year* new_year = new Year;
        new_year->year_name = year_name;
        new_year->class_head = nullptr;
        new_year->semester_head = nullptr;
        new_year->year_next = nullptr;

        if (!year_head)
        {
            year_head = new_year;
            temp = year_head;
        }
        else
        {
            temp->year_next = new_year;
            temp = temp->year_next;
        }
    }

    ifs.close();
    return year_head;
}