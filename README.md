# static-webpage-framework
The SWF is a basic framework written in C++ for developing static webpages. The SWF was written as a practice project to use polymorphism and virtual functions in a real and practical context.

# An Example Projects
The following code is an example of how the SWF can be used.
```
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
#include "List.h"
#include "InternalStyle.h"
#include "ExternalStyle.h"

int main()
{
   //EXAMPLE USAGE

   //Create a new site called "Test Site" at the current path
   Site newSite("Test Site", "");

   //Create a new page for this site
   Page* newPage = new Page("index", "Home", "en", "UTF-8", "Test Website", "Jack Sheehan", "width=device-width, initial-scale=1.0", "code, programming");

   //Create internal styles and scripts and external styles and scripts
   //External script
   ExternalScript* externalScript = new ExternalScript("scripts/scripts.js");

   //Internal script
   InternalScript* internalScript = new InternalScript("alert(\"This is from an internal script!\");");

   //Internal Style
   InternalStyle* internalStyle = new InternalStyle("body{background-color: cyan;}");

   //External Style
   ExternalStyle* externalStyle = new ExternalStyle("styles/styles.css");

   //Create a new heading for this page
   Heading* heading = new Heading("Heading", HeadingType::H1);

   //Create a new paragraph and edit it's formatting
   Paragraph* paragraph = new Paragraph("This is a paragraph.");
   paragraph->setFontFamily("Courier New");
   paragraph->setFontSize(20);

   //Create a link for the page
   Link* link = new Link("Go to Google", "https://google.com");

   //Create an image for the document; this image is a Google Doodle from Teacher Appreciation Week 2020
   Image* image = new Image("https://www.google.com/logos/doodles/2020/us-teacher-appreciation-week-2020-begins-6753651837108374.6-l.png");

   //Create a button for the page
   Button* button = new Button("Click me!");

   //Set the onclick to call a JS function
   button->setOnClick("testButton()");

   //Create an input for the page
   Input* input = new Input();
   input->setHintText("Enter text");

   //Create a list of text for the document
   std::deque<std::string*> listDeque;
   listDeque.push_back(new std::string("Item 1"));
   listDeque.push_back(new std::string("Item 2"));
   listDeque.push_back(new std::string("Item 3"));

   List* list = new List(ListType::UNORDERED, listDeque);

   //First, add the files created at the top of main
   newPage->addFile(externalScript);
   newPage->addFile(externalStyle);
   newPage->addFile(internalScript);
   newPage->addFile(internalStyle);

   //Add the widgets create above in main to the page
   newPage->addWidget(heading);
   newPage->addWidget(paragraph);
   newPage->addWidget(image);

   //Add a break in the web page
   newPage->addWidget(new Break());

   newPage->addWidget(link);
   newPage->addWidget(button);
   newPage->addWidget(input);
   newPage->addWidget(list);

   //Add the new page to the site
   newSite.addPage(newPage);

   //Finally, write the site's pages to the document
   newSite.write();

   return 0;
}
```
The result of this program is the Test Site file in the repository. The following HTML file is produced by the above code.

<!DOCTYPE html>
<html lang="en">
	<head>
		<meta charset="UTF-8">
		<meta name="description" content="Test Website">
		<meta name="author" content="Jack Sheehan">
		<meta name="viewport" content="width=device-width, initial-scale=1.0">
		<meta name="keywords" content="code, programming">

		<title>Home</title>

		<script src="scripts/scripts.js"></script>
		<link rel="stylesheet" type="text/css" href="styles/styles.css">
		<script>
			alert("This is from an internal script!");
		</script>
		<style>
			body{background-color: cyan;}
		</style>
	</head>

	<body>
		<h1 >Heading</h1>
		<p font-size: 20px;font-family: Courier New;" >This is a paragraph.</p>
		<img src="https://www.google.com/logos/doodles/2020/us-teacher-appreciation-week-2020-begins-6753651837108374.6-l.png" >
		<br>
		<a href="https://google.com" font-size: 16px;" >Go to Google</a>
		<button font-size: 16px;" onclick="testButton()" type="button">Click me!</button>
		<input placeholder="Enter text" type="text">
		<ul>
			<li>Item 1</li>
			<li>Item 2</li>
			<li>Item 3</li>
		</ul>
	</body>
</html>
