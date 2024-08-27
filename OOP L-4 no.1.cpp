#include <iostream>

using namespace std;

// Base class Polygon
class Polygon {
protected:
    double width;
    double height;

public:
    // Constructor to initialize width and height
    Polygon(double w, double h) : width(w), height(h) {}

    // Virtual function to calculate area
    virtual double area() = 0; 
};

// Derived class Rectangle
class Rectangle : public Polygon {
public:
    // Constructor to initialize width and height using Polygon constructor
    Rectangle(double w, double h) : Polygon(w, h) {}

    // Function to calculate area of Rectangle
    double area() override {
        return width * height;
    }
};

// Derived class Triangle
class Triangle : public Polygon {
public:
    // Constructor to initialize width and height using Polygon constructor
    Triangle(double w, double h) : Polygon(w, h) {}

    // Function to calculate area of Triangle
    double area() override {
        return 0.5 * width * height;
    }
};

int main() {
    double rectWidth, rectHeight, triWidth, triHeight;

    // Input for Rectangle
    cout << "Enter the width of the rectangle: ";
    cin >> rectWidth;
    cout << "Enter the height of the rectangle: ";
    cin >> rectHeight;

    // Input for Triangle
    cout << "Enter the base of the triangle: ";
    cin >> triWidth;
    cout << "Enter the height of the triangle: ";
    cin >> triHeight;

    // Creating objects of Rectangle and Triangle
    Rectangle rect(rectWidth, rectHeight);
    Triangle tri(triWidth, triHeight);

    // Displaying the area
    cout << "Area of Rectangle: " << rect.area() << endl;
    cout << "Area of Triangle: " << tri.area() << endl;

    return 0;
}

