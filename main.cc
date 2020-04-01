#include <iostream>
#include "distance.h"

int main()
{
   Distance dis = {"datatest/test.txt","datatest/test2.txt"};
   std::cout << "The distance is = " << dis.ComputeDistance() <<std::endl;
}