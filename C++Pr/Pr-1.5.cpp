#include <iostream>
using namespace std;

class Shape {
public:
    virtual double calculateArea() = 0;
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) {
        radius = r;
    }

    double calculateArea() override {
        return 3.1416 * radius * radius;
    }

    void draw() override {
        cout << "Drawing Circle with radius " << radius << endl;
    }
};

class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }

    double calculateArea() override {
        return length * width;
    }

    void draw() override {
        cout << "Drawing Rectangle (" << length 
             << " x " << width << ")" << endl;
    }
};

int main() {

    int n, choice;
    cout << "Enter number of shapes: ";
    cin >> n;

    Shape* shapes[n];

    for(int i = 0; i < n; i++) {

        cout <<endl<< "Choose Shape " << i+1 << endl;
        cout << "1. Circle"<<endl;
        cout << "2. Rectangle"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {
            double r;
            cout << "Enter radius: ";
            cin >> r;
            shapes[i] = new Circle(r);
        }
        else if(choice == 2) {
            double l, w;
            cout << "Enter length: ";
            cin >> l;
            cout << "Enter width: ";
            cin >> w;
            shapes[i] = new Rectangle(l, w);
        }
        else {
            cout << "Invalid choice! Creating default Circle (radius 1)"<<endl;
            shapes[i] = new Circle(1);
        }
    }

    cout << "\n--- Shape Details ---\n";

    for(int i = 0; i < n; i++) {
        shapes[i]->draw();
        cout << "Area: " << shapes[i]->calculateArea() << endl;
        cout << "-------------------"<<endl;
    }

    for(int i = 0; i < n; i++) {
        delete shapes[i];
    }

    return 0;
}

//output
//
//Enter number of shapes: 2
//
//Choose Shape 1
//1. Circle
//2. Rectangle
//Enter choice: 1
//Enter radius: 2
//
//Choose Shape 2
//1. Circle
//2. Rectangle
//Enter choice: 2
//Enter length: 1.5
//Enter width: 1.2
//
//--- Shape Details ---
//Drawing Circle with radius 2
//Area: 12.5664
//-------------------
//Drawing Rectangle (1.5 x 1.2)
//Area: 1.8