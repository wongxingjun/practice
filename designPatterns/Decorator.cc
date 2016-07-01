#include <iostream>
using namespace std;

class Component
{
    public:
        virtual void Operation(){}
};

class ConcreteComponent: public Component
{

    public:
        void Operation()
        {
            cout << "This is the concrete operation! Do nothing." << endl;
        }
};

class Decorator: public Component
{
    protected:
        Component* comp;
    public:
        void setComp(Component* c){comp = c;}
        void Operation()
        {
            if(comp != NULL)
                comp -> Operation();
        }
};

class Decorator1: public Decorator
{
    private:
        int a = 23;
    public:
        void Operation()
        {
            Decorator::Operation();
            cout << "Printing operation added! " << "a^2=" << a*a <<endl;
        }
};

class Decorator2: public Decorator
{
    private:
        int a = 12;
        int b = 3;
    public:
        void Operation()
        {
            Decorator::Operation();
            NewOperation();
        }
        void NewOperation()
        {
            cout << "Division operation added! " << "a/b=" << a/b <<endl;
        }

};

int main()
{
    ConcreteComponent* c = new ConcreteComponent();
    Decorator1* d1 = new Decorator1();
    Decorator2* d2 = new Decorator2();
    d1 -> setComp(c);
    d1 -> Operation();

    d2 -> setComp(c);
    d2 -> Operation();

    d2 -> setComp(d1);
    d2 -> Operation();

    return 0;
}

