#pragma once

//Done

#include"STLINCLUDE.h"
#include "Weapon.h"
#include "Armour.h"

class BackPack
{
public:
	BackPack();
	~BackPack();
	BackPack(const BackPack& obj);
	inline int size() const
	{
		return this->numberOfItems;
	};
	Item& operator[](const int index);
	void operator=(const BackPack& obj);
	void addItem(const Item& item);
	void removeItem(int index);
	inline void debugPrint() const
	{
		for(size_t i = 0; i < this->numberOfItems; i++)
		{
			cout << this->itemArr[i]->debugPrint() << endl;
		}
	}


private:

	int cap;
	int numberOfItems;
	Item** itemArr;
	void expand();
	void initialize(const int from = 0);

};
























/*class BackPack // My character's inventory
{
public:
	BackPack();
	~BackPack();
	BackPack(const BackPack& obj);
	int size() const
	{
		return this->numberOfItems;
	};
	Item& operator[](const int index);
	void addItem(const Item& item); // Add and remove items
	void removeItem(int index);
	void debugPrint() const
	{
		for (size_t i = 0; i < this->numberOfItems; i++) // Created an array for my BackPack space
		{
			cout << this->itemArr[i]->debugPrint() << endl; // printing out array of BackPack
		}
	}

private:
	int cap;
	int numberOfItems;
	Item** itemArr;
	void expand();
	void initialize(const int from = 0);


};*/

