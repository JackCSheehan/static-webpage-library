#ifndef EXTERNAL_STYLE_H
#define EXTERNAL_STYLE_H

#include <string>
#include <fstream>
#include "File.h"

/*
This class is used for importing external CSS files. Corresponds to the <link rel="stylesheet" type="text/css"> tag.
*/
class ExternalStyle : public File
{
private:
   std::string source;  //Source file of external style

   virtual void write(std::ofstream&) const override final;

public:
   ExternalStyle(std::string = "");
   ~ExternalStyle() {}
};

#endif