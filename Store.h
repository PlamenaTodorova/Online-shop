#ifndef STORE_H
#define STORE_H

#include "Product.h"

class Store
{
public:
	//The big four
	Store();
	Store(const Store & st);
	~Store();
	Store& operator=(const Store & st);

	//Data modifiers
	void AddProduct(int sku, char * brand, char * model, char * category, char * engin, int horsePower, double price, int count);
	void AddProduct(const Product & product);
	void RemoveProduct(int sku);
	void RemoveProduct(const Product & product);
	void ChangeProduct(char * changedProduct);

	//Data display
	void PrintProducts() const;

private:
	//Private
	enum { NO_MATCHING_PRODUCT_FOUND = -1, NUMBER_OF_PROPERTIES = 8, DELIMITER = ' '};

	//Class members
	int amountOfProducts;
	int storeCapasity;
	Product * products;

	//Helper functions
	void CopyObject(const Store & st);
	void FreeReservedMemory();
	void Grow();
	void TransferElements(Product * first, Product * second);
	void SwapToTheBack(int index);

	bool ExistingSku(int sku) const;

	int FindProduct(int sku) const;

	//Functions connected with the chage objext function
	char ** SplitByDelimiter(char * str, char delimiter);
	int FindNext(char * str, int start, char delimiter);


};


#endif // !STORE_H



