//
//  ECAirlineFinancial.cpp
//  

#include "ECAirlineFinancial.h"
#include "ECAirlineOperation.h"
#include "ECFlightItinerary.h"

#include <string>
#include <iostream>
using namespace std;

double CalculatePrice(ECFlightItinerary &itinerary)
{
    double flightTime = itinerary.GetFlightTime();
    double price = 120*flightTime;
    
    return price; 
}
