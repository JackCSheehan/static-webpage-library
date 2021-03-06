#ifndef HEADING_H
#define HEADING_H

#include <string>
#include <fstream>
#include "TextWidget.h"
#include "EventWidget.h"

/*
This enum defines the different sizes of headings available.
*/
enum class HeadingType
{
   H1,
   H2,
   H3,
   H4,
   H5,
   H6
};

//Heading tags that corresponds to HeadingType enum to write function knows what tag to write
const std::string HEADING_TAGS[] = {"h1", "h2", "h3", "h4", "h5", "h6"};

/*
This class is used for creating heading of various sizes. Corresponds to the HTML tags <h1>, <h2>, etc.
*/
class Heading : public TextWidget, public EventWidget
{
private:
   HeadingType type;

   virtual void write(std::ofstream&) const override final;

public:
   Heading();
   Heading(std::string, HeadingType);
   ~Heading() {}

   //Getters
   HeadingType getType() const { return type; };

   //Setters
   void setType(HeadingType ht) { type = ht; };
};

#endif