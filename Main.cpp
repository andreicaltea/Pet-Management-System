#include "Products.h"
#include <vector>
#include<sstream>
#include<fstream>
#include<stdio.h>


//class for management store
class Management
{
private:
	vector<Product*> Products;
	vector<string> Sales;
	int MaxQty[4] = { 25, 15, 15, 5 };

public:
	//Constructor
	Management()
	{
		//initialize sales report
		SalesRead("sales.txt");
	}

	~Management()
	{
		//write sales report
		SalesWrite("sales.txt");
	}

	//contains Function
	bool contains(string des, int *q)
	{
		for (int i = 0; i < Products.size(); i++)
		{
			if (Products[i]->getDescription() == des)
			{
				*q = i;
				return true;
			}
		}
		*q = -1;
		return false;
	}

	//Sell Function
	void Sell()
	{
		cout << "What do you want to sell?\n";
		cout << "Type: ";
		string type;
		getline(cin, type);
		if (type == "Food")
		{
			cout << "Enter Description: ";
			string description;
			int qty;
			getline(cin, description);
			int index;
			if (contains(description, &index))
			{
				cout << "Quantity: ";
				cin >> qty;
				if (qty < Products[index]->getQuantity())
				{
					float cost = qty * Products[index]->getPrice();
					Products[index]->setQuantity(Products[index]->getQuantity() - qty);
					cout << "Sold! Total Cost = " << cost << endl;
					Sales.push_back(type + ": " + description + " @ $" + to_string(cost));
				}
				else
					cout << "Insufficient items!\n";
			}
			else
			{
				cout << "This item is not available!\n";
			}
		}
		else if (type == "Accessory")
		{
			cout << "Enter Description: ";
			string description;
			int qty;
			getline(cin, description);
			int index;
			if (contains(description, &index))
			{
				cout << "Quantity: ";
				cin >> qty;
				if (qty < Products[index]->getQuantity())
				{
					float cost = qty * Products[index]->getPrice();
					Products[index]->setQuantity(Products[index]->getQuantity() - qty);
					cout << "Sold! Total Cost = " << cost << endl;
					Sales.push_back(type + ": " + description + " @ $" + to_string(cost));
				}
				else
					cout << "Insufficient items!\n";
			}
			else
			{
				cout << "This item is not available!\n";
			}
		}
		else if (type == "Toy")
		{
			cout << "Enter Description: ";
			string description;
			int qty;
			getline(cin, description);
			int index;
			if (contains(description, &index))
			{
				cout << "Quantity: ";
				cin >> qty;
				if (qty < Products[index]->getQuantity())
				{
					float cost = qty * Products[index]->getPrice();
					Products[index]->setQuantity(Products[index]->getQuantity() - qty);
					cout << "Sold! Total Cost = " << cost << endl;
					Sales.push_back(type + ": " + description + " @ $" + to_string(cost));
				}
				else
					cout << "Insufficient items!\n";
			}
			else
			{
				cout << "This item is not available!\n";
			}
		}
		else if (type == "Book")
		{
			cout << "Enter name: ";
			string description;
			int qty;
			getline(cin, description);
			int index;
			if (contains(description, &index))
			{
				cout << "Quantity: ";
				cin >> qty;
				if (qty < Products[index]->getQuantity())
				{
					float cost = qty * Products[index]->getPrice();
					Products[index]->setQuantity(Products[index]->getQuantity() - qty);
					cout << "Sold! Total Cost = " << cost << endl;
					Sales.push_back(type + ": " + description + " @ $" + to_string(cost));
				}
				else
					cout << "Insufficient items!\n";
			}
			else
			{
				cout << "This item is not available!\n";
			}
		}
		else
		{
			cout << "This type doesn`t exist!\n";
		}
	}

	//Add Function
	void Add()
	{
		cout << "What do you want to Add?\n";
		cout << "Type: ";
		string type;
		getline(cin, type);
		if (type == "Food")
		{
			cout << "Enter Description: ";
			string description;
			int qty;
			float price;
			getline(cin, description);
			int index;
			if (contains(description, &index))
			{
				cout << "This item is already present in the list!\n";
			}
			else
			{
				cout << "Enter Price: ";
				cin >> price;
				cout << "Quantity: ";
				cin >> qty;
				Product* p = new Food(price, type, description, qty);
				Products.push_back(p);
				cout << "Item Successfully added\n";
			}
		}
		else if (type == "Accessory")
		{
			cout << "Enter Description: ";
			string description;
			int qty;
			float price;
			getline(cin, description);
			int index;
			if (contains(description, &index))
			{
				cout << "This item is already present in the list!\n";
			}
			else
			{
				cout << "Enter Price: ";
				cin >> price;
				cout << "Quantity: ";
				cin >> qty;
				Product* p = new Accessory(price, type, description, qty);
				Products.push_back(p);
				cout << "Item Successfully added\n";
			}
		}
		else if (type == "Toy")
		{
			cout << "Enter Description: ";
			string description;
			int qty;
			float price;
			getline(cin, description);
			int index;
			if (contains(description, &index))
			{
				cout << "This item is already present in the list!\n";
			}
			else
			{
				cout << "Enter Price: ";
				cin >> price;
				cout << "Quantity: ";
				cin >> qty;
				Product* p = new Toy(price, type, description, qty);
				Products.push_back(p);
				cout << "Item Successfully added\n";
			}
		}
		else if (type == "Book")
		{
			cout << "Enter name: ";
			string description;
			int qty;
			float price;
			getline(cin, description);
			int index;
			if (contains(description, &index))
			{
				cout << "This item is already present in the list!\n";
			}
			else
			{
				cout << "Enter author: ";
				string author;
				getline(cin, author);
				cin >> price;
				cout << "Quantity: ";
				cin >> qty;
				Product* p = new Book(price, type, description, author, qty);
				Products.push_back(p);
				cout << "Item Successfully added\n";
			}
		}
		else
		{
			cout << "This type doesn`t exist!\n";
		}
	}


	//Menu Function
	void Menu()
	{
		cout << "1) Sell items." << endl;
		cout << "2) Add new items." << endl;
		cout << "3) Restock items." << endl;
		cout << "4) Update Stock Quantity." << endl;
		cout << "5) View listing of all Products." << endl;
		cout << "6) Load Products from file." << endl;
		cout << "7) Save Products to file." << endl;
		cout << "8) View Sales Report." << endl;
		cout << "9) Exit." << endl;
	}

	//Function to view listing of all products
	void List()
	{
		cout << "List of Products" << endl;
		for (int i = 0; i < Products.size(); i++)
		{
			Products[i]->Display();
		}
	}

	//Sales Report
	void SalesReport()
	{
		cout << "Sales Report:\n";
		for (int i = 0; i < Sales.size(); i++)
			cout << Sales[i] << endl;
		cout << endl;
	}

	//Function to load Products from file
	void Load(string filename)
	{
		//open file
		ifstream fin(filename);
		string line;
		// Use a while loop together with the getline() function to read the file line by line
		while (getline(fin, line)) 
		{
			stringstream data(line);
			string word;
			vector<string> p;
			while (data >> word)
			{
				p.push_back(word);
			}
			int index;
			if (p[0] == "Food")
			{
				//if product is already in product
				if (contains(p[1], &index))
				{
					Products[index]->setQuantity(Products[index]->getQuantity() + stoi(p[3]));
					if (Products[index]->getQuantity() > MaxQty[0])
					{
						Products[index]->setQuantity(MaxQty[0]);
					}
				}
				else
				{
					Product* F = new Food(stof(p[2]), p[0], p[1], stoi(p[3]));
					if (F->getQuantity() > MaxQty[0])
						F->setQuantity(MaxQty[0]);
					Products.push_back(F);
				}
			}
			else if (p[0] == "Accessory")
			{
				//if product is already in product
				if (contains(p[1], &index))
				{
					Products[index]->setQuantity(Products[index]->getQuantity() + stoi(p[3]));
					if (Products[index]->getQuantity() > MaxQty[1])
					{
						Products[index]->setQuantity(MaxQty[1]);
					}
				}
				else
				{
					Product* F = new Accessory(stof(p[2]), p[0], p[1], stoi(p[3]));
					if (F->getQuantity() > MaxQty[1])
						F->setQuantity(MaxQty[1]);
					Products.push_back(F);
				}
			}
			else if (p[0] == "Toy")
			{
				//if product is already in product
				if (contains(p[1], &index))
				{
					Products[index]->setQuantity(Products[index]->getQuantity() + stoi(p[3]));
					if (Products[index]->getQuantity() > MaxQty[2])
					{
						Products[index]->setQuantity(MaxQty[2]);
					}
				}
				else
				{
					Product* F = new Toy(stof(p[2]), p[0], p[1], stoi(p[3]));
					if (F->getQuantity() > MaxQty[2])
						F->setQuantity(MaxQty[2]);
					Products.push_back(F);
				}
			}
			else if (p[0] == "Book")
			{
				//if product is already in product
				if (contains(p[1], &index))
				{
					Products[index]->setQuantity(Products[index]->getQuantity() + stoi(p[4]));
					if (Products[index]->getQuantity() > MaxQty[3])
					{
						Products[index]->setQuantity(MaxQty[3]);
					}
				}
				else
				{
					Product* F = new Book(stof(p[3]), p[0], p[1], p[2], stoi(p[4]));
					if (F->getQuantity() > MaxQty[3])
						F->setQuantity(MaxQty[3]);
					Products.push_back(F);
				}
			}
		}

		// Close the file
		fin.close();

	}

	//Function to save data to a file
	void Save(string filename)
	{
		ofstream fout(filename);
		for (int i = 0; i < Products.size(); i++)
			fout << Products[i]->toString() << endl;
		fout.close();
	}

	//Function to restock items
	void Restock()
	{
		for (int i = 0; i < Products.size(); i++)
		{
			if (Products[i]->getType() == "Food")
				Products[i]->setQuantity(MaxQty[0]);
			else if (Products[i]->getType() == "Accessory")
				Products[i]->setQuantity(MaxQty[1]);
			else if (Products[i]->getType() == "Toy")
				Products[i]->setQuantity(MaxQty[2]);
			else if (Products[i]->getType() == "Book")
				Products[i]->setQuantity(MaxQty[3]);
		}
	}

	//Function to update stock levels
	void setStockLevels()
	{
		cout << "Enter New stock levels.";
		cout << "Food: ";
		cin >> MaxQty[0];
		cout << "Accessory: ";
		cin >> MaxQty[1];
		cout << "Toy: ";
		cin >> MaxQty[2];
		cout << "Book: ";
		cin >> MaxQty[3];
		cout << "Stock Levels updated. New Levels:\n";
		cout << "Food: " << MaxQty[0] << ", Accessory: " << MaxQty[1] << ", Toy: " << MaxQty[2] << ", Book: " << MaxQty[3] << endl;
	}

	//Sales Read
	void SalesRead(string filename)
	{
		ifstream fin(filename);
		string line;
		// Use a while loop together with the getline() function to read the file line by line
		while (getline(fin, line))
		{
			Sales.push_back(line);
		}

		//file close
		fin.close();
	}

	//Sales Write
	void SalesWrite(string filename)
	{
		ofstream fout(filename);
		for (int i = 0; i < Sales.size(); i++)
			fout << Sales[i] << endl;
		fout.close();
	}

	//Functionality of Program
	void Program()
	{
		while (true)
		{
			Menu();
			cout << "Enter: ";
			int choice;
			cin >> choice;
			cin.ignore();
			if (choice == 9)
			{
				cout << "Good Bye!\n";
				break;
			}
			else
			{
				switch (choice)
				{
				case 1:
					Sell();
					break;
				case 2:
					Add();
					break;
				case 3:
					Restock();
					cout << "Items Restocked" << endl;
					break;
				case 4:
					setStockLevels();
					break;
				case 5:
					List();
					cout << endl;
					break;
				case 6:
					Load("products.txt");
					cout << "Sucessfully loaded.\n";
					break;
				case 7:
					Save("products.txt");
					cout << "Sucessfully Saved.\n";
					break;
				case 8:
					SalesReport();
					break;
				default:
					cout << "Invalid Choice!\n";
					break;
				}
			}
		}
	}
};

//Main Function
int main()
{
	Management m;
	m.Program();
	return 0;
}