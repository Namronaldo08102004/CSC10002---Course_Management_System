#include "../Header/Staff.h"

Student* getStudentListFromFile(Year *year_head, Class* class_head)
{
    string filename = class_head->class_name + "-" + year_head->year_name + ".txt";
    filename = "../Txt_Csv/" + filename;

    ifstream ifs;
    ifs.open(filename);
    if (!ifs.is_open())
    {
        cerr << "Error: Unable to open file for reading\n";
        return nullptr;
    }

    string ignore_line;
    getline(ifs, ignore_line);

    string official_line = ""; getline(ifs, official_line);
    if (official_line == "")
    {
        ifs.close();

        ifs.open("../Txt_Csv/student_info.csv");
        if (!ifs.is_open())
        {
            cerr << "Error: Unable to open file for reading\n";
            return nullptr;
        }

        std::ofstream ofs;
        string filename = class_head->class_name + "-" + year_head->year_name + ".txt";
        filename = "../Txt_Csv/" + filename;

        ofs.open(filename);
        if (!ofs.is_open())
        {
            ofs.close();
            return nullptr;
        }

        ofs << "student ID,student_socialID,student_fisrtname,student_lastname,gender,class_name,DOB\n";

        string dummy;
        getline(ifs, dummy);

        class_head->student_head = nullptr;
        Student* temp = nullptr;
        
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

            if (class_head->class_name == new_student->student_class.class_name)
            {
                addTail(class_head->student_head, new_student); 

                ofs << new_student->student_ID << "," << new_student->student_socialID << ","
                << new_student->student_fisrtname << "," << new_student->student_lastname << ","
                << new_student->gender << "," << new_student->student_class.class_name << ","
                << new_student->DOB.day << "/" << new_student->DOB.month << "/" << new_student->DOB.year << "\n";
            }
        }

        ifs.close();
        ofs.close();

        return class_head->student_head;
    }

    ifs.close();

    ifs.open(filename);
    if (!ifs.is_open())
    {
        // cerr << "Error: Unable to open file for reading\n";
        return nullptr;
    }

    string dummy;
    getline(ifs, dummy);

    class_head->student_head = nullptr;
    Student* temp = nullptr;
    
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

        addTail(class_head->student_head, new_student);
    }

    ifs.close();
    return class_head->student_head;
}