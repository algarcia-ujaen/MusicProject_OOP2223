//
// Created by algarcia on 9/03/23.
//

#include "PlayList.h"
#include "MusicException.h"

PlayList::PlayList ( const std::string &name ) : _name ( name )
{
   for ( int i = 0; i < MAX_SONGS; i++ )
   {
      _songs[i] = nullptr;
   }
}

PlayList::~PlayList ()
{
   for ( int i = 0; i < _nSongs; i++ )
   {
      _songs[i] = nullptr;
   }
}

void PlayList::addSong ( Song &s )
{
   if ( _nSongs == MAX_SONGS )
   {
      throw MusicException ( "PlayList", "addSong"
                           , "Playlist full!");
   }
   _songs[_nSongs] = &s;
   _nSongs++;
}