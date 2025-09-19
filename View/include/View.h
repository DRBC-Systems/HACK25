/*
-----------------------------------------------------------
| Last update: 13/9/2025
| User: Giorgos
| File: View.h
| Description: Header file for View module
-----------------------------------------------------------
*/

#ifndef VIEW_H
#define VIEW_H

#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Menu_Button.H>
#include <Controller.h>

namespace App 
{

class View {
private:
    Fl_Window* window;
    Fl_Button* button;
    Fl_Box* title;
    static Fl_Menu_Item unit1_items[];
    Fl_Choice* unit1_choice;
    Fl_Menu_Button* unit1_button;
    
    Controller* controller;
public:
    View();
    void show();
    void createBackround(int, int);
    void createUnits(int, int);
    void setController(Controller* c); // store pointer for callbacks
    void attachUnitChoiceCallback();
};

}
#endif