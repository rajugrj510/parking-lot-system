
#ifndef Admin_HPP
#define Admin_HPP
#include "loadDataFunctions.hpp"
#include "ticketStructure.h"
#include <vector>
#include <string>
/**
 * This is a headfile for admin.cpp class
 * All the required function for admin user is called from this class.
 * Utilities function like 
 * login() - Prompts the user to login in the system. Depending on the entered user, verifyUser() function decides which user is logging into the system.
 * verifyUser() - The id which is entered  when logging in is checked with the existing databas in this function
 * adminMenu() - Function prompts the admin user to chose option to 
 *   add, remove, search, view, change password and perform each task based on the user desire
 * generateRandomID() - this function generated random ID and passed based on which user id creating new user
 * userSelectionMenu() - this function takes the each user into specific functionalities of the system 
 *  A' --- Admin login
* 'M' -- Management login
* 'U' -- User login
 */
class Admin
{       
     public:
     void registerNewUser(vector <user>&); //Function to register new user
     //Utilities functions used for different operation
     void login(vector <admin>&, vector <management>&, vector <user>&, vector <ticket>&); //Login feature is prompt to user where vectors are passed by refrence
     char verifyUser(long, string, vector <admin>, vector <management>, vector <user>); // login prompt uses this function to verify the user who is 
     //trying to login into the system, vector passed by value and by reference
     void adminMenu(vector <admin>&, vector <management>&, vector <user>&); // menu to admin User to perform different functionalities
     long generateRandomID(vector <admin>, vector <management>, vector <user>, char); // generate random id depending on the range provided
     void userSelectionMenu(char, vector <admin>&, vector <management>&, vector <user>&, vector <ticket>&); // gives user selection menu to each type
     //******Administrator Level functionalities**********
     void addAdmin(vector <admin>&, long ); //function to add new adim where vector is passes by reference
     void removeAdmin(vector <admin>&); // function to remove  admin where vector is passes by reference
     void searchAdmin(vector <admin>); // Display specific User id search where vector is passed by value
     void viewAdmin(vector <admin>); //Display all information of admin user department where vector is passed by value
      void changeAdminPassword(vector <admin>&);  //accessed should be given to only currently logged in user where vector is passes by reference.
     //******Management level functionalities***********
     void addManagement(vector <management>&, long ); //function to add new user where vector is passes by reference
     void removeManagement(vector <management>& ); //function to add new user where vector is passes by reference
     void viewManagement(vector <management>); //Display all information of management user department where vector is passed by value
     void searchmanagement(vector <management>); // Display specific User id search where vector is passed b
     //*****User Level functionalities********************
     /**
      * To remove user, View all user information and Search user information 
      * These functions are used form management.cpp file
      */
};

#endif