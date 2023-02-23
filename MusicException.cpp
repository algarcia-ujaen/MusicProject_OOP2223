//
// Created by algarcia on 23/02/23.
//

#include "MusicException.h"

MusicException::MusicException ( const std::string &className, const std::string &methodName,
                                 const std::string &errorMsg ) : _errorMsg ( errorMsg ), _className ( className )
                                                               , _methodName ( methodName )
{ }

const std::string &MusicException::getErrorMsg () const
{
   return _errorMsg;
}

void MusicException::setErrorMsg ( const std::string &errorMsg )
{
   _errorMsg = errorMsg;
}

const std::string &MusicException::getClassName () const
{
   return _className;
}

void MusicException::setClassName ( const std::string &className )
{
   _className = className;
}

const std::string &MusicException::getMethodName () const
{
   return _methodName;
}

void MusicException::setMethodName ( const std::string &methodName )
{
   _methodName = methodName;
}

std::string MusicException::getFullMessage ()
{
   return ( _className + "::" + _methodName
            + ": " + _errorMsg );
}
