#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <fstream>
#include "Widget.h"

/*
This class allows users to insert images into the document. Corresponds to the HTML <img> tag.
*/
class Image : public Widget
{
private:
   std::string source;   //URL to image
   int width;                 //Width of image
   int height;                //Height of image
   std::string altText;       //Alternative text to display if image can't be shown

   virtual void write(std::ofstream&) const override final;

public:
   Image(std::string = "", int = 0, int = 0, std::string = "");
   ~Image() {}

   //Getters
   std::string getSource() const { return source; }
   int getWidth() const { return width; }
   int getHeight() const { return height; }
   std::string getAltText() const { return altText; }

   //Setters
   void setSource(std::string s) { source = s; }
   void setWidth(int w) { width = w; }
   void setHeight(int h) { height = h; }
   void setAltText(std::string a) { altText = a; }

};

#endif