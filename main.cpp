#include "../headers/main.h"

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

        if(!true_usr{
            continue;
        }

        //load userspace based on management level

        
        //exit

    }

    return 0;
}