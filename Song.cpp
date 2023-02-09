//
// Created by algarcia on 8/02/23.
//

#include "Song.h"

Song::Song ( float l, std::string t ): _length ( l ), _title ( t )
{}

Song::Song ( float length, const std::string &genre, const std::string &artist, const std::string &title ) : _length (
   length ), _genre ( genre ), _artist ( artist ), _title ( title )
{ }


float Song::getLength () const
{
   return this->_length;
}

void Song::setLength ( float length )
{
   if ( length < 0 )
   {
      throw std::string ( "The length cannnot be negative" );
   }

   this->_length = length;
}

//const std::string &Song::getGenre () const
//{
//   return _genre;
//}

void Song::setGenre ( const std::string &genre )
{
   _genre = genre;
}

const std::string &Song::getArtist () const
{
   return _artist;
}

void Song::setArtist ( const std::string &artist )
{
   _artist = artist;
}

const std::string &Song::getTitle () const
{
   return _title;
}

void Song::setTitle ( const std::string &title )
{
   _title = title;
}

