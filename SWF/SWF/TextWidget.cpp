#include "TextWidget.h"

/*
Default constructor; assigns text to given string and assigns default values to members. Parameter t defaults to "" if no argument is passed.
*/
TextWidget::TextWidget(std::string t)
{
   text = t;
   backgroundColor = "";
   textColor = "";
   fontFamily = "";
   fontSize = DEFAULT_FONT_SIZE;
   textAlignment = "";
   shouldWriteFontSize = true;
}

/*
This function writes the text widget's attributes. It is assumed that the opening and closing tags of the widget
will be written by the widget that derives this class. As such, this function only writes attributes.
*/
void TextWidget::write(std::ofstream& file) const
{
   //Call the base classes write function since it won't be called due to the fact that it's virtual
   Widget::write(file);

   //Write the style property and opening quotes
   file << "style=\"";
   
   //Only the attributes which aren't blank will be written
   if (shouldWriteFontSize) file << "font-size: " << fontSize << "px;";
   if (!backgroundColor.empty()) file << "background-color: " << backgroundColor << ";";
   if (!textColor.empty()) file << "color: " << textColor << ";";
   if (!fontFamily.empty()) file << "font-family: " << fontFamily << ";";
   if (!textAlignment.empty()) file << "text-align: " << textAlignment << ";";

   //Write the closing quotes
   file << "\"";
}
