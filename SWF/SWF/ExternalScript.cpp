#include "ExternalScript.h"

/*
Default constructor; assigns source to given string. Source defaults to a blank string.
*/
ExternalScript::ExternalScript(std::string s)
{
   source = s;
}

/*
This function writes the <script> tag and writes the source.
*/
void ExternalScript::write(std::ofstream& file) const
{
   //Write opening tag, script source, and closing tag
   file << "<script src = \"" << source << "\"></script>\n";
}