//
// Created by algarcia on 9/03/23.
//

#ifndef MYMUSICPROJECT_PLAYLIST_H
#define MYMUSICPROJECT_PLAYLIST_H

#include <string>
#include "Song.h"
#include "MyAggregationVector.h"

#define MAX_SONGS 100

class PlayList
{
   private:
      std::string _name = "";
//      Song* _songs[MAX_SONGS];
//      int _nSongs = 0;
   MyAggregationVector<Song> _songs;

   public:
      PlayList ( const std::string &name );
      virtual ~PlayList ();
      int getLength ();
      void addSong ( Song &s );
      Song& getSong ( int whichOne );
      void deleteSong ( int whichOne );
      int getNumberOfSongs ();
};

#endif //MYMUSICPROJECT_PLAYLIST_H
