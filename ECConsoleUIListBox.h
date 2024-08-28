//
//  ECConsoleUIListBox.h
//  
//
//

#ifndef ECConsoleUIListBox_h
#define ECConsoleUIListBox_h

#include <string>
#include <vector>

#include "ECConsoleUIItem.h"

//*****************************************************************************
// Console UI list box: several rows (items) to choose from

class ECConsoleUIListBox : public ECConsoleUIItem
{
public:
    // specifiy the portion of the view for this list box
    ECConsoleUIListBox(int xUL, int yUL, int xLR, int yLR );
    
    // Add a choice item
    void AddChoice(const std::string &text);
    
    // Choose an item
    void Choose(int rIndex);
    
    // Get the chosen one
    int GetChoice() const { return indexChoice; }
    
    // Get displayed text at a specific row
    // Text is relative to the item portion (i.e., relative to (xLR, yLR))
    virtual std::string GetTextAtRow(int r) const;
    
    // Get highlighted part (if any); return the row with highlight
    // if one, return -1; also store the highlightd portion (yLeft, yRight) of this row
    // Assume: at most a single row with highlighted part
    virtual int GetHighlightPosition(int &xLeft, int &xRight) const;

    // Are there any other function you might need to override?
    //Functions overrided from parent class

    virtual bool IsHandlingKeys() const;

    // Handle up key
    virtual void HdlKeyUp();

    // Handle down key
    virtual void HdlKeyDown();

    std::string GetChoiceAt() const; 

    void ClearChoices();
    
    
private:
    //Choice of index
    int indexChoice; 

    //Vector of choices
    std::vector<std::string> options;

    //Starting index s
    int s; 
};

#endif /* ECConsoleUIListBox_h */
