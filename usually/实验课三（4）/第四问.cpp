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
    ~Figure() {
        cout << "Figure destructor called\n";
    }
};

class Triangle : public Figure {
public:
    void show_area() {
        cout << "Triangle with height " << x << " and base " << y;
        cout << " has an area of " << x * 0.5 * y << endl;
    }
    ~Triangle() {
        cout << "Triangle destructor called\n";
    }
};

class Square : public Figure {
public:
    void show_area() {
        cout << "Rectangle with dimensions " << x << " and " << y;
        cout << " has an area of " << x * y << endl;
    }
    ~Square() {
        cout << "Square destructor called\n";
    }
};

class Circle : public Figure {
public:
    void show_area() {
        cout << "Circle with radius " << x;
        cout << " has an area of " << 3.14159 * x * x << endl;
    }
    ~Circle() {
        cout << "Circle destructor called\n";
    }
};

int main() {
    Figure *p;
    
    p = new Triangle;
    p->set_dim(10.0, 5.0);
    p->show_area();
    delete p;
    cout << endl;
    
    p = new Square;
    p->set_dim(10.0, 5.0);
    p->show_area();
    delete p;
    cout << endl;
    
    p = new Circle;
    p->set_dim(10.0);
    p->show_area();
    delete p;
    
    return 0;
}