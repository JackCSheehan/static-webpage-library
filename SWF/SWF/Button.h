#ifndef BUTTON_H
#define BUTTON_H

#include <string>
#include <fstream>
#include "TextWidget.h"
#include "FormWidget.h"

/*
Enum used for keeping track of the type of button; used for determining what type of button attribute to give
the button in the HTML code.
*/
enum class ButtonType
{
   BUTTON,
   RESET,
   SUBMIT
};

//Text that corresponds to the ButtonTypes enum; used for writing the button type to the page
const std::string BUTTON_TYPES_TEXT[] = { "button", "reset", "submit" };

/*
A simple, clickable button widget. Corresponds to the HTML <button> element.
*/
class Button : public TextWidget, public FormWidget
{
private:
   ButtonType type;  //The type of the HTML button

   virtual void write(std::ofstream&) const override final;

public:
   Button();
   Button(std::string, ButtonType = ButtonType::BUTTON);
   ~Button() {}

   //Getters
   ButtonType getType() const { return type; }

   //Setters
   void setType(ButtonType t) { type = t; }
};

#endif
