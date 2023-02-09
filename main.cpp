#include <iostream>

#include "Song.h"

int main ()
{
   Song s1;
   Song s2 ( 5 );
   Song s3 ( 5, "kk" );
   Song songs [3];

   try
   {
      s1.setLength ( -1 );
      s1.setLength ( 2 );
   }
   catch ( std::string& e )
   {
      std::cout << "Exception caught: " << e << std::endl;
   }
   return 0;
}
