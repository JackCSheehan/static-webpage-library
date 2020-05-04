#include <iostream>
#include <fstream>
#include <direct.h>
#include <vector>
#include "Site.h"
#include "Page.h"
#include "Body.h"

int main()
{
   //TESTING
   Site site("Test Site", "");

   Page* p1 = new Page("index", "Home");

   //Body widget
   Body* b = new Body("Here is some test text!");
   b->setFontSize(40);
   b->setTextAlignment("center");
   b->setTextColor("red");

   p1->addWidget(b);

   site.addPage(p1);

   site.write();

   //Work on widget sub classes

   //TODO: make add eventwidget class and make applicable classes derive from it

   return 0;
}