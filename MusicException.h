//
// Created by algarcia on 23/02/23.
//

#ifndef MYMUSICPROJECT_MUSICEXCEPTION_H
#define MYMUSICPROJECT_MUSICEXCEPTION_H

#include <string>

class MusicException
{
   private:
      std::string _errorMsg = "";
      std::string _className = "";
      std::string _methodName = "";
   public:
      MusicException ( const std::string &className, const std::string &methodName
                     , const std::string &errorMsg );
      ~MusicException() = default;
      const std::string &getErrorMsg () const;
      void setErrorMsg ( const std::string &errorMsg );
      const std::string &getClassName () const;
      void setClassName ( const std::string &className );
      const std::string &getMethodName () const;
      void setMethodName ( const std::string &methodName );
      std::string getFullMessage ();
};

#endif //MYMUSICPROJECT_MUSICEXCEPTION_H
