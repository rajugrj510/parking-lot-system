#include "Admin.hpp"
#include "management.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;

Management mObj; // Management class object to to get functionalities for the management user
long loggedInId;// Global variable to check who is currently checked in as a USER)  
  /**
   * This function creates a Prompt for registering user in the database
   * Prompts the user to enter different details like Name, ID, Password, 
   * Car information like, Make, Mode, Year and License Plate
   * and Store them in USER database
   * Parameter: a vector of user type is passed by reference
   */
  void Admin::registerNewUser(vector <user>& userVector){
    user userVar;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, userVar.userName);
    cout <<"\nEnter ID: ";
    cin >> userVar.userID;
    cout << "\nEnter Password: ";
    cin.ignore();
    getline(cin, userVar.userPassword);
    cout << "\nNow Enter your Vechicle information ... ";
    cout << "\nEnter Vechicle make: ";
    cin >> userVar.carMake;
    cout << "\nEnter Vechicle model: ";
    cin >>userVar.carModel;
    cout << "\nEnter Vechicle year: ";
    cin >> userVar.carYear;
    cout << "\nEnter Vechicle Plate nuber: ";
    cin >> userVar.licensePlate;

    userVector.push_back(userVar);
    cout <<"\nRegistration is complete.";
    
  } 
  //****************************ADMINISTRATOR FUNCTIONALITIES BEGIN*******************
  /**
   * This Function creates menu for Administrator user and prompts user to type one option
   * Based on that option, user is allowed to perform spection task 
   * Finally, in each case of switch, adminmenu() function is recursively called to admin menu prompt is given utill user log out
   * Parameter is a vector of admin, management and user type passed by reference
   * No return value
   */
  void Admin::adminMenu(vector <admin>& adminVector, vector <management>& mgmtVector, vector <user>& userVector){
    int choice = 0;
    long randomNum; 
    cout <<"\n****************ADMIN MENU REACHED**********************" << endl;
    cout <<"\nType Option 1: Add new administrative employee.";
    cout <<"\nType Option 2: Remove new administrative employee.";
    cout <<"\nType Option 3: View all administrative employee information(excluding password.)";
    cout <<"\nType Option 4: Search information for specific administrative employee.";
    cout <<"\nType Option 5: Change password of the account you are currently logged in.";
    cout <<"\nType Option 6: Add new management employee.";
    cout <<"\nType Option 7: Remove new management employee.";
    cout <<"\nType Option 8: View all management employee information(excluding password).";
    cout <<"\nType Option 9: Search information for specific management employee.";
    cout <<"\nType Option 10: Remove user.";
    cout <<"\nType Option 11: View all user info(excluding password)";
    cout <<"\nType Option 12: Search information for specific user.  ";
    cout <<"\nType Option 13: Logout"<< endl;
    cout <<"Option: ";
    cin >> choice;
    switch(choice){

          case 1:
              //Add new Adminstrative employee to database
              cout << endl <<"ADDING NEW Adminstrative employee";
              //call random number generator function
              randomNum = generateRandomID(adminVector, mgmtVector, userVector, 'A'); // Generating random number between the range for admin ID
              addAdmin(adminVector, randomNum);
              adminMenu(adminVector, mgmtVector, userVector);
              break;
          case 2:
              //Add new Adminstrative employee to database
              cout << endl <<"Removing NEW Adminstrative employee";
              //call add  function
              removeAdmin(adminVector);
              adminMenu(adminVector, mgmtVector, userVector);
              break;
          case 3:
              // View administrative employee information
              cout << endl << "VIEWING administrative employee information" << endl;
              //call view function
              viewAdmin(adminVector);
              adminMenu(adminVector, mgmtVector, userVector);
              break;
          case 4:
              //Search new Adminstrative employee to database
              cout << endl <<"SEARCHING information for specific administrative employee.";
              //call search  function
              searchAdmin(adminVector);
              adminMenu(adminVector, mgmtVector, userVector);
              break;
          case 5:
              //Change password
              cout << endl <<"Changing Password.";
              //call changepassword function
              changeAdminPassword(adminVector);
              adminMenu(adminVector, mgmtVector, userVector);
              break;
          case 6:
              //Add new management employee to database
              cout <<endl << "ADDING Management employee information!!" << endl;
              //call random number generator function
              randomNum = generateRandomID(adminVector, mgmtVector, userVector, 'M'); // Generating random number between the range for Management ID
              addManagement(mgmtVector, randomNum);
              adminMenu(adminVector, mgmtVector, userVector);
              break;
          case 7:
              //Remove Management employee to database
              cout << endl <<"Removing new management employee";
              //call removing function
              removeManagement(mgmtVector);
              adminMenu(adminVector, mgmtVector, userVector);
              break;
          case 8:
              //View all management employee informations
              cout << endl <<"Viewing all management employee information(excluding password).";
              //call view function
              viewManagement(mgmtVector);
              adminMenu(adminVector, mgmtVector, userVector);
              break;
          case 9:
              // seach a specific data of a management employee
              cout << endl << "Searching information for specific management employee." << endl;
              //call search function function
              searchmanagement(mgmtVector);
              adminMenu(adminVector, mgmtVector, userVector);
              break;
          case 10:
              // remove user from database
              cout << endl <<"Removing a user..";
              mObj.removeUser(userVector);
              adminMenu(adminVector, mgmtVector, userVector);
              break;
          case 11:
              // view all user info(excluding password)
              cout << endl << "Displaying all user info(excluding password)";
              mObj.viewUser(userVector);
              adminMenu(adminVector, mgmtVector, userVector);
              break;
          case 12:
              // search for specific user data
              cout << endl << "Searching information for specific user." << endl;
              mObj.searchUser(userVector);
              adminMenu(adminVector, mgmtVector, userVector);
              break;
          case 13:
              cout <<"\n*******Logging out*******" <<endl;
              break;

          default:
             cout <<" \nWrong Input!! Try Again!!\n\n";
             adminMenu(adminVector, mgmtVector, userVector); 
      }

  }
     /**
      * This function creates random Id for Admin, Management and user after
      * verify if generated random number already exist or not
      * Parameter is a vector of admin, management and user type passed by reference
      * @return the generated random number of type long
      */ 
     long Admin::generateRandomID(vector <admin> adminVector, vector <management> mgmtVector, vector <user> userVector, char user){
       srand((unsigned) time(0));
       cout <<"\n******Checking DATABASE FOR ID REDUNDANCY!!******";
        int redundant = 0;// to check if same ID is created by random number generator
        long randomNum; // variable to store randomly generated value
        switch(user){ //check cases which user is trying to generate random ID
              case 'A':
                    cout <<"\nGenerating random ID for New Admin User";
                    randomNum  = (rand() % (500 + 1 - 101)) + 101;  //generate a random number between 101 and 500(inclusive) and assign to randomNum
                    for(int i = 0; i < adminVector.size(); ++i){//Loop through the admin database container to check if generated ID already exist
                        if(adminVector[i].adminID  == randomNum){
                            ++redundant;
                          }      
                    }
                    if(redundant == 1){ //Recursive loop if randomly greated ID Matches
                         cout <<"\nAlert!--Redundant ID, Generating New ID.";
                         generateRandomID(adminVector, mgmtVector, userVector, 'A');
                    }      
                    return randomNum;
              case 'M':
                    cout <<"\nGenerating random ID for New Management User";
                    randomNum  = (rand() % (1000 + 1 - 501)) + 501;
                    for(int i = 0; i < mgmtVector.size(); ++i){
                        if(mgmtVector[i].mgmtID  == randomNum){
                            ++redundant;
                          }      
                    }
                    if(redundant == 1){
                         cout <<"\nAlert!--Redundant ID, Generating New ID.";
                         generateRandomID(adminVector, mgmtVector, userVector, 'M');
                    }      
                    return randomNum;

              case 'U':
                    break;
              
              default:
                  break;
        }
        return randomNum;
      }
     /**
			*This function prompts the user to enter Login credintials and check with the database
			*depending on the type of logged in user, call each type function call 
      * Parameter is a vector of admin, management and user type passed by reference
      * No return value
			*/
   void Admin::login(vector <admin>& adminVector, vector <management>& mgmtVector, vector <user>& userVector, vector <ticket>& ticketVector){
    	
			//long id;
			std:: string password;
			 //Possible 'A', 'M', 'U'
			char curUser = 'P'; //'P' = Pass condition 'F' = fail condition
  	
      do{
          cout <<"Enter ID NO:";
          cin >> loggedInId;
          cout <<"Enter Password:";
          cin.ignore();
          getline(cin, password);
      
          //call the function to decide which type user(ADMIN, MANAGEMENT or USER) logged in the system
          curUser = verifyUser(loggedInId, password, adminVector, mgmtVector, userVector);
          if(curUser == 'F')
              cout << "\nAlert!------Credentials do not match Try Again!!------\n"<< endl;
          userSelectionMenu(curUser, adminVector, mgmtVector, userVector, ticketVector);
        
        }while(curUser == 'F');
	
   }
  /**
   * Function takes in curUser return value and takes the program to specific user type
   * 'A' --- Admin login
   * 'M' -- Management login
   * 'U' -- User login
   * Each User type menu is given and each respective function call are performed
   * Parameter is a vector of admin, management and user type passed by reference
   * No return value
   */
   void Admin:: userSelectionMenu(char curUser, vector <admin>& adminVector, vector <management>& mgmtVector, vector <user>& userVector, vector <ticket>& ticketVector){
      switch(curUser)
            {
              case 'A':
                  // --------> Admin
                  cout <<"\nWelcome to the Parking Lot System!!";
                  cout << endl <<"You have Administrator level privillege!" << endl;
                  //call administrattive function call and perfom inside this case
                  adminMenu(adminVector, mgmtVector, userVector);
                  break;

              case 'M':
                  // -------->Management
                  cout <<"\nWelcome to the Parking Lot System!!";
                  cout << endl <<"You have Management level privillege!" << endl;
                  //call management function call and perfom inside this case
                   mObj.setMgmtID(loggedInId);
                  mObj.managementMenu(adminVector, mgmtVector, userVector, ticketVector);
                 
                  break;

              case 'U':
                  // -------->User
                  cout <<"\nWelcome to the Parking Lot System!!";
                  cout << endl <<"You have User level privillege!" << endl;
                  mObj.userMenu(userVector, ticketVector, loggedInId);
                  //call user function call and perfom inside this case
                  break;
              
              default:
                break;
            }
   }
   /**
     * Function checks which type of user is logged into the system and return each type 
     * if curr id matches with any range of ID and specify which user is trying to log in.
     * verify if Id and password matches, if not prompts the user for re-enter password
     * return which type user  
     * 'A' --- Admin login
     * 'M' -- Management login
     * 'U' -- User login
     * check with database which account it uses
     * if range is from 101 --- to 500 ====> admin
     * else if range is from 501--- 1000 =====> management
     * else if range more than 50000 then user
     * Parameter is a vector of admin, management and user type passed by value
     * char type return value
     */ 
  char Admin::verifyUser(long checkID, string checkPassword, vector <admin> adminVector, vector <management> mgmtVector, vector <user> userVector){
        cout << endl << "\n******Checking DATABASE!!******";
        int flag = 0;
        if(checkID >=101 && checkID <= 500){
            for(int i = 0; i < adminVector.size(); ++i){
              if(adminVector[i].adminID == checkID && adminVector[i].adminPassword == checkPassword){
                ++flag;
                return 'A';
              }       
            }
            if(flag == 0){
                cout<< "\nAlert! --Wrong Credentials!"; 
                return 'F'; 
            }   
        }  
        else if(checkID >= 501 && checkID <= 1000){
            for(int i = 0; i < mgmtVector.size(); ++i){
              if(mgmtVector[i].mgmtID == checkID && mgmtVector[i].mgmtPassword == checkPassword){
                 ++flag;
                 return 'M';
             }             
          }
          if(flag == 0){
                cout<< "\nAlert! --Wrong Credentials!"; 
                return 'F'; 
          } 
        }
        else if(checkID >= 50001){
            for(int i = 0;i < userVector.size(); ++i){
              if(userVector[i].userID == checkID && userVector[i].userPassword == checkPassword){
                 ++flag;
                 return 'U';
              }  
            }
            if(flag == 0){
                cout<< "\nAlert! --Wrong Credentials!"; 
                return 'F'; 
            } 
        }
        return (flag == 1)? 'P': 'F'; 
  }
  
/**
 * Change password of the currently logged in user
 * prompt user to enter new password
 * Function takes admin vector as a parameter which is passes by reference
 * Loop is created to go through each element in the vector and update the element which id match ithe the currently logged in user.
 * Parameter is a vector of admin type passed by reference 
 * No return value
 */
  void Admin::changeAdminPassword(vector <admin>& adminVector){
    string newPassword;
    cout <<"\nEnter new Password: ";
    cin.ignore();
    getline(cin, newPassword);
 
    for(int j = 0; j < adminVector.size(); ++j){
     if(adminVector[j].adminID == loggedInId){
        adminVector[j].adminPassword = newPassword;
        cout <<"\n*********Password changed successfully**********";
        break;
     }
    }
  }
/**
 * Function to add user into the database
 * Function assign the random value and assign to adminId variable.
 * Prompts are given to enter new Admin user name and new password
 * New data is pushed into the vector container.
 * Parameter is a vector of admin type passed by reference and a long type to store random value
 * No return value
 */
void Admin::addAdmin(vector <admin>& adminVector, long randomNum){
  admin adminVar;
  adminVar.adminID = randomNum;
  cout <<"\nNew randomly genereated admin ID is: " <<adminVar.adminID;  //***********************************Make Id generation random
  
  cout << "\nEnter New admin name: ";
  cin.ignore();
  getline(cin, adminVar.adminName);
  cout <<"Enter new admin password: ";
  getline(cin, adminVar.adminPassword);
  cout <<"\n**********New Admin user created Successfully!***********" << endl;
  adminVector.push_back(adminVar);
}
/**
 * This function removes the data of the Admin user from the database
 * Prompts the user to enter the ID of the Admin
 * Checks through the database and when match is found removes
 * Function also checks if User is deleting itself which is avoided by checking that case
 * An interator is created with for loop which changes the pointer in each element of the vector and 
 * check the Id with the deleting ID, When match is found, deletion is performed
 * Parameter is a vector of admin type passed by reference
 * No return value
 */
void Admin::removeAdmin(vector <admin>& adminVector){
admin adminVar;
int match = 0;
  do{
    cout <<"\nEnter Admin ID you want to remove: ";
    cin >> adminVar.adminID;
    if(adminVar.adminID == loggedInId){
      match = 1;
      cout <<"\nAlert! --You cannot remove currently Logged In Admin User. Try again with different ID";
    }else
    {
      match = 0;
    } 
  }while(match == 1);
  
  int j = 0, flag = 0;
  for(auto i = adminVector.begin(); i != adminVector.end(); ++i, ++j){//Iterator to loop through the element of the vector
    
      if(adminVector[j].adminID == adminVar.adminID){
        adminVector.erase(i);
        cout <<"\n*********Entered Admin ID user removed successfully!**********";
        ++flag;
        break;
     } 
  }
  if(flag == 0)
    cout <<"\nAlert! --No Entered ID Exist in the system.";
}

/**
 * This function search for a specific Admin user based on ID provided
 * Prompt user for search ID and display all information excluding password
 * Parameter is vector of admin type passed by value
 * No return value
 */
void Admin::searchAdmin(vector <admin> adminVector){
  // prints admin data from adminVector
  admin printID;
  int flag = 0;
  cout << "\nEnter the ID you want to search: ";
  cin >> printID.adminID;

	for(int i=0; i < adminVector.size(); i++)  // this loop just outputs
	{                                          // admin employee info
		if(adminVector[i].adminID == printID.adminID){
      cout << "\n---------Entered ID Admin Information------------" << endl;
	    cout << "---------------------------------------------------" << endl;
	    cout << "Name                           ID                  " << endl;
	    cout << "---------------------------------------------------\n" << endl;
      cout << left << setw(30) << adminVector[i].adminName
			 << setw(30) << adminVector[i].adminID << endl;
      ++flag;
      break;
    }
	}   
    if(flag == 0)
      cout<< "\nAlert! --NO Entered ID Exist in the system.";   
}

/**
 * Function to print data admin data from the database in the screen
 * It displays all the information excluding password looping through each elements of the vector
 * Parameter is vector of admin type passed by value
 * No return value
 */
void Admin::viewAdmin(vector <admin> adminVector){
  // prints admin data from adminVector
	cout << "\n---------All Admin Employee Information------------" << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "Name                           ID         " << endl;
	cout << "---------------------------------------------------\n" << endl;
	
	for(int i=0; i < adminVector.size(); i++)  // this loop just outputs
	{                                          // admin employee info
		cout << left << setw(30) << adminVector[i].adminName
			 << setw(30) << adminVector[i].adminID << endl;
	}
}
//********************MANAGEMENT FUNCTIONALITIES BEGIN**********************************

/**
 * Function to add a new management employee where management vector is passes by reference
 * random num is also passes which is stored in new management id
 * Creates a new variable of the type management class and pushes into the vector
 * Parameter is a vector of management type passed by reference and a long random number which stores the randomly created ID for management
 * No return value
 */
void Admin::addManagement(vector <management>& mgmtVector, long randomNum){
  management mgmtVar;

  cout <<"\nRandomly Generated Management ID is: " << randomNum;//*******************************make ID generation random
  mgmtVar.mgmtID = randomNum;
  cout << "\nEnter new Management name: ";
  cin.ignore();
  getline(cin, mgmtVar.mgmtName);
  cout <<"Enter new Management password: ";
  getline(cin, mgmtVar.mgmtPassword);
  cout <<"\n**********New Management user created Successfully!***********" << endl;
  mgmtVector.push_back(mgmtVar);
}
/**
 * This function removes the data of the management user from the database
 * Prompts the user to enter the ID of the Management
 * Checks through the database and when match is found removes the element
 * Function also checks if User is deleting itself which is avoided by checking that case first
 * An interator is created with for loop which changes the pointer in each element of the vector and 
 * check the Id with the deleting ID, When match is found, deletion is performed
 * Parameter is management vector type passed by reference
 * No return value
 */
void Admin::removeManagement(vector <management>& mgmtVector){
  management mgmtVar;
  cout <<"\nEnter Management ID you want to remove: ";
  cin >> mgmtVar.mgmtID;
  int j = 0, flag = 0;
  for(auto i = mgmtVector.begin(); i != mgmtVector.end(); ++i, ++j){
      if(mgmtVector[j].mgmtID == mgmtVar.mgmtID){
        mgmtVector.erase(i);
        cout <<"\n*********Entered Management Employee is removed successfully!************";
        ++flag;
        break;  
      }
    }  
  if(flag == 0)
    cout <<"Alert! --No Entered ID Exist in the system.";
}
/**
 * Search spection ID information for specific Management 
 * prompts management to enter ID to search for 
 * Only entered ID when found, data is printed in a clean order
 * Parameter is vector of management type passed by value
 * No return value
 */
void Admin::searchmanagement(vector <management> mgmtVector){
  // prints admin data from adminVector
  management printID;
  int flag = 0;
  cout << "Enter the ID you want to search: " ;
  cin >> printID.mgmtID;

	for(int i=0; i < mgmtVector.size(); i++)  // this loop just outputs
	{                                          // admin employee info
		if(mgmtVector[i].mgmtID == printID.mgmtID){
      cout << "\n---------Entered ID Management Information------------" << endl;
	    cout << "---------------------------------------------------" << endl;
	    cout << "Name                           ID         " << endl;
	    cout << "---------------------------------------------------\n" << endl;
      cout << left << setw(30) << mgmtVector[i].mgmtName
			 << setw(30) << mgmtVector[i].mgmtID << endl;
      ++flag;
      break;
    }
	}   
    if(flag == 0)
      cout<< "\nAlert! --NO Entered ID exist in the system.";   
}
/**
 * Function to print management data in the screen 
 * Functions prints all the data available for the each management user in a order
 * paramenter is vector of management type passed by value.
 * No return value 
 */
void Admin::viewManagement(vector <management> mgmtVector){
 cout << "\n---------All Management Employee Information----------------" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "Name                 ID         " << endl;
	cout << "-------------------------------------------------------------\n" << endl;
	
	for(int i=0; i < mgmtVector.size(); i++)               // for loop to print management info
	{                                                      // (only prints name and ID)
		cout << left << setw(20) << mgmtVector[i].mgmtName
			 << setw(30) << mgmtVector[i].mgmtID 
			 << endl;
	}
}



