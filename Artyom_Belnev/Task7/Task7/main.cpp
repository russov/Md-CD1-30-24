#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Sphere {
private:
	string name = "Sphere";
public:
	string getName() const {
		return name;
	}
};

class Cylinder {
private:
	string name = "Cylinder";
public:
	string getName() const {
		return name;
	}
};

class Pyramid {
private:
	string name = "Pyramid";
public:
	string getName() const {
		return name;
	}
};

template<typename T>
class Array {
private:
	vector<T*> elements;
	
	size_t length = 0;

public:

	T& operator[](int index) {
		return *elements[index];
	}

	void add(T* object) {
		elements.push_back(object);
		length = elements.size();
	}

	int size() {
		return length;
	}
};

