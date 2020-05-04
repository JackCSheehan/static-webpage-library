#include "Widget.h"

/*
Default constructor; initializes all values to default values
*/
Widget::Widget()
{
   className = "";
   ID = "";
   style = "";
   hidden = DEFAULT_IS_HIDDEN;
}

/*
Writes the global widget's attributes to the given file. This function assumes that the tag's brackets and name
have already been written by a derived class, hence why only the attributes are written. The file is also 
assumed to be valid, as it is created and validated by the Page class. A widget's style member, if assigned
directly, will override any individual styles set by a member function.
*/
void Widget::write(std::ofstream& file) const
{
   //Only the values that aren't default or blank are written
   if (!className.empty()) file << "class = \"" << className << "\" ";
   if (!ID.empty()) file << "id = \"" << ID << "\" ";
   if (!style.empty()) file << "style = \"" << style << "\" ";
   if (hidden != DEFAULT_IS_HIDDEN) file << "hidden ";
}
