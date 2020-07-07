#ifndef PROCESS_H
#define PROCESS_h


#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>
#include <iostream>
#include <vector>

#define MANAGER 2
#define EMPLOYEE 1
#define ERROR 0

using namespace std;

class database {

    public:

        //constructor

        database(string path);

        //checks to see if user exists;
        //0 if false
        //1 if employee
        //2 if manager
        vector<string> *auth_user(string username, string password); //checks if user exists

        void clock_user(int emp_id);

        //decontructor

        ~database();

    private:
    
        sqlite3 *db;



};

#endif