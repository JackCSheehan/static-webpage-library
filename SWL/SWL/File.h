#ifndef FILE_H
#define FILE_H

#include <fstream>

class Page; //Forward declaration of page

/*
This abstract class acts as a base class for the ExternalScript and ExternalStyle classes.
*/
class File
{
protected:
   virtual void write(std::ofstream&) const = 0;

   //Page needs to be a friend so it can call the write function of all File classes
   friend class Page;
};

#endif