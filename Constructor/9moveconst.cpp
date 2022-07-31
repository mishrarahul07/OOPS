/*

 sometimes copy constructors are called many times automatically 
 due to copy semantics of c++

 copy const doing deep copying can have a significant performance 
 bottleneck

 Move const Moves an object rather than copying it 

 optional but recommended when you have a raw pointer and when 
 using a raw pointer do deep copying.

 when you dont call Move const, copy const are automatically called

 when none of them are called then it is called copy elision which is 
 compiler optimisation technique avoiding unnecessary copying 
 one type is return value optimistion(RVO)

Move semantics deal with R values

instead of doing deep copying, it Moves the resources on the heap
by assigning pointer from source object to the current object


*/


#include<iostream>
#include<vector>
using namespace std;


class Move
{
private:
	int *data;
public: 
	void set_data_value(int d)
	{
		*data=d;
	}

	int get_data_value()
	{
		return *data;
	}


	//consructor with int arg
	Move(int d);

	//copy const
	Move(const Move &source);

	// Move(Move &&source) noexcept;

	~Move();

};

Move::Move(int d)
{
	data=new int;
	*data=d;
	cout<<"Const called for: "<<d<<endl;

}
x
Move::Move(const Move &source)
: Move(*source.data)
{
	cout<<"Copy Const - deep copy for"<<*data<<endl;
}

// //Move const

// Move::Move(Move &&source) noexcept
// :data{source.data}
// {
// 	source.data=nullptr;
// 	cout<<"Move Constructor - moving resource: "<<*data<<endl;
// }


Move::~Move()
{
	if(data!=nullptr)
	{
		cout<<"Destructor freeing data for "<<*data<<endl;
	}	
	else
	{
		cout<<"Destructor freeing data for nullptr "<<endl;
	}

	delete data;
}

int main()
{
	vector<Move> vec;
	vec.push_back(Move{20});

	 vec.push_back(Move{20});
    vec.push_back(Move{30});
    vec.push_back(Move{40});
     vec.push_back(Move{50});
    vec.push_back(Move{60});
    vec.push_back(Move{70});
    vec.push_back(Move{80});
}

