    #pragma once
    #include <string>
/**
 * This is a header file for User database.
 * 7 variable are created 
 * userName - to store Name of the user
 * userPassword - to store password of the user
 * userID - to store user ID information 
 * carMake - To store information of the make
 * carModel- to store car model
 * licensePlate to store car licenseplate
 * carYear - to store car year
 */
    // data structure for user database
    // you can add to it for ticket info etc
        class user
        {
            public:
                std::string userName; //to  hold  name of the user
                std::string userPassword; //To hold password of the user
                std::string carMake; // To hold make of the car
                std::string carModel; //to hold the name of the car model
                std::string licensePlate; // to hold license plate name 
                int   carYear; // to hold car year
                int userID; //to hold user ID number
       };     