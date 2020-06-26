#include "../headers/employee.h"


//constructor
employee::employee(){
    return;
}

//destructor
employee::~employee(){
    return;
}

//loads information into the class
void employee::load_info(int argc, char**argv){

    for(int i = 0; i < argc; i++){

        switch(i){
            case 0:
                username = argv[i];
                break;           
            case 1:
                id = atoi(argv[i]);
                break;
            case 2:
                manager_id = atoi(argv[i]);
                break;
            case 3:
                password = argv[i];
                break;
            case 4:
                hours_current = atoi(argv[i]);
                break;

        }

    }
    //cout << id << " " << manager_id << "\n";

    if(id == manager_id){
        is_manager = true;
    }

    is_valid = true;

}

//will contain main loop and functions for employee login.
void employee::render_emp(){
    cout << "render employee = " << username << " hours = " << hours_current << "\n";
}


//will contain main loop and functions for manager login.
void employee::render_man(){
    cout << "render manager  = " << username << " hours = " << hours_current << "\n";
}

void employee::render(){


    //render based on if manager.
    if(is_manager){
        render_man();
    }
    else{
        render_emp();
    }


}