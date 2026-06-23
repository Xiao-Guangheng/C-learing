第五问
class Figure {
protected:
    double x, y;
public:
    void set_dim(double i, double j = 0) {
        x = i; 
        y = j; 
    }
    virtual void show_area() {
        cout << "No area computation defined for this class.\n";
    }
    virtual ~Figure() {  // 虚析构函数
        cout << "Figure destructor called\n";
    }
};

// 其他类不变...