#pragma once

// Функция doOperation() выполняет операцию сложения своих параметров
//int doOperation(int a, int b)
//{
//    return a + b;
//}

namespace A
{
    // Эта версия doOperation() принадлежит пространству имен Boo
    int doOperation(int a, int b)
    {
        return a + b;
    }
}