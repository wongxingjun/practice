#include <iostream>
using namespace std;
class Operation
{
    public:
        double op_a;
        double op_b;
        Operation(double a, double b)
        {
            op_a = a;
            op_b = b;

        }
        virtual double getRes(){};
        ~Operation(){}

};

class Add : public Operation
{
    public:
        Add(double a, double b):Operation(a, b){}
        double getRes()
        {
            return this->op_a + this->op_b;

        }

};

class Sub : public Operation
{
    public:
        Sub(double a, double b):Operation(a, b){}
        double getRes()
        {
            return this->op_a - this->op_b;

        }

};

class Mul : public Operation
{
    public:
        Mul(double a, double b):Operation(a, b){}
        double getRes()
        {
            return this->op_a * this->op_b;

        }

};

class Div : public Operation
{
    public:
        Div(double a, double b):Operation(a, b){}
        double getRes()
        {
            try{
                return this->op_a / this->op_b;

            }catch(double){
                cout<< "Error" <<endl;

            }

        }

};

class OpFactory
{
    public:
        Operation* createOperation(char o, double a, double b)
        {
            Operation* op = NULL;
            switch(o)
            {
                case '+':
                    op = new Add(a,b);
                    break;
                case '-':
                    op = new Sub(a,b);
                    break;
                case '*':
                    op = new Mul(a,b);
                    break;
                case '/':
                    op = new Div(a,b);
                    break;

            }
            return op;

        }

};

int main()
{
    Operation* op;
    op = OpFactory().createOperation('+',1.0,2.0);
    cout << op->getRes() <<endl;
    op = OpFactory().createOperation('/',4.00,2.09);
    cout << op->getRes() <<endl;
    return 0;
}

