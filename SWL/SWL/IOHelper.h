#ifndef IO_HELPER_H
#define IO_HELPER_H

#include <string>
#include <deque>

/*
This class provides static function to help with IO functions.
*/
class IOHelper
{
public:
   static std::deque<std::string> splitLines(std::string);
};

#endif