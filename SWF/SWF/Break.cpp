#include "Break.h"

/*
Default constructor; sets line count to given value; l parameter defaults to 1
*/
Break::Break(unsigned l)
{
   lineCount = l;
}

/*
Writes a with lineCount lines of spacing. Does NOT call the Widget::write() function because no other
attributes are needed for a break.
*/
void Break::write(std::ofstream& file) const
{
   //Check to see if line count is the default before writing
   if (lineCount > 1)
   {
      file << "<br style = \"line-height:" << lineCount << "\"" << ">\n";
   }
   else
   {
      file << "<br>\n";
   }
}