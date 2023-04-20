//
// Created by algarcia on 15/03/23.
//

#include "Melody.h"

const std::string &Melody::getScore () const
{
   return _score;
}

void Melody::setScore ( const std::string &s )
{
   _score = s;
}