#include "Image.h"

/*
Default constructor; takes image source, width, height, and alt text. Image source an alt text are "" by default.
Width and height are both 0 by default (note: width and height are not written if they are 0).
*/
Image::Image(std::string s, int w, int h, std::string a)
{
   source = s;
   width = w;
   height = h;
   altText = a;
}


/*
Writes the image to the file and also calls the base class's write function to write the necessary attributes.
*/
void Image::write(std::ofstream& file) const
{
   //Write the image tag
   file << "<img ";

   //Write the image attributes
   if (!source.empty()) file << "src = \"" << source << "\" ";
   if (!altText.empty()) file << "alt = \"" << altText << "\"";

   if (width > 0) file << "width = \"" << width << "\" ";
   if (height > 0) file << "height = \"" << height << "\" ";

   //Write the rest of the relevant attributes from base class
   Widget::write(file);

   //Write the closing bracket
   file << ">\n";
}