#include <iostream>
using namespace std;

class Interval;  //前向引用声明

class PrintStrategy {
public:
    virtual void doPrint(Interval *val) = 0;  // 纯虚函数
};

class Interval {
public:
    Interval(double p_lower, double p_upper) {
        lowerBound = p_lower;
        upperBound = p_upper;
    }

    void printInterval(PrintStrategy *ptr) {
        ptr->doPrint(this); 
    }

    double getLower() { return lowerBound; }
    double getUpper() { return upperBound; }

private:
    double lowerBound;
    double upperBound;
};

class PrintIntervalsComma : public PrintStrategy {
public:
    void doPrint(Interval *val) {
        cout << "[" << val->getLower() << "," << val->getUpper() << "]" << endl;
    }
};

class PrintIntervalsDots : public PrintStrategy {
public:
    void doPrint(Interval *val) {
        cout << "[" << val->getLower() << "..." << val->getUpper() << "]" << endl;
    }
};

class PrintIntervalsLine : public PrintStrategy {
public:
    void doPrint(Interval *val) {
        cout << "[" << val->getLower() << "-" << val->getUpper() << "]" << endl;
    }
};

enum TYPE { COMMA, DOTS, LINE };  //枚举类型

PrintStrategy* getStrategy(int type) {
    PrintStrategy *st;
    switch(type) {
        case COMMA:
            st = new PrintIntervalsComma();  
            break;
        case DOTS:
            st = new PrintIntervalsDots();   
            break;
        case LINE:
            st = new PrintIntervalsLine();   
            break;
    }
    return st;
}

int main() {
    Interval a(1.7, 2.1);

    a.printInterval(getStrategy(COMMA));   
    a.printInterval(getStrategy(DOTS));    
    a.printInterval(getStrategy(LINE));   

    return 0;
}
