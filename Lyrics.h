//
// Created by algarcia on 15/03/23.
//

#ifndef MYMUSICPROJECT_LYRICS_H
#define MYMUSICPROJECT_LYRICS_H

#include <string>

class Lyrics
{
   private:
      std::string _contents = "";

   public:
      Lyrics() = default;
      ~Lyrics() = default;
      const std::string &getContents () const;
      void setContents ( const std::string &c );
};

#endif //MYMUSICPROJECT_LYRICS_H
