#include "List.h"

/*
Default constructor; type defaults to DEFAULT_TYPE
*/
List::List(ListType t)
{
   type = t;
}

/*
Constructor; assigns both type and widgets
*/
List::List(ListType t, std::deque<std::string*> w)
{
   type = t;
   listItems = w;
}

/*
Destructor; de-allocates all the list items
*/
List::~List()
{
   //De-allocate all list items
   for (std::string* listItem : listItems)
   {
      delete listItem;
   }
}

/*
Writes the list to the file and writes every nested widget to the file.
*/
void List::write(std::ofstream& file) const
{
   std::string tag = LIST_TAGS[static_cast<unsigned>(type)];   //Get the right tag based on the type

   //Write the opening list tag
   file << "<" << tag << ">\n";

   //Write each list item by iterating through the list items member and write the string
   for (std::string* listItem : listItems)
   {
      file << "\t\t\t<li>" << *listItem << "</li>\n";
   }

   //Write the closing list tag
   file << "\t\t</" << tag << ">\n";
}

/*
Adds the given list item to the list items deque.
*/
void List::addListItem(std::string* newListItem)
{
   listItems.push_back(newListItem);
}


//Appends the given deque to the list items deque.
void List::addListItems(std::deque<std::string*> newListItems)
{
   listItems.insert(listItems.end(), newListItems.begin(), newListItems.end());
}