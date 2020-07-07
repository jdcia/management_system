#include "../headers/database.h"

//construct user
database::database(string path){

    //open data base using sqllite3.
    int res = sqlite3_open(path.c_str(), &db);

    //check connection
    if(res){
        cout << "error can't connect to db\n";
        exit(1);
    }
}

//clean this up
int callback(void* data, int argc, char** argv, char** azColName) 
{ 
    //if statement returns data
    if(argc > 0){
        //add each piece of data return from statement to string vector.
        for (int i = 0; i < argc; i++) { 
            static_cast <vector<string> *>(data)->push_back(string(argv[i]));
        }
        
    }
    
    return 0; 
} 

//checks to see if user exists;
vector<string> *database::exec_statement(string sql){

    //allocate return data.
    vector<string> *data = new vector<string>;

    //exec sql statement.
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

