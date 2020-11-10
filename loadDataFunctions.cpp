#include "loadDataFunctions.hpp" // header file which includes prototypes
#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <iomanip> 
#include <vector>

using namespace std;
/**
 * This function accepts three vector which are passed by reference
 * adminvector, mgmtvetor and uservector are passed to the functio
 * function is called in main
 * Diplaying a proper format of parking lot spaces and data is done
 * Function reads in the data from the input file and store in each vector container
 * At the end, another function loadDataBase is called
 * @return No return value
 */

void loadParkingLotData(vector <admin>& adminVector, vector <management>& mgmtVector, vector <user>& userVector)
{
	string firstLine;     // declaring variables
	string inputFileName; // inputFileName holds the user's choice for input file
	string adminFileName; // holds name of admin database file
	string managementFileName; // holds name of mgmt database file
	string userFileName; // holds name of user database file
	int line;            // this is just a temp variable for using stoi()
	int numLots;         // holds value from first line on input file (# of lots)
	const int typeSpaces = 3; // there are only three types of spaces (R,M,D)
	
 
 
	cout << "Enter input file name (include .txt): ";  // prompt for input file
	cin >> inputFileName;
 
	ifstream inFile;			 // creates input stream for file
 	inFile.open(inputFileName);
 	
 	while(!inFile.is_open())     // input file validation
	{
    	cout << "\nError opening file, please re-enter file name: ";
    	cin >> inputFileName;
    	inFile.open(inputFileName);
	}
 
   
	getline(inFile, firstLine);  // reads first line of file
	numLots = stoi(firstLine);   // coverts to int and stores in numLots
   

   	int parkingLotArray [numLots][typeSpaces]; // declare 2D array 
	string curLine;                            // temp variable for reading data
	
	
	// This loop initializes the parkingLotArray
	
	for(int i = 0; i < numLots; i++)        // [i] represents lot number
    	for(int j = 0; j < typeSpaces; j++) // [j] represents the type 
    	{									// 3 types of spaces (R,M,D)
        	getline(inFile, curLine);
        	line = stoi(curLine);           // convert to int and store
        	parkingLotArray[i][j] = line;   // in parkingLotArray[i][j]
    	}
       
	
	// Loop to repeat all below steps for numLots
   	for(int i = 0; i < numLots; i++)
	{
    	int regularParkingSpaces = 0;     // variables start at 0 for each lot
    	int motorcycleParkingSpaces = 0;
    	int disabledParkingSpaces = 0;
    	int totalParkingSpaces = 0;
      
    	regularParkingSpaces += parkingLotArray[i][0]; 	  // lot[i] and column[0] (regular spaces)
    	motorcycleParkingSpaces += parkingLotArray[i][1]; // lot[i] and column[1] (motorcycle spaces)
    	disabledParkingSpaces += parkingLotArray[i][2];   // lot[i] and column[2] (disabled spaces)
    	
    	// Adds all types of spaces for each lot to get total number of spaces
    	totalParkingSpaces = regularParkingSpaces + motorcycleParkingSpaces + disabledParkingSpaces;
 
    	// Outputs all relevant information for each lot
		cout << "\nLot #" << i+1 << " Has "<< totalParkingSpaces << " total spaces." << endl;
    	cout << "Lot #" << i+1 << " Has "<< regularParkingSpaces << " regular spaces." << endl;
    	cout << "Lot #" << i+1 << " Has "<< motorcycleParkingSpaces << " motorcycle spaces." << endl;
    	cout << "Lot #" << i+1 << " Has "<< disabledParkingSpaces << " disabled spaces." << endl;
 		cout << "\nParking Lot #" << i + 1 << " layout: \n" << endl;
      
    	for(int r = 0; r < regularParkingSpaces; r++) // These three for loops
        	cout << "|R|";							  // print the layout of each
        cout << endl;								  // parking lot.
    	for(int m = 0; m < motorcycleParkingSpaces; m++)
        	cout << "|M|";
    	
		for(int d = 0; d < disabledParkingSpaces; d++)
        	cout << "|D|";
    	cout << "\n" << endl;
	}
	
	// this just prints a line to separate som e output text
	cout << "------------------------------------------------\n";
	
	
	// get file names for each database
    getline(inFile,adminFileName);
    getline(inFile,managementFileName);
    getline(inFile,userFileName);
    
    inFile.close(); // close the input file
    				// all data has been read
    				
    
    // Call next function, passing 3 file names and passing 3 vector by reference
	// for database files.				
    loadDataBases(adminFileName, managementFileName, userFileName, adminVector, mgmtVector, userVector);
	
}



/**
 *  This function opens the names of the files that were read in from "input.txt
 * and reads in to a vector<struct> for each of the respective three databases.
 * All three file passed form the function call is done, and also three vector admin, management and user are passed as reference
 * so each data when update reflects back to the vector stored in main.
 * @return No return value
 */
void loadDataBases(string adminFile, string mgmtFile, string userFile, vector <admin>& adminVector, vector <management>& mgmtVector, vector <user>& userVector)
{
	//Uncomment this two line below to make the program read admin adn Management data from input file
	//adminFile.erase(adminFile.size()-1); // these remove the "\r" from windows file
	//mgmtFile.erase(mgmtFile.size()-1);   // so that it can be read in linux
	
	// create file stream object
	ifstream dataBaseFile;
	// open file
	dataBaseFile.open(adminFile);
	
	// create vector of type <admin>
	// called adminVector
	
	admin var;
	 // use this variable to assign values for each 
	// trait of the struct (ID, Name, Password)
	
	string temp; // this is just temp variable for 
				 // using stoi() to convert string to int
	
	// while the adminName can be read & end of file hasn't been reached
	// getline until comma reached and store in adminName
	while(getline(dataBaseFile, var.adminName, ',') && !dataBaseFile.eof())
	{
		getline(dataBaseFile, temp, ','); // get next block of info
		var.adminID = stoi(temp);         // convert to int and store in adminID
		getline(dataBaseFile, var.adminPassword, '\n'); // store adminPassword
		adminVector.push_back(var); // send this set of data to adminVector
	}


	
	dataBaseFile.close();  // close the database file
	
	// prints admin data from adminVector
	cout << "\n---------All Admin Employee Information------------" << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "Name                           ID         " << endl;
	cout << "---------------------------------------------------\n" << endl;
	
	for(int i=0; i < adminVector.size(); i++)  // this loop just outputs
	{                                          // admin employee info
		cout << left << setw(30) << adminVector[i].adminName
			 << setw(30) << adminVector[i].adminID 
			 << endl;
	}
	
	
	
	dataBaseFile.open(mgmtFile);   // open mgmtFile
	 // create mgmtVector of type <management>
	management mgmtVar;            // mgmtVar for assigning values to traits
	                               // of mgmt(Name, ID, Password) 
	
	
	// same loop as above, but this time for mgmtVector
	while(getline(dataBaseFile, mgmtVar.mgmtName, ',') && !dataBaseFile.eof())
	{
		getline(dataBaseFile, temp, ',');
		mgmtVar.mgmtID = stoi(temp);
		getline(dataBaseFile, mgmtVar.mgmtPassword, '\n');
		mgmtVector.push_back(mgmtVar);
	}
	
	dataBaseFile.close();    // close the file
	
	
	cout << "\n---------All Employee Information----------------" << endl;
	cout << "---------------------------------------------------" << endl;
	cout << "Name                 ID         " << endl;
	cout << "---------------------------------------------------\n" << endl;
	
	for(int i=0; i < mgmtVector.size(); i++)               // for loop to print management info
	{                                                      // (only prints name and ID)
		cout << left << setw(20) << mgmtVector[i].mgmtName
			 << setw(30) << mgmtVector[i].mgmtID 
			 << endl;
	}
	
	
	dataBaseFile.open(userFile);   // open userFile
	 // create userVector of type <user>
	user userVar;            // userVar for assigning values to traits
	                         // of user(Name, ID, Password, Car Make, etc..) 
	
	
	// same loop as above, but this time for userVector
	// and extra code to get extra info (car model, make, etc)
	while(getline(dataBaseFile, userVar.userName, ',') && !dataBaseFile.eof())
	{
		getline(dataBaseFile, temp, ','); // read ID and convert to int
		userVar.userID = stoi(temp);      // store in userID
		getline(dataBaseFile, userVar.userPassword, ',');
		getline(dataBaseFile, userVar.carMake, ',');
		getline(dataBaseFile, userVar.carModel, ','); // same code as earlier but now
		getline(dataBaseFile, temp, ',');             // for extra info
		userVar.carYear = stoi(temp);                 // convert carYear to int
		getline(dataBaseFile, userVar.licensePlate, '\n');

		userVector.push_back(userVar);                // send this data to vector
	}
	
	dataBaseFile.close();    // close the file
	
	
	cout << "\n------------------------------------------All User Information---------------------------------------------------------" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Name                 ID         Make        Model              Year      Plate Number" << endl;
	cout << "-----------------------------------------------------------------------------------------------------------------------\n" << endl;
	
	for(int i=0; i < userVector.size(); i++)         // loop to display all user info
	{
		cout << left << setw(20) << userVector[i].userName
			 << setw(10) << userVector[i].userID 
			 << setw(15) << userVector[i].carMake
			 << setw(20) << userVector[i].carModel
			 << setw(4)  << userVector[i].carYear
			 << setw(7)  << "\t" << userVector[i].licensePlate
			 << endl;
	}

		
}




