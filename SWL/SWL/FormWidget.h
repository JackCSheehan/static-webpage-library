#ifndef FORM_WIDGET_H
#define FORM_WIDGET_H

#include <string>
#include <fstream>
#include "Widget.h"

/*
This class acts as a base class for all widgets that can be used in a form. These are three common properties
among all HTML elements that can be put in a form. 
*/
class FormWidget : virtual public Widget
{
protected:
   bool autoFocused; //Determines whether or not widget is auto-focused
   std::string form; //Name of form that this widget belongs to
   bool disabled;    //Determines whether or not form widget is enabled

   virtual void write(std::ofstream&) const override;

public:
   FormWidget();
   virtual ~FormWidget() {}

   //Getters
   bool isAutoFocused() const { return autoFocused; }
   std::string getForm() const { return form; }
   bool isDisabled() const { return disabled; }

   //Setters
   void setAutoFocused(bool a) { autoFocused = a; }
   void setForm(std::string f) { form = f; }
   void setDisabled(bool d) { disabled = d; }
};

#endif