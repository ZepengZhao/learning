// Inheritance: using base pointers to handle derived objects.

#include <iostream>
#include <string>

using namespace std;

// BASE class
class UCLA_Person{
  protected:
    string name;

  public:
    void set_name( string n ){
        name = n;
    }
};

// DERIVED classes
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
   Up to this point there are no major changes from our previous example (c.f.
   02-derived-stud-prof-test-p1.cpp).

   Now in main we 
   1. Create `UCLA_Student` and `UCLA_Professor` objects.
   2. Create pointers to `UCLA_Person` objects and point them to the objects
      created in step 1.
   3. Set object names via the pointers from step 2. 
   4. Display `id_cards` via the objects created in step 1.
**/
int main(){
    UCLA_Student s;
    UCLA_Professor p;

    UCLA_Person* p_stud = &s;
    UCLA_Person* p_prof = &p;

    p_stud->set_name("Elmer Homero Petatero");
    p_prof->set_name("Aquiles Esquivel Madrazo");

    cout << s.id_card() << "\n";
    cout << p.id_card() << "\n";

    return 0;
}

/** 
    What happens if we use pointers instead of the actual objects in step 4
    above???
**/
