#ifndef BODY_H
#define BODY_H

#include <string>
#include <fstream>
#include "Widget.h"
#include "TextWidget.h"

/*
This class allows users to create a body of text on their site. Corresponds to the HTML <body> element.
*/
class Body : public TextWidget
{
private:
   virtual void write(std::ofstream&) const override final;

public:
   Body() : TextWidget() {}
   Body(std::string t) : TextWidget(t) {}
   ~Body() {}
};

#endif