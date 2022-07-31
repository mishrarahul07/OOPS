/*
    A function like void fun()=0; is called a do nothing function. Such functions cannot be called.
    So if they are in some class then its object cannot be created. But such classes can be inherited
    and therefore other methods can be called from there. So you create an object of child class but you should
    make a blank function of same name fun() so that it is overriden.
    Now you should put virtual ahead of parent class func so that it is late binded and so that always. 
    Such functions are called pure virtual functions. 
    And a class containing pure virtual function is called an abstract class.
*/
#include <iostream>

using namespace std;

class Person
{
    virtual void fun()=0;
    void f1(){}
    
    
};

class Student:public Person
{
    void fun(){}
      
};







int main()
{
    cout<<"Hello World";

    return 0;
}
