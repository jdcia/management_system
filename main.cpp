#include "./headers/main.h"
#include "../headers/employee.h"

int main(){

    //connect to db
    database *db = new database("management.db");

    string username;

    string password;

    bool true_usr;

    while(true){
        //authenticate

        cout << "username: ";
        
        cin >> username;


        cout << "password: ";

        cin >> password;

        true_usr = db->auth_user(username, password);

        //check to see if valid user.
        if(true_usr == ERROR){
            continue;
        }
        else if(true_usr == EMPLOYEE){
            
        }
        else if(true_usr == MANAGER){

        }

        //load userspace based on management level

        
        //exit

    }

    return 0;
}