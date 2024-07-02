#include <iostream>
#include <cctype>
#include <limits>
#include <fstream>
#include "make_file.h"
#include "read_file.h"
#include "sum_average.h"
#include "write_end_file.h"

int main()
{
    makeFileNumbers();
    readReverse();
    sumAverage();
    writeInTheFileEnd();
    return 0;
}
