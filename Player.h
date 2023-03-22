//
// Created by algarcia on 22/03/23.
//

#ifndef MYMUSICPROJECT_PLAYER_H
#define MYMUSICPROJECT_PLAYER_H

#include "Artist.h"

class Player: public Artist
{
   private:
      std::string _instrument = "";

   public:
      Player ();
      Player ( const std::string &instrument );
      Player ( const Player& orig );
      virtual ~Player ();
      const std::string &getInstrument () const;
      void setInstrument ( const std::string &instrument );
};

#endif //MYMUSICPROJECT_PLAYER_H
