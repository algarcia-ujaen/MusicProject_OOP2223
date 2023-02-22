/**
 * @brief Declaration of the Song class
 * @author algarcia
 * @date 8/feb/2023
 */

#ifndef MYMUSICPROJECT_SONG_H
#define MYMUSICPROJECT_SONG_H

#include <string>

/**
 * The objects of this class will represent songs
 */
class Song
{
   private:
      float _length = 0;   ///< Length in seconds
      std::string _genre = "";   ///< Music genre
      std::string _artist = "";   ///< Singer/player of the song
      std::string _title = "";   ///< Title of the song
      std::string *_comments = nullptr;   ///< Comments about the song
      int _nComments = 0;   ///< Amount of comments about the song
   public:
      Song ( float l = 1, std::string t = "" );
      Song ( float length, const std::string &genre, const std::string &artist, const std::string &title );
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
      const std::string &getArtist () const;
      void setArtist ( const std::string &artist );
      const std::string &getTitle () const;
      void setTitle ( const std::string &title );
      const int getNComments ();
      void addComment ( const std::string &comment );
      Song& operator= ( const Song &other );
      bool operator> ( const Song &other );
      Song operator+ ( const Song &other );
};

#endif //MYMUSICPROJECT_SONG_H
