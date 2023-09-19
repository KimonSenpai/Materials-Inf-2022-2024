#include <iostream>
#include "Stack.h"
using std::cout;


int main() {
    Stack s;

    s << 2 << 4 << 7;
    cout << s << '\n';
}