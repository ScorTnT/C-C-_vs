#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


class Book
{
	char* title;
	int price;
public:
	Book(const char* title, int price);
	~Book();
//	Book(const Book& book);
	void set(const char* title, int price);
	void show() { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(const char* title, int price)
{
	this->price = price;
	int len = strlen(title);
	this->title = new char[len+1];
	strcpy(this->title, title);
}
Book::~Book(){}
void Book::set(const char* title, int price) {
	this->price = price;
	int len = strlen(title);
	if (this->title != NULL) {
		delete this->title;
	}
	this->title = new char[len+1];
	strcpy(this->title, title);
}
//Book::Book(const Book& book) {
//	this->price = book.price;
//	int len = strlen(book.title);
//	this->title = new char[len + 1];
//	strcpy(this->title, book.title);
//}
int main(void) {
	Book cpp("명품C++", 10000);
	Book java = cpp;
	java.set("명품자바", 12000);
	cpp.show();
	java.show();
	return 0;
}