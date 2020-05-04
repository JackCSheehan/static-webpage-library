#include "Paragraph.h"

/*
This function writes the paragraph HTML tag and calls other functions from base classes to write attributes.
*/
void Paragraph::write(std::ofstream& file) const
{
   //Write the body tag
   file << "<p ";

   //Write attributes of base class
   TextWidget::write(file);

   //write the closing bracket, text, then closing tag
   file << ">" << text << "</p>\n";
}
