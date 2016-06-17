class Singleton
{
public:
    static Singleton* Instance();//To make sure that only one instance is created.
protected:
    Singleton();
private:
    static Singleton* _instance;//Save the only instance.
};

Singleton* Singleton::_instance = 0;
Singleton* Singleton::Instance()
{
    if(_instance==0)
    {
        _instance = new Singleton;
    }
    return _instance;
}

