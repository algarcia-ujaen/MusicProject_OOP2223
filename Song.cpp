/**
 * @brief Implementation of the Song class
 * @author algarcia
 * @date 8/feb/2023
 */

#include "Song.h"
#include "MusicException.h"

/**
 * Parameterized constructor that works as default also.
 * Creates a song without lyrics
 * @param l Length in seconds
 * @param t Title of the song
 * @note No checks are done on the parameter validity
 */
Song::Song ( float l, std::string t ): _length ( l ), _title ( t )
                                     , _songMusic ()
{
   if ( _length < 0 )
   {
      throw MusicException ( "Song", "Song"
                           , "Negative length!!!" );
   }
}

/**
 * Parameterized constructor. Creates a song without lyrics
 * @param length Length in seconds
 * @param genre Musical genre of the song
 * @param artist Name of the singer/player of the song
 * @param title Title of the song
 * @note No checks are done on the parameter validity
 */
Song::Song ( float length, const std::string &genre, Artist &artist
           , const std::string &title ) : _length ( length ), _genre ( genre )
           , _author ( &artist ), _title ( title ), _songMusic ()

{ }

/**
 * Copy constructor
 * @param orig Song whose attributes are copied
 */
Song::Song ( const Song &orig ): _length (orig._length)
                              , _author ( orig._author )
                              , _genre ( orig._genre )
                              , _title ( orig._title )
                              , _nComments ( orig._nComments )
                              , _songMusic ( orig._songMusic )
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

   // If there are lyrics for the original song, copy them
   if ( orig._songLyrics )
   {
      _songLyrics = new Lyrics ( *orig._songLyrics );
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

   // Not every song has lyrics, but if it has them, we have
   // to delete them
   if ( _songLyrics )
   {
      delete _songLyrics;
      _songLyrics = nullptr;
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
 * @throw MusicException If the new length value is less than 0
 */
void Song::setLength ( float length )
{
   if ( length < 0 )
   {
      throw MusicException ( "Song", "setLength"
                           , "The length cannnot be negative" );
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
const Artist &Song::getAuthor () const
{
   return *_author;
}

/**
 * Changes the singer/player of the song
 * @param artist New singer/player of the song
 */
void Song::setAuthor ( Artist &artist )
{
   _author = &artist;
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

/**
 * Assignment operator
 * @param other Song whose values are copied in the current object
 * @return The current object, so that chained assignments can be done
 */
Song& Song::operator= ( const Song &other )
{  if ( this != &other ) // Make sure we are not trying to assign an object to itself
   {  _length = other._length;   // Assign the attributes of simple types
      _genre = other._genre;
      _author = other._author;
      _title = other._title;
      _songMusic = other._songMusic;

      if ( other._songLyrics )   // There are lyrics for the other
      {
         if ( _songLyrics )   // This song has lyrics; copy the other
         {
            *_songLyrics = *other._songLyrics;
         }
         else   // This song has no lyrics; create new lyrics
         {
            _songLyrics = new Lyrics ( *other._songLyrics );
         }
      }

      // Delete old comments if necessary
      if ( _nComments != other._nComments )
      {  delete [] _comments;
         _comments = new std::string[other._nComments];
         _nComments = other._nComments;
      }

      // Copy comments of the original song
      for ( int i = 0; i < _nComments; i++ )
      {  _comments[i] = other._comments[i];
      }
   }
   return *this;
}

/**
 * Greater than operator.
 *
 * A song is greater than another one if its length or its title are greater
 * @param other Song to compare with
 * @retval true If the current song is greater than the other
 * @retval false If the current song is not greater than the other
 */
bool Song::operator> ( const Song &other )
{  bool toRet = true;   // True unless proved otherwise

   if ( _length <= other._length )
   {  toRet = false;
   }

   if ( _title <= other._title )
   {  toRet = false;
   }

   return toRet;
}

/**
 * Add operator
 * @param other Song to be added
 * @return A new song with combines the values of the two objects
 */
Song Song::operator+ ( const Song &other )
{  Song aux;
   aux._length = this->_length + other._length;
   aux._genre = this->_genre + " & " + other._genre;
   //aux._author = this->_author + " & " + other._author;
   aux._title = this->_title + " & " + other._title;
   aux._nComments = this->_nComments + other._nComments;

   // Comments are combined in a new set
   aux._comments = new std::string [aux._nComments];

   int j = 0;
   for ( int i = 0; i < this->_nComments; i++ )
   {  aux._comments [j] = this->_comments[i];
      j++;
   }

   for ( int i = 0; i < other._nComments; i++ )
   {  aux._comments [j] = other._comments[i];
      j++;
   }

   return aux;
}