//
//  ECAirlineSimulator.cpp
//  

#include "ECAirlineSimulator.h"
#include "ECAirlineOperation.h"
#include "ECAirlineTicketing.h"
#include "ECAirlineFinancial.h"
#include "ECAirport.h"
#include "ECFlight.h"
#include "ECFlightItinerary.h"

#include <iostream>
#include <stack>


using namespace std;
ECAirlineSimulator :: ECAirlineSimulator()
{
    Init();
}

/**************DESTRUCTOR***************/
ECAirlineSimulator :: ~ECAirlineSimulator()
{
    delete pAirlineOp;
    delete pAirlineFin;
    delete pAirlineTicket;
}

/***************CONFIGURATION*****************/
void ECAirlineSimulator :: AddAirport(const std::string &name, const std::string &code)
{
    ECAirport *pAirport = new ECAirport(name, code);
    ECAirportInfo::GetInstance()->CreateAirport(name, code);
}

void ECAirlineSimulator :: SetDistBtwAirports(const std::string &srcAirport, const std::string &destAirport, int dist)
{
    ECAirportInfo::GetInstance()->SetTime(srcAirport, destAirport, dist);
    ECAirportInfo::GetInstance()->SetDistanceBtw(srcAirport, destAirport, dist);
}

void ECAirlineSimulator :: AddFlight(const std::string &srcAirport, const std::string &destAirport, double tmDepart, int maxPassengers, double costOperate )
{
    ECFlight *pFlight = new ECFlight(srcAirport, destAirport, tmDepart, maxPassengers);
    pAirlineOp->addFlight(pFlight);
}

void ECAirlineSimulator :: DoneFlightAdding()
{

}


/***************FLIGHT SEARCH*****************/

void ECAirlineSimulator :: DFS(const std::string &src, const std::string &dest, std::vector<ECFlightItinerary> &itineraries) const
{
    //Get all the flights
    std::vector<ECFlight *> currentFlights = pAirlineOp->GetFlights();

    //Create a map of source to flights
    std::map<std::string, std::vector<ECFlight *> > adj;

    stack<ECFlightItinerary> s;
    
    //Creates the adjacency list
    for (auto i = 0; i < currentFlights.size(); i++)
    {
        adj[currentFlights[i]->GetSource()].push_back(currentFlights[i]);

        if(currentFlights[i]->GetSource() == src){
            ECFlightItinerary itinerary;
            itinerary.AddSegment(currentFlights[i]);
            s.push(itinerary);
        }
    }

    //Gets the last flight
    ECFlight* latestFlight; 
    while (!s.empty())
    {
        //Gets the top of the stack and pops it
        ECFlightItinerary v = s.top();
        s.pop();

        //Gets the segment of the last flight in the itinerary
        ECFlight* latestFlight = v.GetSegment(v.GetNumSegments()-1);
        
        //Creates a set of visited airports
        std::set<std::string> beenVisited;
        
        //Adds all the visited airports to the set
        for(int i = 0; i < v.GetNumSegments(); i++)
        {

            beenVisited.insert(v.GetSegment(i)->GetSource());

        }

        //If the last flight destination is the destination, add the itinerary to the list
        if(latestFlight->GetDest() == dest)
        {
            itineraries.push_back(v);
        }


        //For each flight in the adjacency list
        for(auto flight : adj[latestFlight->GetDest()])
        {
            //If the departure time of the flight is greater than the arrival time of the last flight
            if(latestFlight->GetArrivalTime() <= flight->GetDepartureTime())
            {
                //If the destination of the flight is not in the visited set
                if(beenVisited.find(flight->GetDest()) == beenVisited.end())
                {
                    ECFlightItinerary itin = v;

                    itin.AddSegment(flight);

                    s.push(itin);
                }
            }
        }

    }
}

void ECAirlineSimulator :: SearchForFlights(const std::string &src, const std::string &dest, std::vector<ECFlightItinerary> &listItineraries ) const
{
    if (src != dest)
    {
        //Call DFS
        DFS(src, dest, listItineraries);
    }

}

/********************INITIALIZATION******************/
void ECAirlineSimulator :: Init()
{
    pAirlineOp = new ECAirlineOperation;
    pAirlineFin = new ECAirlineFinancial;
    pAirlineTicket = new ECAirlineTicketing;
}