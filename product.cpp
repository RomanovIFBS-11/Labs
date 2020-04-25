#include"product.h"

Product::Product():Product("Model", "Color", 0){}

Product::Product(const char* Name,const  char*Color, int Size)
{
    this ->Name = NULL;
    setName(Name);
    this ->Color = NULL;
    setColor(Color);
    if(!setSize(Size))
    {
        this-> Size = 0;
    }
};
void Product :: print()
{
    std::cout << "Name = " << Name <<  ",";
    std::cout << "Color = " << Color <<  ",";
    std::cout << "Size = " << Size <<  "\n";
}

Product::~Product()
{
    delete [] Name;
    delete [] Color;
}

void Product::setName(const char* Name)
{
    delete [] this ->Name;
    int len = strlen(Name);
    this ->Name = new char[len];
    strcpy (this ->Name, Name);
}

void Product::setColor(const char* Color)
{
    delete [] this ->Color;
    int len = strlen(Color);
    this ->Color = new char[len];
    strcpy (this ->Color, Color);
}

bool Product::setSize(int Size)
{
    if(Size >=0)
        {
            this->Size = Size;
            return true;
        }
    return false;
}

int Product::getSize()
{
    return Size;
}

char* Product::getName(char* Name)
{
    strcpy(Name, this->Name);
    return Name;
}

char* Product::getColor(char* Color)
{
    strcpy(Color, this->Color);
    return Color;
}


bool Product::operator> (const Product & p) const
{
    return(Size > p.Size);
}

bool Product::operator< (const Product & p) const
{
    return(Size < p.Size);
}

bool Product::operator>= (const Product & p) const
{
    return !(*this < p);
}

bool Product::operator<= (const Product & p) const
{
    return !(*this > p);
}

bool Product::operator== (const Product & p) const
{
    return(Size == p.Size);
}

bool Product::operator!= (const Product & p) const
{
    return !(*this == p);
}

Product&Product::operator=(Product &p)
{
    this ->Name = NULL;
    setModel(p.Name);
    this ->Color = NULL;
    setColor(p.Color);
    this-> Size = p.Size;
    return *this;
}
void Product::operator++()
{
    this->Size ++;
}
void Product::operator--()
{
    this->Size --;
}
ostream& operator<< (ostream &out, const Product &p)
{
    out << " Size: " << p.Size << " Name: " << p.Name << " Color: " << p.Color;
    return out;
}
istream& operator>> (istream &in, Product &p)
{
    in >> p.Name;
    in >> p.Color;
    in >> p.Size;
    return  in;
}
