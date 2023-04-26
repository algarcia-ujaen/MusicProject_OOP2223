//
// Created by algarcia on 26/04/23.
//

#ifndef MYMUSICPROJECT_NEWMUSICEXCEPTION_H
#define MYMUSICPROJECT_NEWMUSICEXCEPTION_H

#include <stdexcept>

class NewMusicException: public std::logic_error
{
   public:
      NewMusicException( const std::string &message );
      NewMusicException ( const NewMusicException& orig );
      virtual ~NewMusicException() noexcept = default;
};

#endif //MYMUSICPROJECT_NEWMUSICEXCEPTION_H
