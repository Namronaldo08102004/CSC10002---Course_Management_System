#include "../Header/Structures.h"

void deallocateStudents(Student *&head_student)
{
    while (head_student != nullptr)
    {
        Student *temp_student = head_student;
        head_student = head_student->student_next;
        Course *curr_course = temp_student->course_head;
        while (curr_course != nullptr)
        {
            Course *temp_course = curr_course;
            curr_course = curr_course->course_next;
            delete temp_course;
        } 
        delete temp_student;
    }
}