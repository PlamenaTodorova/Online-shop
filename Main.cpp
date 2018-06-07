#include<iostream>
#include "Store.h"

using namespace std;

const int INPUT_MAX_SIZE = 1000;
const int SINGLE_INPUT_SIZE = 100;

void PrintMenu();
void AddElement(Store& carStore);
bool ExecuteCommand(char command, Store& carStore);

int main()
{
	char command;
	Store carStore;

	bool active = true;

	do
	{
		PrintMenu();
		
		cin >> command;

		try
		{
			active = ExecuteCommand(command, carStore);
		}
		catch (const char * msg)
		{
			cout << msg << endl;
		}


	} while (active);

	system("pause");
	return 0;
}

void PrintMenu()
{
	cout << "Press :" << endl;
	cout << "A - Add new profuct" << endl;
	cout << "X - Delete product" << endl;
	cout << "C - Change profuct" << endl;
	cout << "D - Display profuct" << endl;
	cout << "Q - Quit" << endl;
}

void AddElement(Store& carStore)
{
	int choise;
	cout << "Chose 1 to enter all the parameters one by one or 2 to enter a whole object:" << endl;

	do
	{
		cin >> choise;
	} while (choise != 1 && choise != 2);

	if (choise == 1)
	{
		int sku;
		char brand[SINGLE_INPUT_SIZE];
		char model[SINGLE_INPUT_SIZE];
		char category[SINGLE_INPUT_SIZE];
		char engin[SINGLE_INPUT_SIZE];
		int horsePower;
		double price;
		int count;

		cout << "Enter a Sku:";
		cin >> sku;
		
		cout << "Enter a Brand:";
		cin >> brand;
		
		cout << "Enter a Model:";
		cin >> model;
		
		cout << "Enter a Category:";
		cin >> category;
		
		cout << "Enter a Engin:";
		cin >> engin;
		
		cout << "Enter a HorsePower:";
		cin >> horsePower;
		
		cout << "Enter a Price:";
		cin >> price;
		
		cout << "Enter a Count:";
		cin >> count;
		
		carStore.AddProduct(sku, brand, model, category, engin, horsePower, price, count);
	}
	else
	{
		cout << "Enter Product:";
		Product pt;
		cin >> pt;
		carStore.AddProduct(pt);
	}
}

bool ExecuteCommand(char command, Store& carStore)
{
	switch (command)
	{
	case 'A':
	case 'a':
		AddElement(carStore);
		break;
	case 'X':
	case 'x':
		cout << "You want to delete an element with a sku: ";

		int sku;
		cin >> sku;

		carStore.RemoveProduct(sku);
		break;
	case 'C':
	case 'c':
		cout << "Add Product information that you want to change(the sku should be a valid and already existing, all the parameters should be separated by a space):" << endl;
		
		char input[INPUT_MAX_SIZE];

		cin.clear();
		cin.ignore();
		cin.getline(input, INPUT_MAX_SIZE);

		carStore.ChangeProduct(input);

		break;
	case 'D':
	case 'd':
		carStore.PrintProducts();
		break;
	case 'Q':
	case 'q':
		return false;
		break;
	}

	return true;
}