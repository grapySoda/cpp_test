#include <iostream>

class PpeDB
{
   public:
    typedef void (PpeDB::*FunctionPtr)();

    PpeDB(bool condition)
    {
        if (condition) {
            clean_method = &PpeDB::clean_destory;
        } else {
            clean_method = &PpeDB::clean_overwrite;
        }
    }

    void clean_destory() { std::cout << "Method clean_destory" << std::endl; }
    void clean_overwrite()
    {
        std::cout << "Method clean_overwrite" << std::endl;
    }
    void clean() { (this->*clean_method)(); }

   private:
    FunctionPtr clean_method;
};

int main()
{
    PpeDB obj(true);
    obj.clean();

    PpeDB obj2(false);
    obj2.clean();

    return 0;
}
