//
// Created by algarcia on 22/03/23.
//

#ifndef MYMUSICPROJECT_SINGER_H
#define MYMUSICPROJECT_SINGER_H

#include "Artist.h"

class Singer: public Artist
{
   private:
      std::string _voiceType = "";

   public:
      Singer ();
      Singer ( const std::string &voiceType );
      Singer ( const int i, const std::string n
             , const std::string vT );
      Singer ( const Singer& orig );
      virtual ~Singer ();
      const std::string &getVoiceType () const;
      void setVoiceType ( const std::string &voiceType );
};

#endif //MYMUSICPROJECT_SINGER_H
