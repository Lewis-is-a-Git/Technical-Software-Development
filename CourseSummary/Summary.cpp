int main(int argc, char* argv[]) {
//include guard
	//guard against repeated inclusion
	#ifndef HEADER_H_
	#define HEADER_H_
	#endif
	
	//or
	#pragma once

//Separation of Concerns
	//seporating aprogram into distinc features
	//a concern is a piece of interest, or feature
	//achieved throught modular program design

//Abstraction
	//Interfaces: set of values to represent data type
	//Implementations: representation of the data and code for the operations

//Functions
	//parameterised abstractions over expressions
	//encapsulate reoccuring expressions

//call by reference
	//use & symbol after type
	//sends the memory address instead of the value

//File Streams
	#include <fstream>
	//Open files (example of output file)
	bool openOutputFile(char* aFileName, std::ofstream& aOutput)
	{
		aOutput.open(aFileName, ofstream::out);
		if (!aOutput.good())
		{
			//operation failed
			cerr << "Cannot open output file " << aFileName << endl;
			return false;
		}
		else
			return true;
	}

	//File validation
	ifstream lInput;
	if (openInputFile(argv[1], lInput))
	{
		ofstream lOutput;
		if (openOutputFile(argv[2], lOutput))
		{
			processData(lInput, lOutput);

			lInput.close();
			lOuput.close();
			return 0;
		}
		else
		{
			lInput.close();
			return 3; //error codes
		}
		else
			return 2; //error codes
	}

//CamelCase
	//InputStreamReader
	//inner uppercase letters to denote embedded words
	//

//Hungarian Notation
	//the name of a variable indicates its type
	//not a great idea

//formatting
//brackets
{
	//ANSI style
}

//Style Guide Delphi elements
	//Field names: start with f
	//Local variables: start with l
	//Parameter names: start with a
	//Global variables: start with g
	

//Documantation elelments
	//program description
	//change logs
	//commented program listings
	//sample test runs
	//user manual
	//dont write the documantation in the same structure and the program

//Version Control
	//records changes to files over time
	//usueally identified by a number

//programming paradigms
	//Imperative style:
	program = algorithms + data;
	//Functional style:
	program = function * function;
	//Logic programming stye:
	program = facts + rules;
	//Object-oriented style:
	program = objects + messages;


//object orianted programming
	//based in the concepts of class and inheritance

//design philosiphy of c++
	//hybrid, statically typed, general purpose
	// multiple programming styles
	//avoids featuers that are platform specific

//Class in c++
	class x
	{
	private:
	protected:
	public:
	}; //dont forget the semicolon
	//definition of new data type is a class

//Access modifiers
	//public: members accessed anywhere, even outside class
	//protected: members accessed within class or derived class
	//private: members accessed only in the class they are declared

//code organisation
	//interface: defined in .h header file
	//implementation: occurs in .cpp source files

//Data Encapsulation
	//protect information captured by data type
	//instance variables hace private visibility
	//member functions have public visibility

//Enumerators
	//define constsnts
	enum CardSuit {Blank, Club, Diamond, Heart, Spade};

//Static
	//mark the linage of a variable or function internal
	//retain the value of a local variable
	//declare a class instance variable
	//define a class method
	static string gCardSuits(" CDHS");

//Throw Expression
#include <stdexcept> //throw
	const Card& Deck::drawCard()
	{
		if (fCardIndex < 52)
			return fCards[fCardIndex++];
		else
			throw out_of_range("Invalid index");
	}
	//raises an exception, encodes the cause

//Try-Catch Blocks
	try {
		//code that could throw exception
	}
	catch (exception1& e1) {
		//code that handles exception 1
	}

//strong typing
	//every expresssion has a type
	//places restrictions on permissable intermixing of data

//polymorhpism
	//adHoc
		//coercion: integers can be used where floats are expected
		//Overloading: + applies to both integers and floats
	//Universal
		//Inclusion: class-based inheritance
		//Parametric: templates

//Public inheritance
	//enables polymorphism
	//object of a subclass can be used anywhere a superclass is expected
	//models raltionships amoung classes
	//sharing what is common and specialising in whats different
	//derive new classes form existing ones

//Base class initailisers
	//if a base class does not have a constructor 
	//a derived class must provide a base class initialiser
	//appear alongside member initalisers
	BankAccount::BankAccount(long aNumber, double aRate) : Account(aNumber)
	{
		fInterestRate = aInterestRate;
	}
	//Account is the member initaliser
	//constructor: initailise the account features and set interest rate

//Virtual member functions
	//constructors cannot be virtual
	//if delcared virtual it remains virtual
	//to allow a memeber fucntion to be overridden it must be declared virtual

//interface
	//related abstract members

//Pure virtual member functions
	//abstract class
	class IVideoPokerView
	{
	public:
		virtual ~IvideoPokerView() {}
		virtual void showhand() = 0;
	};
	//= 0 denaotes that a member function is abstract
	//defer implementation to subclasses

//Abstract classes as interfaces
	//an interface is a set of member functions
	//A class implements an interface by defining all member fucntions
	//An abstract class can be viewed as an interface 
	//only contains public pure virtual member function and a destructor

//Forwarding methods
	int VideoPoker::getScore()
	{
		return fHand.getScore(); //forwarded to another class
	}

//reference data memebers
	//requires a constructor
	class RefMember
	{
	private:
		OtherClass & fRef;
	public:
		//data members must be initalised before the constructor body
		RefMember(OtherClass& aRef) : fRef(aRef) {}
	};

//Model-View-Controller paradigm
	//two objects: view and model
	//controller to interface them
	//main function instantiates the model, view and controller
	//main fucntion just tells the controller to run

//multiple inheritance
	//allows a class to inherant from several base classes
	//mehcanism to compose orthoganal behaviour
	//we can acpture these feateurs in interfaces
	//this avoids the problem associated with multiple inheritance

//virtual base classes
	//allows multiple instances of a base class
	//included in an object of a derived class
	//members of virtual base classes are merged into one representative

//Big Oh: Running time estimation
	/*ranking
	� Fastest : O(1)
				O(log n)
				O(n)
				O(n log n)
				O(n_2)
				O(n_2 log n)
				O(n_3)
				O(2_n)
	� Slowest : O(n!) 
	*/
	//Ignore lower order terms
	//performance analysis
		//best case: first element in a lsit O(1)
		//worst case: last element in a a list O(n)
		//average case: O(n/2)

	//running time of nested for loops 
		//O(n_NumberOfForLoops) : O(n_2)
	//consecutive statements
	//O(m_maximumRunningTime) : O(m)
	

//greedy algorithms produce a feasable solution and stop
	//dont guarantee an optimal solution

//brute force algorithms
	//exhaustivly enumerating all possibilities

//bubble sort
	//nested for loops
	//O(n_2)
	//unsuiatable for large data sets

//algorithmic patterns
	//direct solution strategies
		//brute force and greedy
	//Backtracking
		//branch and bound algorithms
	//top down
		//divide and conquer
	//randomised
		//monte carlo algorithms

//sorting by Fisher&yates
	//variables passed by reference so any type works
	#include <stdlib.h>  //srand, rand
	#include <algorithm> //swap
	int n = 52;
	while (n > 1)
	{
		//new random index
		int k = rand() % n;
		n--;
		swap(fCards[n], fCards[k]);
	}


//containers
	//containers are abstract data types
	//collection types all have .size()
	//all have ::iterators
	//normal arrays: computation time O(n)
		//n is the number of elements in the array
		//may run out of space (buffer overflow)
	//vector
	//list
	//stack
	//queue

//templates
	//blueprints generated based on perameters
	//each time it is used with new pearmeters a new version is generated
	//each new fucntion is called a specialisation
	

//class template
	//parameterised abstracton over a class
	//supply desired types as template perameters
	template<class one, class two>
	class AClassTemplate
	{
		//class specification
	};

//typedef
	//makes code more readable
	typedef Adder<int> IntAdder;
	IntAdder aIntAdder(2, 4);

//Vector arrays
	//dynamic array, normal arrays have a fixed length
	//proper initaliazation of elements
	//can only use push_back to append
	//can be copied and assignet to other vector variables
	#include <vector>
	vector<int> lVectorA(); //create empty array
	while (lInput >> lNumber)
	{
		lVectorA.push_back(lNumber); //add new element
	}
	
//List Container
	//no random access, must traverse to element
	//list can grow in both directons
	//iterator allows traverse forwards or backwards
	list<int> lListA(10); // list fo 10 integers all = 0
	//this is a for each : loop
	for (list<int>::iterator pos = lListA.begin(); pos != lListA.end(); pos++)
	{
		cout << *pos << endl; // * means dereference operator (value)
	}
	//singly-linked list
	//pairs of data, a value and a reference to the next element
	//Doubly-linked list
	//three items per element, data, reference to the previos and next element
	//insert new elements by rewiring things not moving things
	//begin() and rbegin() to move in different directions

//Stack Behavior
	//LIFO push(), pop() and top()
	//stack underflow: try to pop an empty stack
	//stack overflow: try to push a full stack
	//used for balancing, must be mepty at the end to be balanced

//Queue Behavior
	//FIFO insert at one end an remove at the other
	//queue underflow: try to dequeue an empty queue
	//queue overflow: try to nequeue on a full queue
	//used to shedule tasks
	//never fill up a queue because the bigger it get the slower it gets

//Requiremtns Analysis
	//what type of input is required
	//what output is required
	//how do we represent the data and information

//Constructor method
point::point() //method called the same as the class
{
	//initailise values
	fDimentions = 0;
}

//Getters (Getter Methods)
int point::getDimentions() const
{
	return fDimentions;
}

// Output operator overload
	//header specification
	std::ostream& operator<<(stde::ostream& aOStream, const point& aObject);

	//class implementation
	ostream& operator<<(ostream& aOStream, const point aObject) //const here?
	{
		aOStream << aObject.getDimentions();
		return aOStream;
	}

	//another example
	//class implementation
	bool Card::operator>(const Card& aOtherCard) const
	{
		//enables sorting value followed by suit
		if (fValue == aOtherCard.fValue)
		{
			return fSuit > aOtherCard.fSuit;
		}
		return fValue > aOtherCard.fValue;
	}

	//another example
	bool Card::operator==(const Card& aOtherCard) const
	{
		return fSuit == aOtherCard.fSuit &&
			   fValue == aOtherCard.fValue;
	}

//Do not forget about documantation comment tags
	/**
	*  program starts with a multi line comment
	*/
	//define the purpose
	//@param: parameter name description
	//@version: test
	//@author: name
	//@return: description
	//@exception: full-classname description
	//@throws: full-classname description
	//@see reference
	//@depreciated explanation
	//@since version

//Final Exam
	//concepts
	//tutorials and assignments should take about 20 mins

return 0;
}