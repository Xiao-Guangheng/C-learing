class Figure {
protected:
    double x, y;
public:
    void set_dim(double i, double j = 0) {
        x = i; 
        y = j; 
    }
    void show_area() {  // 去掉 virtual
        cout << "No area computation defined for this class.\n";
    }
};