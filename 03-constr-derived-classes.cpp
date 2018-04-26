// Inheritance: instantiation of derived objects (part 2).  

#include <iostream>

using namespace std;

// BASE class provides two constructors: default & one-parameter
class BaseClass { 
  public: 
    BaseClass(){ 
        cout << "BASE constr: no params\n"; 
    }
    BaseClass( int a ){ 
        cout << "BASE constr: int param\n"; 
    }
};

// This derived class inherits the default base constructor and uses it in its
// explicitly defined one-parameter constructor
class Derived1 : public BaseClass { 
  public: 
    Derived1( int a ){ 
        cout << "Derived1 constr: int param\n\n"; 
    }
};

// This derived class does inherit the default base constructor as well, however
// said constructor is not used as this class specifically requests a different
// base constructor (see initialization list).
class Derived2 : public BaseClass { 
  public: 
    Derived2( int a ) : BaseClass( a ) { 
        cout << "Derived2 constr: int param\n\n"; 
    }
};


// The big idea: A derived object is constructed "on top" of a base object. This
// means that the base object needs to be created, somehow. If one is careless
// when coding, big surprises might arise as the `default` constructor might
// be inadvertently called.
int main () {
    Derived1 d1(0);
    Derived2 d2(0);

    return 0;
}
