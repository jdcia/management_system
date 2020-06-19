#ifndef PROCESS_H
#define PROCESS_h

#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>
#include <iostream>

using namespace std;

class database {

    public:

        //constructor

        database(char * path);

        //checks to see if user exists;

        //0 if false
        //1 if employee
        //2 if manager
        int auth_user(string username, string password); //checks if user exists

        //decontructor

        ~database();


    private:
    
        sqlite3 *db;

};

#endif