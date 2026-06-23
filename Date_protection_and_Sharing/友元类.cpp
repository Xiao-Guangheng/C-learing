//友元类

//若A为B的友元类，则A的所有成员函数都是B的友元函数，都可以访问B的私有和保护成员。



// class{
//     ……
//     friend class A;  //A是B的友元类
//     ……
// };

//友元关系不能传递，友元关系是单向的

class A{
public:
    void display(){cout<<x<endl;}
    int getX() {return x;}
    friend class B;
private:
    int x;
};

class B{
public:
    void set(int i);
    void display();
private:
    A a;
};

void B::set(int i){
    a.x=i;  //B 是A的友元，B的成员函数可以访问A的私有成员
}