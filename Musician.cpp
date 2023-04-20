//
// Created by algarcia on 22/03/23.
//

#include "Musician.h"
#include <sstream>
#include <iostream>

Musician::Musician (): Artist()
{ }

Musician::Musician ( int i, std::string n, std::string ins ): Artist ( i, n)
                                                              , _instrument ( ins )
{}

Musician::Musician ( const std::string &instrument ): Artist()
                                                      , _instrument ( instrument )
{ }

Musician::Musician ( const Musician &orig ): Artist ( orig )
                                             , _instrument ( orig._instrument )
{ }

Musician::~Musician ()
{

}

const std::string &Musician::getInstrument () const
{
   return _instrument;
}

void Musician::setInstrument ( const std::string &instrument )
{
   _instrument = instrument;
}

std::string Musician::toCSV () const
{
   std::stringstream aux;

   aux << "Musician;" << Artist::toCSV () << ";" << _instrument;

   return aux.str();
}

void Musician::playMusic ()
{
   std::cout << getName() << " started playing the "
                          << _instrument << std::endl;
}
