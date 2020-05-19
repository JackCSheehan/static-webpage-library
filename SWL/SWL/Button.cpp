#include "Button.h"

/*
Default constructor.
*/
Button::Button() : TextWidget(), FormWidget()
{
   type = ButtonType::BUTTON;
}

/*
Constructor; calls TextWidget constructor to set the text of the button. Button type defaults to BUTTON if not
given.
*/
Button::Button(std::string t, ButtonType bt) : TextWidget(t), FormWidget()
{
   type = bt;
}

/*
Writes the <button> tag and attributes, and calls base class write functions
to write base class attributes.
*/
void Button::write(std::ofstream& file) const
{
   //Get the text of the button type
   std::string buttonTypeText = BUTTON_TYPES_TEXT[static_cast<unsigned>(type)];

   //Write opening button tag
   file << "<button ";

   //Write base class attributes
   TextWidget::write(file);
   FormWidget::write(file);
   EventWidget::write(file);

   //Write button attribute
   file << "type=\"" << buttonTypeText << "\"";

   //Write closing bracket, text, and closing tag
   file << ">" << text << "</button>\n";
}