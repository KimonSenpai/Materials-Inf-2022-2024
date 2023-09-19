#pragma once
#include <iostream>
using std::ostream;

class Stack {
 public:
    Stack();
    Stack(const Stack& obj);
    ~Stack();

    int top() const;
    int pop();
    void push(int val) noexcept;
    bool is_empty() const noexcept;
    size_t size() const noexcept;

    Stack& operator<<(int val) noexcept;
    //s << 2 << 4 << 6;
    Stack& operator>>(int& val);
    //s >> a >> b >> c;

    friend ostream& operator<<(ostream& out, Stack& obj);

 private:
    struct Node {
        int val;
        Node* next;
    };

    Node* beg_;
    size_t size_;

    static Node* copy(Node* root);

};
