// Inheritance: a couple of DERIVED classes.

#include <iostream>
#include <string>

using namespace std;

// The BASE class
class UCLA_Person{
  protected:
    string name;

  public:
    void set_name( string n ){
        name = n;
    }
};

// The DERIVED classes: Student and Professor
class UCLA_Student : public UCLA_Person {
  public:
    string id_card() const  {
        return "Student: " + name;
    }
};

class UCLA_Professor : public UCLA_Person {
  public:
    string id_card() const  {
        return "Professor: " + name;
    }
};

// In both of these cases we are using `public` inheritance. The other two
// options are:
//   - `protected`, and
//   - `private`.
//
// When using
//   - `public` inheritance: 
//      * all members of the base class retain their previous status (e.g.
//        `private` members remain `private`, `protected` members remain
//        `protected`, etc.). 
//
//   - `protected` inheritance: 
//      * `public` & `protected` members of the base class become `protected`. 
//      * `private` members of the base class remain `private`. 
//
//   - `private` inheritance: 
//      * all members of the base class become/remain `private`. 

int main(){

    return 0;
}
