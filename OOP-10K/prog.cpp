#include <iostream>
#include "Queue.h"
using std::cout, std::cin;


int main() {
    Queue q;
    q << 3 << 5 << 7;
    cout << q << '\n';
    return 0;
}