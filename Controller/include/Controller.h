/*
-----------------------------------------------------------
| Last update: 14/9/2025
| User: Giorgos
| File: Controller.h
| Description: Header file for Controller module
-----------------------------------------------------------
*/

// Controller.h
#ifndef CONTROLLER_H
#define CONTROLLER_H

// forward declarations for your app classes
namespace App {
    class View;
    class Model;
}

// forward declare FLTK widget type so header doesn't require FLTK include
class Fl_Widget;

namespace App {

class Controller {
private:
    View* view;
    Model* model;
public:
    Controller(View* v, Model* m);
    void onUnitSelected(int index);
    void unit_choice_cb(Fl_Widget* w, void* data);
};

} // namespace App

#endif // CONTROLLER_H