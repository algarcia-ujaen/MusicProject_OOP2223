//
// Created by algarcia on 8/03/23.
//

#include "Artist.h"

const std::string &Artist::getName () const
{
   return _name;
}

void Artist::setName ( const std::string &name )
{
   _name = name;
}

int Artist::getId () const
{
   return _id;
}

void Artist::setId ( int id )
{
   _id = id;
}
