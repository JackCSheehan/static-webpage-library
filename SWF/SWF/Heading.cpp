#include "Heading.h"

/*
Default constructor; sets flag so that font size isn't written
*/
Heading::Heading() : TextWidget() 
{ 
   type = HeadingType::H1;
   shouldWriteFontSize = false;
}

/*
Constructor; sets flag so that font size isn't written
*/
Heading::Heading(std::string t, HeadingType ht) : TextWidget(t) 
{ 
   type = ht; 
   shouldWriteFontSize = false;
}

/*
This function writes the <h{n}> tag and calls base class write functions to write attributes;
*/
void Heading::write(std::ofstream& file) const
{
   std::string tag = HEADING_TAGS[static_cast<unsigned>(type)];   //Correct heading tag based on type member

   //Write opening tag
   file << "<" << tag << " ";

   //Call base class write function to write attributes
   TextWidget::write(file);

   //Write closing bracket, text, and closing 
   file << ">" << text << "</" << tag << ">\n";
}