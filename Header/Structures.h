#ifndef Structures_h
#define Structures_h

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <regex>
#include <conio.h>
#include <vector>
#include <Windows.h>
#include <mmsystem.h>
using namespace std;

struct Scoreboard;
struct Course;
struct Student;
struct Class;
struct Semester;
struct Year;
struct Date;

struct Date
{
    unsigned int day, month, year;
};

struct Class
{
    string class_name;
    string class_id;
    Student *student_head; // Points to the Student
    Class *next_class; // Next class
};

struct Student
{   
    string student_ID;
    string student_socialID;
    string student_fisrtname;
    string student_lastname;
    Class student_class;
    bool gender; //0: Male, 1: Female
    Date DOB; // Date of Birth
    Course *course_head; // Points to the Course
    Student *student_next; // Next student
};

struct Course
{
    string teacher_name;
    string course_ID;
    string course_name;
    string class_name;
    int numCredits;
    int maxNumStudents; //default 50
    string dayInWeek;
    string Session;
    Scoreboard *scoreboard_head; //Points to the ScoreBoard
    Course *course_next; //Next Course
    Student *student_head; //Points to the student
};

struct Year
{
    string year_name;
    Class *class_head; //Points to the Class
    Semester *semester_head; //Points to the Semester
    Year *year_next; //Next Year
};

struct Semester
{
    unsigned int Semester_Ord; //Ordinal number
    Date start_date;
    Date end_date;
    Course *course_head; //Points to the Course
    Semester *semester_next; //Next Semester
};

struct Scoreboard
{
    float total_mark;
    float midterm_mark;
    float final_mark;
    float other_mark;
    Student *student_head;
};

//Implementation with user's input
void getdata(Year* &year_head);
void deletedata(Year* &year_head);

//Authentication functions
bool isLoggedIn();
void login(bool isStudent, string &username, bool &opt);
void logout();

//Password management function
void changePass(string username, bool isStudent, int& opt);

//Screen functions
int firstScreen(bool &check);
void viewSchoolYear_Screen(string username, Year* &year_head);
void Main_Staff_Screen(string &username, Year* &year_head);
void Main_Student_Screen(string username);
void Myinterface(int option, Year* &year_head);

//Memory management functions
void deallocateCourses(Course *&head_course);
void deallocateStudents(Student *&head_student);
void deallocateClasses(Class *&class_head);
void deallocateSemesters(Semester *&head_semester);
void deallocateYears(Year *&year_head);

//Helper function
void addTail(Student* &student_head, Student* tmp);
void getDate(Student* &tmp , string date_string);
string printDate(Date a);

//Main function
int main();
#endif