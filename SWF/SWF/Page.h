#ifndef PAGE_H
#define PAGE_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream> //TODO: remove header
#include "Widget.h"

class Site; //Forward declaration of Site class

const std::string DEFAULT_LANGUAGE = "en";  //Default language

class FailedFileCreationException
{
private:
   std::string fileName;

public:
   FailedFileCreationException(std::string f) { fileName = f; };
   ~FailedFileCreationException() {};

   std::string what() const { return "Could not create file: " + fileName; }
};

/*
The Page class represents actual HTML files that belong to a particular site.
*/
class Page
{
private:
   std::string name;             //Name of page (for the name of the file)
   std::string title;            //Title of page (text of <title> tag)
   std::string language;         //Language of page (based on HTML language code)
   std::vector<Widget*> widgets;   //List of widgets that belong to this page

   void write(std::string);

public:
   Page(std::string, std::string);
   Page(std::string, std::string, std::string);
   ~Page();

   //Getters
   std::string getName() const { return name; }
   std::string getTitle() const { return title; }
   std::string getLanguage() const { return language; }
   std::vector<Widget*> getWidgets() const { return widgets; }

   //Setters
   void setName(std::string n) { name = n; }
   void setTitle(std::string t) { title = t; }
   void setLanguage(std::string l) { language = l; }
   
   void addWidget(Widget*);
   void addWidgets(std::vector<Widget*>);

   /*
   The Site class is made friend so it can access Page::write(). This relationship is needed
   because the Page::write() function should not be accessible outside of the Site::write() function
   */
   friend class Site;
};

#endif

