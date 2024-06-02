#pragma once
#include <vector>

template <class T>
class Container
{
private:
	std::vector<T*> figures;
public:
	Container()
	{
	}

	~Container()
	{
		for (auto f : figures)
		{
			delete f;
		}
		figures.clear();
	}

	void push_back(T *figure)
	{
		this->figures.push_back(figure);
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

