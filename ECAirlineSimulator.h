//
//  ECAirlineSimulator.hpp
//  
//
//  Simulate airline activities: booking, flights, etc

#ifndef ECAirlineSimulator_h
#define ECAirlineSimulator_h

#include <string>
#include <set>
#include <vector>
#include <map> 
#include <stack> 

class ECAirlineOperation;
class ECAirlineTicketing;
class ECAirlineFinancial;
class ECFlightItinerary;
//added
class ECFlightItinerary;
class ECFlight;

//****************************************************************************
// Airline simulator

class ECAirlineSimulator
{
public:
    ECAirlineSimulator();
    virtual ~ECAirlineSimulator();
    
    // *****************************************************
    // Configuration
    
    // Adding airport with name and IATA code
    void AddAirport(const std::string &name, const std::string &code);
    
    // Setup distaince between airport; note distance is symmetric: the distance from dest to src is the same as from src to dest
    void SetDistBtwAirports(const std::string &srcAirport, const std::string &destAirport, int dist);
    
    // Adding flights: src airport, dest airport, depart time, max number of passenger, operating cost
    void AddFlight(const std::string &srcAirport, const std::string &destAirport, double tmDepart, int maxPassengers, double costOperate );
    
    // Called to indicate no more flights to add
    void DoneFlightAdding();
    

    // *****************************************************
    // Flight search

    ECFlightItinerary dfs(const std::string &src, const std::string &dest, std::set<std::string> &visited, std::vector<ECFlightItinerary> &listItineraries) const;

    // Searcch for flights; return all flights in listItineraries that go from src to dest
    void SearchForFlights(const std::string &src, const std::string &dest, std::vector<ECFlightItinerary> &itineraries) const;
    
    //Helper Function DFS
    void DFS(const std::string &src, const std::string &dest, std::vector<ECFlightItinerary> &itineraries) const;

    
    // Access airlines
    ECAirlineFinancial *GetAirlineFin() { return pAirlineFin; }
    ECAirlineOperation *GetAirlineOp() { return pAirlineOp; }
    ECAirlineTicketing *GetAirlineTicketing() { return pAirlineTicket; }

    // Returns for now 
    void PreferLowPrice() {return;}
    void PreferShortTime() {return;}
    void PreferEarlyArrival() {return;}
    
    
private:
    // initialize
    void Init();
    
    // key data member
    ECAirlineOperation *pAirlineOp;
    ECAirlineFinancial *pAirlineFin;
    ECAirlineTicketing *pAirlineTicket;
};

#endif /* ECAirlineSimulator_h */


