

//singleton

//#include <string>
//#include <iostream>
//#include <mutex>
//using namespace std;
//
//class Singleton {
//private:
//
//    // member variables
//    std::string name, loves;
//    static std::mutex mtx;
//
//    static Singleton* instancePtr;
//
//    // Default constructor
//    Singleton()
//    {
//    }
//
//public:
//
//    // deleting copy constructor
//    Singleton(const Singleton& obj)
//        = delete;
//
//    /*
//      getInstance() is a static method that returns an
//      instance when it is invoked. It returns the same
//      instance if it is invoked more than once as an instance
//      of Singleton class is already created. It is static
//      because we have to invoke this method without any object
//      of Singleton class and static method can be invoked
//      without object of class
//
//      As constructor is private so we cannot create object of
//      Singleton class without a static method as they can be
//      called without objects. We have to create an instance of
//      this Singleton class by using getInstance() method.
//    */
//    static Singleton* getInstance()
//    {
//        std::lock_guard<std::mutex> lock(mtx);
//         
//        // If there is no instance of class
//        // then we can create an instance.
//        if (instancePtr == NULL)
//        {
//            // We can access private members 
//            // within the class.
//            instancePtr = new Singleton();
//        }
//        
//        return instancePtr;
//
//    }
//
//    // sets values of member variables.
//    void setValues(string name,
//        string loves)
//    {
//        this->name = name;
//        this->loves = loves;
//    }
//
//    // prints values of member variables
//    void print()
//    {
//        cout << name << " Loves " <<
//            loves << "." << endl;
//    }
//};
//
//// initializing instancePtr with NULL
//Singleton* Singleton::instancePtr{ nullptr };
//std::mutex Singleton::mtx;
//
//// Driver code
//int main()
//{
//    Singleton* GeeksForGeeks
//        = Singleton::getInstance();
//
//    // setting values of member variables.
//    GeeksForGeeks->setValues("Manish",
//        "GeeksForGeeks");
//
//    // printing values of member variables.
//    GeeksForGeeks->print();
//
//    cout << "Address of GeeksForGeeks: " <<
//        GeeksForGeeks << endl;
//
//    cout << endl;
//
//    Singleton* gfg = Singleton::getInstance();
//
//    // setting values of member variables.
//    gfg->setValues("Vartika",
//        "GeeksForGeeks");
//
//    // Printing values of member variables.
//    gfg->print();
//
//    cout << "Address of gfg: " << gfg << endl;
//    return 0;
//}


//------------------------------------------------------------------------------------------------
//Facade
//#include <iostream>
//
//class Light {
//public:
//    void on() {
//        std::cout << "Lights are on." << std::endl;
//    }
//    void off() {
//        std::cout << "Lights are off." << std::endl;
//    }
//    void dim(int level) {
//        std::cout << "Lights dimmed to " << level << "%" << std::endl;
//    }
//};
//
//class Heating {
//public:
//    void setTemperature(int temperature) {
//        std::cout << "Heating set to " << temperature << " degrees." << std::endl;
//    }
//};
//
//class SecuritySystem {
//public:
//    void arm() {
//        std::cout << "Security system armed." << std::endl;
//    }
//    void disarm() {
//        std::cout << "Security system disarmed." << std::endl;
//    }
//};
//
//class AudioSystem {
//public:
//    void playMusic() {
//        std::cout << "Playing music." << std::endl;
//    }
//    void stopMusic() {
//        std::cout << "Music stopped." << std::endl;
//    }
//};
//
////Facade class
//class SmartHomeFacade {
//private:
//    Light* light;
//    Heating* heating;
//    SecuritySystem* security;
//    AudioSystem* audio;
//
//public:
//    SmartHomeFacade(Light* l, Heating* h, SecuritySystem* s, AudioSystem* a)
//        : light(l), heating(h), security(s), audio(a) {}
//
//    void morningRoutine() {
//        std::cout << "Starting morning routine..." << std::endl;
//        light->on();
//        light->dim(70);
//        heating->setTemperature(22);
//        audio->playMusic();
//    }
//
//    void nightRoutine() {
//        std::cout << "Starting night routine..." << std::endl;
//        light->dim(20);
//        heating->setTemperature(18);
//        security->arm();
//        audio->stopMusic();
//        light->off();
//    }
//};
//
////client
//int main() {
//    // Создание компонентов подсистемы
//    Light light;
//    Heating heating;
//    SecuritySystem security;
//    AudioSystem audio;
//
//    // Создание Facade
//    SmartHomeFacade smartHome(&light, &heating, &security, &audio);
//
//    // Использование Facade для управления системой "Умный дом"
//    smartHome.morningRoutine();
//    std::cout << std::endl;
//    smartHome.nightRoutine();
//
//    return 0;
//}





//-----------------------------------------------------------------------------------
// Bridge
//#include <iostream>
//
//// Интерфейс для всех устройств
//class Device {
//public:
//    virtual bool isEnabled() const = 0;
//    virtual void enable() = 0;
//    virtual void disable() = 0;
//    virtual int getVolume() const = 0;
//    virtual void setVolume(int percent) = 0;
//    virtual int getChannel() const = 0;
//    virtual void setChannel(int channel) = 0;
//    virtual ~Device() {}
//};
//
//// Конкретное устройство - Телевизор
//class Tv : public Device {
//private:
//    bool powerOn;
//    int volume;
//    int channel;
//public:
//    Tv() : powerOn(false), volume(50), channel(1) {}
//
//    bool isEnabled() const override { return powerOn; }
//    void enable() override { powerOn = true; }
//    void disable() override { powerOn = false; }
//    int getVolume() const override { return volume; }
//    void setVolume(int percent) override { volume = percent; }
//    int getChannel() const override { return channel; }
//    void setChannel(int channel) override { this->channel = channel; }
//};
//
//// Конкретное устройство - Радио
//class Radio : public Device {
//private:
//    bool on;
//    int volume;
//    int frequency;
//public:
//    Radio() : on(false), volume(30), frequency(90) {}
//
//    bool isEnabled() const override { return on; }
//    void enable() override { on = true; }
//    void disable() override { on = false; }
//    int getVolume() const override { return volume; }
//    void setVolume(int percent) override { volume = percent; }
//    int getChannel() const override { return frequency; }
//    void setChannel(int frequency) override { this->frequency = frequency; }
//};
//
//// Класс пульта, который делегирует действия устройству
//class Remote {
//protected:
//    Device* device;
//public:
//    Remote(Device* device) : device(device) {}
//
//    void togglePower() {
//        if (device->isEnabled())
//            device->disable();
//        else
//            device->enable();
//    }
//
//    void volumeDown() {
//        device->setVolume(device->getVolume() - 10);
//    }
//
//    void volumeUp() {
//        device->setVolume(device->getVolume() + 10);
//    }
//
//    void channelDown() {
//        device->setChannel(device->getChannel() - 1);
//    }
//
//    void channelUp() {
//        device->setChannel(device->getChannel() + 1);
//    }
//};
//
//// Расширенный пульт, наследуется от основного
//class AdvancedRemote : public Remote {
//public:
//    AdvancedRemote(Device* device) : Remote(device) {}
//
//    void mute() {
//        device->setVolume(0);
//    }
//};
//
//// Клиентский код
//int main() {
//    Tv* tv = new Tv();
//    Remote* remote = new Remote(tv);
//
//    remote->togglePower();
//    remote->volumeUp();
//    remote->channelUp();
//
//    Radio* radio = new Radio();
//    AdvancedRemote* advancedRemote = new AdvancedRemote(radio);
//
//    advancedRemote->togglePower();
//    advancedRemote->mute();
//
//    delete tv;
//    delete remote;
//    delete radio;
//    delete advancedRemote;
//
//    return 0;
//}





//----------------------------------------------------------------------------------------------------------------
//observer
#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

// Общий интерфейс подписчиков
class EventListener {
public:
    virtual void update(const std::string& filename) = 0;
    virtual ~EventListener() {}
};

// Базовый класс-издатель
class EventManager {
private:
    std::unordered_map<std::string, std::vector<EventListener*>> listeners;

public:
    void subscribe(const std::string& eventType, EventListener* listener) {
        listeners[eventType].push_back(listener);
    }

    void unsubscribe(const std::string& eventType, EventListener* listener) {
        auto& eventListeners = listeners[eventType];
        for (auto it = eventListeners.begin(); it != eventListeners.end(); ++it) {
            if (*it == listener) {
                eventListeners.erase(it);
                return;
            }
        }
    }

    void notify(const std::string& eventType, const std::string& data) {
        auto& eventListeners = listeners[eventType];
        for (auto listener : eventListeners) {
            listener->update(data);
        }
    }
};

// Конкретный класс-издатель
class Editor {
private:
    EventManager events;
    std::string filePath;

public:
    Editor() {}

    void openFile(const std::string& path) {
        filePath = path;
        events.notify("open", filePath);
    }

    void saveFile() {
        events.notify("save", filePath);
    }

    void subscribe(const std::string& eventType, EventListener* listener) {
        events.subscribe(eventType, listener);
    }

    void unsubscribe(const std::string& eventType, EventListener* listener) {
        events.unsubscribe(eventType, listener);
    }
};

// Конкретный подписчик - логгер
class LoggingListener : public EventListener {
private:
    std::string logFilename;
    std::string message;

public:
    LoggingListener(const std::string& filename, const std::string& msg)
        : logFilename(filename), message(msg) {}

    void update(const std::string& filename) override {
        std::cout << "Logging: " << message << " " << filename << std::endl;
    }
};

// Конкретный подписчик - уведомление по email
class EmailAlertsListener : public EventListener {
private:
    std::string email;
    std::string message;

public:
    EmailAlertsListener(const std::string& emailAddress, const std::string& msg)
        : email(emailAddress), message(msg) {}

    void update(const std::string& filename) override {
        std::cout << "Email sent to " << email << ": " << message << " " << filename << std::endl;
    }
};

// Пример использования
int main() {
    Editor editor;

    LoggingListener logger("/path/to/log.txt", "Someone has opened file: %s");
    editor.subscribe("open", &logger);

    EmailAlertsListener emailAlerts("admin@example.com", "Someone has changed the file: %s");
    editor.subscribe("save", &emailAlerts);

    // Моделируем открытие и сохранение файла
    editor.openFile("/path/to/file.txt");
    editor.saveFile();

    // Отписка от событий
    editor.unsubscribe("open", &logger);
    editor.unsubscribe("save", &emailAlerts);

    return 0;
}