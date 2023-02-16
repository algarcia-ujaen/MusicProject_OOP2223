/**
 * @brief Implementation of the Song class
 * @author algarcia
 * @date 8/feb/2023
 */

#include "Song.h"

/**
 * Parameterized constructor that works as default also
 * @param l Length in seconds
 * @param t Title of the song
 * @note No checks are done on the parameter validity
 */
Song::Song ( float l, std::string t ): _length ( l ), _title ( t )
{}

/**
 * Parameterized constructor
 * @param length Length in seconds
 * @param genre Musical genre of the song
 * @param artist Name of the singer/player of the song
 * @param title Title of the song
 * @note No checks are done on the parameter validity
 */
Song::Song ( float length, const std::string &genre, const std::string &artist, const std::string &title ) : _length (
   length ), _genre ( genre ), _artist ( artist ), _title ( title )
{ }

/**
 * Copy constructor
 * @param orig Song whose attributes are copied
 */
Song::Song ( const Song &orig ): _length (orig._length)
                              , _artist ( orig._artist )
                              , _genre ( orig._genre )
                              , _title ( orig._title )
                              , _nComments ( orig._nComments )
{
   // The comments have to be duplicated, in order to avoid memory problems
   if ( _nComments > 0 )
   {
      _comments = new std::string[_nComments];
      for ( int i = 0 ; i < _nComments ; i++ )
      {
         _comments[i] = orig._comments[i];
      }
   }
}

/**
 * Destructor
 */
Song::~Song ()
{
   if ( _nComments > 0 )
   {
      delete[] _comments;
      _comments = nullptr;
      _nComments = 0;
   }
}

/**
 * Query the song for its length
 * @return The length of the song in seconds
 */
float Song::getLength () const
{
   return this->_length;
}

/**
 * Changes the song length
 * @param length New length in seconds
 * @throw std::string If the new length value is less than 0
 */
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

/**
 * Changes the musical genre of the song
 * @param genre New musical genre
 */
void Song::setGenre ( const std::string &genre )
{
   _genre = genre;
}

/**
 * Queries the song for its singer/player
 * @return The name of the singer/player of the song
 */
const std::string &Song::getArtist () const
{
   return _artist;
}

/**
 * Changes the singer/player of the song
 * @param artist New singer/player of the song
 */
void Song::setArtist ( const std::string &artist )
{
   _artist = artist;
}

/**
 * Queries the song for its title
 * @return The title of the song
 */
const std::string &Song::getTitle () const
{
   return _title;
}

/**
 * Changes the title of the song
 * @param title New title of the song
 */
void Song::setTitle ( const std::string &title )
{
   _title = title;
}

/**
 * Queries the song for the number of comments it has
 * @return The number of comments of the song
 */
const int Song::getNComments ()
{
   return _nComments;
}

/**
 * Adds a new comment for the song
 * @param comment New comment to be added
 */
void Song::addComment ( const std::string &comment )
{
   // We need a bigger container for the previous comments
   // plus the new one
   std::string* biggerGlass = nullptr;

   // Allocates the memory block
   biggerGlass = new std::string [_nComments+1];
   // Copies the old comments into the new container
   for ( int i = 0; i  < _nComments; i++ )
   {
      biggerGlass[i] = _comments[i];
   }

   // Adds the new comment at the end
   biggerGlass[_nComments] = comment;
   // Now there are one more comment than before
   _nComments++;

   // The old container has to be destroyed
   delete [] _comments;
   // Now the new container becomes the only container
   _comments = biggerGlass;
   // The auxiliary pointer is no longer needed
   biggerGlass = nullptr;
}


