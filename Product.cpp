#include "Product.h"
#include<iostream>
#include<iomanip>

Product::Product()
{
	sku = -1;

	brand = NULL;
	category = NULL;
	model = NULL; 
	engin = NULL;

	horsePower = 0;
	price = 0;
	count = 0;
}

Product::Product(const Product & pr)
{
	CopyObject(pr);
}

Product::~Product()
{
	DeleteObject();
}

Product & Product::operator=(const Product & pr)
{
	if (this != &pr)
	{
		DeleteObject();
		CopyObject(pr);
	}

	return *this;
}

Product::Product(int sku, char * brand, char * model, char * category, char * engin, int horsePower, double price, int count)
{
	if (IsValidSku(sku))
		this->sku = sku;
	else 
		throw "Invalid number for Sku";

	if (IsValidHorsePower(horsePower))
		this->horsePower = horsePower;
	else
		throw "Invalid number for Horse Power";

	if (IsPositiveNumber(price))
		this->price = price;
	else
		throw "Invalid number for Price";

	if (IsPositiveNumber(count))
		this->count = count;
	else
		throw "Invalid number for Amount";

	int length;

	length = strlen(brand) + 1;
	this->brand = new char[length];
	strcpy_s(this->brand, length, brand);

	length = strlen(model) + 1;
	this->model = new char[length];
	strcpy_s(this->model, length, model);

	length = strlen(engin) + 1;
	this->engin = new char[length];
	strcpy_s(this->engin, length, engin);

	length = strlen(category) + 1;
	this->category = new char[length];
	strcpy_s(this->category, length, category);
}

void Product::PrintProduct() const
{
	std::cout << std::setw(6) << sku << std::setw(12) << brand << std::setw(12) << model << std::setw(12) << category
		<< std::setw(12) << engin << std::setw(4) << horsePower << std::setw(5) << price << std::setw(7) << count 
		<< std::endl;
}

void Product::ChangeProduct(char * brand, char * model, char * category, char * engin, int horsePower, double price, int count)
{
	if (IsValidHorsePower(horsePower))
		this->horsePower = horsePower;
	else
		throw "Invalid number for Horse Power";

	if (IsPositiveNumber(price))
		this->price = price;
	else
		throw "Invalid number for Price";

	if (IsPositiveNumber(count))
		this->count = count;
	else
		throw "Invalid number for Amount";

	int length;

	delete[] this->brand;
	length = strlen(brand) + 1;
	this->brand = new char[length];
	strcpy_s(this->brand, length, brand);

	delete[] this->model;
	length = strlen(model) + 1;
	this->model = new char[length];
	strcpy_s(this->model, length, model);

	delete[] this->engin;
	length = strlen(engin) + 1;
	this->engin = new char[length];
	strcpy_s(this->engin, length, engin);

	delete[] this->category;
	length = strlen(category) + 1;
	this->category = new char[length];
	strcpy_s(this->category, length, category);
}

void Product::CopyObject(const Product & pr)
{
	sku = pr.sku;

	horsePower = pr.horsePower;
	price = pr.price;
	count = pr.count;
	
	int length;

	length = strlen(pr.brand) + 1;
	brand = new char[length];
	strcpy_s(brand, length, pr.brand);

	length = strlen(pr.model) + 1;
	model = new char[length];
	strcpy_s(model, length, pr.model);

	length = strlen(pr.engin) + 1;
	engin = new char[length];
	strcpy_s(engin, length, pr.engin);

	length = strlen(pr.category) + 1;
	category = new char[length];
	strcpy_s(category, length, pr.category);
}

void Product::DeleteObject()
{
	delete[] brand;
	delete[] model;
	delete[] engin;
	delete[] category;
}

bool Product::IsValidObject() const
{
	return IsValidSku(sku) && IsValidHorsePower(horsePower) && IsPositiveNumber(count) && IsPositiveNumber(price);
}

std::ostream & operator<<(std::ostream& os, const Product& pt)
{
	os << std::setw(6) << pt.sku << std::setw(12) << pt.brand << std::setw(12) << pt.model << std::setw(12) << pt.category
		<< std::setw(12) << pt.engin << std::setw(6) << pt.horsePower << std::setw(9) << pt.price << std::setw(7) << pt.count
		<< std::endl;

	return os;
}

std::istream & operator>>(std::istream& is, Product & pt)
{
	is >> pt.sku;

	char temp[pt.MAXIMUM_SIZE_OF_A_STRING_FEILD];
	int length;

	is >> temp;
	length = strlen(temp) + 1;
	pt.brand = new char[length];
	strcpy_s(pt.brand, length, temp);

	is >> temp;
	length = strlen(temp) + 1;
	pt.model = new char[length];
	strcpy_s(pt.model, length, temp);

	is >> temp;
	length = strlen(temp) + 1;
	pt.category = new char[length];
	strcpy_s(pt.category, length, temp);

	is >> temp;
	length = strlen(temp) + 1;
	pt.engin = new char[length];
	strcpy_s(pt.engin, length, temp);

	is >> pt.horsePower;
	is >> pt.price;
	is >> pt.count;

	if (!pt.IsValidObject())
	{
		throw "Invalid arguments for some feilds";
	}

	return is;
}
