//
// Created by algarcia on 26/04/23.
//

#include "NewMusicException.h"

NewMusicException::NewMusicException ( const std::string &message ):
std::logic_error ( message )
{}

NewMusicException::NewMusicException ( const NewMusicException &orig ):
std::logic_error ( orig )
{}
