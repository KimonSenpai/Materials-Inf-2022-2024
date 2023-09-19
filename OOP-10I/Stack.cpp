#include "Stack.h"


Stack::Stack(): beg_(nullptr), size_(0) {}

Stack::Stack(const Stack& obj) {
    beg_ = copy(obj.beg_);
    size_ = obj.size_;
}

Stack::Node* Stack::copy(Stack::Node* root) {
    if (root == nullptr) return nullptr;

    Node* p = new Node;
    p->val = root->val;
    p->next = copy(root->next);
    return p; 
}

int Stack::top() const {
    if (beg_ == nullptr) throw 1;
    return beg_->val;
}

int Stack::pop() {
    int tmp = top();

    Node* p = beg_;
    beg_ = beg_->next;
    delete p;
    --size_;

    return tmp;
}

void Stack::push(int val) noexcept {
    Node* p = new Node;
    p->val = val;
    p->next = beg_;
    beg_ = p;
    ++size_;
}

bool Stack::is_empty() const noexcept {
    return size_ == 0;
}

size_t Stack::size() const noexcept {
    return size_;
}

Stack& Stack::operator<<(int val) noexcept {
    push(val);
    return *this;
}

Stack& Stack::operator>>(int& val) {
    val = pop();
    return *this;
}

ostream& operator<<(ostream& out, Stack& obj) {
    for (Stack::Node* p = obj.beg_; p != nullptr; p = p->next) {
        out << p->val << ' ';
    }
    return out;
}

Stack::~Stack() {
    while (beg_ != nullptr) {
        Node* p = beg_;
        beg_ = beg_->next;
        delete p;
    }
}

