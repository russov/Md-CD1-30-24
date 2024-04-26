#include "pch.h"
#include "../Module_21_task/module_21_task.h"

// Тестирование функции calculateSum
TEST(CalculateSumTest, EmptyVector) {
    std::vector<int> numbers;
    EXPECT_EQ(0, calculateSum(numbers));
}

TEST(CalculateSumTest, PositiveNumbers) {
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    EXPECT_EQ(15, calculateSum(numbers));
}

TEST(CalculateSumTest, NegativeNumbers) {
    std::vector<int> numbers = { -1, -2, -3, -4, -5 };
    EXPECT_EQ(-15, calculateSum(numbers));
}

TEST(CalculateSumTest, MixedNumbers) {
    std::vector<int> numbers = { -1, 2, -3, 4, -5 };
    EXPECT_EQ(-3, calculateSum(numbers));
}


// Тестирование функции calculateAverage
TEST(CalculateAverageTest, EmptyVector) {
    std::vector<int> numbers;
    EXPECT_DOUBLE_EQ(0.0, calculateAverage(numbers));
}

TEST(CalculateAverageTest, PositiveNumbers) {
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    EXPECT_DOUBLE_EQ(3.0, calculateAverage(numbers));
}

TEST(CalculateAverageTest, NegativeNumbers) {
    std::vector<int> numbers = { -1, -2, -3, -4, -5 };
    EXPECT_DOUBLE_EQ(-3.0, calculateAverage(numbers));
}

TEST(CalculateAverageTest, MixedNumbers) {
    std::vector<int> numbers = { -1, 2, -3, 4, -5 };
    EXPECT_DOUBLE_EQ(-0.6, calculateAverage(numbers));
}


// Тестирование функции printVectorReverse
TEST(PrintVectorReverseTest, EmptyVector) {
    std::vector<int> numbers;
    testing::internal::CaptureStdout();
    printVectorReverse(numbers);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Numbers in reverse order:\n", output);
}

TEST(PrintVectorReverseTest, NonEmptyVector) {
    std::vector<int> numbers = { 1, 2, 3, 4, 5 };
    testing::internal::CaptureStdout();
    printVectorReverse(numbers);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ("Numbers in reverse order:\n5\n4\n3\n2\n1\n", output);
}


// Тестирование функции writeNumbersToFile
TEST(WriteNumbersToFileTest, ValidInput) {
    // Создание временного файла
    const std::string filename = "test_numbers.txt";

    // Ввод тестовых данных для функции writeNumbersToFile
    std::istringstream input("10 20 done");
    std::streambuf* oldCinBuf = std::cin.rdbuf(input.rdbuf());

    // Вызов тестируемой функции
    writeNumbersToFile(filename);

    // Восстановление стандартного ввода
    std::cin.rdbuf(oldCinBuf);

    // Проверка созданного файла
    std::ifstream file(filename);
    EXPECT_TRUE(file.good());
    file.close();
    // Удаление временного файла
    std::remove(filename.c_str());
}

TEST(WriteNumbersToFileTest, InvalidInput) {
    // Путь к временному файлу для тестирования
    const std::string filename = "test_numbers.txt";

    // Удаление временного файла
    std::remove(filename.c_str());

    // Создаем поток, чтобы захватить вывод на stderr
    testing::internal::CaptureStderr();

    // Ввод некорректных данных для функции writeNumbersToFile
    std::istringstream input("abc done");
    std::streambuf* oldCinBuf = std::cin.rdbuf(input.rdbuf());

    // Запись чисел в файл
    writeNumbersToFile(filename);
    
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_NE(output.find("Invalid input. Please enter a valid number."), std::string::npos);

    // Проверка содержимого файла (должен быть пустой)
    std::ifstream file(filename);
    std::string line;
    EXPECT_FALSE(std::getline(file, line)); // Ожидаем пустой файл
    file.close();

    // Восстановление стандартного ввода
    std::cin.rdbuf(oldCinBuf);
}


// Тест для проверки завершения записи при вводе 'done'
TEST(WriteNumbersToFileTest, DoneInput) {
    // Путь к временному файлу для тестирования
    const std::string filename = "test_numbers.txt";

    // Удаление временного файла
    std::remove(filename.c_str());

    // Ввод 'done' для завершения записи в файл
    std::istringstream input("done");
    std::streambuf* oldCinBuf = std::cin.rdbuf(input.rdbuf());

    // Запись чисел в файл
    writeNumbersToFile(filename);

    // Восстановление стандартного ввода
    std::cin.rdbuf(oldCinBuf);

    // Проверка содержимого файла (должен быть пустой)
    std::ifstream file(filename);
    std::string line;
    EXPECT_FALSE(std::getline(file, line)); // Ожидаем пустой файл
    file.close();
}


// Тестирование функции readNumbersFromFile
TEST(ReadNumbersFromFileTest, ValidFile) {
    const std::string filename = "test_numbers.txt";
    std::ofstream outfile(filename);
    outfile << "1 2 3 4 5";
    outfile.close();

    auto numbers = readNumbersFromFile(filename);

    EXPECT_EQ(numbers.size(), 5);
    EXPECT_EQ(numbers[0], 1);
    EXPECT_EQ(numbers[1], 2);
    EXPECT_EQ(numbers[2], 3);
    EXPECT_EQ(numbers[3], 4);
    EXPECT_EQ(numbers[4], 5);

    // Удаление временного файла
    std::remove(filename.c_str());
}

// Тестирование функции readNumbersFromFile
TEST(ReadNumbersFromFileTest, EmptyFile) {
    const std::string filename = "test_numbers.txt";
    std::ofstream outfile(filename);
    outfile.close();

    auto numbers = readNumbersFromFile(filename);
    EXPECT_EQ(numbers.size(), 0);

    // Удаление временного файла
    std::remove(filename.c_str());
}

// Тестирование функции readNumbersFromFile
TEST(ReadNumbersFromFileTest, MixedTypesFile) {
    const std::string filename = "test_numbers.txt";
    std::ofstream outfile(filename);
    outfile << "a b c d e";
    outfile.close();

    auto numbers = readNumbersFromFile(filename);

    EXPECT_EQ(numbers.size(), 0);

    // Удаление временного файла
    std::remove(filename.c_str());
}

// Тестирование функции readNumbersFromFile
TEST(ReadNumbersFromFileTest, StringFile) {
    const std::string filename = "test_numbers.txt";
    std::ofstream outfile(filename);
    outfile << "1 2 c 3 e";
    outfile.close();

    auto numbers = readNumbersFromFile(filename);

    EXPECT_EQ(numbers.size(), 2);
    EXPECT_EQ(numbers[0], 1);
    EXPECT_EQ(numbers[1], 2);

    // Удаление временного файла
    std::remove(filename.c_str());
}

TEST(ReadNumbersFromFileTest, NonExistentFile) {
    const std::string filename = "non_existent_file.txt";
    ASSERT_THROW(readNumbersFromFile(filename), std::runtime_error);
}