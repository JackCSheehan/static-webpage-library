#include "IOHelper.h"

/*
This function splits the given string into a deque at each newline.
*/
std::deque<std::string> IOHelper::splitLines(std::string str)
{
   std::deque<std::string> lines;   //The lines split from the given string
   std::string currentLine;         //The current line being read from the given string

   //Iterate through each character in the given string
   for (char c : str)
   {
      //Add only non-newline characters the current line
      if (c != '\n')
      {
         currentLine += c;
      }
      //Once a newline character has been found, add the current line to the lines deque
      else
      {
         lines.push_back(currentLine);

         //Reset current line
         currentLine = "";
      }
   }

   //Add the last currentLine to the lines deque
   lines.push_back(currentLine);

   return lines;
}