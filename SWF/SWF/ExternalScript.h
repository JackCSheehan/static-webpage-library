#ifndef EXTERNAL_SCRIPT_H
#define EXTERNAL_SCRIPT_H

#include <string>
#include <fstream>
#include "File.h"

/*
This widget is used for including external scripts in a page.
*/
class ExternalScript : public File
{
private:
   std::string source;  //Source file of script that user wants to include

   virtual void write(std::ofstream&) const override final;

public:
   ExternalScript(std::string = "");
   ~ExternalScript() {}
};

#endif