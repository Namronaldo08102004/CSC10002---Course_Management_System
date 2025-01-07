#include "../Header/Staff.h"
#include "../Header/Design.h"

Student* getStudentCourseFromFile(Year* &year_head, Semester* &semester_head, Course* &course_head);

Student* getStudentCourseFromFile(Year* &year_head, Semester* &semester_head, Course* &course_head)
{
    ifstream ifs;
    //convert semester_head->Semester_Ord to string
    char ch_semester = static_cast<char>(semester_head->Semester_Ord + 48);
    string filename = "../Txt_Csv/" + course_head->course_ID + "_Semester" + ch_semester + "_" + course_head->class_name + "_" + year_head->year_name  + "_student.csv";
    ifs.open(filename);
    if (!ifs.is_open())
    {
        // cerr << "ERROR: UNABLE TO OPEN FILE FOR READING\n";
        return nullptr;
    }
    course_head->student_head = nullptr;
    Student* temp = nullptr;
    string dummy;
    getline(ifs, dummy);

    string line;
    while (getline(ifs, line))
    {
        string tmp;
        stringstream ss(line);
        
        Student* new_student = new Student;
        getline(ss, tmp, ',');
        new_student->student_ID = tmp;
        getline(ss, tmp, ',');
        new_student->student_socialID = tmp;
        getline(ss, tmp, ',');
        new_student->student_fisrtname = tmp;
        getline(ss, tmp, ',');
        new_student->student_lastname = tmp;
        getline(ss, tmp, ',');
        new_student->gender = stoi(tmp);
        getline(ss, tmp, ',');
        new_student->student_class.class_name = tmp;
        getline(ss, tmp, '\n');
        getDate(new_student, tmp);
        new_student->course_head = nullptr;
        new_student->student_next = nullptr;

        addTail(course_head->student_head, new_student);
    }

    ifs.close();
    return course_head->student_head;
}