// Our example gets a bit more complex. The idea is to take advantage of the
// fact that all pointers, store the same type of memory addresses (regardless
// of their type.

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

class UCLA_Professor : public UCLA_Person {
  public:
    string id_card() const  {
        return "Professor: " + name;
    }
};

/**

   Let's try again. Shall we?

   Now in main we 
   1. Create objects UCLA_Student and UCLA_Professor
   2. Create pointers to UCLA_Person objects and point 
      them to the objects created in 1.

   3. Set names via the pointers created in 2. 

   4. Display id_cards via objects created in 1.
*/
int main(){
    UCLA_Student s;
    UCLA_Professor p;

    UCLA_Person* p_stud = &s;
    UCLA_Person* p_prof = &p;

    p_stud->set_name("Elmer Homero Petatero");
    p_prof->set_name("Aquiles Esquivel Madrazo");

    /**
    cout << s.id_card() << "\n";
    cout << p.id_card() << "\n";
    */

    // Let's try using pointers...
    cout << p_stud->id_card() << "\n";
    cout << p_prof->id_card() << "\n";

    return 0;
}
/** 
    PROBLEM:
    My compiler did not like it.

    inher_and_poly.cpp: In function ‘int main()’:
    inher_and_poly.cpp:66:20: error: ‘class UCLA_Person’ has no member named ‘id_card’
        cout << p_stud->id_card() << "\n";
                        ^
    inher_and_poly.cpp:67:20: error: ‘class UCLA_Person’ has no member named ‘id_card’
        cout << p_prof->id_card() << "\n";
                        ^
**/


