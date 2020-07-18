#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "database.h"
#include "date.h"

using namespace std;


class employee{


    public:
        //constructor
        employee(vector<string> data, database *d);
        //destructor
        ~employee();

        void render_emp();
        void render_man();
        void render();

    private:

        //functions

        //base
        void clock_timecard();
        void check_curr();
        void show_projs();

        //manager
        void show_team();
        void add_to_proj();

        //cur_time
        cur_date cur_time();

        //variables

        database *db;
        //user information

        string username;
        string password;

        int id;
        int manager_id;

        int hours_current;

        bool is_manager = false;
        

};


#endif


