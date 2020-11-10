#ifndef management_h
#define management_h
#pragma once
#include <vector>
#include <string>
#include "userStructure.h"
#include "ticketStructure.h"
#include "Admin.hpp"
#include <iostream>
#include <random>
#include <cstdlib>
#include <ctime>
using namespace std;

/**
 * This is a headfile for management.cpp class
 */class Management{
     public:
     //************Management functionalities******
     void managementMenu(vector <admin>&, vector<management>&, vector<user>&, vector<ticket>&); //Gives management menu and prompts for input of the choice
     void changeMgmtPassword(vector<management>&); //Change password of the management employee
     void removeUser(vector <user>&); //Remove user in the data
     void viewUser(vector <user>); // View user in the database
     void searchUser(vector <user>); //Search user in the database
     //*********Ticket functionalities********
     long generateRandomID(vector <ticket>); // generate random id depending on the range provided
     void viewTicket(vector <ticket>);//Display all ticket information where vector is passed by value
     void removeTicket(vector <ticket>&); //function to remove ticket where vector is passed by reference
     void addTicket(vector <ticket>&, long); //function to add new ticket where vector is passed by reference
     void searchTicket(vector <ticket>, vector <user>); // Display ticket onformation for specific ticket where vector is passsed by value
     void ticketMenu(vector <ticket>&, vector<user> );
     //*****User Level functionalities*********
     void userMenu(vector<user>&, vector<ticket>&, long); // User menu created 
     void changeUserPassword(vector <user>&); //Change password for the user
     void changeVehicleInfo(vector<user>&, long); //Change vechicle information
     void viewVehicleInfo(vector<user>&, long); // View vechicle information
     void viewUserTicket(vector<user>&, vector<ticket>&, long); //View user Ticket information
     void payTicket(vector<ticket>&, long); //Pay ticket amount
     //Utilities functions
     void setMgmtID(long); // Function to set global variable of the logged in user and set to variable in management class 
 };

#endif
