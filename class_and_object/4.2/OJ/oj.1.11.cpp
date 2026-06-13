// oj.1.11.cpp
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

//你提交的代码在这里
class Book{
private:
    char author[40];
    char title[40];
    double price;
public:
    Book():price(0){
        strcpy(author,"NULL");
        strcpy(title,"NULL");
    }
    Book(const char* author,const char* title,double price):price(price){
        strcpy(this->author,author);
        strcpy(this->title,title);
    }
    const char* GetAuthor(){
        return author;
    }
    const char* GetTitle(){
        return title;
    }
    double GetPrice(){
        return price;
    }
    void Set(const char* author,const char* title,double price){
        strcpy(this->author,author);
        strcpy(this->title,title);
        this->price=price;
    }
    void Set(){
        strcpy(author,"J.K.Rowling");
        strcpy(title,"Harry Potter");
        price=29.99;
    }
    void Show(){
        cout<<title<<"，"<<author<<"，"<<price<<endl;
    }
};
int main()
{
    cout<<fixed<<setprecision(2);
    Book b1;
    cout<<"Show object b1:";
    cout<<b1.GetTitle()<<"，"<<b1.GetAuthor()<<"，"<<b1.GetPrice()<<endl;
    char title[40],author[40];
    double price;
    cin>>title>>author>>price;
    Book b2(title,author,price);
    cout<<"Show object b2:";
    cout<<b2.GetTitle()<<"，"<<b2.GetAuthor()<<"，"<<b2.GetPrice()<<endl;
    cin>>title>>author>>price;
    cout<<"Reset and Show object b1:";
    b1.Set(title,author,price);
    b1.Show();
    cout<<"Reset and Show object b2:";
    b2.Set();
    b2.Show();
    return 0;
}