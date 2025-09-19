/*
-----------------------------------------------------------
| Last update: 13/9/2025
| User: Giorgos
| File: Controller.cpp
| Description: Controller functions implementation.
----------------------------------------------------------- 
*/

#include <Controller.h>
#include <iostream>
#include <string>
#include <FL/Fl_Choice.H>
#include <View.h>
#include <Model.h>

using namespace App;

Controller::Controller(View* v, Model* m)
    : view(v), model(m)
{
    std::cout << "Controller constructor called\n";

    // Attach the View callback function that forwards to the view signal
    // Ensure View is already constructed and unit1_choice is valid before calling this.
    view->attachUnitChoiceCallback();
    view->show();

    // subscribe to the view's std::function signal
    view->onUnitSelected = [this](int idx){
        this->onUnitSelected(idx);
    };
}

void Controller::onUnitSelected(int index) {
    std::cout << "Controller::onUnitSelected called with index = " << index << std::endl;
}

void Controller::unit_choice_cb(Fl_Widget* w, void* data) {
    Controller* c = static_cast<Controller*>(data);
    Fl_Choice* choice = static_cast<Fl_Choice*>(w);
    int idx = choice->value();
    c->onUnitSelected(idx);
}