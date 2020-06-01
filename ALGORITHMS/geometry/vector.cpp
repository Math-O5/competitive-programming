#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Point {   
    public:         
        int x, y;

    Point(int a, int b) {
        x = a;
        y = b;
    }

    Point operator+(const Point& point) {
        return Point(x + point.x, y + point.y);
    }

    Point operator-(const Point& point) {
        return Point(x - point.x, y - point.y);
    }

    double dot(const Point& point) {
        return x * point.x + y * point.y;
    }

    double cross(const Point& point) {
        return x * point.y - y * point.x;
    }

    double distance(const Point& point) {
        return sqrt( (x - point.x) * (x - point.x) + (y - point.y)*(y - point.y) );
    }

    double magnitude() {
        return sqrt(x * x + y * y);
    }

    Point normalize() {
		double magnitudeValue = magnitude();
		return Point(x / magnitudeValue, y / magnitudeValue);
	}

    Point scale(int ammount) {
		return Point(x * ammount, y * ammount);
	}

};

