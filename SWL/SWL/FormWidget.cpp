#include "FormWidget.h"

/*
Default constructor
*/
FormWidget::FormWidget()
{
   autoFocused = false;
   form = "";
   disabled = false;
}

/*
This function writes its attributes to the file. This function assumes that the opening and closing HTML tags
are written by a derived widget class.
*/
void FormWidget::write(std::ofstream& file) const
{
   //Write base class attributes
   Widget::write(file);

   //Write attributes of form widget
   if (autoFocused) file << "autofocus ";
   if (!form.empty()) file << "form = \"" << form << "\"";
   if (disabled) file << "disabled ";
}