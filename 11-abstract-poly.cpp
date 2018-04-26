// So, what use [if any] are abstract classes? You can still use pointers. This
// together with polymorphism gives you a great deal of flexibility.

#include <iostream>
#include <string>

using namespace std;

// BASE class with PURELY virtual member function
class UCLA_Person{
   protected:
      string name;

   public:
      void set_name( string n ){
         name = n;
      }

      virtual string id_card() const = 0;

      void print_id_card() const {
         cout << this->id_card() << "\n";
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

   In main 
   1. Create objects UCLA_Student, and UCLA_Professor. 
   2. Create pointers to UCLA_Person objects and point them to 
      objects created in 1.

   3. Set names via pointers created in 2. 
   4. Display id_cards via BASE pointers created in 2.
*/
int main(){
   UCLA_Student s;
   UCLA_Professor p;

   UCLA_Person* p_stud = &s;
   UCLA_Person* p_prof = &p;

   p_stud->set_name("Elmer Homero Petatero");
   p_prof->set_name("Aquiles Esquivel Madrazo");

   p_stud->print_id_card();
   p_prof->print_id_card();

   return 0;
}
/** 
    Note: Why does this work???
    Hint: `this` is the answer.
*/
