#include "../headers/database.h"

//construct user
database::database(string path){
    int res = sqlite3_open(path.c_str(), &db);

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

    cout << username << "\n";

    cout << password << "\n";

    return 0;
}

//destructor
database::~database(){
    sqlite3_close(db);
    return;
}