#include "Body.h"

/*
This function writes the body HTML tag and calls other functions from base classes to write attributes.
*/
void Body::write(std::ofstream& file) const
{
   //Write the body tag
   file << "<body ";

   //Write attributes of base class
   TextWidget::write(file);

   //write the closing bracket, text, then closing tag
   file << ">" << text << "</body>\n";
}
