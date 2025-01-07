#include "../Header/Structures.h"

void deallocateCourses(Course *&head_course)
{
    while (head_course != nullptr)
    {
        Course *temp_course = head_course;
        head_course = head_course->course_next;
        Student *curr_student = temp_course->student_head;
        while (curr_student != nullptr)
        {
            Student *temp_student = curr_student;
            curr_student = curr_student->student_next;
            delete  temp_student;
        } 
        delete temp_course;
    }
}