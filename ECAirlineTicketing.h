//
//  ECAirlineTicketing.h
//  
//
//

#ifndef ECAirlineTicketing_h
#define ECAirlineTicketing_h

#include <vector>
#include "ECAirlineOperation.h"
#include "ECAirlineFinancial.h"
#include "ECFlightItinerary.h"

// ****************************************************************************
// Airline ticketing: search for flights, issue tickets, etc
class ECAirlineTicketing
{

public:
    void SearchForItineraries();
    void OrderItineraries(std::vector<ECFlightItinerary> &itineraries);

    std::vector<ECFlightItinerary> Flights(std::vector<ECFlightItinerary> &itineraries);


private:
    ECAirlineOperation* AirlineOperation;
    ECAirlineFinancial* AirlineFinancial;

};

#endif /* ECAirlineTicketing_h */
