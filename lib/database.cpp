#include "../headers/database.h"

//construct user
database::database(char *path){
    int res = sqlite3_open(path, &db);

    if(res){
        cout << "error can't connect to db\n";
        exit(1);
    }
}


//checks to see if user exists;

//0 if false
//1 if employee
//2 if manager
int database::auth_user(string username, string password){
    return 0;
}

//destructor
database::~database(){
    sqlite3_close(db);
    return;
}