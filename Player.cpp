//
// Created by algarcia on 22/03/23.
//

#include "Player.h"

Player::Player (): Artist()
{ }

Player::Player ( int i, std::string n, std::string ins ): Artist (i, n)
                                                        , _instrument ( ins )
{}

Player::Player ( const std::string &instrument ): Artist()
                                                , _instrument ( instrument )
{ }

Player::Player ( const Player &orig ): Artist ( orig )
                                     , _instrument ( orig._instrument )
{ }

Player::~Player ()
{

}

const std::string &Player::getInstrument () const
{
   return _instrument;
}

void Player::setInstrument ( const std::string &instrument )
{
   _instrument = instrument;
}

