#pragma once 
#include "SingletonTemplate.h"
#include <vector>

template <class T>
class TemplateManager
{

protected:
	std::vector<T*> elements;
public:

	void AddElement(T * element);
	void RemoveElement(T * element);
};

template <class T>
void TemplateManager<T>::AddElement(T * element)
{
	elements.push_back(element);
}

template <class T>
void TemplateManager<T>::RemoveElement(T * element)
{
	for (std::vector<T*>::iterator it = elements.begin(); it != elements.end(); ++it)
	{
		if ((*it) == element)
		{
			elements.erase(it);
			return;
		}
	}
}

