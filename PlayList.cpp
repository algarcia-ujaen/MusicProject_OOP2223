//
// Created by algarcia on 9/03/23.
//

#include "PlayList.h"
#include "MusicException.h"

PlayList::PlayList ( const std::string &name ) : _name ( name ), _songs()
{
//   for ( int i = 0; i < MAX_SONGS; i++ )
//   {
//      _songs[i] = nullptr;
//   }
}

PlayList::~PlayList ()
{
//   for ( int i = 0; i < _nSongs; i++ )
//   {
//      _songs[i] = nullptr;
//   }
}

void PlayList::addSong ( Song &s )
{
   try
   {  _songs.addElement ( s );
   }
   catch ( std::length_error& e )
   {  throw MusicException ( "PlayList", "addSong"
                           , e.what() );
   }
//   if ( _nSongs == MAX_SONGS )
//   {
//      throw MusicException ( "PlayList", "addSong"
//                           , "Playlist full!");
//   }
//   _songs[_nSongs] = &s;
//   _nSongs++;
}

Song& PlayList::getSong ( int whichOne )
{  try
   {  return *_songs.getElement (whichOne);
   }
   catch ( std::out_of_range& e )
   {  throw MusicException ( "PlayList", "getSong"
                           , e.what() );
   }
}

void PlayList::deleteSong ( int whichOne )
{  try
   {  _songs.removeElement (whichOne);
   }
   catch ( std::out_of_range& e )
   {  throw MusicException ( "PlayList", "deleteSong"
                             , e.what() );
   }
}

int PlayList::getNumberOfSongs ()
{  return _songs.getNumberOfElements();
}