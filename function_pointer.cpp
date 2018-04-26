// The idea: functions store their code somewhere. The name of a function
// "points" to the starting location of this code. If we capture this location
// we can "call" the function "without having to use its name".

#include <iostream>

using std::cout;

int my_function() {
	return 2016;
}

int main() {

	cout << "Year: "
		<< my_function << "\n"; // Oops. I meant my_function()

	cout << "Year: "
		<< reinterpret_cast<void*>(my_function) << "\n";


	/**
	void* is the most generic way to store a memory address. Any pointer can
	be reinterpreted as a `void*` type.

	Since we can obtain the starting memory address of a function, we could
	store this information and use it at a later time. To do so we can use a
	pointer.

	Here is what the declaration of the pointer looks like:

	return_type (* [name])(param1, param2, ... )

	In our case, a pointer to `my_function` has the type
	int (*)();
	or
	int (*)(void);

	If we want to declare a pointer that is compatibla with `my_function`,
	we can use
	int (*ptr_to_my_function)();
	or
	int (*ptr_to_my_function)(void);
	**/

	int(*ptr1_to_my_function)();
	int(*ptr2_to_my_function)(void);

	/**
	The parenthesis around the name of the pointer are needed because of
	precedence of operations. The statement
	int *ptr1_to_my_function();
	is interpreted as
	int* ptr1_to_my_function();
	which is the forward declaration of a function that takes no arguments
	and returns a pointer to an `int` type.

	To make a const function pointer, place the const after the asterisk.
	int (*const ptr3_to_my_function)();
	**/

	// Obtaining starting memory adress of my_function
	ptr1_to_my_function = my_function;  // <-- No parenthesis!
	ptr2_to_my_function = &my_function; // <-- & not needed (implicit conv.)
	int(*const ptr3_to_my_function)() = my_function;

	/**
	Some common mistakes include
	ptr1_to_my_function = my_function();
	ptr1_to_my_function = &my_function();
	**/


	// To continue let us call our function via the pointers
	cout << "Year: " << (*ptr1_to_my_function)() << "\n";
	cout << "Year: " << ptr2_to_my_function() << "\n";  // implicit deref.

	cout << "Address? " << ptr1_to_my_function << "\n";
	cout << "Address! " << reinterpret_cast<void*>(ptr1_to_my_function) << "\n";

	/**
	One last "trick". Recall that a swap [var1 <--> var2] looks like this:
	T dummy = var1;
	var1 = var2;
	var2 = dummy
	**/

	// Just for "fun", let us swap `ptr1...` and `ptr2...`
	int(*dummy)() = ptr1_to_my_function;
	ptr1_to_my_function = ptr2_to_my_function;
	ptr2_to_my_function = dummy;

	/**
	// ... and since we already have dummy, we could try to swap `ptr2...` and
	// `ptr3...`, right?
	dummy = ptr2_to_my_function;
	ptr2_to_my_function = ptr3_to_my_function;
	ptr3_to_my_function = dummy; // <-- Wrong!!! Why?
	**/

	return 0;
}