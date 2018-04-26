// Inheritance: the `protected` keyword.

#include <iostream>
#include <string>

using namespace std;

// The BASE class
class UCLA_Person{
  // `protected` members are not visible to most other classes (i.e., they
  // behave like `private` members), however objects that inherit these
  // fields/functions can access their information freely (i.e., they behave
  // like `public` members).
  protected:
    string name;

  public:
    void set_name( string n ){
        name = n;
    }
};

int main(){

   return 0;
}
