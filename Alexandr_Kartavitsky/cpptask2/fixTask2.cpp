#include <iostream>
#include <cctype>
#include <limits>
#include <fstream>
#include "create_file.h"
#include "r_file.h"
#include "sum_ave.h"
#include "write_endd_file.h"

int main() {
   makeFileNumbers();
   readReverse();
   sumAverage();
   writeInTheFileEnd();
 return 0;

 
}
