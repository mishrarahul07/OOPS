/*
final specifier prevents a class to be derived
from
*/

class Number final
{

};
//Number cannot be further derived
class One 
{

};

class Two final:public One
{

};
//Two cannot be further derived


class A
{
public:
	virtual void do_something();
};

class B:public A
{
	virtual void do_something() final;
	//prevents further overriding	
};

class C:public B
{
public:
	virtual void do_something();//error
		
};

int main()
{
	
}


























