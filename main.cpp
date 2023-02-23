#include <iostream>

#include "Song.h"
#include "MusicException.h"

int main ()
{
   Song s1;
 //  Song s2 ( 5 );
 //  Song s3 ( 5, "kk" );
 //  Song s4 (s2);
 //  Song songs [3];
   Song *pS = nullptr;

   try
   {
      pS = new Song ( -1, "Demons" );
      pS->addComment ( "Great!" );
      (*pS).addComment ( "Wonderful!" );
   }
   catch ( MusicException& e )
   {
      std::cerr << e.getFullMessage() << std::endl;
   }
   s1.setLength (120);
   pS = new Song ( 60, "Demons" );

//   s1 = *pS;   // Same as s1.operator= (*pS);
//   *pS = s1;   // Same as pS->operator= (s1);
               // Same as (*pS).operator= (s1);
   if ( s1 > *pS )
   {  std::cout << "s1 is greater" << std::endl;
   }
   else
   {  std::cout << "s1 is not greater" << std::endl;
   }
   try
   {
      s1.setLength ( -1 );
      s1.setLength ( 2 );
   }
   catch ( MusicException& e )
   {
      std::cout << e.getFullMessage() << std::endl;
   }

   Song s7 = s1 + *pS;   // Same as Song s7 = s1.operator+ ( *pS );

   if ( pS != nullptr )
   {
      delete pS;
      pS = nullptr;
   }
   return 0;
}
