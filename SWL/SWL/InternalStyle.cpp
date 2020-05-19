#include "InternalStyle.h"

/*
Default constructor; assigns the value of the code member; parameter c defaults to ""
*/
InternalStyle::InternalStyle(std::string c)
{
   code = c;
}

/*
Writes the style tag and code.
*/
void InternalStyle::write(std::ofstream& file) const
{
   std::deque<std::string> codeLines;  //The internal code split into lines

   file << "<style>\n";

   //Split the code into individual lines
   codeLines = IOHelper::splitLines(code);

   //Write each line of code to the page with three \t for correct formatting
   for (std::string line : codeLines)
   {
      file << "\t\t\t" << line << "\n";
   }

   //Write closing script tag
   file << "\t\t</style>\n";
}