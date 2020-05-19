#ifndef INTERNAL_SCRIPT_H
#define INTERNAL_SCRIPT_H

#include <string>
#include <fstream>
#include <deque>
#include "File.h"
#include "IOHelper.h"

/*
This function is used for embedding internal scripts into the page.
*/
class InternalScript : public File
{
private:
   std::string code; //The code to internal embed into page

   virtual void write(std::ofstream&) const override final;

public:
   InternalScript(std::string = "");
   ~InternalScript() {}
};

#endif