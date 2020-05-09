#include "Input.h"

/*
Default constructor.
*/
Input::Input()
{
   value = "";
   hintText = "";
   altText = "";
   imageSource = "";
   type = InputType::TEXT;
}

/*
Constructor; sets all members based on given values.
*/
Input::Input(std::string v, std::string h, std::string a, std::string i, InputType t)
{
   value = v;
   hintText = h;
   altText = a;
   imageSource = i;
   type = t;
}

/*
Writes input tags and writes attributes.
*/
void Input::write(std::ofstream& file) const
{
   std::string inputTypeText = INPUT_TYPE_TEXT[static_cast<unsigned>(type)];  //Get text of corresponding input type from enum
   //Write input tag
   file << "<input ";

   //Call base class write function
   FormWidget::write(file);

   //Write input widget attributes
   if (!value.empty()) file << "value=\"" << value << "\" ";
   if (!hintText.empty()) file << "placeholder=\"" << hintText << "\" ";
   if (!altText.empty()) file << "alt=\"" << altText << "\" ";
   if (!imageSource.empty()) file << "src=\"" << imageSource << "\" ";

   //Write input type and closing bracket
   file << "type=\"" << inputTypeText << "\">\n";
}