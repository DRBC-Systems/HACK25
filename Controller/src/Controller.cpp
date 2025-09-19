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

Controller::Controller(App::View* view, Model* m) {
    view->setController(this);
    view->attachUnitChoiceCallback();
}

void Controller::onUnitSelected(int index) {
    // For example, update model or print selection
    std::cout << "Selected unit index: " << index << std::endl;
}
/*
void Controller::unit_choice_cb(Fl_Widget* w, void* data) {
    Controller* c = static_cast<Controller*>(data);
    Fl_Choice* choice = static_cast<Fl_Choice*>(w);
    int idx = choice->value(); // selected index
    c->onUnitSelected(idx);
}*/