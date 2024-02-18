#include <iostream>
#include <vector>
#include <climits>
 
template<typename T>
int findMaximum(std::vector<T> const &vec) {
    int max = INT_MIN;
    for (const T &i: vec) {
        if (max < i) {
             max = i;
        }
    }
    return max;
}
 
template<typename T>
int findMinimum(std::vector<T> const &vec) {
    int min = INT_MAX;
    for (const T &i: vec) {
        if (min > i) {
             min = i;
        }
    }
    return min;
}
 
int main()
{
    std::vector<int> v = {2, 1, 3, 6, 7, 9, 8};
 
    int min = findMinimum(v);
    int max = findMaximum(v);
 
    std::cout << min << ", " << max << std::endl;        // 1, 9
 
    return 0;
}