#ifndef PROCESS_H
#define PROCESS_h


#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <sqlite3.h>
#include <iostream>

#define MANAGER 2
#define EMPLOYEE 1
#define ERROR 0

using namespace std;

struct sql_ret{

    int size = -1;

    char **data = NULL;    

    void set(int a, char **b){
        size = a;
        data = b;
    }



};

class database {

    public:

        //constructor

        database(string path);

        //checks to see if user exists;
        //0 if false
        //1 if employee
        //2 if manager
        sql_ret *auth_user(string username, string password); //checks if user exists

        //decontructor

        ~database();

    private:
    
        sqlite3 *db;



};

#endif