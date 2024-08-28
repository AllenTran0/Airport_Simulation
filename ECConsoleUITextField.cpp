//
//  ECConsoleUITextField.cpp
//  
//
//

#include "ECConsoleUITextField.h"
#include "ECTextViewImp.h"

#include <iostream>
using namespace std;

ECConsoleUITextField :: ECConsoleUITextField(ECTextViewImp *pTextView, int xpos, int ypos, int len) : ECConsoleUIItem(xpos, ypos, xpos+len-1, ypos), pTextView(pTextView), fEditMode(false)
{
    strInput = ": ";
}

std::string ECConsoleUITextField :: GetTextAtRow(int r) const
{

    string strOut;
    int rconv = r - GetYUL();
    if( rconv == 0 )
    {
        strOut = this->strInput;
    }

    return strOut;
}

int ECConsoleUITextField :: GetHighlightPosition(int &xLeft, int &xRight) const
{
    //Returns -1
    return -1;
}

void ECConsoleUITextField :: HdlKeyEnter()
{
    //If the user is in edit mode, set the edit mode to true
    fEditMode = true;
    pTextView->Refresh();
    string str = GetTextAtRow(GetYUL());
    pTextView->SetCursorX(GetXUL() + str.size());
    pTextView->SetCursorY(GetYUL());
}

void ECConsoleUITextField :: HdlOtherKey()
{
    //If the user is in edit mode, get the key pressed by the user
    if (fEditMode == true)
    {
        //Get the key pressed by the user
        int c = pTextView->GetPressedKey();
        if (c == BACKSPACE)
        {
            if (strInput.size() > 0)
            {
                strInput.pop_back();
            }
        }

        //If the user presses CTRL C, set the edit mode to false
        else if (c == CTRL_C)
        {
            fEditMode = false;
        }

        else
        {
            strInput.push_back(c);
        }
        string str = GetTextAtRow(GetYUL());
        pTextView->SetCursorX(GetXUL() + str.size());
        pTextView->SetCursorY(GetYUL());
    }

    pTextView->Refresh();
}

