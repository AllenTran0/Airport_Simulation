//
//  ECAirlineOperation.h
//  
//
//  About operation of an airline: especially flights management

#ifndef ECAirlineOperation_h
#define ECAirlineOperation_h

#include <vector>
#include "ECFlight.h"

// put your code about airline operation here...
class ECAirlineOperation
{
public:
    ECAirlineOperation() {}
    ~ECAirlineOperation() {}

    // add a flight to the airline
    void addFlight(ECFlight* flight);
    
    void PostFlightSetup(); 

    void removeFlight(ECFlight* flight);

    std::vector<ECFlight *> GetFlights() { return listFlights; }


private:
    std::vector<ECFlight *> listFlights; 
};

#endif