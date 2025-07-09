#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Enumerations.H>
#include "inc/gui.hpp"

int main()
{
    Fl_Window *window = new Fl_Window(800, 480, "Simple Cipher");
    window->color(FL_LIGHT2);
    create_widgets(window);
    window->show();
    return Fl::run();
}