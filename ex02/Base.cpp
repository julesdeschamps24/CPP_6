#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {}

Base* generate(void) {
    std::srand(std::time(NULL) + getpid());

    int rand = std::rand() % 3;

    switch (rand)
    {
    case 0:
        std::cout << "create A" << std::endl;
        return (new A());
    case 1:
        std::cout << "create B" << std::endl;
        return (new B());
    }
    std::cout << "create C" << std::endl;
    return (new C());
}

void identify(Base* p) {
    std::cout << "identify by pointer: ";
    if(dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

void identify(Base& p) {
    std::cout << "identify by reference: ";
       try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
       } catch (...) {}
       try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
       } catch (...) {}
       try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
       } catch(...) {}
}
