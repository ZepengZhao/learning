// Our example gets a even more complex.... This time we underscore the fact
// that UCLA_Person is too generic and we want to restrict ourselves to more
// specific instances.

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
      No UCLA_Person this time.
   2. Create pointers to UCLA_Person objects and point them to 
      objects created in 1.

   3. Set names via pointers created in 2. 
   4. Display id_cards via pointers created in 1.
*/
int main(){
   UCLA_Student s;
   UCLA_Professor p;
   //UCLA_Person u;

   UCLA_Person* p_stud = &s;
   UCLA_Person* p_prof = &p;
   //UCLA_Person* p_pers = &u;

   p_stud->set_name("Elmer Homero Petatero");
   p_prof->set_name("Aquiles Esquivel Madrazo");
   //p_pers->set_name("Zoila Reyna DelCastillo");

   cout << p_stud->id_card() << "\n";
   cout << p_prof->id_card() << "\n";
   //cout << p_pers->id_card() << "\n";

   return 0;
}
/** 
    Note: What happens if you uncomment any of the 
          lines in main associated to UCLA_Person u ?
*/
