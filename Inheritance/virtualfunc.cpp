#include<iostream>
using namespace std;

class A
{
    public:
    virtual void f1();
    void f2();
    
} ;

class B: public A
{
    void f1(){}
    void f2(int x){}
    
};

int main()
{
    A *o1,a;
    B obj;
    b.f1() //B
    b.f2()//error
    o1=&obj;
    obj.f1();//B
//    o1->f1();//A if not virtual
    o1->f1();//B
    /*
        in this compiler just encounters the pointer. 
        In Inheritance a pointer of the Parent class can point to the object of the parent class 
        as well as to the objects of the descendent classes.Compiler is following early binding over Inheritanced   
        so if we use virtual ahead of class A then compiler does it at run time. Late binding
    */
}