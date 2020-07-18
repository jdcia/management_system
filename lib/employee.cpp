#include "../headers/employee.h"


//constructor
employee::employee(vector<string> data, database *d){

    db = d; //set database
    
    //process employee data
    for(int i = 0; i < data.size(); i++){

        switch(i){
            case 0:
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

    //check if manager
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

        //main selection screen
        cout << "Please select an Action\n";
        cout << "1 : show user info\n";
        cout << "2 : clock in/out\n";
        cout << "3 : check current hours\n";
        cout << "4 : shows current tasks\n";
        cout << "0 : exit\n";

        //get action input
        cin >> user_in;

        //preform task based on input
        switch(user_in){

                //show user info.
            case 1:
                cout << "Name: " << username << "\n";
                cout << "ID: " << id << "\n";
                cout << "Manager ID:" << manager_id << "\n";
                break;

            case 2: 
                //clock in
                clock_timecard();
                break;

            case 3:
                //submit time card.
                check_curr();
                break;

            case 4:
                show_projs();
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

        //manager action selection list.
        cout << "Please select an Action\n";
        cout << "1 : show user info\n";
        cout << "2 : clock in/out\n";
        cout << "3 : check current hours\n";
        cout << "4 : show team\n";
        cout << "5 : show projects\n";
        cout << "6 : add employee to project\n";
        cout << "0 : exit\n";

        //get user input
        cin >> user_in;

        //preform task based on input
        switch(user_in){

                //show user info.
            case 1:
                cout << "Name: " << username << "\n";
                cout << "ID: " << id << "\n";
                cout << "Manager ID:" << manager_id << "\n";

                break;

            case 2: 
                //clock in
                clock_timecard();
                break;

            case 3:
                //submit time card.
                check_curr();
                break;

            case 4:
                show_projs();
                break; 
            case 5:
                show_team();
                break;
            case 6:
                add_to_proj();
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

void employee::clock_timecard(){
    cout << "Clock timecard\n";

    //get current time
    cur_date cur_time = cur_date();

    cout << "current date = " << cur_time.get_date() << "\n";
    cout << "current time = " << cur_time.get_time() << "\n";

    //check to see if user clocked in today. If so update with clockout time.

    //retrieve current users.
    vector<string> * data = db->exec_statement("select * from timecard where emp_id = " + to_string(id) + " and date = \"" + cur_time.get_date() + "\" and clock_out is NULL"); //insert statement to time cards for todays date.


    if(data->empty()){
        //create new time card
        //choose project to change too
        cout << "create new timecard\n";
        data = db->exec_statement(""); //insert statement to create new time card;
    }
    else{
        //update timecards with end date.
        cout << "Update timecard\n";
        data = db->exec_statement(""); //update timecard for todays date. 
        //NOTE: This will override existing end date
    }

    return;
}

void employee::check_curr(){
    cout << "check current hours\n";
    return;
}

void employee::show_projs(){
    cout << "show current projects\n";
    return;
}

void employee::show_team(){
    cout << "show team members\n";
    return;
}

void employee::add_to_proj(){
    cout << "add employee to project\n";
    return;
}