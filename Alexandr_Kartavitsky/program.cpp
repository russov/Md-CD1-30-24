#include <iostream>
#include <fstream>
#include <vector>
int main()
{
    // 1
    std::ofstream file("fileeee.txt");
    if (!file)
    {
        std::cout << "Open file error" << '\n';
        return 1;
    }

    int values;
    std::cout << "Enter your values and in the end double click ENTER: ";
    int newLine = 0;
    while (true)
    {
        std::cin >> values;
        if (std::cin.peek() == '\n')
        {
            newLine++;
        }
        else
        {
            newLine = 0;
        }
        if (newLine >= 2)
        {
            break;
        }
        file << values << '\n';
    }

    // 2
    std::ifstream file_r("fileeee.txt");
    if (!file)
    {
        std::cout << "Open file error" << '\n';
        return 1;
    }
    std::vector<int> v;
    int numb;
    while (file_r >> numb)
    {
        v.push_back(numb);
    }
    for (auto it = v.rbegin(); it != v.rend(); ++it)
    {
        std::cout << *it << '\n';
    }

    // 3
    int sum = 0;
    for (int num : v)
    {
        sum += num;
    }

    std::cout << "Sum of elements: " << sum << '\n';

    return 0;

    // 4
    int summ = 0;
    for (int num : v)
    {
        summ += num;
    }
    double average = sum / v.size();
    std::cout << "Average: " << average << '\n';

    return 0;

    // 5
    std::ofstream filE("fileeee.txt", std::ios::app);
    if (!filE)
    {
        std::cout << "Open file error" << '\n';
        return 1;
    }
    for (int i = 1; i <= 10; ++i)
    {
        file << i << " ";
    }
    file << '\n';

    file.close();

    return 0;
}
