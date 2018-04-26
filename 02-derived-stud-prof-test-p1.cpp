// Inheritance: instantiation of derived objects (part 1).

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

class UCLA_Professor :  public UCLA_Person {
  public:
    string id_card() const  {
        return "Professor: " + name;
    }
};

/**
   In main we simply
   - Create (instantiate) `UCLA_Student`, and `UCLA_Professor` objects.
   - Set their names via the public member function.
   - Display their `id_card`.
**/
int main(){
    UCLA_Student s;
    UCLA_Professor p;

    s.set_name("Elmer Homero Petatero");
    p.set_name("Aquiles Esquivel Madrazo");

    cout << s.id_card() << "\n";
    cout << p.id_card() << "\n";

    return 0;
}

/** 
    Note: Neither class explicitly defines a constructor
*/
