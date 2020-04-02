#include <iostream>
#include "api/distance_api.h"

int main(int argc, char *argv[]) {
   if (argc < 2) {
      std::cout << "Unknown" << std::endl;
      return -1;
   } else {
      std::cout << "The distance is = " << ccdist(argv[1], argv[2]) << std::endl;
   }
   return 0;
}