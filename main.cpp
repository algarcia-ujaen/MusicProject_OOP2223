#include <iostream>

#include "Song.h"

int main ()
{
   Song s1;
 //  Song s2 ( 5 );
 //  Song s3 ( 5, "kk" );
 //  Song s4 (s2);
 //  Song songs [3];
   Song *pS = nullptr;

   pS = new Song ( 60, "Demons" );
   pS->addComment ( "Great!" );
   (*pS).addComment ( "Wonderful!" );

   try
   {
      s1.setLength ( -1 );
      s1.setLength ( 2 );
   }
   catch ( std::string& e )
   {
      std::cout << "Exception caught: " << e << std::endl;
   }

   delete pS;
   pS = nullptr;
   return 0;
}
