//
// Created by algarcia on 22/03/23.
//

#include "Singer.h"

#include <sstream>
#include <iostream>

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

std::string Singer::toCSV () const
{
   std::stringstream aux;

   aux << "Singer;" << Artist::toCSV () << ";" << _voiceType;

   return aux.str();
}

void Singer::playMusic ()
{
   std::cout << getName() << " started singing with their "
             << _voiceType << " voice" << std::endl;
}

