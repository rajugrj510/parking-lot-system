#pragma once    
#include <string>


    // data structure for ticket database
    // you can add to it for ticket info etc
        class ticket
        {
            public:
                std::string ticketStatus; // To hold ticket status like "Paid" or "Unpaid"
                std::string ticketReason; // To hold ticket Reasons like "Illegal Parking"
                std::string ticketLicensePlate; //To hold License plate number
                int ticketID; //To hold Ticket ID Number
                long issuerID; //TO hold the who issued the ticket 
                float ticketAmount; //TO hold the total amount of ticket to be paid
       };  