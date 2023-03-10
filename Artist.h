//
// Created by algarcia on 8/03/23.
//

#ifndef MYMUSICPROJECT_ARTIST_H
#define MYMUSICPROJECT_ARTIST_H

#include <string>

class Artist
{
   private:
      std::string _name = "";
      int _id = 0;
   public:
      Artist() = default;
      ~Artist() = default;
      const std::string &getName () const;
      void setName ( const std::string &name );
      int getId () const;
      void setId ( int id );
};

#endif //MYMUSICPROJECT_ARTIST_H
