
#include "Admin.hpp"
#include "loadDataFunctions.hpp"
#include "management.h"
#include <iostream>
#include <vector>

using namespace std;
/**
 *This is a Parking Lot System written in C++
 *System call the loadParkingLotData which reads in the data store in the vector container. User is prompt to 
 1:login into the system
 2: Register New User - Prompts the user to enter different details like Name, ID, Password, Car information like, Make, Mode, Year and License Plate
 3: Exit the program, Based on the input option, program prompts user to enter credentials untill correct input is done.
 When administrator is logged in, program lets the user to choose specific option for the admin user.
 Similarly, Management and User prompts are done
 None: Currenlty Only Admin section is completed
 Author:
 		Raju Gajmer 
 Final Milestone completed
 Class group prject completed by Stetson and Raju
 */
int main()
{
      
	Admin adminObj;// object of admin is created so its function is accessed in the main
    Management mObj; //Object of the Management class
    //four vectors container are created to store the data.
	vector <admin> adminVec; // Vector to store data of admin type
	vector <management> mgmtVec; // Vector to store data of management type
    vector <user> userVec; // Vector to store data of user type
    vector <ticket> ticketVec; // Vector to store data of ticket type
    //Function call to display parkingLot space format and store Admin, management and user data in passed vector which is done by reference.
	loadParkingLotData(adminVec, mgmtVec, userVec);
	
	//lOGIN INTO THE SYSTEM
	/**	This function lets user decide which action to perfor
		1: Login into the system
		2: Register new user into the system
		3: Exit the program
	*/
	 int choice = 0;
  	 bool flag = true;
   	//Create login options
    while(flag == true){
      cout << endl;
      cout <<"************Parking Lot System************" << endl;
      cout <<"Type option 1 => Login in the system \n";
      cout <<"Type option 2 => Register a new user \n"; //Only Test option
      cout <<"Type option 3 => Exit the system \n";
      cout <<"Option: ";
      cin >> choice;     //Take input from user and pass it to switch which takes user based on chosen option
      switch(choice){

          case 1:
			  //Promt user to enter the type of login account
			  cout << endl <<"*******LOGGIN IN!!******\n";
			  adminObj.login(adminVec, mgmtVec, userVec, ticketVec);
			  break;
          case 2:
              // Call register new user function
              cout << endl << "*********Register New User Window********" << endl;
              adminObj.registerNewUser(userVec);
              break;
          case 3:
              // Exit the program
              cout <<endl << "**********EXITING PROGRAM**********" << endl;
              flag = false;
              break;

          default:
             cout <<" \nWrong Input!! Try Again!!\n\n"; 
      }
    }           
	
	 
 return 0;
} //End of program
