#ifndef TEXT_WIDGET_H
#define TEXT_WIDGET_H

#include <string>
#include <fstream>
#include "Widget.h"

const int DEFAULT_FONT_SIZE = 16;

/*
The TextWidget class is used to define widgets that correspond to HTML elements which rely only on text
between their tags, such as <p>, <button>, and <body>. The text class has extra members so that users can
enter in CSS values for various properties without having to write the entire style member directly.
*/
class TextWidget : public Widget
{
protected:
   std::string text;             //Text of the text widget
   std::string backgroundColor;  //CSS value of background color
   std::string textColor;        //CSS value of text color
   std::string fontFamily;       //CSS value of font family
   int fontSize;                 //Font size in pixels
   std::string textAlignment;    //CSS value of text alignment

   virtual void write(std::ofstream&) const override;

public:
   TextWidget(std::string = "");
   ~TextWidget() {}

   //Getters
   std::string getText() { return text; }
   std::string getBackgroundColor() { return backgroundColor; }
   std::string getTextColor() { return textColor; }
   std::string getFontFamily() { return fontFamily; }
   int getFontSize() { return fontSize; }
   std::string getTextAlignment() { return textAlignment; }

   //Setters
   void setText(std::string t) { text = t; };
   void setBackgroundColor(std::string c) { backgroundColor = c; }
   void setTextColor(std::string t) { textColor = t; }
   void setFontFamily(std::string f) { fontFamily = f; }
   void setFontSize(int s) { fontSize = s; }
   void setTextAlignment(std::string a) { textAlignment = a; }
};

#endif
