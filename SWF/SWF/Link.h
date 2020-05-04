#ifndef LINK_H
#define LINK_H

#include <string>
#include <fstream>
#include "TextWidget.h"

/*
This enum corresponds to the relationship attribute that <a> tags have
*/
enum class LinkRelationship
{
   NONE,
   ALTERNATE,
   AUTHOR,
   BOOKMARK,
   EXTERNAL,
   HELP,
   LICENSE,
   NEXT,
   NO_FOLLOW,
   NO_REFERRER,
   NO_OPENER,
   PREV,
   SEARCH,
   TAG
};

//Values corresponding to the link relationship enum to determine what should be written to the page
const std::string LINK_VALUES[] = {"none", "alternate", "author", "bookmark", "external", "help", "license", "next", "nofollow", "noreferrer", "noopener", "prev", "search", "tag"};

/*
The Link class provides the user with the ability to create link-able text. Corresponds to HTML <a> tag.
*/
class Link : public TextWidget
{
private:
   std::string URL;                 //URL that link leads to
   std::string downloadLink;        //URL to download
   LinkRelationship relationship;   //Relationship between current page and page linked in URL

   virtual void write(std::ofstream&) const override final;

public:
   Link();
   Link(std::string, std::string);
   Link(std::string, std::string, LinkRelationship);
   ~Link() {}

   //Getters
   std::string getURL() const { return URL; }
   std::string getDownloadLink() const { return downloadLink; }
   LinkRelationship getRelationship() const { return relationship; }

   //Setters
   void setURL(std::string u) { URL = u; }
   void setDownloadLink(std::string d) { downloadLink = d; }
   void setRelationship(LinkRelationship r) { relationship = r; };
};

#endif