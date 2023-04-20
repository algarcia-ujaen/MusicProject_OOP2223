//
// Created by algarcia on 20/04/23.
//

#ifndef MYMUSICPROJECT_CANBESAVED_H
#define MYMUSICPROJECT_CANBESAVED_H

#include <string>

class CanBeSaved
{
   public:
      virtual std::string toCSV () const = 0;
      virtual ~CanBeSaved() {}
};

#endif //MYMUSICPROJECT_CANBESAVED_H
