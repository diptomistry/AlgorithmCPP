#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

struct Point {
    double x, y;
};

// Compare function for sorting points based on their x-coordinates
bool compareX(Point p1, Point p2) {
    return p1.x < p2.x;
}

// Compare function for sorting points based on their y-coordinates
bool compareY(Point p1, Point p2) {
    return p1.y < p2.y;
}

// Calculate the Euclidean distance between two points
double calculateDistance(Point p1, Point p2) {
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

// Find the closest pair of points in the strip and update the minimum distance
double stripClosest(vector<Point> &strip, double d) {
    double minDistance = d;

    // Sort points in the strip by their y-coordinates
    sort(strip.begin(), strip.end(), compareY);

    // Check for pairs with smaller distances in the strip
    for (size_t i = 0; i < strip.size(); ++i) {
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDistance; ++j) {
            double dist = calculateDistance(strip[i], strip[j]);
            if (dist < minDistance) {
                minDistance = dist;
            }
        }
    }

    return minDistance;
}

// Find the closest pair of points using a divide and conquer algorithm
double closestPair(vector<Point> &points) {
    size_t n = points.size();

    // If there are 2 or 3 points, compute the minimum distance directly
    if (n <= 3) {
        double minDistance = numeric_limits<double>::max();
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = i + 1; j < n; ++j) {
                double dist = calculateDistance(points[i], points[j]);
                if (dist < minDistance) {
                    minDistance = dist;
                }
            }
        }
        return minDistance;
    }

    // Sort the points by their x-coordinates
    sort(points.begin(), points.end(), compareX);

    // Divide the points into two halves
    size_t mid = n / 2;
    Point midPoint = points[mid];

    vector<Point> leftPoints(points.begin(), points.begin() + mid);
    vector<Point> rightPoints(points.begin() + mid, points.end());

    // Recursively find the closest pair in each half
    double leftDistance = closestPair(leftPoints);
    double rightDistance = closestPair(rightPoints);

    // Find the minimum distance between the two halves
    double minDistance = min(leftDistance, rightDistance);

    // Create a strip containing points within the minimum distance of the dividing line
    vector<Point> strip;
    for (size_t i = 0; i < n; ++i) {
        if (abs(points[i].x - midPoint.x) < minDistance) {
            strip.push_back(points[i]);
        }
    }

    // Find the closest pair in the strip and update the minimum distance
    double stripDistance = stripClosest(strip, minDistance);
    return min(minDistance, stripDistance);
}

int main() {
    vector<Point> points = {
        {2, 3},
        {12, 30},
        {40, 50},
        {5, 1},
        {12, 10},
        {3, 4}
    };

    double minDistance = closestPair(points);
    cout << "The closest pair of points has a distance of: " << minDistance << endl;

    return 0;
}
