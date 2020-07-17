#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include "database.h"
#include <ctime>


using namespace std;

struct date{

    int month;
    int day;
    int year;

    date(int a , int b, int c){
            year = a;
            month = b;
            day = c;
    }

    string str(){

        stringstream ss;

        ss << month << "-" << day << "-" << year;

        return ss.str();
    }



};

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
        date get_date();

        //manager
        void show_team();
        void add_to_proj();

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


