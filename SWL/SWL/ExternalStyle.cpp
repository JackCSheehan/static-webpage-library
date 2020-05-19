#include "ExternalStyle.h"

/*
Default constructor; s parameter defaults to "".
*/
ExternalStyle::ExternalStyle(std::string s)
{
   source = s;
}

/*
Writes link to external stylesheet.
*/
void ExternalStyle::write(std::ofstream& file) const
{
   //Write link tag using the source as the href
   file << "<link rel=\"stylesheet\" type=\"text/css\" href=\"" << source << "\">\n";
}