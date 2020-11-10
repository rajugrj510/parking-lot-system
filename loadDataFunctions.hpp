using namespace std;
// Prevents redefinitions when including the same header multiple times
#pragma once

// Does the same thing, just to make sure 
// (some compilers don't support #pragma once)
#ifndef loadDataFunctions_HPP
#define loadDataFunctions_HPP
#include "adminStructure.h"
#include "mgmtStructure.h"
#include "userStructure.h"
#include <fstream>
#include <string>
#include <array>
#include <iomanip>
#include <vector>

// data structure for admin database
    void loadParkingLotData(vector <admin>&, vector <management>&, vector <user>&);
    void loadDataBases(string, string, string, vector <admin>&, vector <management>&, vector <user>&);


#endif


