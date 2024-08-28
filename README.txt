In order to compile this code use:
g++ ECAirlineFinancial.cpp ECAirlineOperation.cpp ECAirlineSimulator.cpp ECAirlineTicketing.cpp ECAirport.cpp ECFlight.cpp ECFlightItinerary.cpp ECConsoleUIButton.cpp ECConsoleUIListBox.cpp ECConsoleUITextField.cpp ECConsoleUITextLabel.cpp ECConsoleUIView.cpp ECAirlineReservation.cpp ECTextViewImp.cpp -o test -std=c++14

To run the code do
./test

The main file that combines part 1 and part 3 is called ECAirlineReservation.cpp which basically utilizes the functionality from part 1 and part 3 together.

1. Features that I have implemented that work are scrolling up and down from part 3, search for flights from part 1, the button to search for flights, and the listbox and scrolling for the found itineraries
All of the functionalities that are required and said in the PDF for part 4 work. 

2. Features I have not implemented in Part 4 is the text field and passengers which are extra credit. Everything required for Part 4 was implemented. 

3. Some known bugs include some random symbols that may appear at the end of the list box if there are no flights as shown in video.
To mitigate this I refreshed every time the enter button was pressed and added a choice called END OF FLIGHTS AVAILABLE to make it appear cleaner and less buggy. 

4. I have not implemented any additional features. 

In the video, I show the scrolling for the origin and destinations of flights, then the search for flight button, and scrolling through the itineraries that it founded.

Thank you and have a fantastic summer. 
