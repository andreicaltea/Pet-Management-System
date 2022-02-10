#ifndef Products_h
#define Products_h
#include<iostream>
#include<string>
using namespace std;

//Base class
class Product
{
//Each product will have some price
protected:
	float price;
	string type;
	string description;
	int quantity;
public:
	//Constructor
	Product(float p, string t, string d, int q)
	{
		price = p;
		type = t;
		description = d;
		quantity = q;
	}

	void virtual Display()
	{
		cout << type + ": " + description + " @ $" << price << " (Qty: "<<quantity <<")" << endl;
	}

	void setQuantity(int q)
	{
		quantity = q;
	}

	int getQuantity()
	{
		return quantity;
	}

	string virtual getDescription()
	{
		return description;
	}

	string virtual toString()
	{
		return type + " " + description + " " + to_string(price) + " " + to_string(quantity);
	}

	string getType()
	{
		return type;
	}

	float getPrice()
	{
		return price;
	}
};

//Derived classes
class Food : public Product
{

public:
	//Constructor
	Food(float p, string t, string desc, int q) :Product(p, t, desc, q)
	{
		;
	}
};

class Toy : public Product
{
public:
	//Constructor
	Toy(float p, string t, string desc, int q) :Product(p, t, desc, q)
	{
		;
	}
};

class Accessory : public Product
{
public:
	Accessory(float p, string t, string desc, int q) : Product(p, t, desc, q) 
	{
		;
	}
};

class Book : public Product
{
private:
	string name;
	string author;
public:
	Book(float p, string t, string n, string auth, int q) : Product(p, t, "",q)
	{
		name = n;
		author = auth;
	}

	void Display()
	{
		cout << type + ": " + name + " by " + author + " @ $" << price << " (Qty: " << quantity << ")" << endl;
	}

	string getDescription()
	{
		return name;
	}

	string toString()
	{
		return type + " " + name + " " + author + " " + to_string(price) + " " + to_string(quantity);
	}
};


#endif // !Products_H
