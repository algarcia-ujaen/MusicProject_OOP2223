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
      Player ( int i, std::string n, std::string ins );
      Player ( const std::string &instrument );
      Player ( const Player& orig );
      virtual ~Player ();
      const std::string &getInstrument () const;
      void setInstrument ( const std::string &instrument );
      virtual std::string toCSV () const override;
      virtual void playMusic () override;
};

#endif //MYMUSICPROJECT_PLAYER_H
