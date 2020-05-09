#include "Link.h"

/*
Default constructor; calls base class default constructor
*/
Link::Link() : TextWidget()
{
   URL = "";
   downloadLink = "";
   relationship = LinkRelationship::NONE;
}

/*
Constructor; assigns text of link and the link URL
*/
Link::Link(std::string t, std::string u) : TextWidget(t)
{
   URL = u;
   downloadLink = "";
   relationship = LinkRelationship::NONE;
}

/*
Constructor; assigns text of link, link URL, and link relationship
*/
Link::Link(std::string t, std::string u, LinkRelationship r) : TextWidget(t)
{
   URL = u;
   downloadLink = "";
   relationship = r;
}

/*
Writes the link to the file, including the <a> tag.
*/
void Link::write(std::ofstream& file) const
{
   std::string linkRelationshipText = LINK_VALUES[static_cast<unsigned>(relationship)];   //Text of relationship to write as attribute

   //Write opening tag
   file << "<a ";

   //Write link attributes
   if (!URL.empty()) file << "href=\"" << URL << "\" ";
   if (!downloadLink.empty()) file << "download=\"" << downloadLink << "\" ";

   //Check that relationship is not none before writing
   if (relationship != LinkRelationship::NONE)
   {
      file << "rel=\"" << linkRelationshipText << "\" ";
   }

   //Write attributes from base class
   TextWidget::write(file);

   //Write closing bracket, text, then closing tag
   file << ">" << text << "</a>\n";
}