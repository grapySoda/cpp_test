#include <iostream>

class MyClass
{
   public:
    typedef int (MyClass::*FunctionPtr)();

    MyClass(bool condition)
    {
        if (condition) {
            A = &MyClass::B;
        } else {
            A = &MyClass::C;
        }
    }

    int B()
    {
        std::cout << "Method B" << std::endl;
        return 42;
    }
    int C()
    {
        std::cout << "Method C" << std::endl;
        return 99;
    }
    int ExecuteA() { return (this->*A)(); }

   private:
    FunctionPtr A;
};

int main()
{
    MyClass obj(true);
    int result1 = obj.ExecuteA();
    std::cout << "Result from B: " << result1 << std::endl;

    MyClass obj2(false);
    int result2 = obj2.ExecuteA();
    std::cout << "Result from C: " << result2 << std::endl;

    return 0;
}
