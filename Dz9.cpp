#include <iostream>
using namespace std;
template<typename T1, typename T2>
class base {
protected:
    T1 value1;
    T2 value2;
public:
    base(T1 v1, T2 v2) : value1(v1), value2(v2) {
    }
    ~base() {
        cout << "Base destructor called.\n";
    }
    void setValue1(T1 val1) { value1 = val1; }
    void setValue2(T2 val2) { value2 = val2; }
    T1 getValue1() const { return value1; }
    T2 getValue2() const { return value2; }
    virtual void print() const {
       cout << "Base values: " << getValue1() << ", " << getValue2() << endl;
    }
};
template<typename T1, typename T2, typename T3, typename T4>
class child: public base<T1,T2>{
    T3 value3;
    T4 value4;
public:
    child(T1 v1, T2 v2,T3 v3, T4 v4) :base<T1, T2>(v1,v2), value3(v3), value4(v4) {
    }
    void setValue3(T3 val3) { value3 = val3; }
    void setValue4(T4 val4) { value4 = val4; }
    T3 getValue3() const { return value3; }
    T4 getValue4() const { return value4; }
    ~child() {
        cout << "Child destructor called.\n";
    }
    virtual void print() const {
        cout << "Base and child values: " <<this->getValue1() << " , " << this->getValue2() << " , " << getValue3() 
            << ", " << getValue4() << endl;
    }
};
template<typename T1, typename T2, typename T5, typename T6>
class child2 : public base<T1, T2> {
    T5 value5;
    T6 value6;
public:
    child2(T1 v1, T2 v2, T5 v5, T6 v6) :base<T1, T2>(v1, v2), value5(v5), value6(v6) {
    }
    void setValue5(T5 val5) { value5 = val5; }
    void setValue6(T6 val6) { value6 = val6; }
    T5 getValue5() const { return value5; }
    T6 getValue6() const { return value6; }
    ~child2() {
        cout << "Child2 destructor called.\n";
    }
    virtual void print() const {
        cout << "Base and child2 values: " << this->getValue1() << ", " << this->getValue2() << ", " 
            << getValue5() << ", " << getValue6() << endl;
    }
};
template<typename T>
void Print(const T& clas) {
    clas.print();
}
int main()
{
    base<int, double> bas(10, 20.5);
    Print(bas);

    child<double, bool, char, string> chil(83.7, false, 'A', "Hello");
    Print(chil);

    child2<string, double, int, bool> chil2("Cat", 32.67, 8, true);
    Print(chil2);
}

