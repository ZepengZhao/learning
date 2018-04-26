// Inheritance: inheriting from multiple base classes.

#include <iostream>
#include <string>

using namespace std;

// BASE class: UCLA_Person
class UCLA_Person{
  protected:
    string name;

  public:
    UCLA_Person( string n ) : name(n) {}
};


// BASE class: To_Console
class To_Console{
  public:
    // Recall that `static` members are not associated to an individual object
    // but to the class as a whole. That is, even if there are multiple objects
    // of the `To_Console` class, there is ONLY ONE `print()` member function.
    static void print( string s ){
        cout << s << "\n";
    }
};



// DERIVED class: Student
class UCLA_Student : public UCLA_Person, public To_Console {
  public:
    UCLA_Student( string n ) : UCLA_Person(n) {}

    string id_card() const  {
        return "Student: " + name;
    }
};

// DERIVED class: Professor
class UCLA_Professor :  public UCLA_Person, public To_Console {
  public:
    UCLA_Professor( string n ) : UCLA_Person(n) {}

    string id_card() const  {
        return "Professor: " + name;
    }
};

/**
   In `main` we
   - Create `UCLA_Person` objects via constructors 
   - Display their info to console via [a member of the] second base class
**/
int main(){
    UCLA_Student s("Elmer Homero Petatero");
    UCLA_Professor p("Aquiles Esquivel Madrazo");

    s.print( s.id_card() );
    To_Console::print( p.id_card() );

    return 0;
}

/**
  Question:
    Why do we use (prefer?) the notation
       SomeClass::static_member
    on line 61?
**/
