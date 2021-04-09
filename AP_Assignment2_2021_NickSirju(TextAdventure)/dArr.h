#pragma once

//Done


template<typename T>
class dArr
{
public:
	dArr(unsigned size = 5);
	dArr(const dArr& obj);
	~dArr();

	T& operator[] (const unsigned index);
	void operator= (const dArr& obj);

	unsigned maxCap();
	unsigned size(); // This is a function named size that takes no parameters and returns unsigned int
	void push(const T element);
	void remove(const unsigned index, bool ordered = false);

private:
	unsigned cap;
	unsigned initialCap;
	unsigned numberOfElements;
	T** arr;

	void expand();
	void initialize(unsigned from);

};

template<typename T>
dArr<T> ::dArr(unsigned size)
{
	this->initialCap = size;
	this->cap = size;
	this->numberOfElements = 0;

	this->arr = new T * [this->cap];

	this->initialize(0);
}


template<typename T>
dArr<T>::dArr(const dArr& obj)
{
	this->initialCap = obj.initialCap;
	this->cap = obj.cap;
	this->numberOfElements = obj.numberOfElements;

	this->arr = new T * [this->cap];

	for (size_t i = 0; i < this->numberOfElements; i++)
	{
		this->arr[i] = new T(*obj.arr[i]);
	}

	this->initialize(0);

}

template<typename T>
dArr<T>::~dArr()
{
	for (size_t i = 0; i < this->numberOfElements; i++)
	{
		delete this->arr[i];
	}
	delete[] arr;
}

template<typename T>
inline T& dArr<T>::operator[](const unsigned index)
{
	return *this->arr[index];
}

template<typename T>
void dArr<T>::operator= (const dArr& obj)
{

	for (size_t i = 0; i < this->numberOfElements; i++)
	{
		delete this->arr[i];
	}
	delete[] arr;

	this->initialCap = obj.initialCap;
	this->cap = obj.cap;
	this->numberOfElements = obj.numberOfElements;

	this->arr = new T * [this->cap];

	for (size_t i = 0; i < this->numberOfElements; i++)
	{
		this->arr[i] = new T(*obj.arr[i]);
	}

	this->initialize(0);
}


template<typename T>
void dArr<T>::expand()
{
	this->cap *= 2;
	T** tempArr = new T * [this->cap];

	for (size_t i = 0; i < this->numberOfElements; i++)
	{
		tempArr[i] = this->arr[i];
	}

	delete[]arr;
	this->arr = tempArr;

	this->initialize(this->numberOfElements);

}

template<typename T>
void dArr<T>::initialize(unsigned from)
{
	for (size_t i = from; i < this->cap; i++)
	{
		this->arr[i] = nullptr;
	}

}

template<typename T>
unsigned dArr<T>::maxCap()
{
	return this->cap;
}

template<typename T>
inline unsigned dArr<T>::size()
{
	return this->numberOfElements;
}

template<typename T>
void dArr<T>::push(const T element)
{
	if (this->numberOfElements >= this->cap)
		this->expand();

	this->arr[this->numberOfElements++] = new T(element);

}


template<typename T>
void dArr<T>::remove(const unsigned index, bool ordered)
{
	if (index < 0 || index >= this->numberOfElements)
		throw "Out Of Bounds.";

	if (ordered)
	{
		delete this->arr[index];

		for (size_t i = 0; i < this->numberOfElements - 1; i++)
		{
			this->arr[i] = this->arr[i + 1];
		}

		this->arr[--this->numberOfElements] = nullptr;
	}

	else
	{
		delete this->arr[index];

		this->arr[index] = this->arr[this->numberOfElements - 1];

		this->arr[--this->numberOfElements] = nullptr;
	}
}
