/**
 * @brief Declaration of the Song class
 * @author algarcia
 * @date 8/feb/2023
 */

#ifndef MYMUSICPROJECT_SONG_H
#define MYMUSICPROJECT_SONG_H

#include <string>
#include "Artist.h"
#include "Melody.h"
#include "Lyrics.h"

/**
 * The objects of this class will represent songs
 */
class Song
{
   private:
      float _length = 0;   ///< Length in seconds
      std::string _genre = "";   ///< Music genre
      Artist* _author = nullptr;   ///< Singer/player of the song
      std::string _title = "";   ///< Title of the song
      std::string *_comments = nullptr;   ///< Comments about the song
      int _nComments = 0;   ///< Amount of comments about the song

      // These attributes implement the composition. Let us assume
      // that every song has a melody (music), but not every song
      // has lyrics
      Lyrics* _songLyrics = nullptr;   ///< Lyrics of the song
      // This would be also valid, as it also represents a composition
      // (if the song is destroyed, the lyrics also disappear)
      //      Lyrics _songLyrics;
      //Melody* _songMusic = nullptr;
      Melody _songMusic;   ///< Melody of the song

   public:
      Song ( float l = 1, std::string t = "" );
      Song ( float length, const std::string &genre, Artist &artist, const std::string &title );
      Song ( const Song& orig );
      virtual ~Song ();
      float getLength () const;
      void setLength ( float length );
      /**
       * Method to observe the genre of the song
       * @return The genre of the song
       */
      const std::string &getGenre () const    // Example of inline method
      {return _genre;}
      void setGenre ( const std::string &genre );
      Artist &getAuthor () const;
      Artist* getAuthorPtr () const;
      void setAuthor ( Artist &artist );
      const std::string &getTitle () const;
      void setTitle ( const std::string &title );
      const int getNComments ();
      void addComment ( const std::string &comment );
      Song& operator= ( const Song &other );
      bool operator> ( const Song &other );
      Song operator+ ( const Song &other );
};

#endif //MYMUSICPROJECT_SONG_H
