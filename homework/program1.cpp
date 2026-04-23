#include <iostream>

class Base 
{
private:
    int x1=2,y1=3,z1;

    void add_private(int a,int b)
{
    z1 = a+b;
} 
protected:
    int x2=4,y2=5,z2;

    void add_protected(int a,int b)
    {
        z2 = a+b;
    }

public:
    int x3=6,y3=7,z3;

    void add_public(int a,int b)
    {
        z3 = a+b;
    }

    void add_all(int a,int b,int c,int d,int e,int f)
    {
        add_public(a,b);
        add_protected(c,d);
        add_private(e,f);
    }

    void show_all()
    {
        std::cout << "Private members: x1 = " << x1 << ", y1 = " << y1 << ", z1 = " << z1 << std::endl;
        std::cout << "Protected members: x2 = " << x2 << ", y2 = " << y2 << ", z2 = " << z2 << std::endl;
        std::cout << "Public members: x3 = " << x3 << ", y3 = " << y3 << ", z3 = " << z3 << std::endl;
    }
};

class Derived : public Base
{
public:
    void display()
    {
//        std::cout << "Private members: x1 = " << x1 << ", y1 = " << y1 << ", z1 = " << z1 << std::endl; //  ✘ “Erişilmez – derleme hatası” 
        std::cout << "Protected members: x2 = " << x2 << ", y2 = " << y2 << ", z2 = " << z2 << std::endl; // ✔ “Erişilir”  
        std::cout << "Public members: x3 = " << x3 << ", y3 = " << y3 << ", z3 = " << z3 << std::endl; // ✔ “Erişilir” 
    }
};

int main()
{
    Base b;
    b.add_all(10,20,11,22,12,24);
//    b.x1 = 100; // ✘ “Erişilmez – derleme hatası” 
//    b.y1 = 100; // ✘ “Erişilmez – derleme hatası” 
//    b.z1 = 100; // ✘ “Erişilmez – derleme hatası” 
//    b.x2 = 100; // ✘ “Erişilmez – derleme hatası” 
//    b.y2 = 100; // ✘ “Erişilmez – derleme hatası” 
//    b.z2 = 100; // ✘ “Erişilmez – derleme hatası” 
    b.x3 = 100; // ✔ “Erişilir” 
    b.y3 = 100; // ✔ “Erişilir” 
    b.z3 = 100; // ✔ “Erişilir” 
    b.show_all();
    Derived d;
//    d.x1 = 100; // ✘ “Erişilmez – derleme hatası” 
//    d.y1 = 100; // ✘ “Erişilmez – derleme hatası” 
//    d.z1 = 100; // ✘ “Erişilmez – derleme hatası” 
//    d.x2 = 100; // ✘ “Erişilmez – derleme hatası” 
//    d.y2 = 100; // ✘ “Erişilmez – derleme hatası” 
//    d.z2 = 100; // ✘ “Erişilmez – derleme hatası” 
    d.x3 = 100; // ✔ “Erişilir” 
    d.y3 = 100; // ✔ “Erişilir” 
    d.z3 = 100; // ✔ “Erişilir” 
    d.display();
    std::cin.get();
}