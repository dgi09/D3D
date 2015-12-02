#pragma once 

template <class T>
class SingletonTemplate
{
protected:
	static T * ptr;

	SingletonTemplate();
public:

	inline static T * GetPtr();
	static void Destroy();
};

template <class T>
T * SingletonTemplate<T>::ptr = nullptr;

template <class T>
SingletonTemplate<T>::SingletonTemplate()
{
	ptr = static_cast<T*>(this);
}

template <class T>
T * SingletonTemplate<T>::GetPtr()
{

	return ptr;
}

template <class T>
void SingletonTemplate<T>::Destroy()
{
	if (ptr != nullptr)
		delete ptr;
}
