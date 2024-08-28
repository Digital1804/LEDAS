#include "point_circle.h"

Point findClosestPointOnCircle(const Point& A, const Circle& circle) {
    // Проекция точки A на плоскость P окружности
    Point AP = A - circle.center;
    double distance = AP * circle.normal;       
    Point projectedPoint = A - circle.normal * distance;

    // Вектор от центра окружности до проекции точки
    Point vectorToPoint = projectedPoint - circle.center;

    // Проверка, лежит ли проекция внутри окружности
    if (vectorToPoint.norm() <= circle.radius) {
        return projectedPoint;
    } else {
        // Если проекция вне окружности, найти ближайшую точку на границе окружности
        Point closestPointOnBoundary = circle.center + vectorToPoint.normalized() * circle.radius;
        return closestPointOnBoundary;
    }
}