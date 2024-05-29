#include <iostream>
#include <vector>
#include <cmath>

template <class T>
class ArrayStorage {

    public:

        ArrayStorage(){}

        void add_elements(T* element){
            
            arr.push_back(element);
            
        }

        void print_array(){

            for (T* i : arr){
                std::cout << i->Volume() << " ";
            }
        }

        T* operator[](int index){
            return arr[index];
        }

        virtual ~ArrayStorage(){}

    private:        

        std::vector<T*> arr;

};


class Figure {

    public:
       virtual double Volume() const = 0;
       const double pi = 3.14;

};


class Sphere : public Figure {

    public:

        Sphere(double radius) : radius(radius){}

        virtual double Volume() const override {
            return (4/3) * pi * pow(radius, 3);
        }


    private:

        double radius;


};


class Cylinder : public Figure {

    public:

        Cylinder(double radius, double height) : radius(radius), height(height){}

        virtual double Volume() const override {
            return pi * pow(radius, 2) * height;
        }


    private:

        double radius;
        double height;


};


class Pyramid : public Figure {

    public:

        Pyramid(double area, double height) : area(area), height(height){}

        virtual double Volume() const override {
            return (double(1)/3) * area * height;
        }


    private:

        double height;
        double area;
    

};



int main(){

    double radius_sphere = 3.8;
    Sphere sphere (radius_sphere);
    std::cout << sphere.Volume() << "\n";

    double radius_cylinder = 4.2;
    double height_cylinder = 5.37;

    Cylinder cylinder (radius_cylinder, height_cylinder);
    std::cout << cylinder.Volume() << "\n";

    double height_pyramid = 7.1;
    double area_pyramid = 26.47;

    Pyramid pyramid (area_pyramid, height_pyramid);
    std::cout << pyramid.Volume() << "\n";

    ArrayStorage<Figure> array;
    array.add_elements(&sphere);
    array.add_elements(&cylinder);
    array.add_elements(&pyramid);

    array.print_array();

    return 0;
}