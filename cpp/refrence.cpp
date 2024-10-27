//call_by_value_call_refrence
#include <iostream>
using namespace std;

// Function to return by reference
int& returnValue(int& x) {
    cout << "x = " << x << " The address of x is " << &x << endl;
    return x;
}

int main() {
    int a = 20;

    // Function call returning a reference and assigning it to 'b'
    int& b = returnValue(a);

    cout << "a = " << a << " The address of a is " << &a << endl;
    cout << "b = " << b << " The address of b is " << &b << endl;

    // Modifying 'a' using return by reference
    returnValue(a) = 13;

    cout << "a = " << a << " The address of a is " << &a << endl;

    return 0;
}
