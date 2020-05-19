#ifndef SITE_H
#define SITE_H

#include <string>
#include <deque>
#include <direct.h>
#include <filesystem>
#include "Page.h"

namespace fs = std::filesystem;

/*
Exception thrown when a folder cannot be created
*/
class FolderCreationException
{
private:
   std::string folderPath;

public:
   FolderCreationException(std::string f) { folderPath = f; };
   ~FolderCreationException() {};

   std::string what() const { return "Could not create folder: " + folderPath; }
};

/*
The Site class is used for created the file structure for a website as well as handling the pages that belong
to the site.
*/
class Site
{
private:
   std::string name;          //Name of the website or project
   std::string path;          //Path on machine where site's data should be written; path of project folder
   std::deque<Page*> pages;    //List of pages that belong to the site

public:
   Site(std::string, std::string);
   ~Site();

   //Getters
   std::string getName() const { return name; }
   std::string getPath() const { return path; }
   std::deque<Page*> getPages() const { return pages; }

   //Setters
   void setName(std::string n) { name = n; }
   void setPath(std::string p) { path = p; }
   
   void addPage(Page*);
   void addPages(std::deque<Page*>);

   void write();
};

#endif

