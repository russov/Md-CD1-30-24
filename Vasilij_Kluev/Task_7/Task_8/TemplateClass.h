#pragma once
#include <vector>
#include "figure.h"

template <typename T>
class TemplateClass {
public:
    ~TemplateClass();
    void add(T* figure);
    void displayAll() const;
    T* operator[](size_t index);
    const T* operator[](size_t index) const;

protected:
    std::vector<T*> figures;
};

template <typename T>
TemplateClass<T>::~TemplateClass() {
    for (auto figure : figures) {
        delete figure;
    }
}

template <typename T>
void TemplateClass<T>::add(T* figure) {
    figures.push_back(figure);
}

template <typename T>
void TemplateClass<T>::displayAll() const {
    for (const auto& figure : figures) {
        figure->display();
    }
}

template <typename T>
T* TemplateClass<T>::operator[](size_t index) {
    if (index >= figures.size()) {
        throw std::out_of_range("Index out of range");
    }
    return figures[index];
}

template <typename T>
const T* TemplateClass<T>::operator[](size_t index) const {
    if (index >= figures.size()) {
        throw std::out_of_range("Index out of range");
    }
    return figures[index];
}