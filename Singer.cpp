//
// Created by algarcia on 22/03/23.
//

#include "Singer.h"

Singer::Singer (): Artist()
{ }

Singer::Singer ( const std::string &voiceType ): Artist()
                                               , _voiceType ( voiceType )
{ }

Singer::Singer ( const Singer &orig ): Artist ( orig )
                                     , _voiceType ( orig._voiceType )
{}

Singer::Singer ( const int i, const std::string n
               , const std::string vT ): Artist ( i, n )
                                       , _voiceType ( vT )
{}

Singer::~Singer ()
{}

const std::string &Singer::getVoiceType () const
{
   return _voiceType;
}

void Singer::setVoiceType ( const std::string &voiceType )
{
   _voiceType = voiceType;
}


