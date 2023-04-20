//
// Created by algarcia on 22/03/23.
//

#ifndef MYMUSICPROJECT_MUSICIAN_H
#define MYMUSICPROJECT_MUSICIAN_H

#include "Artist.h"

class Musician: public Artist
{
   private:
      std::string _instrument = "";

   public:
      Musician ();
      Musician ( int i, std::string n, std::string ins );
      Musician ( const std::string &instrument );
      Musician ( const Musician& orig );
      virtual ~Musician ();
      const std::string &getInstrument () const;
      void setInstrument ( const std::string &instrument );
      virtual std::string toCSV () const override;
      virtual void playMusic () override;
};

#endif //MYMUSICPROJECT_MUSICIAN_H
