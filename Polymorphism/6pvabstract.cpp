/*
Abstract class
	1)cannot create abstract class objects
	2)generally used as base classes and generic classes
	3)conatain pure virtual functions

Pure virtual functions make a class abstract.
These functions are do nothing functions.

When we derive abstract classes in derived class
then we need to override all pure virtual function.
If we dont override all the Pure virtual functions
then even the Derived class will act like abstract
class

You can create an abstract class pointer and initialise
it to point to a derived class object
*/

#include<iostream>
#include<vector>
using namespace std;

class Shape
{
public:
	virtual void draw()=0;
	virtual void rotate()=0;

	virtual ~Shape(){}
};

class Open_shape:public Shape//abstract class
{
public:

	virtual ~Open_shape(){}
	
};

class Closed_shape:public Shape//abstract class
{
public:

	virtual ~Closed_shape(){}
	
};

class Line:public Open_shape
{
public:
	virtual void draw()override
	{
		cout<<"Drawing a line "<<endl;
	}

	virtual void rotate()override
	{
		cout<<"Rotating a line "<<endl;
	}
	virtual ~Line(){}
	
};


class Circle:public Closed_shape
{
public:
	virtual void draw()override
	{
		cout<<"Drawing a circle "<<endl;
	}

	virtual void rotate()override
	{
		cout<<"Rotating a circle "<<endl;
	}
	virtual ~Circle(){}
	
};

class Square:public Closed_shape
{
public:
	virtual void draw()override
	{
		cout<<"Drawing a Square "<<endl;
	}

	virtual void rotate()override
	{
		cout<<"Rotating a Square "<<endl;
	}
	virtual ~Square(){}
	
};

void screen_refresh(vector<Shape*>&shapes)
{
	cout<<"Refreshing "<<endl;
	for(auto p:shapes)
	{
		p->draw();

	}
}

int main()
{
	//Shape s; //ERROR

	//Open_shape o;//ERROR
	//Closed_shape c;//ERROR

	Circle c;
	c.draw();
	c.rotate();
	cout<<endl<<endl;

	Shape *ptr=new Circle;
	ptr->draw();
	ptr->rotate();
	

	Shape *s1= new Circle;
	Shape *s2= new Line;
	Shape *s3= new Square;

	vector<Shape*>shapes={s1,s2,s3};

	// for(auto p:shapes)
	// {
	// 	p->draw();
	// }

	screen_refresh(shapes);
	delete s1;
	delete s2;
	delete s3;

}























