#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

// class Point {   
//     public:         
//         long long int x, y;

//     Point(long long int a, long long int b) {
//         x = a;
//         y = b;
//     }

//     Point operator+(const Point& point) const {
//         return Point(x + point.x, y + point.y);
//     }

//     Point operator-(const Point& point) const {
//         return Point(x - point.x, y - point.y);
//     }

//     double dot(const Point& point) const {
//         return x * point.x + y * point.y;
//     }

//     double cross(const Point& point) const {
//         return x * point.y - y * point.x;
//     }

//     double distance(const Point& point) const {
//         return sqrt( (x - point.x) * (x - point.x) + (y - point.y)*(y - point.y) );
//     }

//     double magnitude() const {
//         return sqrt(x * x + y * y);
//     }

//     Point normalize() const {
// 		double magnitudeValue = magnitude();
// 		return Point(x / magnitudeValue, y / magnitudeValue);
// 	}

//     Point scale(int ammount) const {
// 		return Point(x * ammount, y * ammount);
// 	}
// };

struct Point {
    long long int x, y;

    Point(long long int x, long long int y) {
        this->x = x;
        this->y = y;
    }

    Point operator+(const Point& b) const {
        return Point(x + b.x, y + b.y);
    }

    Point operator-(const Point& b) const {
        return Point(x - b.x, y - b.y);
    }

    // Dot: a * b = |a| * |b| * cos(0)
    // cos(0) = 0, 0° or 180°
    // cos(0) = 1, 90°
    long long int operator*(const Point& b) const {
        return x*b.x + y*b.y;
    }

    long long int operator^(const Point& b) const {
        return x*b.y - y*b.x;
    }

    long long int magnitude() {
        return sqrt(x*x + y*y);
    }
};

double distancePoints(const Point& a, const Point& b) {
    return (b-a).magnitude();
}

/* Point c to line AB(point a and b)

   The vectorial product give the area of parallel
*/

double distancPointLine(const Point& a, const Point &b, const Point& c) {
    if((b-a)*(c-a) >= 0 && (a-b)*(c-b) >= 0) {
        long long int area = abs((b-a)^(c-a));
        return area/(b-a).magnitude();
    }
    return min((c-a).magnitude(), (b-c).magnitude());
}

#include <vector>

bool isInside(const vector<Point>& poli, const Point& p) {
    bool ans = true;
    int n = poli.size();
    for(int i = 0; i < n; ++i) {
        Point u = poli[(i+1) % n] - poli[i];
        Point v = p - poli[i];

        if(((u^v) < 0)) {
            ans = false; 
            break;
        }
    }
    return ans;
}

bool isInsideTriangule(const Point& a, const Point& b, const Point& c, const Point& p) {
    if((((b-a)^(p-a)) < 0) &&
        (((c-b)^(p-b)) < 0) &&
        ((a-c)^(p-a)) < 0) {
        return false;
    } else return true;
}

// nlogn
bool isInsideSearch(const vector<Point>& poli, const Point& p) {
    int ini = 1, fim = poli.size()-2;
    int i = 1;
    while(ini <= fim) {
        int mid = (ini+fim)/2;
        Point u = poli[mid]-poli[0];
        Point v = p - poli[0];

        if((u^v) >= 0 ) {
            i = mid;
            ini = mid + 1;
        } else {
            fim = mid - 1;
        }
    }

    return isInsideTriangule(poli[i+1], poli[i], poli[0], p);
}

double area_poly(vector<Point>& poli) {
    double area = 0.0;
    for(int i = 2; i < poli.size(); ++i) {
        area += ((poli[i]-poli[0])^(poli[i-1]^poli[0]))/2;
    }
    return abs(area);
}

int axis(Point p) {
    if(p.y > 0) return 1;
    if(p.y < 0) return 2;
    if(p.x >= 0) return 1;
    return 2;
}

bool cmp(Point u, Point v) {
    if(axis(u) == axis(v)) {
        return (u^v) > 0;
    }
    return axis(u) < axis(v);
}

double intersection_lines(const Point& a, const Point& b, const Point& c, const Point& d) {
    Point d_1(b-a);
    Point d_2(d-c);
    return ((c - a)^d_2)/(d_1^d_2);
}

int main() {
    Point a(3, 0);
    Point b(1, 1);
    Point c(1, 1);
    Point d(5, 0);

    vector<Point> t;
    // sort(t.begin(), t.end(), cmp);
    // long long int cross = u ^ v;
    cout << intersection_lines(a, b, c, d) << endl;
}