#include <iostream>
#include "figure.h"
#include "TemplateClass.h"

int main() {
    TemplateClass<Figure> figures;

    figures.add(new Ball());
    figures.add(new Cylinder());
    figures.add(new Pyramid());

    figures.displayAll();
    figures[0]->display();
    figures[1]->display();
    figures[2]->display();


    return 0;
}