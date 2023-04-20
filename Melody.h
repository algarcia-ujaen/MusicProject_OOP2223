//
// Created by algarcia on 15/03/23.
//

#ifndef MYMUSICPROJECT_MELODY_H
#define MYMUSICPROJECT_MELODY_H

#include <string>

class Melody
{
   private:
      std::string _score = "";   // See https://music-encoding.org

   public:
      Melody () = default;
      virtual ~Melody () = default;
      const std::string &getScore () const;
      void setScore ( const std::string &s );
};

#endif //MYMUSICPROJECT_MELODY_H
