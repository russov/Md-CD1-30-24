//Полное совпадение с std::regex_match
//#include <iostream>
//#include <string>
//#include <regex>
//
//int main()
//{
//
//    if (std::regex_match("subject", std::regex("(sub)(.*)")))
//        std::cout << "string literal matched\n";
//
//    const char cstr[] = "subject";
//    std::string s("subject");
//    std::regex e("(sub)(.*)");
//
//    if (std::regex_match(s, e))
//        std::cout << "string object matched\n";
//
//    if (std::regex_match(s.begin(), s.end(), e))
//        std::cout << "range matched\n";
//
//    std::cmatch cm;    // same as std::match_results<const char*> cm;
//    std::regex_match(cstr, cm, e);
//    std::cout << "string literal with " << cm.size() << " matches\n";
//    for (const auto& c : cm) {
//        std::cout << "  -cmach: " << c << "\n";
//    }
//
//    std::smatch sm;    // same as std::match_results<string::const_iterator> sm;
//    std::regex_match(s, sm, e);
//    std::cout << "string object with " << sm.size() << " matches\n";
//    for (const auto& ss : sm) {
//        std::cout << "  -smach: " << ss << "\n";
//    }
//
//    std::regex_match(s.cbegin(), s.cend(), sm, e);
//    std::cout << "range with " << sm.size() << " matches\n";
//
//    // using explicit flags:
//    std::regex_match(cstr, cm, e, std::regex_constants::match_default);
//
//    std::cout << "the matches were: ";
//    for (unsigned i = 0; i < cm.size(); ++i) {
//        std::cout << "[" << cm[i] << "] ";
//    }
//
//    std::cout << std::endl;
//
//    return 0;
//}


//Поиск подстрок с std::regex_search
//#include <iostream>
//#include <regex>
//#include <string>
//
//int main() {
//    std::string text = "Hello, world! 1234 @#";
//    std::regex pattern("\\d+");  // Совпадение одной или более цифр
//    std::smatch matches;
//
//    if (std::regex_search(text, matches, pattern)) {
//        std::cout << "Found match: " << matches[0] << std::endl;
//    }
//    else {
//        std::cout << "No match found." << std::endl;
//    }
//
//    return 0;
//}




//Замена подстрок с std::regex_replace
//#include <iostream>
//#include <regex>
//#include <string>
//
//int main() {
//    std::string text = "The quick brown fox jumps over the lazy dog.";
//    std::regex pattern("quick|brown|lazy");  // Совпадение слов "quick", "brown" или "lazy"
//    std::string replacement = "slow";
//
//    std::string result = std::regex_replace(text, pattern, replacement);
//    std::cout << "Result: " << result << std::endl;
//
//    return 0;
//}




//  итераторы
//#include <iostream>
//#include <regex>
//#include <string>
//
//int main() {
//    std::string text = "abc 123 def 456 ghi";
//    std::regex pattern("\\d+"); // Шаблон для поиска одной или более цифр
//
//    // Создаем итераторы для поиска всех совпадений
//    std::sregex_iterator it(text.begin(), text.end(), pattern);
//    std::sregex_iterator end;
//
//    // Перебираем все совпадения и выводим их
//    while (it != end) {
//        std::smatch match = *it; // Текущее совпадение
//        std::cout << "Match: " << match.str() << std::endl;
//        ++it;
//    }
//
//    return 0;
//}






// поиск email алресов в файле
//#include <iostream>
//#include <regex>
//#include <string>
//#include <set>
//#include <fstream>
//
//int main() {
//    {
//        std::string content = R"(
//            Hello,
//
//            Welcome to our company. For general inquiries, please contact us at info@company.com.
//            If you have any technical issues, reach out to tech.support@company.com.
//            For sales-related questions, email us at sales@company.com.
//            You can also contact our HR department at hr@company.com for job opportunities.
//
//            Yesterday, we received an email from marketing@partner.com with a proposal.
//            Please review it and get back to them.
//
//            Best regards,
//            The Company Team
//
//            ---
//
//            Our partners are available at the following addresses:
//            - partner1@business.com
//            - partner2@business.com
//            - partner3@business.com
//
//            Thank you for your attention.
//
//            Additional contacts:
//            - alice.smith@example.com
//            - bob.jones@example.net
//            - charlie.brown@example.org
//
//            Please ensure that all customer inquiries are directed to customer.service@company.com.
//            Also, our support team can be reached at support@company.com.
//
//            Thank you,
//            Support Team
//        )";
//
//        std::ofstream file("large_document.txt");
//        if (file.is_open()) {
//            file << content;
//            file.close();
//            std::cout << "Document saved successfully." << std::endl;
//        }
//        else {
//            std::cerr << "Could not open the file for writing!" << std::endl;
//        }
//    }
//
//    //---------
//
//
//    // Открываем большой текстовый файл
//    std::ifstream file("large_document.txt");
//    if (!file.is_open()) {
//        std::cerr << "Could not open the file!" << std::endl;
//        return 1;
//    }
//
//    // Читаем весь файл в строку
//    std::string document((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
//
//    // Регулярное выражение для поиска email-адресов
//    std::regex email_pattern(R"(([\w.%+-]+)@([\w.-]+\.[a-zA-Z]{2,}))");
//
//    // Набор для хранения уникальных email-адресов
//    std::set<std::string> unique_emails;
//    std::sregex_iterator it(document.begin(), document.end(), email_pattern);
//    std::sregex_iterator end;
//
//    // Проход по всем совпадениям и добавление их в набор уникальных email-адресов
//    while (it != end) {
//        unique_emails.insert(it->str());
//        ++it;
//    }
//
//    // Вывод всех уникальных email-адресов
//    std::cout << "Unique email addresses found in the document:" << std::endl;
//    for (const auto& email : unique_emails) {
//        std::cout << email << std::endl;
//    }
//
//    return 0;
//}





//-------------------------------------------------------------------------------------------

//depricated
//#include <iostream>
//
//// Обозначаем функцию как устаревшую
//[[deprecated("Use new_function instead")]]
//void old_function() {
//    std::cout << "This is the old function." << std::endl;
//}
//
//void new_function() {
//    std::cout << "This is the new function." << std::endl;
//} 
//
//int main() {
//    old_function(); // Компилятор выдаст предупреждение о том, что функция устарела
//    new_function();
//    return 0;
//}




//constexpr
//#include <iostream>
//
//// constexpr функция для вычисления факториала
//constexpr int factorial(int n) {
//    int result = 1;
//    for (int i = 1; i <= n; ++i) {
//        result *= i;
//    }
//    return result;
//}
//
//int main() {
//    constexpr int compile_time_val = factorial(5); // Вычисление на этапе компиляции
//    std::cout << "Factorial of 5 (at compile time): " << compile_time_val << std::endl;
//
//    int num;
//    std::cout << "Enter a number: ";
//    std::cin >> num;
//
//    int runtime_val = factorial(num); // Вычисление на этапе выполнения
//    std::cout << "Factorial of " << num << " (at runtime): " << runtime_val << std::endl;
//
//    return 0;
//}




//шаблоны переменных
//#include <iostream>
//
//// Основной шаблон переменной
//template<typename T>
//constexpr T value = T(0);
//
//// Частичная специализация для int
//template<>
//constexpr int value<int> = 42;
//
//// Частичная специализация для double
//template<>
//constexpr double value<double> = 3.14;
//
//int main() {
//    std::cout << "value<int>: " << value<int> << std::endl;
//    std::cout << "value<double>: " << value<double> << std::endl;
//    std::cout << "value<float>: " << value<float> << std::endl; // Использует основной шаблон
//    return 0;
//}






// make_unique
//#include <iostream>
//#include <memory> // для std::unique_ptr и std::make_unique
//
//class Fraction
//{
//private:
//	int m_numerator = 0;
//	int m_denominator = 1;
//
//public:
//	Fraction(int numerator = 0, int denominator = 1) :
//		m_numerator(numerator), m_denominator(denominator)
//	{
//	}
//
//	friend std::ostream& operator<<(std::ostream& out, const Fraction& f1)
//	{
//		out << f1.m_numerator << "/" << f1.m_denominator;
//		return out;
//	}
//};
//
//
//int main()
//{
//	// Создаем объект с динамически выделенным Fraction с numerator = 7 и denominator = 9
//	std::unique_ptr<Fraction> f1 = std::make_unique<Fraction>(7, 9);
//	std::cout << *f1 << '\n';
//
//	// Создаем объект с динамически выделенным массивом Fraction длиной 5.
//	// Используем автоматическое определение типа данных с помощью ключевого слова auto
//	auto f2 = std::make_unique<Fraction[]>(5);
//	std::cout << f2[0] << '\n';
//
//	return 0;
//}





//if constexpr
//#include <iostream>
//#include <memory>
//
//template <typename T>
//void process(T value) {
//    if constexpr (std::is_integral_v<T>) {
//        std::cout << "Integral type" << std::endl;
//    }
//    else if constexpr (std::is_floating_point_v<T>) {
//        std::cout << "Floating point type" << std::endl;
//    }
//    else {
//        std::cout << "Other type" << std::endl;
//    }
//}
//
//int main() {
//    process(42);   // Выведет "Integral type"
//    process(3.14); // Выведет "Floating point type"
//    process("test"); // Выведет "Other type"
//    return 0;
//}






//std::any
//#include <iostream>
//#include <any>
//#include <string>
//
//int main() {
//    std::any val;
//
//    val = 5; // Сохранение целого числа
//    std::cout << "Stored integer: " << std::any_cast<int>(val) << std::endl;
//
//    val = std::string("Hello"); // Сохранение строки
//    std::cout << "Stored string: " << std::any_cast<std::string>(val) << std::endl;
//
//    if (val.has_value()) {
//        std::cout << "Value is present" << std::endl;
//    }
//    else {
//        std::cout << "Value is not present" << std::endl;
//    }
//
//    val.reset(); // Очистка значения
//
//    if (val.has_value()) {
//        std::cout << "Value is present" << std::endl;
//    }
//    else {
//        std::cout << "Value is not present" << std::endl;
//    }
//
//    return 0;
//}





//std::variant
//#include <iostream>
//#include <variant>
//#include <string>
//
//int main() {
//    std::variant<int, double, std::string> v;
//
//    v = 42;
//    std::cout << "Current value: " << std::get<int>(v) << std::endl;
//
//    v = 3.14;
//    std::cout << "Current value: " << std::get<double>(v) << std::endl;
//
//    v = "Hello";
//    std::cout << "Current value: " << std::get<std::string>(v) << std::endl;
//
//    return 0;
//}






//std::optional
//#include <iostream>
//#include <optional>
//
//std::optional<int> divide(int a, int b) {
//    if (b != 0) {
//        return a / b;
//    }
//    else {
//        return std::nullopt; // Возвращаем отсутствие значения
//    }
//}
//
//int main() {
//    auto result = divide(10, 2);
//    if (result.has_value()) {
//        std::cout << "Result: " << result.value() << std::endl;
//    }
//    else {
//        std::cout << "Division by zero!" << std::endl;
//    }
//
//    auto no_result = divide(10, 0);
//    if (!no_result.has_value()) {
//        std::cout << "Division by zero!" << std::endl;
//    }
//
//    return 0;
//}



//std::filesystem
//#include <iostream>
//#include <filesystem>
//
//namespace fs = std::filesystem;
//
//int main() {
//    // Создание директории
//    fs::create_directory("example_dir");
//
//    // Проверка существования файла
//    if (fs::exists("example_dir")) {
//        std::cout << "Directory 'example_dir' exists." << std::endl;
//    }
//
//    // Получение текущего пути
//    fs::path current_path = fs::current_path();
//    std::cout << "Current path: " << current_path << std::endl;
//
//    // Итерация по содержимому директории
//    for (const auto& entry : fs::directory_iterator(current_path)) {
//        std::cout << entry.path() << std::endl;
//    }
//
//    // Удаление директории
//    fs::remove("example_dir");
//
//    return 0;
//}