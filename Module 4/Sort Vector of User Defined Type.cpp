#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    int x;
    int y;
};

int main()
{
    vector<Point> points = {{3, 5}, {1, 2}, {4, 1}};

    // Sort points by x value (ascending)
    sort(points.begin(), points.end(), [](const Point &a, const Point &b) { return a.x < b.x; });

    // Print sorted points
    for (auto p : points)
        cout << "(" << p.x << "," << p.y << ") ";

    return 0;
}