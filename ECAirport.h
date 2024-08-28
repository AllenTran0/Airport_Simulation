//
//  ECAirport.h
//  
//
//

#ifndef ECAirport_h
#define ECAirport_h

#include <string>
#include <set>
#include <map>


// ****************************************************************************
// Airport: start/end point of a flight

class ECAirport 
{
public:
    // by default, airport is operating (except in default constructor)
    ECAirport(); 
    ECAirport(const std::string &nameAP, const std::string &codeIATA);
    ECAirport(const ECAirport &rhs);
    
    // Get the name of the airport
    std::string GetName() const;
    
    // Get IATA code
    std::string GetCode() const;
    
    // Operating status: is it operating normally?
    bool IsOperating();
    
    // Set operating status
    void SetOperating(bool f);
    
private:
    // your ocde
    std::string nameAP;
    std::string codeIATA; 
    bool operating;
};

// ****************************************************************************
// Airport info: access airport information
// Use singleton pattern

class ECAirportInfo
{
public:
    
    // Create a new airport in the system
    void CreateAirport(const std::string &name, const std::string &code);
    
    // Get airport by code
    // Throw exception (std::string) if there is no airport with the code
    const ECAirport &GetAirport(const std::string &code) const;
    
    // Set distance (in miles) between airports
    void SetDistanceBtw(const std::string &ap1Code, const std::string &ap2Code, int dist);
    
    // more to add...
    int GetDistanceBtw(const std::string &ap1Code, const std::string &ap2Code) const;

    void SetTime(const std::string &ap1Code, const std::string &ap2Code, int dist);

    double GetTime(const std::string &ap1Code, const std::string &ap2Code) const;

    static ECAirportInfo *GetInstance();

    //Returns map of all airports
    std::map<std::string, ECAirport> GetAirports() const;

protected:
    ECAirportInfo();
    
private:
   // your code 
    double time; 
    std::map<std::string, ECAirport> airports;
    std::map<std::pair<std::string, std::string>, int> distBtwAirports;
    std::map<std::pair<std::string, std::string>, double> timeBtwAirports; 
    static ECAirportInfo* _inst;
};


#endif /* ECAirport_h */
