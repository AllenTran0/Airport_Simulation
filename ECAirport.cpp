//
//  ECAirport.cpp
//  
//
//

#include "ECAirport.h"
#include <map> 

#include <iostream>

/**********************************************/
//ECAirport
ECAirport :: ECAirport() {
}
ECAirport :: ECAirport(const std::string &nameAP, const std::string &codeIATA) : nameAP(nameAP), codeIATA(codeIATA) {}
ECAirport :: ECAirport (const ECAirport &rhs) {} 

std::string ECAirport :: GetName() const {return nameAP;}
std::string ECAirport :: GetCode() const {return codeIATA;}

bool ECAirport :: IsOperating() {return operating;}
void ECAirport :: SetOperating(bool f) {operating = f;}

/**********************************************/
//ECAirportInfo
ECAirportInfo* ECAirportInfo::_inst = nullptr;

ECAirportInfo :: ECAirportInfo() {}

void ECAirportInfo :: CreateAirport(const std::string &name, const std::string &code) 
{
    ECAirport airport(name, code);
    airports[code] = airport;
}

const ECAirport& ECAirportInfo :: GetAirport(const std::string &code) const
{   
    if (airports.find(code) == airports.end())
    {
        throw std::string("Airport not found");
    }
    return airports.at(code);
}
//Set the distances in a map between the two airports
void ECAirportInfo :: SetDistanceBtw(const std::string &ap1Code, const std::string &ap2Code, int dist)
{
    distBtwAirports[std::pair<std::string, std::string>(ap1Code, ap2Code)] = dist;
    distBtwAirports[std::pair<std::string, std::string>(ap2Code, ap1Code)] = dist;
}

//Returns the distances between the two airports
int ECAirportInfo :: GetDistanceBtw(const std::string &ap1Code, const std::string &ap2Code) const
{
    return distBtwAirports.at(std::pair<std::string, std::string>(ap1Code, ap2Code));
}

void ECAirportInfo :: SetTime(const std::string &ap1Code, const std::string &ap2Code, int dist)
{
    timeBtwAirports[std::pair<std::string, std::string>(ap1Code, ap2Code)] = dist/500.0;
    timeBtwAirports[std::pair<std::string, std::string>(ap2Code, ap1Code)] = dist/500.0;
}

double ECAirportInfo :: GetTime(const std::string &ap1Code, const std::string &ap2Code) const
{
    return timeBtwAirports.at(std::pair<std::string, std::string>(ap1Code, ap2Code));
}

//Returns the airport
ECAirportInfo* ECAirportInfo :: GetInstance()
{
    if (_inst == nullptr)
    {
        _inst = new ECAirportInfo();
    }
    return _inst;
}

std::map<std::string, ECAirport> ECAirportInfo :: GetAirports() const
{
    return airports;
}


