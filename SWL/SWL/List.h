#ifndef LIST_H
#define LIST_H

#include <deque>
#include <string>
#include <fstream>
#include "Widget.h"

/*
The two different list types.
*/
enum class ListType
{
   UNORDERED,
   ORDERED
};

const std::string LIST_TAGS[] = {"ul", "ol"};      //Tags that correspond to the different tag types
const ListType DEFAULT_TYPE = ListType::UNORDERED; //Default list type

/*
This List class allows user to create ordered and unordered lists.
*/
class List : public Widget
{
private:
   std::deque<std::string*> listItems;  //Widgets that are inside the list
   ListType type;                //The type of this list

   virtual void write(std::ofstream&) const override final;

public:
   List(ListType = DEFAULT_TYPE);
   List(ListType, std::deque<std::string*>);
   ~List();

   //Getters
   std::deque<std::string*> getListItems() const { return listItems; }
   ListType getType() const { return type; }

   //Setters
   void setType(ListType t) { type = t; }

   void addListItem(std::string*);
   void addListItems(std::deque<std::string*>);
};

#endif