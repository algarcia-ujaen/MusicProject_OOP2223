#include <iostream>
#include <fstream>

#include "Song.h"
#include "MusicException.h"
#include "NewMusicException.h"
#include "Singer.h"
#include "Musician.h"

//template<typename X>
//void saveToFile ( const X *data, const std::string &fileName )
//{
//   std::ofstream myFile;
//
//   myFile.open ( fileName, std::ios_base::app );
//   myFile << data->toCSV () << std::endl;
//   myFile.close();
//}

// version 2 with interface
void saveToFile ( CanBeSaved *data, const std::string &fileName )
{
   std::ofstream myFile;

   myFile.open ( fileName, std::ios_base::app );
   myFile << data->toCSV () << std::endl;
   myFile.close();
}


int main ()
{
   Song s1;
 //  Song s2 ( 5 );
 //  Song s3 ( 5, "kk" );
 //  Song s4 (s2);
 //  Song songs [3];
   Song *pS = nullptr;

   // Now we can not create Artist objects, as it has a pure
   // virtual method
//   Artist a1;
//   a1.setName ( "Imagine Dragons" );
//   a1.setId ( 1 );

   Singer a1 ( 1, "adsf", "tenor" );
   try
   {
      pS = new Song ( -1, "Demons" );
      pS->addComment ( "Great!" );
      (*pS).addComment ( "Wonderful!" );
   }
//   catch ( MusicException& e )
//   {
//      std::cerr << e.getFullMessage() << std::endl;
//   }
   catch ( NewMusicException& e )
   {
      std::cerr << e.what () << std::endl;
   }
   s1.setLength (120);
   pS = new Song ( 60, "Demons" );
   pS->setAuthor ( a1 );

   std::cout << "The author of song "
             << pS->getTitle() << " is "
             << pS->getAuthor().getName() << std::endl;
   // Application of RTTI with references
   std::cout << "And he/she is a ";
   try
   {  Singer& aux = dynamic_cast<Singer&> ( pS->getAuthor() );
      std::cout << "singer";
      // I could have used here aux as Singer if needed
   }
   catch ( std::bad_cast& e )
   {  std::cout << "musician";
   }

   std::cout << std::endl;

   // Application of RTTI with pointers
   std::cout << "Just to confirm, he/she is a ";
   Singer* ptrSaux = dynamic_cast<Singer*> ( pS->getAuthorPtr() );
   if  ( ptrSaux != nullptr )
   {  std::cout << "singer";
      // I could have used here ptrSaux as Singer* if needed
   }
   else
   {  std::cout << "musician";
   }

   std::cout << std::endl;
//   s1 = *pS;   // Same as s1.operator= (*pS);
//   *pS = s1;   // Same as pS->operator= (s1);
               // Same as (*pS).operator= (s1);
   if ( s1 > *pS )  // Same as s1.operator> (*pS)
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

   Singer mc ( 1, "Mariah Carey", "Soprano" );

   saveToFile ( &mc, "kk.txt" );
//   saveToFile ( s7, "kk2.txt" );

   Artist* band[4];
   band[0] = new Singer ( 2, "Pepe", "Barítono" );
   band[1] = new Musician ( 3, "Manuel", "Electric guitar" );
   band[2] = new Musician  ( 4, "Francisco", "Drums" );
   band[3] = new Musician ( 5, "Isa", "Bass" );

   for ( int i = 0; i < 4; i++ )
   {
      saveToFile ( band[i], "band.csv" );
      band[i]->playMusic();
   }

   for ( int i = 0; i < 4; i++ )
   {
      delete band[i];
      band [i] = nullptr;
   }
   return 0;
}
