#include "../headers/database.h"

//construct user
database::database(string path){
    int res = sqlite3_open(path.c_str(), &db);

    if(res){
        cout << "error can't connect to db\n";
        exit(1);
    }
}


static int callback(void* data, int argc, char** argv, char** azColName) 
{ 
    int i; 
    fprintf(stderr, "%s: ", (const char*)data); 
  
    for (i = 0; i < argc; i++) { 
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL"); 
    } 
  
    printf("\n"); 
    return 0; 
} 

//checks to see if user exists;

//ERROR if false
//EMPLOYEE if employee
//MANAGER if manager
int database::auth_user(string username, string password){

    string sql = "select * from employee where username = \"" + username + "\" and password = \"" + password + "\"";

    string data("CALLBACK FUNCTION"); 


    int rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data.c_str(), NULL); 
  
    if (rc != SQLITE_OK) 
        cerr << "Error SELECT" << endl; 
    else { 
        cout << "Operation OK!" << endl; 
    } 

    return 0;
}

//destructor
database::~database(){
    sqlite3_close(db);
    return;
}

