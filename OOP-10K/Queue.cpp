#include "Queue.h"

Queue::Queue(): beg_(nullptr), end_(nullptr), size_(0) {}

Queue::~Queue() {
    while (beg_ != nullptr) {
        Node* t = beg_;
        beg_ = beg_->next;
        delete t;
    }
}

Queue::Queue(const Queue& obj): beg_(nullptr), end_(nullptr), size_(0) {
    Node* p = obj.beg_;

    while (p != nullptr) {
        push(p->val);
        p = p->next;
    }
}

int Queue::top() const {
    
    return beg_->val;
}

void Queue::push(int val) {
    Node* t = new Node;

    t->val = val;
    t->next = nullptr;
    if (size_ > 0) {
        end_->next = t;
        end_ = t;
    } else {
        beg_ = end_ = t;
    }
    ++size_;
}

int Queue::pop() {
    int t = beg_->val;
    Node* p = beg_;

    beg_ = beg_->next;
    --size_;
    delete p;
    return t;
}

Queue& Queue::operator<<(int val) {
    push(val);
    return *this;
}

Queue& Queue::operator>>(int& val) {
    val = pop();
    return *this;
}

ostream& operator<<(ostream& out, Queue& obj) {
    for (Queue::Node* p = obj.beg_; p != nullptr; p = p->next) {
        out << p->val << ' ';
    }

    return out;
}