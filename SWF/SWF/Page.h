#ifndef PAGE_H
#define PAGE_H

#include <string>
#include <deque>
#include <fstream>
#include "Widget.h"
#include "File.h"

class Site; //Forward declaration of Site class

//Defaults
const std::string DEFAULT_LANGUAGE = "en";
const std::string DEFAULT_CHAR_SET = "UTF-8";

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
   std::string name;                //Name of page (for the name of the file)
   std::string title;               //Title of page (text of <title> tag)
   std::string language;            //Language of page (based on HTML language code)
   std::string charSet;             //Character set to use on this page
   std::string description;         //Description of page
   std::string author;              //Author of page
   std::string viewport;            //Viewport settings
   std::string keywords;            //Keywords of webpage, separated by commas
   std::deque<Widget*> widgets;     //List of widgets that belong to this page
   std::deque<File*> files;         //List of files (scripts and stylesheets) that belong to this page

   void write(std::string);

public:
   Page(std::string, std::string);
   Page(std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string);
   ~Page();

   //Getters
   std::string getName() const { return name; }
   std::string getTitle() const { return title; }
   std::string getLanguage() const { return language; }
   std::string getCharSet() const { return charSet; }
   std::string getDescription() const { return description; }
   std::string getAuthor() const { return author; }
   std::string getViewport() const { return viewport; }
   std::string getKeywords() const { return keywords; }
   std::deque<Widget*> getWidgets() const { return widgets; }
   std::deque<File*> getFiles() const { return files; }

   //Setters
   void setName(std::string n) { name = n; }
   void setTitle(std::string t) { title = t; }
   void setLanguage(std::string l) { language = l; }
   void setCharSet(std::string c) { charSet = c; }
   void setDescription(std::string d) { description = d; }
   void setAuthor(std::string a) { author = a; }
   void setViewport(std::string v) { viewport = v; }
   void setKeywords(std::string k) { keywords = k; }
   
   void addWidget(Widget*);
   void addWidgets(std::deque<Widget*>);
   void addFile(File*);
   void addFiles(std::deque<File*>);

   /*
   The Site class is made friend so it can access Page::write(). This relationship is needed
   because the Page::write() function should not be accessible outside of the Site::write() function
   */
   friend class Site;
};

#endif

