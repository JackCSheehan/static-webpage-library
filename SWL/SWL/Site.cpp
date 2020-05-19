#include "Site.h"

/*
This constructor creates the file structure for the website including the scripts, images, and styles folders.
Takes the name of the site (used to name the project folder) and the path to where the project folder should be
created.
*/
Site::Site(std::string n, std::string p)
{
   std::string imagesFolderPath;    //Path to images folder
   std::string scriptsFolderPath;   //Path to scripts folder
   std::string stylesFolderPath;    //Path to styles folders

   //Assign members
   name = n;

   //If the user did not give a blank path
   if (p.size() != 0)
   {
      //If the last character of the given path is not a slash, add a slash to the project path
      if (p.back() != '/' || p.back() != '\\')
      {
         path = p + "/" + name;
      }
      //If there is already a slash, one does not need to be added
      else
      {
         path = p + name;
      }

   }
   //If the user did give a blank path, the path will just be the name of the site
   else
   { 
      path = name;
   }
   
   //Create the name of the folders in the folder structure to organize website files
   imagesFolderPath = path + "/images";
   scriptsFolderPath = path + "/scripts";
   stylesFolderPath = path + "/styles";

   //Create the project folders
   std::filesystem::create_directory(path);
   std::filesystem::create_directory(imagesFolderPath);
   std::filesystem::create_directory(scriptsFolderPath);
   std::filesystem::create_directory(stylesFolderPath);
}

/*
Destructor; iterates through each dynamically allocated page pointer and deletes them so user does not have
to do it themselves.
*/
Site::~Site()
{
   for (Page* page : pages)
   {
      delete page;
   }
}

/*
This function appends a page to the list of pages on this site. A reference to a pointer is used
to prevent a user from entering a statically allocated object using the & operator, as that would lead
to an uncatchable exception when the Site destructor needs to destroy all the pages.
*/
void Site::addPage(Page* newPage)
{
   pages.push_back(newPage);
}

/*
This function appends the given list of pointers to Pages to the existing Pages list. There is no similar
workaround here as with the addPage function to stop a user from entering in a statically allocated page as
that would require some unintuitive actions by the user (such as creating a vector of type <Page*&>)
*/
void Site::addPages(std::deque<Page*> newPages)
{
   pages.insert(pages.end(), newPages.begin(), newPages.end());
}

/*
Once the user of the framework is ready to write files, this function will be called. This function iterates
through all the pages associated with this site and writes the HTML of each one to the project file.
*/
void Site::write()
{
   //Iterate through each page and call that page's write function
   for (Page* page : pages)
   {
      page->write(path);
   }
}