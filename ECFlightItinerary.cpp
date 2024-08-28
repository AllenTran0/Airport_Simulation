//
//  ECFlightItinerary.cpp
//  
//
//

#include "ECFlightItinerary.h"
#include "ECFlight.h"
#include <iostream>
#include <string>
#include <set>
using namespace std;

ECFlightItinerary :: ECFlightItinerary() {}

int ECFlightItinerary :: GetNumSegments() const
{
    return segments.size();
}

ECFlight* ECFlightItinerary :: GetSegment(int segIndex) const
{
    return segments[segIndex];
}

double ECFlightItinerary :: GetFlightTime() const
{
    double TotalSegmentTime = 0;

    //Adds up all the time by subtracting the arrival time from departure time
    for (int i = 0; i < segments.size(); i++)
    {
        TotalSegmentTime += segments[i]->GetArrivalTime() - segments[i]->GetDepartureTime();
    }

    return TotalSegmentTime;
    //Subtracts the arrival time of the last segment from the departure time of the first segment
}

double ECFlightItinerary :: GetTimeAllSegments() const
{
    return segments[segments.size()-1]->GetArrivalTime() - segments[0]->GetDepartureTime();
}

double ECFlightItinerary :: GetDepartTime() const
{
    return segments[0]->GetDepartureTime(); 
}

double ECFlightItinerary :: GetArrivalTime() const
{
    return segments[segments.size()-1]->GetArrivalTime();

}

double ECFlightItinerary :: GetPrice() const
{
    
    return 120*GetFlightTime(); 

}

void ECFlightItinerary :: AddSegment(ECFlight *seg)
{
    segments.push_back(seg);
}

void ECFlightItinerary :: ClearSegment()
{
    segments.clear();
}

void ECFlightItinerary :: RemoveLastSegment()
{
    segments.pop_back();

}
void ECFlightItinerary :: Dump() const
{
    cout << "Itinerary: ";
    for (int i = 0; i < segments.size(); i++)
    {
        cout << segments[i]->GetSource() << " -> " << segments[i]->GetDest() << " , ";
        cout << "Depart time: " << segments[i]->GetDepartureTime() << " " << segments[i]->GetArrivalTime() << " " << endl;

    }
    cout << endl;
    // cout << "Depart time: " << GetDepartTime() << endl;
    // cout << "Arrive time: " << GetArrivalTime() << endl;
    // cout << "Flight time: " << GetFlightTime() << endl;
    // cout << "Price: " << GetPrice() << endl;
    // cout << "Number of segments: " << GetNumSegments() << endl;
    // cout << "Time of all segments: " << GetTimeAllSegments() << endl;
    cout << endl;
}

