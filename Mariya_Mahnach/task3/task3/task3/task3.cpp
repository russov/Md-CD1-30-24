#include <iostream>

int main()
{
    const int n = 10;
    int a, b, arr[10][10];
    std::cout << "Enter the interval to generate an array of numbers:\n";
    std::cin >> a >> b;
    while (a == b)
    {
        std::cout << "Values must be different!\n";
        std::cout<<"Enter the interval to generate an array of numbers:\n";
        std::cin >> a >> b;
    }
    std::cout << "Generated array:\n";
    if (a > b) std::swap(a, b);
    int numi = 0, numj = 0;
    std::srand(time(0));
    for (int i = 0; i < n; i++)
    {
        std::cout << i + 1 << ")\t";
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = std::rand() % (b - a) + a;
            std::cout << arr[i][j] << '\t';
            if (arr[i][j] < arr[numi][numj]) { numi = i; numj = j; }
        }
        std::cout << '\n';
    }
    std::cout << "\nMinimum element: " << arr[numi][numj] << "\nCoordinates: (" << numi + 1 << "; " << numj + 1 << ")\n\n";
    for (int j = 0; j < n; j++)
        std::swap(arr[0][j], arr[numi][j]);
    if (numi != 0)
    {
        std::cout << "Line 1 and line " << numi + 1 << " switched places\n\n";
        for (int i = 0; i < n; i++)
        {
            if (i == 0) std::cout << numi + 1;
            else if (i == numi) std::cout << '1';
            else std::cout << i + 1;
            std::cout << ")\t";
            for (int j = 0; j < n; j++)
            {
                std::cout << arr[i][j] << '\t';
            }
            std::cout << "\n";
        }
    }
    else std::cout << "The minimum element is already on the first line.\n";
}

