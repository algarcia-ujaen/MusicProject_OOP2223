//
// Created by algarcia on 15/03/23.
//

#include "Lyrics.h"

const std::string &Lyrics::getContents () const
{
   return _contents;
}

void Lyrics::setContents ( const std::string &c )
{
   _contents = c;
}
