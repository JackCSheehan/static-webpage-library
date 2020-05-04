#include "Page.h"

/*
Constructor; sets name of page and title of page to given values and sets the language to the default language.
*/
Page::Page(std::string n, std::string t)
{
   name = n;
   title = t;
   language = DEFAULT_LANGUAGE;
}

/*
Constructor; sets name of page, title of page, and page language to given values
*/
Page::Page(std::string n, std::string t, std::string l)
{
   name = n;
   title = t;
   language = l;
}

/*
Destructor; iterates through each dynamically allocated widget and deletes it so that the user does not have to
do it themselves.
*/
Page::~Page()
{
   for (Widget* widget : widgets)
   {
      delete widget;
   }
}

/*
This function creates the HTML page in memory and writes both the page's data and the data of each 
widget to the file. The given project file path is the path to the site's main folder. Throws
FailedFileCreationException if the file cannot be created.
*/
void Page::write(std::string projectFilePath)
{
   std::ofstream file;  //The output file stream used to create this page's file

   //Create the HTML file
   file.open(projectFilePath + "/" + name + ".html");

   //Validate that the source file was created successfully
   if (file.fail())
   {
      throw FailedFileCreationException(name + ".html");
   }

   //Once the file has been validated, write doctype tag
   file << "<!DOCTYPE html>\n";

   //Write opening HTML tag and language
   file << "<hmtl lang = \"" << language << "\">\n";

   //Write the page's title to the file next
   file << "<title> " << title << " </title>\n";

   //Iterate through the widget's belonging to this page and write them all to the file
   for (Widget* widget : widgets)
   {
      /*
      Since Widget's write function is virtual, the actual type pointed to by widget will have its write function
      invoked, which in turn invokes the write functions of its parent classes.
      */
      widget->write(file);
   }

   //Close off the <html> tag once all data has been written and close the file
   file << "</html>";
   file.close();
}

/*
This function adds the given pointer to a Widget to the widgets list member.
*/
void Page::addWidget(Widget* newWidget)
{
   widgets.push_back(newWidget);
}

/*
This function appends the given list of pointers to Widgets to the widgets list member.
*/
void Page::addWidgets(std::vector<Widget*> newWidgets)
{
   widgets.insert(widgets.end(), newWidgets.begin(), newWidgets.end());
}