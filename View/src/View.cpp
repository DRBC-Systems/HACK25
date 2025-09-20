/*
-----------------------------------------------------------
| Last update: 13/9/2025
| User: Giorgos
| File: View.cpp
| Description: View functions implementation
-----------------------------------------------------------
*/

#include <View.h>
#include <string>
#include <FL/fl_message.H>
#include <cassert>

using namespace App;

    const char* unit_Titles[] = {
        "Unit 1",
        "Unit 2",
        "Unit 3",
        "Unit 4",
        "Unit 5",
        nullptr  // terminator
    };

    Fl_Menu_Item View::unit_items[] = {
    {"Option 1", 0, 0, 0},
    {"Option 2", 0, 0, 0},
    {"Option 3", 0, 0, 0},
    {"Option 4", 0, 0, 0},
    {"Option 5", 0, 0, 0},
    {"Option 6", 0, 0, 0},
    {"Option 7", 0, 0, 0},
    {"Option 8", 0, 0, 0},
    {"Option 9", 0, 0, 0},
    {"Option 10", 0, 0, 0},
    {"Option 11", 0, 0, 0},
    {"Option 12", 0, 0, 0},
    {"Option 13", 0, 0, 0},
    {"Option 14", 0, 0, 0},
    {"Option 15", 0, 0, 0},
    {0} // terminator
};


View::View() {
    // Create the window
    int screenW = Fl::w();  // screen width
    int screenH = Fl::h();  // screen height

    int winW = (int) (screenW * 0.4);
    int winH = (int) (screenH * 0.6);
    window = new Fl_Window(100,100, winH,winW, "My App");
    createBackround(winW, winH);
    createUnits(winW, winH);

    // End window construction
    window->end();
}


void View::createBackround(int winW, int winH){
    // Set purple background
    window->color(fl_rgb_color(52, 21, 57));

    // Create a border box at the top to replicate an outline
    Fl_Box* borderBox = new Fl_Box(0, 0, winW-153, 50);
    borderBox->box(FL_FLAT_BOX);
    borderBox->color(fl_rgb_color(35, 10, 45));
    borderBox->label(NULL);

    // Create a box for the title
    title = new Fl_Box(2, 2, winW-153, winH-573);
    title->box(FL_FLAT_BOX);
    title->color(fl_rgb_color(120, 60, 140));

    // Center text
    title->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE);
    title->label("PIPINGO");
    title->labelfont(FL_TIMES_BOLD_ITALIC);
    title->labelsize(36);

    // Optional: text color
    title->labelcolor(fl_rgb_color(210, 120, 30));
}


void View::createUnits(int winW, int winH){
    
    for (int i = 0; i < 300 ; i += 100){
        // Dropdown choice
        Fl_Box* unit_label_bg = new Fl_Box(45, 100 + i, 73, 50, unit_Titles[i/100] );
        unit_label_bg->box(FL_BORDER_BOX);
        unit_label_bg->color(fl_rgb_color(35, 10, 45));  // purple background
        unit_label_bg->size(130, 50);

        unit_label_bg->labelsize(36);
        unit_label_bg->labelcolor(fl_rgb_color(255, 255, 255)); // label white
        unit_label_bg->labelfont(FL_HELVETICA_BOLD);

    
        Fl_Choice* choice = new Fl_Choice(210, 100 + i, 360, 50, "");
       // unit_choice->callback(unit_choice_cb, controller);
        choice->menu(unit_items);
        choice->box(FL_FLAT_BOX);
        choice->color(fl_rgb_color(35, 10, 45));    // purple background
        choice->labelcolor(fl_rgb_color(255, 255, 255)); // label white
        choice->labelfont(FL_HELVETICA_BOLD);
        choice->textsize(20);

        choice->callback([](Fl_Widget* w, void* data){
            View* view = static_cast<View*>(data);
            Fl_Choice* choice = static_cast<Fl_Choice*>(w);
            int idx = choice->value();

            // Always-visible debug
            fl_message("DEBUG: View callback called; idx=%d", idx);
            std::cerr << "DEBUG: View callback idx=" << idx << std::endl;

            if (view->onUnitSelected) {
                view->onUnitSelected(idx);
            } else {
                std::cerr << "DEBUG: onUnitSelected not set\n";
            }
        }, this);
    }


}


void View::show() {
    window->show();
}
