#ifndef Student_h
#define Student_h

#include "Structures.h"

//view info function
void student_info(string username);

//Scoreboard function
void viewScoreBoard_Student(string username);

//Authentication functions
bool isLoggedIn();
void login(bool isStudent, string &username);

#endif