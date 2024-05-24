// пример реализации потоков
//#include <iostream>
//#include <thread>
//
//// Функция, которая будет выполнена в потоке
//void threadFunction() {
//    std::cout << "Hello from thread!" << std::endl;
//}
//
//int main() {
//    // Создаем объект потока и передаем ему функцию для выполнения
//    std::thread t(threadFunction);
//
//    // Ждем завершения потока
//    t.join();
//    //t.detach();
//
//    std::cout << "Back in main thread" << std::endl;
//
//    return 0;
//}


#include <iostream>
#include <thread>

int main() {
    // Создаем объект потока и передаем ему лямбда-функцию для выполнения
    std::thread t([]() {
        std::cout << "Hello from thread!" << std::endl;
        });

    // Ждем завершения потока
    t.join();

    std::cout << "Back in main thread" << std::endl;

    return 0;
}






//--------------------------------------------------------
//cосотояние гонки
//#include <thread>
//#include <iostream>
//
//int counter = 0;
//
//void increment() {
//    for (int i = 0; i < 100000; ++i) {
//        ++counter;
//    }
//}
//
//int main() {
//    std::thread t1(increment);
//    std::thread t2(increment);
//
//    t1.join();
//    t2.join();
//
//    std::cout << "Counter: " << counter << std::endl;
//    return 0;
//}

// решение проблемы cосотояние гонки

//#include <iostream>
//#include <thread>
//#include <mutex>
//
//int counter = 0;
//std::mutex counter_mutex;
//
//void increment() {
//    for (int i = 0; i < 10000000; ++i) {
//        std::lock_guard<std::mutex> lock(counter_mutex);
//        ++counter;
//    }
//}
//
//int main() {
//    std::thread t1(increment);
//    std::thread t2(increment);
//
//    t1.join();
//    t2.join();
//
//    std::cout << "Counter: " << counter << std::endl;
//    return 0;
//}



//atomic
//#include <iostream>
//#include <thread>
//#include <atomic>
//
//std::atomic<int> counter{ 0 };
//
//void increment() {
//    for (int i = 0; i < 100000000; ++i) {
//        ++counter;
//    }
//}
//
//int main() {
//    std::thread t1(increment);
//    std::thread t2(increment);
//
//    t1.join();
//    t2.join();
//
//    std::cout << "Counter: " << counter << std::endl;
//    return 0;
//}






//-----------------------------------------------------------------------------------
//Deadlock
//#include <iostream>
//#include <thread>
//#include <mutex>
//
//std::mutex m1, m2;
//
//void thread1() {
//    std::lock_guard<std::mutex> lock1(m1);
//    std::this_thread::sleep_for(std::chrono::milliseconds(100));
//    std::lock_guard<std::mutex> lock2(m2);
//}
//
//void thread2() {
//    std::lock_guard<std::mutex> lock1(m2);
//    std::this_thread::sleep_for(std::chrono::milliseconds(100));
//    std::lock_guard<std::mutex> lock2(m1);
//}
//
//int main() {
//    std::thread t1(thread1);
//    std::thread t2(thread2);
//
//    t1.join();
//    t2.join();
//
//    return 0;
//}

// решение deadlock
//#include <iostream>
//#include <mutex>
//#include <thread>
//#include <mutex>
//
//int main()
//{
//    std::mutex m1;
//    std::mutex m2;
//
//    auto f1 = [&m1, &m2]() {
//        std::scoped_lock lg(m1, m2);
//        std::this_thread::sleep_for(std::chrono::milliseconds(10));
//        };
//
//    auto f2 = [&m1, &m2]() {
//        std::scoped_lock lg(m2, m1);
//        std::this_thread::sleep_for(std::chrono::milliseconds(10));
//        };
//
//    std::thread thread1([&f1, &f2]() {
//        f1();
//        });
//
//    std::thread thread2([&f1, &f2]() {
//        f2();
//        });
//
//    thread1.join();
//    thread2.join();
//
//    return 0;
//}


//синхронизация потоков
//------------------------------------------------------------------------------
//мьютекс classic

//#include <mutex>
//#include <queue>
//
//class threadSafe_queue {
//
//    std::queue<int> rawQueue; // структура, общая для всех потоков
//    std::mutex m; // красная дверь rawQueue
//
//public:
//
//    int& retrieve_and_delete() {
//        int front_value = 0; // если пустая, возвращает 0
//        m.lock();
//        // Отныне текущий поток единственный, который имеет доступ к rawQueue
//        if (!rawQueue.empty()) {
//            front_value = rawQueue.front();
//            rawQueue.pop();
//        }
//        m.unlock();
//        // теперь другие потоки могут захватить мьютекс
//        return front_value;
//    };
//
//    void push(int val) {
//        m.lock();
//        rawQueue.push(val);
//        m.unlock();
//    };
//
//};


//lock guard
//#include <mutex>
//#include <queue>
//
//class threadSafe_queue {
//
//    std::queue<int> rawQueue; // структура, общая для всех потоков
//    std::mutex m; // красная дверь rawQueue
//
//public:
//
//    int& retrieve_and_delete() {
//        int front_value = 0; // если пустая, return будет 0
//        std::lock_guard<std::mutex> lg(m);
//        // Отныне текущий поток единственный, который имеет доступ к rawQueue
//        if (!rawQueue.empty()) {
//            front_value = rawQueue.front();
//            rawQueue.pop();
//        }
//        return front_value;
//    };  // теперь другие потоки могут захватить мьютекс
//
//    void push(int val) {
//        std::lock_guard<std::mutex> lg(m);
//        // отныне текущий поток единственный, который имеет доступ к rawQueue
//        rawQueue.push(val);
//    }; // теперь другие потоки могут захватить мьютекс
//};


//unique_lock
//#include <mutex>
//#include <vector>
//std::mutex door; //объявление мьютекса
//std::vector<int> v;
//
//{
//    std::unique_lock<std::mutex> ul(door);
//    // Вызывается конструктор ul, эквивалентный door.lock();
//    // ul, размещённый в стеке
//    // гарантируется монопольное использование вектора
//
//    door.unlock();
//
//    // выполнение операций, не связанных с вектором
//    // ....
//    // теперь мне снова нужен доступ к вектору 
//
//    door.lock();
//    //Снова гарантируется монопольное использование вектора
//} /* unique_lock выходит из области видимости. Вызывается деструктор, эквивалентный door.unlock(); */


//std::scoped_mutex
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <vector>
//
//std::mutex mtx1;
//std::mutex mtx2;
//std::vector<int> shared_vector1;
//std::vector<int> shared_vector2;
//
//void add_to_vectors(int value) {
//    {
//        // Используем std::scoped_lock для одновременного захватывания mtx1 и mtx2
//        std::scoped_lock lock(mtx1, mtx2);
//        shared_vector1.push_back(value);
//        shared_vector2.push_back(value);
//    } // Автоматическое освобождение мьютексов при выходе из области видимости
//}
//
//int main() {
//    std::thread t1(add_to_vectors, 1);
//    std::thread t2(add_to_vectors, 2);
//    std::thread t3(add_to_vectors, 3);
//
//    t1.join();
//    t2.join();
//    t3.join();
//
//    {
//        // Используем std::scoped_lock для безопасного доступа к shared_vector1 и shared_vector2
//        std::scoped_lock lock(mtx1, mtx2);
//        std::cout << "Vector 1 contents: ";
//        for (int v : shared_vector1) {
//            std::cout << v << " ";
//        }
//        std::cout << std::endl;
//
//        std::cout << "Vector 2 contents: ";
//        for (int v : shared_vector2) {
//            std::cout << v << " ";
//        }
//        std::cout << std::endl;
//    } // Автоматическое освобождение мьютексов при выходе из области видимости
//
//    return 0;
//}






//conditional variable
//#include <iostream>
//#include <string>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//
//std::mutex m;
//std::condition_variable cv;
//std::string data;
//bool ready = false;
//bool processed = false;
//
//void worker_thread()
//{
//    // ждем, пока main() не отправит данные
//    std::unique_lock<std::mutex> lk(m);
//    cv.wait(lk, [] {return ready; });
//    // после ожидания мы владеем блокировкой
//    std::cout << "Worker thread is processing data\n";
//    data += " after processing";
//
//    // отправляем данные обратно в main()
//    processed = true;
//    std::cout << "Worker thread signals data processing completed\n";
//
//    // Ручная разблокировка выполняется перед уведомлением,
//    // чтобы не разбудить ожидающий поток только для повторной блокировки
//    // (подробности смотрите в разделе о notify_one)
//    lk.unlock();
//    cv.notify_one();
//}
//
//int main()
//{
//    std::thread worker(worker_thread);
//
//
//    data = "Example data";
//    // отправляем данные в обрабатывающий поток
//    {
//        std::lock_guard<std::mutex> lk(m);
//        ready = true;
//        std::cout << "main() signals data ready for processing\n";
//    }
//    cv.notify_one();
//
//    // ждем обработчика
//    {
//        std::unique_lock<std::mutex> lk(m);
//        cv.wait(lk, [] {return processed; });
//    }
//    std::cout << "Back in main(), data = " << data << '\n';
//
//    worker.join();
//}


//conditional variable
//notify_all
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <condition_variable>
//
//std::mutex mtx;
//std::condition_variable cv;
//bool is_ready = false;
//
//void worker_thread(int id) {
//    std::unique_lock<std::mutex> lck(mtx);
//    cv.wait(lck, [] { return is_ready; }); // Поток ожидает, пока не будет установлен флаг is_ready
//    std::cout << "Worker " << id << " is processing..." << std::endl;
//}
//
//int main() {
//    std::thread workers[5];
//
//    // Запускаем несколько потоков-работников
//    for (int i = 0; i < 5; ++i) {
//        workers[i] = std::thread(worker_thread, i);
//    }
//
//    std::this_thread::sleep_for(std::chrono::seconds(2)); // Имитация какой-то работы
//
//    {
//        std::lock_guard<std::mutex> lck(mtx);
//        is_ready = true; // Устанавливаем флаг is_ready
//    }
//    cv.notify_all(); // Уведомляем все ожидающие потоки
//
//    // Дожидаемся завершения всех потоков
//    for (int i = 0; i < 5; ++i) {
//        workers[i].join();
//    }
//
//    return 0;
//}



//-----------------------------------------------------------------------------------
//atomic
//#include <iostream>
//#include <thread>
//#include <atomic>
//
//std::atomic<int> counter{ 0 };
//
//void increment() {
//    for (int i = 0; i < 1000000; ++i) {
//        counter.fetch_add(1); // Атомарно увеличиваем значение счётчика на 1
//    }
//}
//
//int main() {
//    std::thread t1(increment);
//    std::thread t2(increment);
//
//    t1.join();
//    t2.join();
//
//    std::cout << "Counter: " << counter << std::endl;
//
//    return 0;
//}



//------------------------------------------------------------------------------------
//std::future 
//std::assync
//#include <iostream>
//#include <future>
//
//// Функция, которую мы хотим выполнить асинхронно
//int add(int a, int b) {
//    return a + b;
//}
//
//int main() {
//    // Создаем асинхронную задачу с использованием std::async
//    std::future<int> future_result = std::async(std::launch::async, add, 5, 3);
//
//    // Ждем завершения асинхронной задачи и получаем результат
//    int result = future_result.get();
//
//    // Выводим результат
//    std::cout << "Result: " << result << std::endl;
//
//    return 0;
//}

//#include <iostream>
//#include <future>
//
//int main() {
//    // Создаем асинхронную задачу с использованием лямбда-выражения с параметром
//    std::future<int> future_result = std::async(std::launch::async, [](int input) {
//        std::this_thread::sleep_for(std::chrono::seconds(2));
//        return input * 2; // Лямбда-выражение умножает входной параметр на 2
//        }, 10); // Передаем входной параметр 10
//
//
//    // Проверяем, завершена ли задача
//    auto status = future_result.wait_for(std::chrono::seconds(0));
//
//    if (status == std::future_status::ready) {
//        // Задача завершена, результат готов
//        std::cout << "Task is ready." << std::endl;
//    }
//    else if (status == std::future_status::timeout) {
//        // Задача еще выполняется
//        std::cout << "Task is still running." << std::endl;
//    }
//
//    // Ждем завершения асинхронной задачи и получаем результат
//    int result = future_result.get();
//
//    // Выводим результат
//    std::cout << "Result: " << result << std::endl;
//
//    return 0;
//}


//std::promise, std::future
//#include <iostream>
//#include <future>
//#include <thread>
//#include <chrono>
//
//// Функция, которая будет выполнена асинхронно
//void performAsyncOperation(std::promise<int>& prom) {
//    // Имитация долгих вычислений
//    std::this_thread::sleep_for(std::chrono::seconds(3));
//
//    // Выполняем вычисления
//    int result = 42;
//
//    // Устанавливаем результат в объект std::promise
//    prom.set_value(result);
//}
//
//int main() {
//    // Создаем объект std::promise
//    std::promise<int> prom;
//
//    // Получаем связанный с ним объект std::future
//    std::future<int> fut = prom.get_future();
//
//    // Запускаем функцию performAsyncOperation в новом потоке
//    std::thread th(performAsyncOperation, std::ref(prom));
//
//    // Ожидаем получение результата от потока
//    int result = fut.get();
//
//    std::cout << "Received result: " << result << std::endl;
//
//    // Ждем завершения потока
//    th.join();
//
//    return 0;
//}




//--------------------------------------------------------------------------------------
//паралельные алгоритмы
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <execution>
//#include <chrono>
//#include <thread>
//
//int main() {
//    std::vector<int> vec = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
//
//    // Параллельная сортировка
//    std::sort(std::execution::par, vec.begin(), vec.end());
//
//	std::for_each(std::execution::par, vec.begin(), vec.end(), 
//        [](int& x) {
//		x *= 2;
//		});
//
//    for (int num : vec) {
//        std::cout << num << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}



