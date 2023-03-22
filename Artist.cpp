//
// Created by algarcia on 8/03/23.
//

#include "Artist.h"

Artist::Artist ( const int id
               , const std::string &name ): _id ( id )
                                          ,_name ( name )
{ }

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


