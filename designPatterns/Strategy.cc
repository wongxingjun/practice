#include <iostream>
using namespace std;

class Strategy
{
    public:
        virtual void AlgorithmInter(){}
};

class Algo1 : public Strategy
{
    public:
        void AlgorithmInter()
        {
            cout << "This is Algorithm1" << endl;
        }
};


class Algo2 : public Strategy
{
    public:
        void AlgorithmInter()
        {
            cout << "This is Algorithm2" << endl;
        }
};

class Algo3 : public Strategy
{
    public:
        void AlgorithmInter()
        {
            cout << "This is Algorithm3" << endl;
        }
};

class Context
{
    public:
        Strategy* strategy;
        Context(Strategy* s): strategy(s){}
        void contextInter()
        {
            strategy -> AlgorithmInter();
        }
};

int main()
{
    Context* con;
    con = new Context(new Algo1());
    con -> contextInter();
    con = new Context(new Algo2());
    con -> contextInter();
    con = new Context(new Algo3());
    con -> contextInter();
    return 0;
}

