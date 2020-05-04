#include <iostream>
#include <fstream>
#include <direct.h>
#include <vector>
#include "Site.h"
#include "Page.h"
#include "Paragraph.h"
#include "Heading.h"
#include "Link.h"
#include "Break.h"
#include "Image.h"

int main()
{
   //TESTING
   Site site("Test Site", "");

   Page* p1 = new Page("index", "Home");

   //Heading widget
   Heading* h = new Heading("Heading", HeadingType::H1);

   //Paragraph Widget
   Paragraph* paragraph = new Paragraph
   (
      "The paragraph widget is useful for large blocks of text that need to be individually formatted. This is the only widget built into SWF that is optimal for large blocks of text like this.\n\n I wonder if HTML respects newlines?"
   );
   paragraph->setFontFamily("Courier New");
   paragraph->setFontSize(20);

   //Link widget
   Link* link = new Link("Go to YouTube", "https://youtube.com");

   //Image widget
   Image* image = new Image("https://www.google.com/logos/doodles/2020/us-teacher-appreciation-week-2020-begins-6753651837108374.6-l.png");

   p1->addWidget(h);
   p1->addWidget(paragraph);
   p1->addWidget(image);

   //Break widget
   p1->addWidget(new Break());

   p1->addWidget(link);

   site.addPage(p1);

   site.write();

   //Work on widget sub classes

   //TODO: UML break class 
   //TODO: make break class for new lines (use line-height)
   //TODO: make add eventwidget class and make applicable classes derive from it

   return 0;
}