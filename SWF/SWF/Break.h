#ifndef BREAK_H
#define BREAK_H

#include <fstream>
#include "Widget.h"

/*
Adds newline(s) to the page. Corresponds to the HTML <br> tag.
*/
class Break : public Widget
{
private:
   unsigned lineCount;  //The number of lines to be inserted into the document

   virtual void write(std::ofstream&) const override final;

public:
   Break(unsigned = 1);
   ~Break() {}

   //Getters
   unsigned getLineCount() const { return lineCount; }

   //Setters
   void setLineCount(unsigned l) { lineCount = l; }
};

#endif