//
//  ECFlight.h
//  
//
//

#ifndef ECFlight_h
#define ECFlight_h

#include <string>


// ****************************************************************************
// Flight: service between two airports at a specific time;

class ECFlight 
{
public:
    ECFlight(const std::string &srcIn, const std::string &destIn, double tmDepartIn, int maxPassengersIn);

    virtual ~ECFlight()
    {
    }
    
    // Get departure time
    double GetDepartureTime() const;
    
    // Get arrival time
    double GetArrivalTime() const;
    
    // Set max passenger for this flight
    void SetMaxNumPassengers(int m);
    
    // Get src airport code
    std::string GetSource() const;
    
    // Get destination code
    std::string GetDest() const;

    // more to add...  

    //Sets the arrival time of the flight
    void SetArrivalTime();

    int GetMaxNumPassengers() const;

    void ObserveAirports();

private:
    // your code
    std::string src;
    std::string dest;
    double tmDepart;
    double tmArrive; 
    double maxPassengers;

};

#endif /* ECFlight_h */
