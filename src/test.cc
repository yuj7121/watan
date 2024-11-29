#include <iostream>
#include <memory>

using namespace std;

class B;
class A {
    int n;
    shared_ptr<B> f;
 public:
    A(int n) : n{n} {}
    void setFriend(shared_ptr<B> b);
    void print() const;
    int getN() const { return n; }
    void incN() { n++; }
};

class B {
    int n;
    shared_ptr<A> f;
 public:
    B(int n) : n{n} {}
    void setFriend(A &a) {
        f = make_shared<A>(a);
        // a->setFriend(make_shared(*this));
    }
    void print() const { cout << "B: " << n << ", f = " << f->getN() << endl;}
    int getN() const { return n; }
    void incN() { n++; }
};

void A::setFriend(shared_ptr<B> b) {
    f = b;
    b->setFriend(*this);
}
void A::print() const { cout << "A: " << n << ", f = " << f->getN() << endl;}

int main() {
    shared_ptr<A> a = make_shared<A>(10);
    shared_ptr<B> b = make_shared<B>(20);
    a->setFriend(b);
    a->incN();
    b->incN();
    a->print();
    b->print();
}
    
