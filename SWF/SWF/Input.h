#ifndef INPUT_H
#define INPUT_H

#include <string>
#include <fstream>
#include "FormWidget.h"

/*
Corresponds to the different input types in HTML
*/
enum class InputType
{
   CHECKBOX,
   COLOR,
   DATE,
   EMAIL,
   FILE,
   IMAGE,
   NUMBER,
   PASSWORD,
   RADIO,
   RANGE,
   TEXT,
   URL
};

//Text that corresponds to each type of input
const std::string INPUT_TYPE_TEXT[] = {"checkbox", "color", "date", "email", "file", "image", "number", "password", "radio", "range", "text", "url"};

/*
Widget used for creating area for input; corresponds to HTML <input> element.
*/
class Input : public FormWidget
{
private:
   std::string value;         //Initial value to be filled in the input
   std::string hintText;      //Hint text inside the input element
   std::string altText;       //Alternate text if image type is chosen and image can't be loaded
   std::string imageSource;   //Source of the image if the image type is chosen
   InputType type;            //The type of the input

   virtual void write(std::ofstream&) const override final;

public:
   Input();
   Input(std::string, std::string, std::string, std::string, InputType);
   ~Input() {}

   //Getters
   std::string getValue() const { return value; }
   std::string getHintText() const { return hintText; }
   std::string getAltText() const { return altText; }
   std::string getImageSource() const { return imageSource; }
   InputType getType() const { return type; }

   //Setters
   void setValue(std::string v) { value = v; }
   void setHintText(std::string h) { hintText = h; }
   void setAltText(std::string a) { altText = a; }
   void setImageSource(std::string i) { imageSource = i; }
   void setType(InputType t) { type = t; }
};

#endif