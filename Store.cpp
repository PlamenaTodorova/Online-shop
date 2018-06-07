#include "Store.h"
#include<iostream>
#include<string>

Store::Store()
{
	amountOfProducts = 0;
	storeCapasity = 1;
	products = new Product[storeCapasity];
}

Store::Store(const Store & st)
{
	CopyObject(st);
}

Store::~Store()
{
	FreeReservedMemory();
}

Store & Store::operator=(const Store & st)
{
	if (this != &st)
	{
		FreeReservedMemory();
		CopyObject(st);
	}

	return *this;
}

void Store::AddProduct(int sku, char * brand, char * model, char * category, char * engin, int horsePower, double price, int count)
{
	Product newProduct(sku, brand, model, category, engin, horsePower, price, count);

	AddProduct(newProduct);
}

void Store::AddProduct(const Product & product)
{
	//Check if it has a unique id
	if (ExistingSku(product.GetSku()))
	{
		throw "This product sku is already taken";
	}

	//Make space for it if there is a need;
	if (amountOfProducts == storeCapasity)
	{
		Grow();
	}

	products[amountOfProducts++] = product;
}

void Store::RemoveProduct(int sku)
{
	int index = FindProduct(sku);
	
	if (index == NO_MATCHING_PRODUCT_FOUND)
	{
		throw "No such product";
	}
	
	SwapToTheBack(index);
	amountOfProducts--;
}

void Store::RemoveProduct(const Product & product)
{
	RemoveProduct(product.GetSku());
}

void Store::ChangeProduct(char * changedProduct)
{

	char ** changes = SplitByDelimiter(changedProduct, DELIMITER);

	int sku = std::stoi(changes[0]);
	int horsePower = std::stoi(changes[5]);
	double price = std::stod(changes[6]);
	int count = std::stoi(changes[7]);

	int index = FindProduct(sku);

	if (index == NO_MATCHING_PRODUCT_FOUND)
	{
		throw "No such product";
	}
	
	products[index].ChangeProduct(changes[1], changes[2], changes[3], changes[4], horsePower, price, count);
}

void Store::PrintProducts() const
{
	for (int i = 0; i < amountOfProducts; i++)
	{
		std::cout<<products[i];
	}
}

void Store::CopyObject(const Store & st)
{
	amountOfProducts = st.amountOfProducts;
	storeCapasity = st.storeCapasity;

	products = new Product[storeCapasity];

	TransferElements(st.products, products);
}

void Store::FreeReservedMemory()
{
	delete[] products;
}

void Store::Grow()
{
	storeCapasity *= 2;

	Product * newContainer = new Product[storeCapasity];

	TransferElements(products, newContainer);

	FreeReservedMemory();

	products = newContainer;
}

void Store::TransferElements(Product * first, Product * second)
{
	for (int i = 0; i < amountOfProducts; i++)
	{
		second[i] = first[i];
	}
}

void Store::SwapToTheBack(int index)
{
	for (int i = index; i < amountOfProducts - 1; i++)
	{
		Product temp = products[i];
		products[i] = products[i + 1];
		products[i + 1] = temp;
	}
}

bool Store::ExistingSku(int sku) const
{
	for (int i = 0; i < amountOfProducts; i++)
	{
		if (products[i].GetSku() == sku)
		{
			return true;
		}
	}

	return false;
}

int Store::FindProduct(int sku) const
{
	for (int i = 0; i < amountOfProducts; i++)
	{
		if (products[i].GetSku() == sku)
		{
			return i;
		}
	}

	return NO_MATCHING_PRODUCT_FOUND;
}

char ** Store::SplitByDelimiter(char * str, char delimiter)
{
	char ** result = new char*[NUMBER_OF_PROPERTIES];

	int expressionLength = strlen(str);
	int lastDelemeterIndex = -1;


	for (int index = 0; index < NUMBER_OF_PROPERTIES; index ++)
	{
		int currentExpressionLength = FindNext(str, lastDelemeterIndex + 1, delimiter) - lastDelemeterIndex - 1;

		result[index] = new char[currentExpressionLength + 1];
		
		for (int j = 0; j < currentExpressionLength; j++)
		{
			result[index][j] = str[lastDelemeterIndex + 1 + j];
		}
		
		result[index][currentExpressionLength] = '\0';
		
		lastDelemeterIndex += currentExpressionLength + 1;
	}

	return result;
}

int Store::FindNext(char * str, int start, char delimiter)
{
	int expressionLength = strlen(str);
	
	for (; start < expressionLength; start++)
	{
		if (str[start] == delimiter)
		{
			break;
		}
	}

	return start;
}
