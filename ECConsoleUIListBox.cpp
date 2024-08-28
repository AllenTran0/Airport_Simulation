//
//  ECConsoleUIListBox.cpp
//  
//
//

#include "ECConsoleUIListBox.h"
ECConsoleUIListBox :: ECConsoleUIListBox(int xUL, int yUL, int xLR, int yLR ): ECConsoleUIItem(xUL, yUL, xLR, yLR), indexChoice(0), s(0)
{
}

void ECConsoleUIListBox :: AddChoice(const std::string &text)
{
    //Pushes choices into the vector
    options.push_back(text);
}

void ECConsoleUIListBox :: ClearChoices()
{
    //Clears the options vector
    options.clear();
}

void ECConsoleUIListBox :: Choose(int rIndex)
{
    //Sets the indexChoice to the rIndex
    indexChoice = rIndex;
}

std::string ECConsoleUIListBox :: GetTextAtRow(int r) const
{
    //If the row is not within the range of the listbox, return an empty string

    // if( r < GetYUL() || r > GetYLR() )
    // {
    //     return "";
    // }
    std::string str;
    int rconv = r - GetYUL();

    if( rconv <0 || /*rconv >= 1 ||*/ rconv >= GetHeight() )
    {
        return str;
    }

    return options[r-GetYUL()+s];

}

int ECConsoleUIListBox :: GetHighlightPosition(int &xLeft, int &xRight) const
{
    //If there are no options in the listbox, return -1
    if( options.size() == 0 )
    {
        return -1;
    }

    else
    {
        xLeft = 0;
        xRight = GetWidth()-1;
        //Return the indexChoice
        return indexChoice - s;
    }

    return 0; 
}

bool ECConsoleUIListBox :: IsHandlingKeys() const
{
    return true; 
}

void ECConsoleUIListBox :: HdlKeyUp() 
{
    //If the indexChoice is greater than 0, decrement the indexChoice
    if(indexChoice > 0)
    {
        indexChoice--;

        if(indexChoice < s)
        {
            s--;
        }
    }
}

void ECConsoleUIListBox :: HdlKeyDown()
{
    //If the indexChoice is less than the size of the options vector, increment the indexChoice
    if(indexChoice < (int)options.size()-1)
    {
        indexChoice++;

        if(indexChoice >= s + GetHeight())
        {
            s++;
        }
    }

}

std::string ECConsoleUIListBox :: GetChoiceAt() const
{
    return options[indexChoice];
}