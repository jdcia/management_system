#include "../headers/employee.h"


//constructor
employee::employee(vector<string> data){
    
    for(int i = 0; i < data.size(); i++){

        //cout << argv[i] << "\n";

        switch(i){
            case 0:
                //cout << "asdf" << (string)argv[i] << "\n";
                username = data[i];
                break;           
            case 1:
                id = atoi(data[i].c_str());
                break;
            case 2:
                manager_id = atoi(data[i].c_str());
                break;
            case 3:
                password = data[i];
                break;
            case 4:
                hours_current = atoi(data[i].c_str());
                break;

        }

    }
    //cout << id << " " << manager_id << "\n";

    if(id == manager_id){
        is_manager = true;
    }

}

//destructor
employee::~employee(){
    return;
}

//will contain main loop and functions for employee login.
void employee::render_emp(){

    int user_in;

    while(true){

        cout << "Please select an Action\n";
        cout << "1 : show user info\n";
        cout << "2 : clock in/out\n";
        cout << "3 : check current hours\n";
        cout << "0 : exit\n";

        cin >> user_in;

        switch(user_in){

                //show user info.
            case 1:
                cout << "Name: " << username << "\n";
                cout << "ID: " << id << "\n";
                cout << "Manager ID:" << manager_id << "\n";
                break;

            case 2: 
                //clock in
                cout << "Clock toggle selected\n";
                break;

            case 3:
                //submit time card.
                cout << "Current hours selected\n";
                break;

            case 0:
                //exit program
                exit(0);
                break;
            default:
                cout << "Invalid option";
                break;

        }

    }
}


//will contain main loop and functions for manager login.
void employee::render_man(){
 int user_in;

    while(true){

        cout << "Please select an Action\n";
        cout << "1 : show user info\n";
        cout << "2 : clock in/out\n";
        cout << "3 : check current hours\n";
        cout << "4 : show team\n";
        cout << "0 : exit\n";

        cin >> user_in;

        switch(user_in){

                //show user info.
            case 1:
                cout << "Name: " << username << "\n";
                cout << "ID: " << id << "\n";
                cout << "Manager ID:" << manager_id << "\n";

                break;

            case 2: 
                //clock in
                cout << "Option 2 selected\n";
                break;

            case 3:
                //submit time card.
                cout << "Option 3 selected\n";
                break;

            case 4:
                cout << "Option 4 selected\n";
                break; 

            case 0:
                //exit program
                exit(0);
                break;
            default:
                cout << "Invalid option";
                break;

        }

    }}

void employee::render(){


    //render based on if manager.
    if(is_manager){
        render_man();
    }
    else{
        render_emp();
    }


}