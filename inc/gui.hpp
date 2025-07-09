#pragma once
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Widget.H>
#include "inc/cipher.hpp"

struct Widgets
{
    Fl_Input *text_input;
    Fl_Input *key_input;
    Fl_Output *text_output;
    Cipher *cipher;
};

void encode_callback(Fl_Widget *widget, void *data);
void decode_callback(Fl_Widget *widget, void *data);
void create_widgets(Fl_Window *window);