#include<iostream>
/*

A constructor will have exact same name as the class and it does not have any return type at all, not even void. Constructors can be very useful for setting initial values for certain member variables.

Every object in C++ has access to its own address through an important pointer called this pointer.
The this pointer is an implicit parameter to all member functions. Therefore, inside a member function, this may be used to refer to the invoking object.

Friend functions do not have a this pointer, because friends are not members of a class. Only member functions have a this pointer.



The copy constructor is a constructor which creates an object by initializing it with an object of the same class, which has been created previously. The copy constructor is used to:

Initialize one object from another of the same type.

Copy an object to pass it as an argument to a function.

Copy an object to return it from a function.

If a copy constructor is not defined in a class, the compiler itself defines one.
If the class has pointer variables and has some dynamic memory allocations, then it is a must to have a copy constructor. 
The most common form of copy constructor is shown here:

classname (const classname &obj) {
   // body of constructor
}
*/
using namespace std;

class Box{
	public:
	static int objCount;
	//constructor definition
	Box(double l, double b);    //regular constructor
	Box(const Box &obj); 		//copy constructor
	~Box(); //destructor
	double area();
	int compare(Box box);
	friend void printWidth(); //friend function
	static int getCount();
	
		
      // Overload + operator to add two Box objects.
      Box operator+(const Box& b) {
         Box box;
         box.length = this->length + b.length;
         box.breadth = this->breadth + b.breadth;
         return box;
      }
	  
	private:
	int length;
	int breadth;
};

Box::Box(double l, double b)
{
	length = l;
	breadth = b;
	objCount++;
}
	
Box::Box(const Box &obj) 
{
	length = *obj.length; //copy the values
	breadth = *obj.breadth;
}

// Note: printWidth() is not a member function of any class.
void printWidth( Box box ) {
   /* Because printWidth() is a friend of Box, it can
   directly access any member of this class */
   cout << "Width of box : " << box.breadth <<endl;
}

double Box::area()
{
	return length *breadth
}
	
int Box::compare(Box Box)
{
	return (this->area() > box.area());
}

int Box::getCount()
{
	return objCount;
}

int Box::objCount = 0;

int main()
{
	
	Box box1(4.0, 5.0);
	Box box2(3.0, 2.0);
	
	// Print total number of objects before creating object.
    cout << "Count: " << Box::getCount() << endl;
	
	 // Use friend function to print the wdith.
	printWidth( box1 );
   
	Box box3 = box2;  //calls copy constructor
	cout<< "Box3 area "<<box3.area()<<endl;
	
	int ret = Box2.compare(box1);
	if(ret)
	{
		cout<<"Greater"<<endl;
	}
	else cout<<"Not greater" <<endl;
	//operator over loading
	Box box4 = box2 + box1;
	//area of box 4
   double area  = box4.area();
   cout << "Volume of Box3 : " << area <<endl;

}

o/p 
 Count: 2
Box3 area 6
Not greater












#include <iostream>
using namespace std;

// first name space
namespace first_space{
   void func(){
      cout << "Inside first_space" << endl;
   }
}

// second name space
namespace second_space{
   void func(){
      cout << "Inside second_space" << endl;
   }
}

using namespace first_space;
int main () {
 
   // This calls function from first name space.
   func();
   
   return 0;
}