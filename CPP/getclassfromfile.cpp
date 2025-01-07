#include "../Header/Staff.h"

Class* getClassListFromFile(Year *&year_head, string filename)
{
    ifstream ifs;
    ifs.open(filename);
    if (!ifs.is_open())
    {
        //cerr << "Error: Unable to open file for reading\n";
        return nullptr;
    }
    year_head->class_head = nullptr;
    Class* temp = nullptr;
    string class_name;

    while (getline(ifs, class_name, '\n'))
    {
        Class* new_class = new Class;
        new_class->class_name = class_name;
        new_class->student_head = nullptr;
        new_class->next_class = nullptr;

        if (!year_head->class_head)
        {
            year_head->class_head = new_class;
            temp = year_head->class_head;
        }
        else
        {
            temp->next_class = new_class;
            temp = temp->next_class;
        }
    }

    ifs.close();
    return year_head->class_head;
}