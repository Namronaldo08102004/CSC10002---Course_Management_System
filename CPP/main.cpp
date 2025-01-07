#include "../Header/Staff.h"
#include "../Header/Student.h"

void getdata(Year* &year_head)
{
    year_head = getYearListFromFile(); //Get the list of years
    if (year_head)
    {
        Year* temp_year = year_head;
        while (temp_year)
        {
            temp_year->semester_head = getSemesterListFromFile(temp_year); //Get the list of semesters
            if (temp_year->semester_head)
            {
                Semester* temp_semester = temp_year->semester_head;
                while (temp_semester)
                {
                    temp_semester->course_head = getCourseListFromFile(temp_year, temp_semester);
                    if (temp_semester->course_head)
                    {
                        Course* temp_course = temp_semester->course_head;
                        while (temp_course)
                        {
                            temp_course->student_head = getStudentCourseFromFile(temp_year, temp_semester, temp_course);
                            temp_course = temp_course->course_next;
                        }
                    }

                    temp_semester = temp_semester->semester_next;
                }
            }

            string filename;
            filename = "class_" + temp_year->year_name + ".txt";
            filename = "../Txt_Csv/" + filename;
            temp_year->class_head = getClassListFromFile(temp_year, filename); //Get the list of classes
            if (temp_year->class_head)
            {
                Class* temp_class = temp_year->class_head;
                while (temp_class)
                {
                    temp_class->student_head = getStudentListFromFile(temp_year, temp_class);
                    temp_class = temp_class->next_class;
                }
            }

            temp_year = temp_year->year_next;
        }
    }
}

void deletedata (Year* &year_head)
{
    if (year_head)
    {
        Year* temp_year = year_head;
        while (temp_year)
        {
            if (temp_year->semester_head)
            {
                Semester* temp_semester = temp_year->semester_head;
                while (temp_semester)
                {
                    if (temp_semester->course_head)
                    {
                        Course* temp_course = temp_semester->course_head;
                        while (temp_course)
                        {
                            deallocateStudents(temp_course->student_head);
                            temp_course = temp_course->course_next;
                        }
                        deallocateCourses(temp_semester->course_head);
                    }

                    temp_semester = temp_semester->semester_next;
                }
                deallocateSemesters(temp_year->semester_head);
            }

            if (temp_year->class_head)
            {
                Class* temp_class = temp_year->class_head;
                while (temp_class)
                {
                    deallocateStudents(temp_class->student_head);
                    temp_class = temp_class->next_class;
                }
                deallocateClasses(temp_year->class_head);
            }

            temp_year = temp_year->year_next;
        }
        deallocateYears(year_head);
    }
}

int main()
{
    bool check;
    PlaySoundA("BackgroundMusic.wav", NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NOSTOP);
    int option = firstScreen(check);
    if (check == false) //Out the program
    {
        PlaySound(NULL, NULL, 0);
        return 0;
    }

    Year* year_head = nullptr;
    Myinterface(option, year_head); //Continue with 1 of 2 rest options
    PlaySound(TEXT("BackgroundMusic.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP | SND_NOSTOP);
    return 0;
}