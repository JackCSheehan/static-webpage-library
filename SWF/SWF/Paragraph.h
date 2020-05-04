#ifndef PARAGRAPH_H
#define PARAGRAPH_H

#include <string>
#include <fstream>
#include "Widget.h"
#include "TextWidget.h"

/*
This class allows users to create a body of text on their site. Corresponds to the HTML <body> element.
*/
class Paragraph : public TextWidget
{
private:
   virtual void write(std::ofstream&) const override final;

public:
   Paragraph() : TextWidget() {}
   Paragraph(std::string t) : TextWidget(t) {}
   ~Paragraph() {}
};

#endif