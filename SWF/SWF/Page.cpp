#include "Page.h"

/*
Constructor; sets default values to members.
*/
Page::Page(std::string n, std::string t)
{
   name = n;
   title = t;
   language = DEFAULT_LANGUAGE;
   charSet = DEFAULT_CHAR_SET;
   description = "";
   author = "";
   viewport = "";
   keywords = "";
}

/*
Constructor; sets name of page, title of page, and page language to given values.
*/
Page::Page(std::string n, std::string t, std::string l, std::string c, std::string d, std::string a, std::string v, std::string k)
{
   name = n;
   title = t;
   language = l;
   charSet = c;
   description = d;
   author = a;
   viewport = v;
   keywords = k;
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
   file << "<html lang=\"" << language << "\">\n";

   //Write the opening head tag
   file << "\t<body>\n";

   //Write all metadata
   if (!charSet.empty()) file << "\t\t<meta charset=\"" << charSet << "\">\n";
   if (!description.empty()) file << "\t\t<meta name=\"description\" content=\"" << description << "\">\n";
   if (!author.empty()) file << "\t\t<meta name=\"author\" content=\"" << author << "\">\n";
   if (!viewport.empty()) file << "\t\t<meta name=\"viewport\" content=\"" << viewport << "\">\n";
   if (!keywords.empty()) file << "\t\t<meta name=\"keywords\" content=\"" << keywords << "\">\n\n";

   //Write the page's title to the file
   file << "\t\t<title>" << title << "</title>\n\n";

   //Write all external files in the head tag
   for (File* externalFile : files)
   {
      //Tab character for formatting
      file << "\t\t";

      //Call each file's virtual write function
      externalFile->write(file);
   }

   //Write closing head tag
   file << "\t</head>\n\n";

   //Write opening body tag, which is where all widgets will be written
   file << "\t<body>\n";

   //Iterate through the widget's belonging to this page and write them all to the file
   for (Widget* widget : widgets)
   {
      file << "\t\t";

      //Call each widget's virtual write function
      widget->write(file);
   }

   //Close off body and html tags
   file << "\t</body>\n</html>";
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
void Page::addWidgets(std::deque<Widget*> newWidgets)
{
   widgets.insert(widgets.end(), newWidgets.begin(), newWidgets.end());
}

/*
This function adds the given pointer to a File to the files list member.
*/
void Page::addFile(File* newFile)
{
   files.push_back(newFile);
}

/*
This function appends the given list of pointers to Files to the files list member.
*/
void Page::addFiles(std::deque<File*> newFiles)
{
   files.insert(files.end(), newFiles.begin(), newFiles.end());
}