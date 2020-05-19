#ifndef INTERNAL_STYLE_H
#define INTERNAL_STYLE_H

#include <string>
#include <fstream>
#include "File.h"
#include "IOHelper.h"

/*
This class is used for adding internal CSS code. Corresponds to the <style> tag in HTML.
*/
class InternalStyle : public File
{
private:
   std::string code; //The CSS code to embed into the page

   virtual void write(std::ofstream&) const override final;

public:
   InternalStyle(std::string = "");
   ~InternalStyle() {}
 
   //Getters
   std::string getCode() const { return code; }

   //Setters
   void setCode(std::string c) { code = c; }
};

#endif