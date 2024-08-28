#include "ECAirport.h"
#include "ECAirlineOperation.h"
#include "ECAirlineTicketing.h"
#include "ECAirlineFinancial.h"
#include "ECFlightItinerary.h"
#include "ECAirlineSimulator.h"

#include "ECTextViewImp.h"
#include "ECConsoleUIView.h"
#include "ECConsoleUITextLabel.h"
#include "ECConsoleUIListBox.h"
#include "ECConsoleUITextField.h"
#include "ECConsoleUIButton.h"

#include <string>
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;

void check_spaces(string &str, std::vector <int> &inSpaces)
{

    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == ' ')
        {
            inSpaces.push_back(i);
        }

    }
}


void read_config(ECConsoleUIListBox *orig, ECConsoleUIListBox *dest, ECAirlineSimulator *sim, const std::string &filename)
{
    ifstream file(filename);

    string line; 
    string nums;

    while(getline(file, line))
    {
        if(line[0] == '#')
        {
            continue;
        }
        string apCode;
        string apName;
        string apCode1;
        string apCode2;
        double depTime;
        int cap; 
        int distance;
        int costOperate;
        std::vector<int> inSpaces;

        switch (line[0]){
            case '1':
                apCode = line.substr(2, 3);
                apName = line.substr(6, 7);
                orig->AddChoice(apCode);
                dest->AddChoice(apCode);
                sim->AddAirport(apName, apCode);
                break;
            case '2':
                apCode1 = line.substr(2, 3);
                apCode2 = line.substr(6, 3);
                check_spaces(line, inSpaces);
                distance = stoi(line.substr(inSpaces[2]+1, 4));
                sim->SetDistBtwAirports(apCode1, apCode2, distance);
                break;
            case '3':
                apCode1 = line.substr(2, 3);
                apCode2 = line.substr(6, 3);
                check_spaces(line, inSpaces);
                depTime = stod(line.substr(inSpaces[2]+1, inSpaces[3]-inSpaces[2]-1));
                cap = stoi(line.substr(inSpaces[3]+1, inSpaces[4]-inSpaces[3]-1));
                costOperate = stoi(line.substr(inSpaces[4]+1, inSpaces[5]-inSpaces[4]-1));
                sim->AddFlight(apCode1, apCode2, depTime, cap, distance);
                break;
            default:
                break;
        }
    }
    file.close();

}

// construct a simple UI
static void Test1(ECConsoleUIView &viewTest,const  std::string& filename, ECAirlineSimulator *sim)
{
    // create several labels
    ECConsoleUITextLabel *AirlineName = new ECConsoleUITextLabel(15, 1, "Galaxy Airlines Flight Reservation System");
    AirlineName->SetHighlight(true);
    viewTest.AddUIItem(AirlineName);
    ECConsoleUITextLabel *ori = new ECConsoleUITextLabel(15, 5, "Origination");
    viewTest.AddUIItem(ori);
    ECConsoleUITextLabel *dest= new ECConsoleUITextLabel(40, 5, "Destination");
    viewTest.AddUIItem(dest);

    // Create a border (well, not very pretty)
    string horizBar;
    for(int i=0; i<viewTest.GetColNumInView(); ++i)
    {
        horizBar += '-';
    }
    
    ECConsoleUITextLabel *horibar = new ECConsoleUITextLabel(0, 0, horizBar);
    viewTest.AddUIItem(horibar);
    ECConsoleUITextLabel *horibar2 = new ECConsoleUITextLabel(0, viewTest.GetRowNumInView()-1, horizBar);
    viewTest.AddUIItem(horibar2);

    // Add a list box
    ECConsoleUIListBox *srcBox = new ECConsoleUIListBox(15, 7, 35, 9 );
    ECConsoleUIListBox *destBox = new ECConsoleUIListBox(40, 7, 45, 9 );
    std::vector<string> apCodes;
    read_config(srcBox, destBox, sim, filename);

    srcBox->Choose(0);
    viewTest.AddUIItem(srcBox);

    destBox->Choose(0);
    viewTest.AddUIItem(destBox);

    ECConsoleUITextLabel *flights = new ECConsoleUITextLabel(30, 14, "Flights");
    viewTest.AddUIItem(flights);

    ECConsoleUIListBox *route = new ECConsoleUIListBox(20, 16, 70, 18);

    ECConsoleUISearchButton *fs = new ECConsoleUISearchButton(20, 12, 45, 12, "Search for flights", srcBox, destBox, route, sim, &viewTest);
    viewTest.AddUIItem(fs);

}



int main(int argc, char *argv[])
{
    ECTextViewImp wndTest;
    std::string file = "config.txt";
    if (argc > 1){
        file = argv[1];
    }
    // add a status bar
    wndTest.AddStatusRow("UI test", "For demo only", true);
    
    // Create a console UI view
    ECConsoleUIView viewUI(&wndTest);
        
    ECAirlineSimulator sim;
   
    // Add a few UI items
    Test1(viewUI, file, &sim);
    
    // Display it
    viewUI.Refresh();
    
    // Show the window
    try {
        wndTest.Show();
    }
    catch(std::string ex)
    {
        cout << "Exception: " << ex << endl;
    }
    return 0;
}
