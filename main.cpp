#include <iostream>

class MyClass
{
   public:
    typedef void (MyClass::*FunctionPtr)();

    MyClass(bool condition)
    {
        if (condition) {
            A = &MyClass::B;
        } else {
            A = &MyClass::C;
        }
    }

    void B() { std::cout << "Method B" << std::endl; }
    void C() { std::cout << "Method C" << std::endl; }
    void ExecuteA() { (this->*A)(); }

   private:
    FunctionPtr A;
};

int main()
{
    MyClass obj(true);
    obj.ExecuteA();

    MyClass obj2(false);
    obj2.ExecuteA();

    return 0;
}
