/*
-----------------------------------------------------------
| Last update: 14/9/2025
| User: Giorgos
| File: Controller.h
| Description: Header file for Controller module
-----------------------------------------------------------
*/

#ifndef CONTROLLER_H
#define CONTROLLER_H

namespace App 
{
class View;  // forward declaration
class Model; // forward declaration
class Controller {
private:
    View* view;
    Model* model; 
public:
    Controller(View* v , Model* m );
    void onUnitSelected(int index);
    void unit_choice_cb(Fl_Widget* w, void* data);
};

}
#endif