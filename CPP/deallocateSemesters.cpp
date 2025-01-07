#include "../Header/Structures.h"

void deallocateSemesters(Semester *&head_semester)
{
    while (head_semester != nullptr)
    {
        Semester *temp_semester = head_semester;
        head_semester = head_semester->semester_next;
        deallocateCourses(temp_semester->course_head);
        delete temp_semester;
    }
}