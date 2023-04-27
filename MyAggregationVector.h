//
// Created by algarcia on 27/04/23.
//

#ifndef MYMUSICPROJECT_MYAGGREGATIONVECTOR_H
#define MYMUSICPROJECT_MYAGGREGATIONVECTOR_H

#include <stdexcept>

#define MAX_SIZE 100

template<typename T>
class MyAggregationVector
{
   private:
      T* _data[MAX_SIZE];
      int _usedData = 0;

   public:
      MyAggregationVector();
      MyAggregationVector ( const MyAggregationVector& orig );
      virtual ~MyAggregationVector();
      void addElement ( T& e );
      T* getElement ( int which );
      T* removeElement ( int which );
      int getNumberOfElements ();
};

template<typename T>
MyAggregationVector<T>::MyAggregationVector ()
{  for ( int i = 0; i < MAX_SIZE; i++ )
   {  _data[i] = nullptr;
   }
}

template<typename T>
MyAggregationVector<T>::MyAggregationVector ( const MyAggregationVector<T> &orig ):
                        _usedData ( orig._usedData )
{  for ( int i = 0; i < MAX_SIZE; i++ )
   {  _data[i] = orig._data[i];
   }
}

template<typename T>
MyAggregationVector<T>::~MyAggregationVector ()
{  for ( int i = 0; i < MAX_SIZE; i++ )
   {  _data[i] = nullptr;
   }
}

template<typename T>
void MyAggregationVector<T>::addElement ( T &e )
{  if ( _usedData == MAX_SIZE )
   {  throw std::length_error ( "MyAggregationVector::addElement: vector full" );
   }

   _data[_usedData] = &e;
   _usedData++;
}

template<typename T>
T* MyAggregationVector<T>::getElement ( int which )
{  if ( ( which < 0 ) || ( which >= _usedData ) )
   {  throw std::out_of_range ( "MyAggregationVector::getElement: invalid index" );
   }

   return _data [which];
}

template<typename T>
T* MyAggregationVector<T>::removeElement ( int which )
{  if ( ( which < 0 ) || ( which >= _usedData ) )
   {  throw std::out_of_range ( "MyAggregationVector::removeElement: invalid index" );
   }

   T* aux = _data[which];
   _usedData--;

   // As order is not important, just move the element at the end to the
   // removed position. If the vector is empty, just do nothing
   if ( _usedData != 0 )
   {  _data[which] = _data[_usedData];
   }

   _data[_usedData] = nullptr;
   return aux;
}

template<typename T>
int MyAggregationVector<T>::getNumberOfElements ()
{  return _usedData;
}

#endif //MYMUSICPROJECT_MYAGGREGATIONVECTOR_H
