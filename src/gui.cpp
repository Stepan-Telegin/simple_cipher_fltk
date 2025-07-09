#include <FL/fl_ask.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Group.H>
#include <FL/Enumerations.H>
#include "inc/gui.hpp"
#include "inc/cipher.hpp"

void create_widgets(Fl_Window *window)
{
    Fl_Input *text_input = new Fl_Input(240, 60, 320, 32, "Text:");
    text_input->color(FL_WHITE);
    text_input->textcolor(FL_BLUE);
    text_input->labelcolor(FL_BLUE);

    Fl_Input *key_input = new Fl_Input(240, 120, 320, 32, "Key:");
    key_input->color(FL_WHITE);
    key_input->textcolor(FL_BLACK);
    key_input->labelcolor(FL_BLACK);

    Fl_Output *text_output = new Fl_Output(240, 180, 320, 32, "Result:");
    text_output->color(FL_WHITE);
    text_output->textcolor(FL_RED);
    text_output->labelcolor(FL_RED);

    Fl_Button *encode_button = new Fl_Button(260, 240, 120, 36, "Encode");
    encode_button->color(FL_BLUE);
    encode_button->labelcolor(FL_WHITE);

    Fl_Button *decode_button = new Fl_Button(420, 240, 120, 36, "Decode");
    decode_button->color(FL_BLACK);
    decode_button->labelcolor(FL_WHITE);

    Cipher *cipher = new Cipher();
    Widgets *widgets = new Widgets;
    widgets->text_input = text_input;
    widgets->key_input = key_input;
    widgets->text_output = text_output;
    widgets->cipher = cipher;

    encode_button->callback(encode_callback, widgets);
    decode_button->callback(decode_callback, widgets);
}

void process_cipher(Widgets *widgets, bool encode)
{
    std::string text = widgets->text_input->value();
    std::string key = widgets->key_input->value();
    std::string mode;
    if (encode)
    {
        mode = "encrypt";
    }
    else
    {
        mode = "decrypt";
    }
    if (text.empty())
    {
        fl_alert((std::string("Enter text to ") + mode + "!").c_str());
        return;
    }
    if (key.empty())
    {
        fl_alert((std::string("Enter key to ") + mode + "!").c_str());
        return;
    }
    std::string result;
    if (encode)
    {
        result = widgets->cipher->encode(text, key);
    }
    else
    {
        result = widgets->cipher->decode(text, key);
    }
    widgets->text_output->value(result.c_str());
}

void encode_callback(Fl_Widget *widget, void *data)
{
    process_cipher(static_cast<Widgets *>(data), true);
}

void decode_callback(Fl_Widget *widget, void *data)
{
    process_cipher(static_cast<Widgets *>(data), false);
}