//
//  ECConsoleUIButton.h
//  
//
//

#ifndef ECConsoleUIButton_h
#define ECConsoleUIButton_h

#include <string>
#include <vector>

#include "ECConsoleUIItem.h"
#include "ECConsoleUIView.h"
#include "ECConsoleUIListBox.h"
#include "ECTextViewImp.h"
#include "ECAirlineSimulator.h"
#include "ECFlightItinerary.h"

//*****************************************************************************
// Console UI button: with a text and can be clicked

class ECConsoleUIButton : public ECConsoleUIItem
{
public:
    // specifiy the portion of the view for this button and the text
    ECConsoleUIButton(int xUL, int yUL, int xLR, int yLR, const std::string &textButton );

    // Get position info
    virtual int GetYUL() const { return ECConsoleUIItem::GetYUL()-1; }
    virtual int GetYLR() const { return ECConsoleUIItem::GetYLR()+1; }
    virtual int GetHeight() const { return GetYLR()-GetYUL()+1; }

    // Get displayed text at a specific row (absolute row in the screen/view sense; not specific to the item)
    // Text is relative to the item portion (i.e., relative to (xLR, yLR))
    virtual std::string GetTextAtRow(int r) const;

    // Get highlighted part (if any); return the row with highlight
    // if one, return -1; also store the highlightd portion (yLeft, yRight) of this row
    // Assume: at most a single row with highlighted part
    virtual int GetHighlightPosition(int &xLeft, int &xRight) const;
    
    // Handle up key
    // Is responding to keys? YES: button handles keys!
    virtual bool IsHandlingKeys() const { return true; }
    // Handle enter key
    virtual void HdlKeyEnter();
    
private:
    std::string strButton;
    ECTextViewImp *pTextView;
};

class ECConsoleUISearchButton : public ECConsoleUIButton
{
public:
    ECConsoleUISearchButton(int xUL, int yUL, int xLR, int yLR, const std::string &textButton, ECConsoleUIListBox *inSrcBox, ECConsoleUIListBox *inDstBox, ECConsoleUIListBox *inRouteBox, ECAirlineSimulator *inSim, ECConsoleUIView *viewTest);
    virtual void HdlKeyEnter();

private:
    ECConsoleUIListBox *srcBox;
    ECConsoleUIListBox *dstBox;
    ECConsoleUIListBox *routeBox;
    ECAirlineSimulator *sim;
    ECConsoleUIView *viewTest;
    bool pressed = false;
    ECTextViewImp *pTextView;
};

#endif /* ECConsoleUIButton_h */
