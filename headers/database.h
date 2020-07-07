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

        //execs statement
        vector<string> *exec_statement(string sql); //checks if user exists

        //decontructor

        ~database();

    private:
    
        sqlite3 *db;



};

#endif