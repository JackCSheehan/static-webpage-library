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
#include "Button.h"
#include "Input.h"
#include "ExternalScript.h"
#include "InternalScript.h"

int main()
{
   //TESTING
   Site site("Test Site", "");

   Page* p1 = new Page("index", "Home");

   //Heading widget
   Heading* h = new Heading("Heading", HeadingType::H1);
   h->setClassName("heading");

   //Paragraph Widget
   Paragraph* paragraph = new Paragraph("The paragraph widget is useful for large blocks of text that need to be individually formatted. This is the only widget built into SWF that is optimal for large blocks of text like this. I wonder if HTML respects newlines?");
   paragraph->setFontFamily("Courier New");
   paragraph->setFontSize(20);

   //Link widget
   Link* link = new Link("Go to YouTube", "https://youtube.com");

   //Image widget
   Image* image = new Image("https://www.google.com/logos/doodles/2020/us-teacher-appreciation-week-2020-begins-6753651837108374.6-l.png");

   //Button widget
   Button* button = new Button("Click me!");

   //Input widget
   Input* input = new Input();
   input->setHintText("Enter text!");

   //External script
   ExternalScript* es = new ExternalScript("scripts/test.js");

   //Internal script
   InternalScript* is = new InternalScript("alert(\"This is from an internal script!\")");

   p1->addWidget(h);
   p1->addWidget(paragraph);
   p1->addWidget(image);
   //Break widget
   p1->addWidget(new Break());
   p1->addWidget(link);
   p1->addWidget(button);
   p1->addWidget(input);

   p1->addWidget(es);
   p1->addWidget(is);

   site.addPage(p1);

   site.write();

   //TODO: make add eventwidget class and make applicable classes derive from it
   //TODO: Add style sheets classes
   //TODO: Add file base class and add deque to Page class for files. Then, make Style and Script classes derive
   //from file instead so they aren't added as widgets
   //TODO: replace vectors in site and page classes with deques

   return 0;
}