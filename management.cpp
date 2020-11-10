#include "management.h"
#include <iomanip>
using namespace std;
long mgmtLoggedId;
//******************************USER FUNCTIONALITIES************************

/**
   * This Function creates menu for user and prompts user to type one option
   * Based on that option, user is allowed to perform specific task 
   */
  void Management::userMenu(vector <user>& userVector, vector <ticket>& ticketVector, long loggedInId){
    int choice = 0; 
    cout <<"\n****************USER MENU REACHED**********************" << endl;
    cout <<"\nType Option 1: Change current user password.";
    cout <<"\nType Option 2: Change current user vechicle info.";
    cout <<"\nType Option 3: View current user vechicle info.";
    cout <<"\nType Option 4: View tickets for current user.";
    cout <<"\nType Option 5: Pay ticket for current user.";
    cout <<"\nType Option 6: Logout"<< endl;
    cout <<"Option: ";
    cin >> choice;
    switch(choice){

          case 1:
              //Remove user from database
              cout << endl <<"Changing User Password";
              changeUserPassword(userVector);
              userMenu(userVector, ticketVector, loggedInId);
              break;
          case 2: 
              //Change vehicle info
              cout << endl <<"Changing Vehicle info..";
              changeVehicleInfo(userVector, loggedInId);
              userMenu(userVector, ticketVector, loggedInId);
              break;
          case 3:
              //Display all user info
              cout << endl <<"Displaying user vechicle info...";
              viewVehicleInfo(userVector, loggedInId);
              userMenu(userVector, ticketVector, loggedInId);
              break;
          case 4:
                //Display ticket info for user
              cout << endl << "Diplaying tickets for current user...";
              viewUserTicket(userVector, ticketVector, loggedInId);
              userMenu(userVector, ticketVector, loggedInId);
              break;
          case 5:
                //GO inside the Payment function
              cout << endl << "Payment portal loading...";
              payTicket(ticketVector, loggedInId);
              userMenu(userVector, ticketVector, loggedInId);
              break;
          case 6:
                cout <<"\n**********Logging Out *******";
                break;

          default:
             cout <<" \nWrong Input!! Try Again!!\n\n";
             userMenu(userVector, ticketVector, loggedInId); 
      }

  }
  /**
 * Function for user to pay ticket in the database
 *Check if entered ticket exist before prompting for payments
 *If User enter the correct ticket number and pays the full amount
 *then ticked status will be changed to "Paid" or "Unpaid"
 * Parameter: a vector of type ticket is passed by reference and a type long  passed
 */
void Management::payTicket(vector <ticket> & ticketVector, long loggedInId){
    
    float amountPaid;
    int ticketNumber;
    int match = 0;
    if(ticketVector.size() == 0)
     {
         cout << "\nNo tickets recorded Entered";
         return;
     }

    cout << "\nEnter the ticket ID you would like to pay: ";
    cin >> ticketNumber;
    for(int i =0; i < ticketVector.size(); i++)
    {
      if(ticketVector[i].ticketID == ticketNumber) 
        match = 1; // Ticket found in the database
    }
    if(match != 1) 
      {
          cout <<"\nEntered Ticket number does not Exist.";
          return;
      }  

    cout << "\nEnter the amount you would like to pay: $";
    cin >> amountPaid;
    for(int i =0; i < ticketVector.size(); i++)
    {
      if(ticketVector[i].ticketID == ticketNumber)
      {
          if(amountPaid == ticketVector[i].ticketAmount){
              cout << "\nTicket successfully paid!";
              ticketVector[i].ticketStatus = "Paid";
              break;
          }
          else
              cout << "\nERROR: Please pay full amount only!";

      }
    }
}
/**
 * Function to view ticket for current user
 * This function checks if user has any tickets if yes, shows all the tickets only for the user logged in.
 * Parameter:vector of user type, vector of ticket type both passed by reference and one long type
 */
void Management::viewUserTicket(vector <user> &userVector, vector <ticket> &ticketVector, long loggedInId) {
     int match = 0;
     if(ticketVector.size() == 0)
     {
         cout << "\n\nNo tickets found";
         return;
     }
     for (int j = 0; j < userVector.size(); j++)
     {  
          if(userVector[j].userID == loggedInId){
              for(int i = 0; i < ticketVector.size(); i++)
              {
                   if(userVector[j].licensePlate == ticketVector[i].ticketLicensePlate)
                    {  
                        match = 1;
                        // prints ticket info from ticketVector
                        cout << "\n---------All Ticket Information----------------------------------------------" << endl;
                        cout << "-------------------------------------------------------------------------------" << endl;
                        cout << "Ticket number        Issued By      Status         Amount      Reason" << endl;
                        cout << "-------------------------------------------------------------------------------\n" << endl;

                        cout << left << setw(10) << ticketVector[i].ticketID 
                         <<  "           " << ticketVector[i].issuerID 
                         << setw(10) <<"   " << ticketVector[i].ticketStatus 
                         << setw(10) <<"   " << ticketVector[i].ticketAmount 
                         << setw(10) <<"   " << ticketVector[i].ticketReason << endl;
                         return;
                   }                  
              }

              break;
            }
     }
     if( match != 1)
        cout <<"\nNO Ticket Found in the system.";

}
//this function allows user to change their vehicle info
void Management::changeVehicleInfo(vector <user>& userVector, long loggedInId) {
    string newCarMake;
    string newCarModel;
    string newPlate;
    int newYear;
    cout << "\nEnter new Vechicle make: ";
    cin >> newCarMake;
    cout << "\nEnter new Vechicle model: ";
    cin >> newCarModel;
    cout <<"\n Enter new Vechicle Year: ";
    cin >> newYear;
    cout << "\nEnter new Vechicle license plate: ";
    cin >> newPlate;
    int j = 0, flag = 0;
    for (int i =0; i < userVector.size(); i++) {
        if (userVector[i].userID == loggedInId) {
            userVector[i].carMake = newCarMake;
            userVector[i].carModel = newCarModel;
            userVector[i].carYear = newYear;
            userVector[i].licensePlate = newPlate;
            cout << "\n*********Car info changed successfully!************";
            ++flag;
            break;
        }
    }
    if (flag == 0)
        cout << "Alert! --No Entered ID Exist in the system.";
}
// this function allows user to display their current vehicle info
void Management::viewVehicleInfo(vector <user>& userVector, long loggedInId) {
    int flag =0;
    for (int i =0; i < userVector.size(); i++) {
        if (userVector[i].userID == loggedInId) {
            cout << "\nVechicle make: " << userVector[i].carMake << endl;
            cout << "Vechicle model: " << userVector[i].carModel << endl;
            cout << "Vechicle year: " << userVector[i].carYear << endl;
            cout << "Vechicle license plate number: " << userVector[i].licensePlate << endl;
            ++flag;
            break;
        }
    }
    if (flag == 0)
        cout << "Alert! --No Entered ID Exist in the system.";
}
/**
 * Change password of the currently logged in USER(not management/admin)
 * prompt user to enter new password */
void Management::changeUserPassword(vector <user>& userVector) {
    string newPassword;
    int match = 0;
    long loggedInId;//  variable to check who is currently checked in as a USER)
    do{
        cout <<"\nEnter your Id: ";
        cin >> loggedInId;
        for (int j = 0; j < userVector.size(); ++j) {
            if (userVector[j].userID == loggedInId) {
                match = 1;
                break;
             }                  
         }
         if(match != 1){
             cout << "\nEnter ID Management Employee does not Exist.";
            cout <<"\nTry Again";

         }
    }while(match != 1);

    cout << "Enter new Password: ";
    cin.ignore();
    getline(cin, newPassword);

    for (int j = 0; j < userVector.size(); ++j) {
        if (userVector[j].userID == loggedInId) {
            userVector[j].userPassword = newPassword;
            cout << "\n*********Password changed successfully**********";
            break;
        }
    }
}
//****************TICKET FUNCTIONALITIES BEGIN*********************************

// This function displays menu for ticketing system for management
void Management::ticketMenu(vector <ticket>& ticketVector, vector<user> userVector){
int choice = 0;
long randomNum;
cout << "\n****************TICKET MENU REACHED**********************" << endl;
cout << "\nType Option 1: Issue new ticket.";
cout << "\nType Option 2: View all ticket information";
cout << "\nType Option 3: View information for specific ticket";
cout << "\nType Option 4: Remove ticket";
cout << "\nType Option 5: Go Back To Management Menu" << endl;
cout << "Option: ";
cin >> choice;
switch (choice) {

    case 1:
        //Issue new ticket to database
        cout << endl << "Issuing NEW ticket";
        //call random number generator function
        randomNum = generateRandomID(ticketVector); // Generating random number between the range 
        addTicket(ticketVector, randomNum);
        ticketMenu(ticketVector, userVector);
        break;
    case 2:
        // View ticket information
        cout << endl << "VIEWING all ticket information" << endl;
        //call view function
        viewTicket(ticketVector);
        ticketMenu(ticketVector, userVector);
        break;

    case 3:
        //View specific ticket info
        cout << endl << "View details for specific ticket information.";
        //call search  function
        searchTicket(ticketVector, userVector);
        ticketMenu(ticketVector, userVector);
        break;

    case 4:
        //Remove ticket from database
        cout << endl << "Removing Ticket";
        //call add  function
        removeTicket(ticketVector);
        ticketMenu(ticketVector, userVector);
        break;

    case 5:
        cout << "\n*******Logging out*******" << endl;
        break;

    default:
        cout << " \nWrong Input!! Try Again!!\n\n";
        ticketMenu(ticketVector, userVector);
}
}
/**
 * this function generates random ID number for  new ticket
 * Ticket is generated from the range of 1001 to 50000
 * Function also checks if the Auto created Ticket number already exist
 * if yes, generateRandomID is called again recursively and new ticket number is issued and returned
 */
long Management::generateRandomID(vector <ticket> ticketVector) {
    srand((unsigned)time(0));
    cout << "\n******Checking DATABASE FOR ID REDUNDANCY!!******";
    int redundant = 0;// to check if same ID is created by random number generator
    long randomNum; // variable to store randomly generated value

        cout << "\nGenerating random ID for Ticket";
        randomNum = (rand() % (50000 + 1 - 1001)) + 1001;  //generate a random number between 1091 and 50000(inclusive) and assign to randomNum
        for (int i = 0; i < ticketVector.size(); ++i) {//Loop through the ticket database container to check if generated ID already exist
            if (ticketVector[i].ticketID == randomNum) {
                ++redundant;
            }
        }
        if (redundant == 1) { //Recursive loop if randomly greated ID Matches
            cout << "\nAlert!--Redundant ID, Generating New ID.";
            generateRandomID(ticketVector);
        }
        return randomNum;
}
/**
 * Function to issue a ticket into the database
 * Function assign the random value and assign to ticketId variable.
 * Prompts the management employee to enter different details like amount, reasons, License plate and store the whole data into ticket vector
 */
void Management::addTicket(vector <ticket> & ticketVector, long randomNum){
    
    ticket ticketVar;
    ticketVar.ticketID = randomNum;
    cout << "\nNew Auto genereated ticket ID is: " << ticketVar.ticketID;  //**Make Id generation random
    ticketVar.issuerID = mgmtLoggedId;
    cout <<"\nTicket Issued by: " << ticketVar.issuerID;
    cout << "\nEnter Ticket Amount: $";
    cin >> ticketVar.ticketAmount;
    cout <<"\nReason for Ticket: ";
    cin.ignore();
    getline(cin, ticketVar.ticketReason);
    cout <<"\nEnter License Plate number: ";
    getline(cin, ticketVar.ticketLicensePlate);
    ticketVar.ticketStatus = "Unpaid";
    cout << "\nRecording in database..Press Enter";
    ticketVector.push_back(ticketVar);
    cin.ignore();
    cout <<"\n New Ticket recorded successfully. ";
}
/**
 * Function to view all ticket in the database
 */
void Management::viewTicket(vector <ticket> ticketVector) {
     if(ticketVector.size() == 0)
     {
         cout << "\n\nNo tickets found";
         return;
     }
     // prints ticket info from ticketVector
     cout << "\n---------All Ticket Information--------------------------------------" << endl;
     cout << "-----------------------------------------------------------------------" << endl;
     cout << "Ticket Number        Issued by      Status         Amount     Reason" << endl;
     cout << "------------------------------------------------------------------------\n" << endl;
     if(ticketVector.size() == 0)
          return;
     int flag =0;
     for (int i = 0; i < ticketVector.size(); i++)  // this loop just outputs
     {                                          // ticket info
          cout << left << setw(10) << ticketVector[i].ticketID 
               <<"           " << ticketVector[i].issuerID  
               << setw(10) <<" "<< ticketVector[i].ticketStatus 
               <<  setw(10) <<" "<< ticketVector[i].ticketAmount 
               << setw(10) <<"  "<<ticketVector[i].ticketReason << endl;
          flag++;
     }
     if(flag == 0)
     {
          cout << "\n**********No ticket found************" << endl;
     }
     
}
/**
 * Function to view ticket details for a specific ticket in the database
 * Checks if entered ticket exist in system looping through the ticket database
 * When found, Checks the tickets license plate matches with any user database
 * When found, display all the details of the tickets and user
 * ParameterL vectorof type ticket and user are passed by value
 */
void Management::searchTicket(vector <ticket> ticketVector, vector <user> userVector) {
     // prints ticket info from ticketVector
     ticket printID;
     int flag = 0;
     cout << "\nEnter the ticket number you want to search: ";
     cin >> printID.ticketID;

     if(ticketVector.size() == 0)
     {
         cout << "\n\nNo tickets found";
         return;
     }
     for (int i = 0; i < ticketVector.size(); i++)  // this loop just outputs
     {                                          // ticket info
          if (ticketVector[i].ticketID == printID.ticketID) 
          {  
                for(int j = 0; j < userVector.size(); j++){
                    if(ticketVector[i].ticketLicensePlate == userVector[j].licensePlate)
                    {
                        cout <<"\nTicket number: " << ticketVector[i].ticketID;
                        cout <<"\nTicket amount: $" << ticketVector[i].ticketAmount;
                        cout <<"\nTicket status: " << ticketVector[i].ticketStatus;
                        cout <<"\nTicket reason: " << ticketVector[i].ticketReason;
                        cout <<"\nTicket Issued By: " << ticketVector[i].issuerID;
                        cout <<"\nVechicle Owner ID: " << userVector[j].userID;
                        cout <<"\nVechicle Owner Name: " << userVector[j].userName;
                        cout <<"\nVechicle make: " << userVector[j].carMake;  
                        cout <<"\nVechicle model: " << userVector[j].carModel;
                        cout <<"\nVechicle year: " << userVector[j].carYear;
                        cout <<"\nVechicle plate number: " << ticketVector[i].ticketLicensePlate;
                        ++flag;
                        return;
                    }
                  
                }  
                cout <<"\nTicket number: " << ticketVector[i].ticketID;
                cout <<"\nTicket amount: $" << ticketVector[i].ticketAmount;
                cout <<"\nTicket status: " << ticketVector[i].ticketStatus;
                cout <<"\nTicket reason: " << ticketVector[i].ticketReason;
                cout <<"\nTicket Issued By: " << ticketVector[i].issuerID;
                cout <<"\nVechicle Owner ID: ";
                cout <<"\nVechicle Owner Name: ";
                cout <<"\nVechicle make: " ;  
                cout <<"\nVechicle model: ";
                cout <<"\nVechicle year: " ;
                cout <<"\nVechicle plate number: " << ticketVector[i].ticketLicensePlate;
                ++flag;
                break;                  
            }
        }      
    if (flag == 0)
       cout << "\nAlert! --NO Entered Ticket Number Exist in the system.";
}
// This function allows management to remove ticket by ID
void Management::removeTicket(vector <ticket>& ticketVector){
    int ticketRemoveID;
    cout << "\nEnter ticket number to remove: ";
    cin >> ticketRemoveID;
    cout << "\nSearching for ticket to remove..." << endl;
    int j = 0;
    int flag = 0;
    for (auto i = ticketVector.begin(); i != ticketVector.end(); ++i, ++j) {
        if (ticketVector[j].ticketID == ticketRemoveID) {
            ticketVector.erase(i);
            cout << "\n*********Ticket is removed successfully!************";
            ++flag;
            break;
        }
    }
    if (flag == 0)
        cout << "Alert! --No Entered Ticket Exist in the system.";

}

//***************MANAGEMENT FUNCTIONALITIES BEGIN************************

 /**
   * This Function creates menu for management user and prompts user to type one option
   * Based on that option, user is allowed to perform spection task 
   */
  void Management::managementMenu(vector <admin>& adminVector, vector <management>& mgmtVector, vector <user>& userVector, vector <ticket>& ticketVector){
    int choice = 0; 
    Management mObj;
    cout <<"\n****************MANAGEMENT MENU REACHED**********************" << endl;
    cout <<"\nType Option 1: Remove User.";
    cout <<"\nType Option 2: View all User Info.";
    cout <<"\nType Option 3: Search for specific user Info.";
    cout <<"\nType Option 4: Access ticketing system.";
    cout <<"\nType Option 5: Change password of current account.";
    cout <<"\nType Option 6: Logout"<< endl;
    cout <<"Option: ";
    cin >> choice;
    switch(choice){

          case 1:
              //Remove user from database
              cout << endl <<"Removing User from Database..";
              removeUser(userVector);
              managementMenu(adminVector, mgmtVector, userVector, ticketVector);
              break;
          case 2:
              //View all user info
              cout << endl << "Viewing User info.";
              viewUser(userVector);
              managementMenu(adminVector, mgmtVector, userVector, ticketVector);
              break;
          case 3:
              cout << endl << "Searching for user...";
              searchUser(userVector);
              managementMenu(adminVector, mgmtVector, userVector, ticketVector);
              break;
          case 4:
              cout << endl << "Going to ticket menu.." << endl;
              ticketMenu(ticketVector, userVector);
              managementMenu(adminVector, mgmtVector, userVector, ticketVector);
              break;
          case 5:
              cout << endl << "Accessing password changing function.." << endl;
              changeMgmtPassword(mgmtVector);
              managementMenu(adminVector, mgmtVector, userVector, ticketVector);
              break;
          case 6:
              cout <<"\n*******Logging out*******" <<endl;
              break;

          default:
             cout <<" \nWrong Input!! Try Again!!\n\n";
             managementMenu(adminVector, mgmtVector, userVector, ticketVector); 
      }

  }
  /**
   * Set the global variable mgmtLogged ID to what function call is being done
   * Takes one parameter of type long and sets the value
   */
  void Management::setMgmtID(long mgmtID){
      mgmtLoggedId = mgmtID;
  }
/**
 * Change password of the currently logged in management user
 * prompt user to enter new password
 */
void Management::changeMgmtPassword(vector <management>& mgmtVector) {
    string newPassword;
    int match = 0;
    long loggedInId;//  variable to check who is currently checked in as a USER)
    do{
        cout <<"\nEnter your Id: ";
        cin >> loggedInId;
        for (int j = 0; j < mgmtVector.size(); ++j) {
            if (mgmtVector[j].mgmtID == loggedInId) {
                match = 1;
                break;
             }                  
         }
         if(match != 1){
             cout << "\nEnter ID Management Employee does not Exist.";
            cout <<"\nTry Again";

         }
    }while(match != 1);
    
    cout << "Enter new Password: ";
    cin.ignore();
    getline(cin, newPassword);

    for (int j = 0; j < mgmtVector.size(); ++j) {
        if (mgmtVector[j].mgmtID == loggedInId) {
            mgmtVector[j].mgmtPassword = newPassword;
            cout << "\n*********Password changed successfully**********";
            break;
        }
    }
}
// this function allows management/admin to remove user
void Management::removeUser(vector <user>& userVector) {
    user userVar;
    cout << "\nEnter User ID you want to remove: ";
    cin >> userVar.userID;
    int j = 0, flag = 0;
    for (auto i = userVector.begin(); i != userVector.end(); ++i, ++j) {
        if (userVector[j].userID == userVar.userID) {
            userVector.erase(i);
            cout << "\n*********Entered User is removed successfully!************";
            ++flag;
            break;
        }
    }
    if (flag == 0)
        cout << "Alert! --No Entered ID Exist in the system.";
}
  // this function allows management/admin to view all user info (except password)
void Management::viewUser(vector <user> userVector) {
    // prints user data from userVector
    cout << "\n------------------------------------------All User Information-------------------------------------------------" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Name                 ID         Make        Model              Year      Plate Number" << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------\n" << endl;

    for (int i = 0; i < userVector.size(); i++)         // loop to display all user info
    {
        cout << left << setw(20) << userVector[i].userName
            << setw(10) << userVector[i].userID
            << setw(15) << userVector[i].carMake
            << setw(19) << userVector[i].carModel
            << setw(4) << userVector[i].carYear
            << setw(7) << "\t" << userVector[i].licensePlate
            << endl;
    }
} 


// this function allows admin / management to search for specific user
void Management::searchUser(vector <user> userVector) {
    // prints user data from userVector
    user printID;
    int flag = 0;
    cout << "\nEnter the ID you want to search: ";
    cin >> printID.userID;

    for (int i = 0; i < userVector.size(); i++)  // this loop just outputs
    {                                          // user info
        if (userVector[i].userID == printID.userID) {
            cout << "\n------------------------------------------All User Information---------------------------------------------" << endl;
            cout << "-------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Name                 ID         Make        Model              Year      Plate Number" << endl;
            cout << "-------------------------------------------------------------------------------------------------------------\n" << endl;
            cout << left << setw(20) << userVector[i].userName
                << setw(10) << userVector[i].userID 
                << setw(15) << userVector[i].carMake 
                << setw(19) << userVector[i].carModel
                << setw(3) << userVector[i].carYear 
                << setw(10) << "    "<< userVector[i].licensePlate << endl;
            ++flag;
            break;
        }
    }
    if (flag == 0)
        cout << "\nAlert! --NO Entered ID Exist in the system.";
}
 


