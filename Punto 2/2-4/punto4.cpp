#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// Clase base
class Shape {
protected:
    string color;
public:
    Shape(const string& color = "undefined") : color(color) {}

    virtual double area() const = 0; // Función virtual pura para el área
    virtual double perimeter() const = 0; // Función virtual pura para el perímetro

    virtual void display() const {
        cout << "Color: " << color << "\n";
    }

    void setColor(const string& newColor) {
        color = newColor;
    }

    string getColor() const {
        return color;
    }
};

// Clase derivada para Rectángulo
class Rectangle : public Shape {
protected:
    double width, height;
public:
    Rectangle(double w, double h, const string& color = "undefined")
        : Shape(color), width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    double perimeter() const override {
        return 2 * (width + height);
    }

    void display() const override {
        Shape::display();
        cout << "Rectangle width: " << width << ", height: " << height << "\n";
        cout << "Area: " << area() << "\n";
        cout << "Perimeter: " << perimeter() << "\n";
    }
};

// Clase derivada para Cuadrado (caso especial de Rectángulo)
class Square : public Rectangle {
public:
    Square(double side, const string& color = "undefined")
        : Rectangle(side, side, color) {}

    void display() const override {
        Shape::display();
        cout << "Square side: " << width << "\n";
        cout << "Area: " << area() << "\n";
        cout << "Perimeter: " << perimeter() << "\n";
    }
};

// Clase derivada para Triángulo
class Triangle : public Shape {
private:
    double a, b, c;
public:
    Triangle(double side1, double side2, double side3, const string& color = "undefined")
        : Shape(color), a(side1), b(side2), c(side3) {}

    double area() const override {
        double s = perimeter() / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c)); // Fórmula de Herón
    }

    double perimeter() const override {
        return a + b + c;
    }

    void display() const override {
        Shape::display();
        cout << "Triangle sides: " << a << ", " << b << ", " << c << "\n";
        cout << "Area: " << area() << "\n";
        cout << "Perimeter: " << perimeter() << "\n";
    }
};

int main() {
    Rectangle rect(5.0, 3.0, "red");
    Square sq(4.0, "blue");
    Triangle tri(3.0, 4.0, 5.0, "green");

    cout << "Rectangle:\n";
    rect.display();

    cout << "\nSquare:\n";
    sq.display();

    cout << "\nTriangle:\n";
    tri.display();

    return 0;
}
