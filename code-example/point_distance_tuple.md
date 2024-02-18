#include <iostream>
#include <cmath>
#include <tuple>

struct Point {
    int x = 0; 
    int y = 0;
};

float distance(const std::tuple<Point, Point>& line) {
    return sqrt(pow(std::get<0>(line).x - std::get<1>(line).x, 2) +
                pow(std::get<0>(line).y - std::get<1>(line).y, 2));
}

int main() {
    Point p1{10, 20};
    Point p2{40, 50};
    auto line = std::tie(p1, p2);
    float d = distance(line);
    std::cout << d << '\n'; // 42.4264
}