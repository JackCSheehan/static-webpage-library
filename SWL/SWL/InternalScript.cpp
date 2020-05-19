#include "InternalScript.h"

/*
Default constructor; assigns code to given value. Code defaults to "".
*/
InternalScript::InternalScript(std::string c)
{
   code = c;
}

/*
Writes internal code
*/
void InternalScript::write(std::ofstream& file) const
{
   std::deque<std::string> codeLines;  //The internal code split into lines

   file << "<script>\n";

   //Split the code into individual lines
   codeLines = IOHelper::splitLines(code);

   //Write each line of code to the page with three \t for correct formatting
   for (std::string line : codeLines)
   {
      file << "\t\t\t" << line << "\n";
   }

   //Write closing script tag
   file << "\t\t</script>\n";
}