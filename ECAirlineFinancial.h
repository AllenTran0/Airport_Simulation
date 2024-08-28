//
//  ECAirlineFinancial.h
//  


#ifndef ECAirlineFinancial_h
#define ECAirlineFinancial_h

#include "ECAirlineOperation.h"
#include "ECFlightItinerary.h"
// ****************************************************************************
// Airline finanical: budgetting, pricing and money bookkeeping

class ECAirlineFinancial
{

public:
    double CalculatePrice(ECFlightItinerary &itinerary) const;

private:
    ECAirlineOperation* AirlineOperation; 

};

#endif
