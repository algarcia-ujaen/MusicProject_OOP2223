//
// Created by algarcia on 8/02/23.
//

#ifndef MYMUSICPROJECT_SONG_H
#define MYMUSICPROJECT_SONG_H

#include <string>

class Song
{
   private:
      float _length = 0;
      std::string _genre = "";
      std::string _artist = "";
      std::string _title = "";
      std::string *_comments = nullptr;
      int _nComments = 0;
   public:
      Song ( float l = 1, std::string t = "" );
      Song ( float length, const std::string &genre, const std::string &artist, const std::string &title );
      Song ( const Song& orig );
      float getLength () const;
      void setLength ( float length );
      const std::string &getGenre () const
      {return _genre;}
      void setGenre ( const std::string &genre );
      const std::string &getArtist () const;
      void setArtist ( const std::string &artist );
      const std::string &getTitle () const;
      void setTitle ( const std::string &title );
};

#endif //MYMUSICPROJECT_SONG_H
