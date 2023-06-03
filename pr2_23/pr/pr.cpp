#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Point {
    double x;
    double y;
};

bool isAcuteAngle(const Point& A, const Point& B, const Point& C) {
    double dotProduct = (B.x - A.x) * (C.x - B.x) + (B.y - A.y) * (C.y - B.y);
    double magnitudeAB = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
    double magnitudeBC = sqrt(pow(C.x - B.x, 2) + pow(C.y - B.y, 2));
    double cosine = dotProduct / (magnitudeAB * magnitudeBC);
    double angle = acos(cosine);
    return angle < 3.14159265358979323846 / 2;
}

bool isConvexQuadrilateral(const Point& A, const Point& B, const Point& C, const Point& D) {
    double crossProduct1 = (B.x - A.x) * (C.y - B.y) - (B.y - A.y) * (C.x - B.x);
    double crossProduct2 = (C.x - B.x) * (D.y - C.y) - (C.y - B.y) * (D.x - C.x);
    double crossProduct3 = (D.x - C.x) * (A.y - D.y) - (D.y - C.y) * (A.x - D.x);
    double crossProduct4 = (A.x - D.x) * (B.y - A.y) - (A.y - D.y) * (B.x - A.x);

    // Проверяем, что все трехугольники имеют одинаковую ориентацию
    bool sameOrientation = (crossProduct1 >= 0 && crossProduct2 >= 0 && crossProduct3 >= 0 && crossProduct4 >= 0) ||
        (crossProduct1 <= 0 && crossProduct2 <= 0 && crossProduct3 <= 0 && crossProduct4 <= 0);

    return sameOrientation;
}

std::vector<std::vector<Point>> findConvexQuadrilaterals(const std::vector<Point>& points) {
    std::vector<std::vector<Point>> result;

    int n = points.size();

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                for (int l = k + 1; l < n; ++l) {
                    if (isConvexQuadrilateral(points[i], points[j], points[k], points[l])) {
                        std::vector<Point> quadrilateral{ points[i], points[j], points[k], points[l] };
                        result.push_back(quadrilateral);
                    }
                }
            }
        }
    }

    return result;
}

int main() {
    std::vector<Point> points{ {0.0, 0.0}, {1.0, 1.0}, {-1.0, 1.0}, {2.0, 0.0}, {0.0, 2.0}, {2.0, 2.0}, {3.0, 3.0} };
    std::vector<std::vector<Point>> convexQuadrilaterals = findConvexQuadrilaterals(points);

    for (const auto& quadrilateral : convexQuadrilaterals) {
        std::cout << "Convex quadrilateral: ";
        for (const auto& point : quadrilateral) {
            std::cout << "(" << point.x << ", " << point.y << ") ";
        }
        std::cout << "\n";
    }

    return 0;
}