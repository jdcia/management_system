#include "../headers/database.h"

//construct user
database::database(string path){
    int res = sqlite3_open(path.c_str(), &db);

    if(res){
        cout << "error can't connect to db\n";
        exit(1);
    }
}


int callback(void* data, int argc, char** argv, char** azColName) 
{ 
    int i; 

    //cout << argc << " asdf\n";
  
    // for (i = 0; i < argc; i++) { 
    //     printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL"); 
    // } 

    // cout << "argc = " << argc << "\n";
    // cout << "arg1 = " << argv[1] << "\n";
    // cout << "arg2 = " << argv[2] << "\n";
    if(argc > 3 && stoi(argv[1]) == stoi(argv[2])){
        *(int *)data = MANAGER;
    }
    else if (argc > 3){
        *(int *)data = EMPLOYEE;
    }
  
    //printf("\n"); 
    return 0; 
} 

//checks to see if user exists;

//ERROR if false
//EMPLOYEE if employee
//MANAGER if manager
int database::auth_user(string username, string password){

    string sql = "select * from employee where username = \"" + username + "\" and password = \"" + password + "\"";

    int data = ERROR;

    int rc = sqlite3_exec(db, sql.c_str(), callback, (void*)&data, NULL); 
  
    if (rc != SQLITE_OK) 
        cerr << "Error SELECT" << endl; 
    else { 
        cout << "Operation OK!" << endl; 
    } 

    if(data == ERROR){
        cout << "USER not found\n";
    }
    else if(data == EMPLOYEE){
        cout << "Employee logged in\n";
    }
    else if(data == MANAGER){
        cout << "Manager logged in\n";
    }

    return 0;
}

//destructor
database::~database(){
    sqlite3_close(db);
    return;
}

