#include "./headers/main.h"

int main(){

    //connect to db
    database *db = new database("management.db");

    string username;

    string password;

    employee *current_user;

    vector<string> * data;

    while(true){
        //authenticate

        cout << "username: ";
        
        cin >> username;


        cout << "password: ";

        cin >> password;

        data = db->auth_user(username, password);

        //check to see if valid user.
        if(data->empty()){
            cout << "Error incorrect login info\n";
            continue;
        }

        current_user = new employee(*data, db);

        //load userspace based on management level
        current_user->render();
        
        //exit

    }

    return 0;
}