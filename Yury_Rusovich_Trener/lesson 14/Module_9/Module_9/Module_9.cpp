//#include <iostream>
//#include <boost/property_tree/ptree.hpp>
//#include <boost/property_tree/json_parser.hpp>
//#include <boost/regex.hpp>
//
//int main() {
//    // Пример JSON-строки
//    std::string json_str = R"({"name": "John", "age": 30, "city": "New York", "email": "john@example.com"})";
//
//    // Разбор JSON-строки в дерево свойств
//    boost::property_tree::ptree pt;
//    std::istringstream json_stream(json_str);
//    boost::property_tree::read_json(json_stream, pt);
//
//    // Получение значений из дерева свойств
//    std::string name = pt.get<std::string>("name");
//    int age = pt.get<int>("age");
//    std::string city = pt.get<std::string>("city");
//    std::string email = pt.get<std::string>("email");
//
//    std::cout << "Name: " << name << std::endl;
//    std::cout << "Age: " << age << std::endl;
//    std::cout << "City: " << city << std::endl;
//    std::cout << "Email: " << email << std::endl;
//
//    // Пример работы с регулярными выражениями
//    std::string input = "Boost libraries are very useful!";
//    boost::regex expr("\\b\\w+\\b");
//    boost::sregex_iterator it(input.begin(), input.end(), expr);
//    boost::sregex_iterator end;
//
//    std::cout << "Words in the input string:" << std::endl;
//    while (it != end) {
//        std::cout << *it++ << std::endl;
//    }
//
//    return 0;
//}


// boost asio
#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

void server(boost::asio::io_context& io_context, short port) {
    tcp::acceptor acceptor(io_context, tcp::endpoint(tcp::v4(), port));
    tcp::socket socket(io_context);
    acceptor.accept(socket);

    std::array<char, 1024> buffer;
    boost::system::error_code error;
    size_t length = socket.read_some(boost::asio::buffer(buffer), error);
    if (error) {
        std::cerr << "Error reading from socket: " << error.message() << std::endl;
    }
    else {
        std::cout << "Received message from client: " << std::string(buffer.data(), length) << std::endl;
        boost::asio::write(socket, boost::asio::buffer(buffer, length));
    }
}

void client(boost::asio::io_context& io_context, const std::string& message, const std::string& server_ip, short port) {
    tcp::socket socket(io_context);
    socket.connect(tcp::endpoint(boost::asio::ip::make_address(server_ip), port));

    boost::asio::write(socket, boost::asio::buffer(message));

    std::array<char, 1024> buffer;
    size_t length = socket.read_some(boost::asio::buffer(buffer));
    std::cout << "Received message from server: " << std::string(buffer.data(), length) << std::endl;
}

int main() {
    try {
        boost::asio::io_context io_context;

        std::thread server_thread([&io_context]() { server(io_context, 8888); });

        std::this_thread::sleep_for(std::chrono::seconds(1)); // Pause to let the server start

        client(io_context, "Hello from client!", "127.0.0.1", 8888);

        server_thread.join();
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}