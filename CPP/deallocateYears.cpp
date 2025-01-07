#include "../Header/Structures.h"

void deallocateYears(Year *&year_head)
{
    while (year_head != nullptr)
    {
        Year *temp_year = year_head;
        year_head = year_head->year_next;
        deallocateSemesters(temp_year->semester_head);
        delete temp_year;
    }
}