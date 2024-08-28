#include <iostream>
#include "point_circle.h"

int main() {
    Point A = {1.0, 2.0, 3.0}; // Заданная точка A
    Circle circle = {{0.0, 0.0, 0.0}, 5.0, {0.0, 0.0, 1.0}}; // Заданная окружность

    Point closestPoint = findClosestPointOnCircle(A, circle);

    std::cout << "Ближайшая точка: (" << closestPoint.x << ", " << closestPoint.y << ", " << closestPoint.z << ")\n";

    return 0;
}
