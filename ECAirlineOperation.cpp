//
//  ECAirlineOperation.cpp
//  


#include "ECAirlineOperation.h"
#include "ECFlightItinerary.h"
#include "ECAirlineFinancial.h"

#include <iostream>
#include <string>
using namespace std;

void ECAirlineOperation :: addFlight(ECFlight* flight)
{
    listFlights.push_back(flight);
}

void ECAirlineOperation :: PostFlightSetup()
{
}

void ECAirlineOperation :: removeFlight(ECFlight* flight)
{
    // listFlights.erase(std::remove(listFlights.begin(), listFlights.end(), flight), listFlights.end());
}
