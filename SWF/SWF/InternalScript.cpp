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
   file << "<script>\n" << code << "\n</script>\n";
}