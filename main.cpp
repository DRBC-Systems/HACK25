#include <FL/Fl.H>
#include <View.h>
#include <Controller.h>
#include <Model.h>
#include <iostream>
using namespace App;

int main() {
    Model m;  // call constructor
    View v;   // call constructor
    Controller c(&v, &m); // pass view and model to controller
    std::cout << "Main finished succefully . " << std::endl;
    return Fl::run();
}