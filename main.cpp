#include "./headers/main.h"
#include "./headers/employee.h"

int main(){

    //connect to db
    database *db = new database("management.db");

    string username;

    string password;

    while(true){
        //authenticate

        cout << "username: ";
        
        cin >> username;


        cout << "password: ";

        cin >> password;

        auto current_user = db->auth_user(username, password);

        //check to see if valid user.
        if(!current_user->is_valid){
            continue;
        }

        //load userspace based on management level
        current_user->render();
        
        //exit

    }

    return 0;
}