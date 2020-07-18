#include <ctime>
#include <sstream>


struct cur_date{

    int month;
    int day;
    int year;
    
    double hour;
    double min;
    double sec;

    //begins with current date.
    cur_date(){
        std::time_t t = std::time(0);   // get time now
        std::tm* now = std::localtime(&t);

        month = now->tm_mon + 1;
        year = now->tm_year + 1900;
        day = now->tm_mday;

        
        hour = now->tm_hour;
        sec = now->tm_sec;
        min = now->tm_min;
     }

    string get_date(){

        stringstream ss;

        ss << month << "-" << day << "-" << year;

        return ss.str();
    }

    string get_time(){

        stringstream ss;

        ss << hour + (min / 60) + (sec / 360);

        return ss.str();

    }

};