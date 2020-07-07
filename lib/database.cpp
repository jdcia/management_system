#include "../headers/database.h"

//construct user
database::database(string path){
    int res = sqlite3_open(path.c_str(), &db);

    if(res){
        cout << "error can't connect to db\n";
        exit(1);
    }
}

//clean this up
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
    if(argc > 0){
        for (i = 0; i < argc; i++) { 
            static_cast <vector<string> *>(data)->push_back(string(argv[i]));
        }
        
    }
    
    //printf("\n"); 
    return 0; 
} 

//checks to see if user exists;
vector<string> *database::exec_statement(string sql){

    //string sql = "select * from employee where username = \"" + username + "\" and password = \"" + password + "\"";

    vector<string> *data = new vector<string>;

    int rc = sqlite3_exec(db, sql.c_str(), callback, (void*)data, NULL); 
    if (rc != SQLITE_OK) 
        cerr << "Error SELECT" << endl; 

    return data;
}

//destructor
database::~database(){
    sqlite3_close(db);
    return;
}

