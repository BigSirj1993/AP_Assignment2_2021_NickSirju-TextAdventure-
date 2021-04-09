#include "BackPack.h"

//Done


BackPack::BackPack()
{
	this->cap = 5;
	this->numberOfItems = 0;
	this->itemArr = new Item * [cap];
	this->initialize(); 
}


BackPack::~BackPack()
{
	for (size_t i = 0; i < this->numberOfItems; i++)
	{
		delete this->itemArr[i];
	}
	
}

BackPack::BackPack(const BackPack& obj)
{
	this->cap = obj.cap;
	this->numberOfItems = obj.numberOfItems;
	this->itemArr = new Item * [this->cap];

	for (size_t i = 0; i < this->numberOfItems; i++)
	{
		this->itemArr[i] = obj.itemArr[i]->clone();
	}
	
	initialize(this->numberOfItems);

}

Item& BackPack::operator[](const int index)
{
	if (index < 0 || index >= this->numberOfItems)
		throw("Bad Index!");

	return *this->itemArr[index];
}

void BackPack::operator=(const BackPack& obj)
{
	for (size_t i = 0; i < this->numberOfItems; i++)
	{
		delete this->itemArr[i];
	}
	delete[] this->itemArr;

	this->cap = obj.cap;
	this->numberOfItems = obj.numberOfItems;
	this->itemArr = new Item * [this->cap];

	for (size_t i = 0; i < this->numberOfItems; i++)
	{
		this->itemArr[i] = obj.itemArr[i]->clone();
	}

	initialize(this->numberOfItems);
}

void BackPack :: expand()
{
	this->cap *= 2;
	Item **tempArr = new Item * [this->cap];

	for (size_t i = 0; i < this->numberOfItems; i++)
	{
		tempArr[i] = this->itemArr[i];
	}

	
	
	delete[] this->itemArr;

	this->itemArr = tempArr;

	this->initialize(this->numberOfItems);

}



void BackPack :: initialize(const int from)
{
	for (size_t i = from; i < cap; i++)
	{
		this->itemArr[i] = nullptr;
	}
}

void BackPack::addItem(const Item& item)
{
	for (size_t i = numberOfItems; i < cap; i++)
	{
		//expand();
	}
	this->itemArr[this->numberOfItems++] = item.clone();
}

void BackPack::removeItem(int index)
{
	if (index < 0 || index >= this->numberOfItems)
		throw("Out of Bounds. Remove Item from Backpack");

	delete this->itemArr[index];
	this->itemArr[index] = this->itemArr[this->numberOfItems - 1];
	this->itemArr[--this->numberOfItems] = nullptr;
}