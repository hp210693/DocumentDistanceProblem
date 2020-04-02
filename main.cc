#include <iostream>
#include "distance_api.h"

int main() {
   std::cout << "The distance is = " << ccdist("datatest/test.txt","datatest/test2.txt") << std::endl;
}