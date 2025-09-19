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

    view->show();

    view->onUnitSelected = [this](int idx) {
        std::cout << "DEBUG: Controller subscriber lambda called with idx=" << idx << std::endl;
        this->onUnitSelected(idx);
    };
    
    std::cout << "DEBUG: Controller subscribed to view->onUnitSelected\n";

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