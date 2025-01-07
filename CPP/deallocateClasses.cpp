#include "../Header/Structures.h"

void deallocateClasses(Class *&class_head)
{
    while (class_head != nullptr)
    {
        Class *temp_class = class_head;
        class_head = class_head->next_class;
        deallocateStudents(temp_class->student_head);
        delete temp_class;
    }
}