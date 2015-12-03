#pragma once 

template <class T>
class SingletonTemplate
{
protected:
	static T * ptr;

	SingletonTemplate();
public:

	static T * GetPtr();
	static void Destroy();
};

template <class T>
T * SingletonTemplate<T>::ptr = nullptr;

template <class T>
SingletonTemplate<T>::SingletonTemplate()
{
	
}

template <class T>
T * SingletonTemplate<T>::GetPtr()
{
	if (ptr == nullptr) ptr = new T;

	return ptr;
}

template <class T>
void SingletonTemplate<T>::Destroy()
{
	if (ptr != nullptr)
		delete ptr;
}
