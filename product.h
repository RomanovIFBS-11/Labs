#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED
#include <iostream>
#include<cstring>
using namespace std;

class Product
{
    char* Name;
    char* Color;
    int Size;

public:
    Product();
    Product(const char* Name,const char*color, int Size);
    Product(const Product &p);
    ~Product();

    void print();
    void setName(const char* Name);
    void setColor(const char* color);
    bool setSize(int Size);

    int getSize();
    char* getName(char* Name);
    char* getColor(char* color);

    bool operator> (const Product & p) const;
    bool operator< (const Product & p) const;
    bool operator>= (const Product & p) const;
    bool operator<= (const Product & p) const;
    bool operator== (const Product & p) const;
    bool operator!= (const Product & p) const;

    Product &operator=(Product &p);

    void operator++();
    void operator--();

    friend ostream& operator<< (ostream &out, const Product &p);
    friend istream& operator>> (istream &in, Product &p);
};


#endif // PRODUCT_H_INCLUDED
