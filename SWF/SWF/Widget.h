#ifndef WIDGET_H
#define WIDGET_H

#include <string>
#include <fstream>

class Page; //Forward declaration of page

//Default values for applicable attributes; based on default HTML values
const bool DEFAULT_IS_HIDDEN = false;

/*
This class serves as a base class for all widgets, and contains attributes that all
HTML tags can have.
*/
class Widget
{
protected:
   std::string className;  //The class name of the widget; used for assigning HTML tag class
   std::string ID;         //The ID of the widget; used for assigning HTML tag ID
   std::string style;      //In-line CSS to format widget
   bool hidden;            //Determines whether or not widget will be displayed

   virtual void write(std::ofstream&) const;

public:
   Widget();
   ~Widget() {}

   //Getters
   std::string getClassName() const { return className; }
   std::string getID() const { return ID; }
   std::string getStyle() const { return style; }
   bool isHidden() const { return hidden; }

   //Setters
   void setClassName(std::string c) { className = c; }
   void setID(std::string i) { ID = i; }
   void setStyle(std::string s) { style = s; }
   void setHidden(bool h) { hidden = h; }

   //Page needs to be a friend so it can access the write function to invoke the writing of widget data
   friend class Page;
};

#endif WIDGET_H
