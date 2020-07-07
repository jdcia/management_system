#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "database.h"


using namespace std;

class employee{


    public:
        //constructor
        employee(vector<string> data);
        //destructor
        ~employee();

        void render_emp();
        void render_man();
        void render();

    private:

        //database db;
        //user information

        string username;
        string password;

        int id;
        int manager_id;

        int hours_current;

        bool is_manager = false;
        

};


#endif


