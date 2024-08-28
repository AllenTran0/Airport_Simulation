//
//  ECFlight.cpp
//  
//
//

#include "ECFlight.h"
#include "ECAirport.h"

#include <iostream>
using namespace std;

ECFlight :: ECFlight(const std::string &srcIn, const std::string &destIn, double tmDepartIn, int maxPassengersIn) : src(srcIn), dest(destIn), tmDepart(tmDepartIn), maxPassengers(maxPassengersIn)
{
    SetArrivalTime();
}

double ECFlight :: GetDepartureTime() const
{
    return tmDepart; 
}

double ECFlight :: GetArrivalTime() const
{
    return tmArrive;
}

void ECFlight :: SetMaxNumPassengers(int m)
{
    maxPassengers = m; 
}

std::string ECFlight :: GetSource() const
{
    return src; 
}

std::string ECFlight :: GetDest() const
{
    return dest; 
}

void ECFlight :: SetArrivalTime() 
{
    tmArrive = GetDepartureTime() + ECAirportInfo::GetInstance()->GetTime(GetSource(), GetDest());
}

int ECFlight :: GetMaxNumPassengers() const
{
    return maxPassengers;
}


