#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>


using namespace std;

class employee{


    public:
        //constructor
        employee();
        //destructor
        ~employee();

        void load_info(int argc, char**argv);

        void render_emp();
        void render_man();
        void render();

        bool is_valid = false;

    private:
        //user information

        string username;
        string password;

        int id;
        int manager_id;

        int hours_current;

        bool is_manager = false;
        

};


#endif


