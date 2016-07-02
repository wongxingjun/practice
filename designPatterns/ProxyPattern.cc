#include <iostream>
using namespace std;

class Girl
{
public:
    string name;
    int age;
    Girl(string s,int a)
    {
        name=s;age=a;
    }
};

class Actions
{
public:
    virtual void sendFlowers(){}
    virtual void sendLoveLetters(){}
};

class Pursuit: public Actions
{
public:
    Girl* girl;
    Pursuit(Girl* g):girl(g){}
    void sendFlowers()
    {
        cout << "Send flowers to " <<girl->name<<endl;
    }
    void sendLoveLetters()
    {
        cout << "Send a love letter to "<< girl->name<<endl;
    }
};

class Proxy: public Actions
{
public:
    Pursuit* boy;
    Proxy(Girl* girl)
    {
        boy = new Pursuit(girl);
    }
    void sendFlowers()
    {
        boy->sendFlowers();
    }
    void sendLoveLetters()
    {
        boy->sendLoveLetters();
    }
};

int main()
{
    Girl* meinv = new Girl("Wang",18);
    Proxy* sender = new Proxy(meinv);

    sender->sendFlowers();
    sender->sendLoveLetters();
}
