#include<iostream>
using namespace std;

class A
{
    public:
    void f1();
    void f2();
    
} ;

class B: public A
{
    void f1(){}
    void f2(int x){}
    
};

int main()
{
    B obj;
    b.f1() //B it is called function overriding
    /*
        if compiler finds same name functions with same prototypes but different body then 
        it considers the child one.
    */
    b.f2()//error
    /*
        compiler first finds the method called in child class and if it does not find it there
        then it looks up in the parent class.
        
        This case is different. The compiler has found the function with the exact name as the function
        called so it does not go to parent class and displays error. This is called method hiding
    */
}