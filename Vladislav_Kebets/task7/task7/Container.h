#pragma once
#include <vector>
template <class T>
class Container
{
private:
	std::vector<T*> figures;
public:
	Container()
	{}

	void push_back(T* figure)
	{
		this->figures.push_back(figure);
	}

	void pop_back()
	{
		this->figures.pop_back();
	}

	int size() 
	{
		return figures.size();
	}

	const T* operator[](const unsigned int& index) const
	{
		return figures.at(index);
	}

	T* operator[](unsigned int& index) const
	{
		return figures.at(index);
	}
};

