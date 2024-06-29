#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include <clocale> // для setlocale

using namespace sf;
using namespace std;

const int WIDTH = 800; // ширина окна
const int HEIGHT = 600; // высота окна
const int GRID_SIZE = 20; // размер одной ячейки на сетке

struct SnakeSegment {
    int x, y; // координаты сегмента змеи
};

enum Direction { UP, DOWN, LEFT, RIGHT }; // направления движения змеи
enum FruitType { NORMAL, SPECIAL }; // типы фруктов

class SnakeGame {
public:
    SnakeGame(int initialSpeed, bool withOpponent, bool increaseSpeed)
        : window(VideoMode(WIDTH, HEIGHT), "Snake Game"),
        direction(RIGHT), opponentDirection(RIGHT),
        gameOver(false), speed(initialSpeed), opponentSpeed(initialSpeed),
        withOpponent(withOpponent), increaseSpeed(increaseSpeed), currentFruitType(NORMAL) {
        snake.push_back({ 10, 10 }); // начальная позиция змеи
        generateFruit(); // генерация первого фрукта
        if (withOpponent) {
            opponentSnake.push_back({ WIDTH / GRID_SIZE - 10, HEIGHT / GRID_SIZE - 10 }); // начальная позиция оппонента
        }
    }

    void run() {
        while (window.isOpen()) {
            Clock clock;
            Clock opponentClock;
            gameOver = false;
            snake.clear();
            snake.push_back({ 10, 10 }); // сброс змеи на начальную позицию
            nTail = 0;
            generateFruit(); // генерация нового фрукта
            if (withOpponent) {
                opponentSnake.clear();
                opponentSnake.push_back({ WIDTH / GRID_SIZE - 10, HEIGHT / GRID_SIZE - 10 }); // сброс оппонента на начальную позицию
                opponentTail = 0;
            }

            while (window.isOpen() && !gameOver) {
                handleInput(); // обработка ввода пользователя
                if (withOpponent) {
                    updateOpponentDirection(); // обновление направления оппонента
                }
                float elapsed = clock.getElapsedTime().asMilliseconds();
                float opponentElapsed = opponentClock.getElapsedTime().asMilliseconds();
                if (elapsed >= speed) {
                    update(); // обновление состояния игры
                    clock.restart();
                }
                if (withOpponent && opponentElapsed >= opponentSpeed) {
                    updateOpponent(); // обновление состояния оппонента
                    opponentClock.restart();
                }
                render(); // отрисовка текущего состояния игры
            }

            if (window.isOpen()) {
                if (!askForReplay()) {
                    window.close(); // закрытие окна, если игрок не хочет играть снова
                }
            }
        }
    }

private:
    RenderWindow window;
    vector<SnakeSegment> snake;
    vector<SnakeSegment> opponentSnake;
    SnakeSegment fruit;
    Direction direction;
    Direction opponentDirection;
    bool gameOver;
    int speed;
    int opponentSpeed;
    size_t nTail = 0;
    size_t opponentTail = 0;
    bool withOpponent;
    bool increaseSpeed;
    FruitType currentFruitType;

    // Обработка ввода пользователя для управления змеей
    void handleInput() {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed) {
                if ((event.key.code == Keyboard::W || event.key.code == Keyboard::Up) && direction != DOWN) direction = UP;
                if ((event.key.code == Keyboard::S || event.key.code == Keyboard::Down) && direction != UP) direction = DOWN;
                if ((event.key.code == Keyboard::A || event.key.code == Keyboard::Left) && direction != RIGHT) direction = LEFT;
                if ((event.key.code == Keyboard::D || event.key.code == Keyboard::Right) && direction != LEFT) direction = RIGHT;
                if (event.key.code == Keyboard::Escape) window.close();
            }
        }
    }

    // Обновление состояния змеи и проверка на столкновения и поедание фруктов
    void update() {
        moveSnake();
        checkCollision();
        checkFruit();
    }

    // Обновление состояния оппонента и проверка на столкновения и поедание фруктов
    void updateOpponent() {
        moveOpponentSnake();
        checkCollision();
        checkFruit();
    }

    // Перемещение змеи игрока
    void moveSnake() {
        SnakeSegment newHead = snake.front();
        switch (direction) {
        case UP: newHead.y--; break;
        case DOWN: newHead.y++; break;
        case LEFT: newHead.x--; break;
        case RIGHT: newHead.x++; break;
        }

        // Проход через стены
        if (newHead.x >= WIDTH / GRID_SIZE) newHead.x = 0;
        else if (newHead.x < 0) newHead.x = WIDTH / GRID_SIZE - 1;
        if (newHead.y >= HEIGHT / GRID_SIZE) newHead.y = 0;
        else if (newHead.y < 0) newHead.y = HEIGHT / GRID_SIZE - 1;

        snake.insert(snake.begin(), newHead);
        if (snake.size() > nTail + 1) {
            snake.pop_back();
        }
    }

    // Перемещение змеи оппонента
    void moveOpponentSnake() {
        SnakeSegment newHead = opponentSnake.front();
        switch (opponentDirection) {
        case UP: newHead.y--; break;
        case DOWN: newHead.y++; break;
        case LEFT: newHead.x--; break;
        case RIGHT: newHead.x++; break;
        }

        // Проход через стены
        if (newHead.x >= WIDTH / GRID_SIZE) newHead.x = 0;
        else if (newHead.x < 0) newHead.x = WIDTH / GRID_SIZE - 1;
        if (newHead.y >= HEIGHT / GRID_SIZE) newHead.y = 0;
        else if (newHead.y < 0) newHead.y = HEIGHT / GRID_SIZE - 1;

        opponentSnake.insert(opponentSnake.begin(), newHead);
        if (opponentSnake.size() > opponentTail + 1) {
            opponentSnake.pop_back();
        }
    }

    // Обновление направления движения оппонента, чтобы он не столкнулся ни с собой, ни с игроком
    void updateOpponentDirection() {
        SnakeSegment head = opponentSnake.front();
        Direction newDirection = opponentDirection;

        if (head.x < fruit.x && opponentDirection != LEFT) {
            newDirection = RIGHT;
        }
        else if (head.x > fruit.x && opponentDirection != RIGHT) {
            newDirection = LEFT;
        }
        else if (head.y < fruit.y && opponentDirection != UP) {
            newDirection = DOWN;
        }
        else if (head.y > fruit.y && opponentDirection != DOWN) {
            newDirection = UP;
        }

        // Проверка на самотаранение и столкновение с игроком
        SnakeSegment nextPos = head;
        switch (newDirection) {
        case UP: nextPos.y--; break;
        case DOWN: nextPos.y++; break;
        case LEFT: nextPos.x--; break;
        case RIGHT: nextPos.x++; break;
        }
        if (nextPos.x >= WIDTH / GRID_SIZE) nextPos.x = 0;
        else if (nextPos.x < 0) nextPos.x = WIDTH / GRID_SIZE - 1;
        if (nextPos.y >= HEIGHT / GRID_SIZE) nextPos.y = 0;
        else if (nextPos.y < 0) nextPos.y = HEIGHT / GRID_SIZE - 1;

        bool willCollide = false;
        for (size_t i = 1; i < opponentSnake.size(); ++i) {
            if (opponentSnake[i].x == nextPos.x && opponentSnake[i].y == nextPos.y) {
                willCollide = true;
                break;
            }
        }
        for (size_t i = 0; i < snake.size(); ++i) {
            if (snake[i].x == nextPos.x && snake[i].y == nextPos.y) {
                willCollide = true;
                break;
            }
        }

        if (!willCollide) {
            opponentDirection = newDirection;
        }
        else {
            // Найти безопасное направление
            findSafeDirection();
        }
    }

    // Поиск безопасного направления для оппонента, чтобы избежать столкновения с самим собой и игроком
    void findSafeDirection() {
        Direction safeDirections[] = { UP, DOWN, LEFT, RIGHT };
        for (Direction dir : safeDirections) {
            if (dir == opponentDirection) continue;

            SnakeSegment nextPos = opponentSnake.front();
            switch (dir) {
            case UP: nextPos.y--; break;
            case DOWN: nextPos.y++; break;
            case LEFT: nextPos.x--; break;
            case RIGHT: nextPos.x++; break;
            }
            if (nextPos.x >= WIDTH / GRID_SIZE) nextPos.x = 0;
            else if (nextPos.x < 0) nextPos.x = WIDTH / GRID_SIZE - 1;
            if (nextPos.y >= HEIGHT / GRID_SIZE) nextPos.y = 0;
            else if (nextPos.y < 0) nextPos.y = HEIGHT / GRID_SIZE - 1;

            bool willCollide = false;
            for (size_t i = 1; i < opponentSnake.size(); ++i) {
                if (opponentSnake[i].x == nextPos.x && opponentSnake[i].y == nextPos.y) {
                    willCollide = true;
                    break;
                }
            }
            for (size_t i = 0; i < snake.size(); ++i) {
                if (snake[i].x == nextPos.x && snake[i].y == nextPos.y) {
                    willCollide = true;
                    break;
                }
            }

            if (!willCollide) {
                opponentDirection = dir;
                break;
            }
        }
    }

    // Проверка столкновений змеи игрока и оппонента
    void checkCollision() {
        SnakeSegment head = snake.front();
        for (size_t i = 1; i < snake.size(); i++) {
            if (snake[i].x == head.x && snake[i].y == head.y) {
                gameOver = true;
                return;
            }
        }

        if (withOpponent) {
            checkOpponentCollision();
        }
    }

    // Проверка столкновений змеи оппонента
    void checkOpponentCollision() {
        SnakeSegment head = snake.front();
        for (size_t i = 0; i < opponentSnake.size(); i++) {
            if (opponentSnake[i].x == head.x && opponentSnake[i].y == head.y) {
                gameOver = true;
                return;
            }
        }

        SnakeSegment opponentHead = opponentSnake.front();
        for (size_t i = 0; i < snake.size(); i++) {
            if (snake[i].x == opponentHead.x && snake[i].y == opponentHead.y) {
                gameOver = true;
                return;
            }
        }

        for (size_t i = 1; i < opponentSnake.size(); i++) {
            if (opponentSnake[i].x == opponentHead.x && opponentSnake[i].y == opponentHead.y) {
                gameOver = true;
                return;
            }
        }

        for (size_t i = 0; i < snake.size(); i++) {
            for (size_t j = 0; j < opponentSnake.size(); j++) {
                if (snake[i].x == opponentSnake[j].x && snake[i].y == opponentSnake[j].y) {
                    gameOver = true;
                    return;
                }
            }
        }
    }

    // Проверка на поедание фрукта и увеличение длины змеи
    void checkFruit() {
        SnakeSegment head = snake.front();
        if (head.x == fruit.x && head.y == fruit.y) {
            if (currentFruitType == NORMAL) {
                nTail++;
            }
            else {
                nTail += 2;
            }
            generateFruit();
            if (increaseSpeed) {
                speed *= 0.98; // Увеличиваем скорость игрока на 2%
            }
        }

        if (withOpponent) {
            SnakeSegment opponentHead = opponentSnake.front();
            if (opponentHead.x == fruit.x && opponentHead.y == fruit.y) {
                if (currentFruitType == NORMAL) {
                    opponentTail++;
                }
                else {
                    opponentTail += 2;
                }
                generateFruit();
                if (increaseSpeed) {
                    opponentSpeed *= 0.98; // Увеличиваем скорость оппонента на 2%
                }
            }
        }
    }

    // Генерация нового фрукта на поле
    void generateFruit() {
        fruit.x = rand() % (WIDTH / GRID_SIZE);
        fruit.y = rand() % (HEIGHT / GRID_SIZE);
        currentFruitType = (rand() % 2 == 0) ? NORMAL : SPECIAL;
    }

    // Отрисовка текущего состояния игры
    void render() {
        window.clear();
        drawGrid();
        drawSnake();
        if (withOpponent) {
            drawOpponentSnake();
        }
        drawFruit();
        window.display();
    }

    // Отрисовка сетки поля
    void drawGrid() {
        RectangleShape line(Vector2f(WIDTH, 1));
        line.setFillColor(Color(50, 50, 50));
        for (int i = 0; i < HEIGHT / GRID_SIZE; i++) {
            line.setPosition(0, i * GRID_SIZE);
            window.draw(line);
        }
        line.setSize(Vector2f(1, HEIGHT));
        for (int i = 0; i < WIDTH / GRID_SIZE; i++) {
            line.setPosition(i * GRID_SIZE, 0);
            window.draw(line);
        }
    }

    // Отрисовка змеи игрока
    void drawSnake() {
        RectangleShape segment(Vector2f(GRID_SIZE - 1, GRID_SIZE - 1));
        segment.setFillColor(Color::Green);
        for (auto& s : snake) {
            segment.setPosition(s.x * GRID_SIZE, s.y * GRID_SIZE);
            window.draw(segment);
        }
    }

    // Отрисовка змеи оппонента
    void drawOpponentSnake() {
        RectangleShape segment(Vector2f(GRID_SIZE - 1, GRID_SIZE - 1));
        segment.setFillColor(Color::Blue);
        for (auto& s : opponentSnake) {
            segment.setPosition(s.x * GRID_SIZE, s.y * GRID_SIZE);
            window.draw(segment);
        }
    }

    // Отрисовка фрукта
    void drawFruit() {
        RectangleShape fruitShape(Vector2f(GRID_SIZE - 1, GRID_SIZE - 1));
        if (currentFruitType == NORMAL) {
            fruitShape.setFillColor(Color::Red);
        }
        else {
            fruitShape.setFillColor(Color::Yellow);
        }
        fruitShape.setPosition(fruit.x * GRID_SIZE, fruit.y * GRID_SIZE);
        window.draw(fruitShape);
    }

    // Запрос на повторную игру
    bool askForReplay() {
        cout << "Игра окончена! Хотите сыграть снова? (y/n): ";
        char choice;
        cin >> choice;
        return choice == 'y' || choice == 'Y';
    }
};

// Выбор режима игры (одиночная игра или игра с оппонентом)
int chooseGameMode() {
    int choice;
    cout << "Выберите режим игры:\n";
    cout << "1. Одиночная игра\n";
    cout << "2. Игра с противником\n";
    cin >> choice;
    return choice;
}

// Выбор уровня сложности игры
int chooseDifficulty() {
    int choice;
    cout << "Выберите уровень сложности:\n";
    cout << "1. Легкий\n";
    cout << "2. Средний\n";
    cout << "3. Тяжелый\n";
    cin >> choice;

    switch (choice) {
    case 1: return 200;
    case 2: return 150;
    case 3: return 100;
    default: return 150; // По умолчанию средний уровень
    }
}

int main() {
    setlocale(LC_ALL, "Russian"); // Установить локаль для поддержки русского языка
    srand(static_cast<unsigned>(time(0)));

    int gameMode = chooseGameMode(); // выбор режима игры
    int initialSpeed = chooseDifficulty(); // выбор уровня сложности
    bool withOpponent = (gameMode == 2);
    bool increaseSpeed = (initialSpeed == 100); // Увеличиваем скорость только на сложном уровне

    SnakeGame game(initialSpeed, withOpponent, increaseSpeed); // создание объекта игры
    game.run(); // запуск игры

    return 0;
}
