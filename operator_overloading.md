```cpp
#include <iostream>

struct Point {
    float x;
    float y;
//// +
    Point& operator+(const float n) {
        this->x += n;
        this->y += n;
        return *this;
    }

    friend Point operator+(const float n, const Point& p) {
        return Point{p.x + n, p.y + n};
    }

    friend Point operator+(const Point& p1, const Point& p2) {
        return Point{p1.x + p2.x, p1.y + p2.y};
    }
//// -
    Point& operator-(const float n) {
        this->x -= n;
        this->y -= n;
        return *this;
    }

    friend Point operator-(const float n, const Point& p) {
        return Point{p.x - n, p.y - n};
    }

    friend Point operator-(const Point& p1, const Point& p2) {
        return Point{p1.x - p2.x, p1.y - p2.y};
    }
//// x
    Point& operator*(const float n) {
        this->x *= n;
        this->y *= n;
        return *this;
    }

    friend Point operator*(const float n, const Point& p) {
        return Point{p.x * n, p.y * n};
    }

    friend Point operator*(const Point& p1, const Point& p2) {
        return Point{p1.x * p2.x, p1.y * p2.y};
    }
//// /
    Point& operator/(const float n) {
        this->x /= n;
        this->y /= n;
        return *this;
    }

    friend Point operator/(const float n, const Point& p) {
        return Point{p.x / n, p.y / n};
    }

    friend Point operator/(const Point& p1, const Point& p2) {
        return Point{p1.x / p2.x, p1.y / p2.y};
    }
};

int main() {
    float a = 10;
    float b = 20;
    Point p1;
    Point p2 = {100, 200};
    p1 = (b + p1) + (10 + a) + 100 - p2 - 100;
    std::cout << p1.x << ", " << p1.y << '\n';
}
/* Output
-59.1514, -160
*/
```