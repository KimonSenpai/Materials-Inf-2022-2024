#pragma once
#include <iostream>
using std::ostream;

class Queue {
 public:
    Queue();
    Queue(const Queue& obj);
    ~Queue();

    int top() const;
    int pop();
    void push(int val);
    size_t size() const {
        return size_;
    }

    Queue& operator<<(int val);
    //q << 3 << 5 << 7;
    Queue& operator>>(int& val);
    //q >> a >> b >> c;

    friend ostream& operator<<(ostream&, Queue&);

 private:
    struct Node {
        int val;
        Node* next;
    };

    Node* beg_;
    Node* end_;
    size_t size_;
};

