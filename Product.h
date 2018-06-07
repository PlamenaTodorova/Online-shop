#ifndef PRODUCT_H
#define PRODUCT_H

#include<iostream>

//Cars
class Product
{
public:
	//Friends
	friend std::ostream& operator<<(std::ostream& os, const Product& pt);
	friend std::istream& operator>>(std::istream& istream, Product& pt);

	//The big four
	Product();
	Product(const Product& pr);
	~Product();
	Product& operator=(const Product& pr);

	//Access Id(SKU)
	int GetSku() const { return sku; }
	
	//Creating a product
	Product(int sku, char * brand, char * model, char * category, char * engin, int horsePower, double price, int count);

	//Printing product
	void PrintProduct() const;

	//ChangeProduct
	void ChangeProduct(char * brand, char * model, char * category, char * engin, int horsePower, double price, int count);

private:
	//constants
	enum {MINIMAL_HORSE_POWER = 10, MAXIMUM_SIZE_OF_A_STRING_FEILD = 100};

	//Class members
	int sku;
	char * brand;
	char * model;
	char * category; //a.k.a Retro, Electric car, Super car, etc.
	char * engin;
	int horsePower;
	double price;
	int count;

	//Helper functions
	void CopyObject(const Product & pr);
	void DeleteObject();

	//Some validation
	bool IsPositiveNumber(double number) const { return number > 0; }
	bool IsValidSku(double number) const { return number >= 0; }
	bool IsValidHorsePower(double number) const { return number >= MINIMAL_HORSE_POWER; }
	bool IsValidObject() const;

	


};

#endif // !PRODUCT_H




