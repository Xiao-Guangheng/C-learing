

#include <iostream>
using namespace std;

int main(){
    int *i;
    cout<<&i<<endl;
    int a,b;
    int *pa,*pb=&b;
    pa=&a;

    //VOID类型指针的使用

    void *pv;
   // void sdhfjk;  //错误，不能定义void类型的变量

    //void指针在指针指向数据不明确的时候使用
    // 一般指针的运算是跟数组联系起来的，因为只有数组才有连续的内存空间，指针才可以进行加减运算
    
    int *p;
    p=0; //指针初始化为0，表示指针不指向任何有效的内存地址
    //所以说p是地址，*是解引用操作符，*p表示指针p所指向的内存地址中的值

    int *y=NULL; //NULL是一个宏定义，表示空指针，等价于0



        //用指针处理数组元素
    //指针的加减运算使得指针特别适合处理储存在一段连续空间的同类数据
    int arr[5]={1,2,3,4,5};
    //数组名arr就是数组的首地址，第一个元素的地址，即arr和&arr[0]是等价的
    //*（arr+1)=arr[1]

    //标准库函数begin ,end
    int *p1=begin(arr);
    int *p2=end(arr);

    while(p1!=p2 && *p1>=0){
        ++p1;
    }

    int line1[]={1,2,3,4,5};
    int line2[]={1,2,3,4,5};
    int line3[]={1,2,3,4,5};

    int *pline[]={line1,line2,line3}; //二维数组的指针表示法
    for (int i=0;i<3;i++){
        for(int j=0;j<5;j++){
            cout<<pline[i][j]<<" ";
        }
        cout<<endl;
    }

    //指针作为函数参数

    //当不同函数之间需要传送大量数据的时候，如果数据是存放在一段连续的空间内，就可以只传递数据的起始地址，而不必传递整个数据，这样可以节省大量的时间和空间，提高效率

    void splitfloat(float x,int *intpart,float *fracpart){
        *intpart=(int)x;
        *fracpart=x-*intpart;
    }

    for(int i=0;i<5;i++){
        float x;
        cout<<"请输入一个浮点数：";
        cin>>x;
        int intpart;
        float fracpart;
        splitfloat(x,&intpart,&fracpart);
        cout<<"整数部分为："<<intpart<<endl;
        cout<<"小数部分为："<<fracpart<<endl;
    }  //利用指针可以改变变量的值，函数可以返回多个值，改变了值就相当于返回了多个值

    
}