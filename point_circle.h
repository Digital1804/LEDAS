#ifndef _POINT_H_
#define _POINT_H_

#include <cmath>
// Структура для представления точки в 3D пространстве
struct Point {
    double x, y, z;

    /** @brief Вычитание координат второй точки из первой
     *  @param other вторая точка
     *  @return Разность координат двух точек
     */
    Point operator-(const Point& other) const {
        return {x - other.x, y - other.y, z - other.z};
    }

    /** @brief Сумма координат двух точек
     *  @param other вторая точка
     *  @return Сумма координат двух точек
     */
    Point operator+(const Point& other) const {
        return {x + other.x, y + other.y, z + other.z};
    }

    /** @brief Умножение координат точки на число
     *  @param scalar число
     *  @return Умножение координат точки на число
     */
    Point operator*(double scalar) const {
        return {x * scalar, y * scalar, z * scalar};
    }
    
    /** @brief Скалярное произведение двух точек
     *  @param other вторая точка
     *  @return Скалярное произведение двух точек
     */
    double operator*(const Point& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    /** @brief Нахождение длины вектора
     *  @return Длина вектора
     */
    double norm() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    /** @brief Нормализация точки
     *  @return Нормализованная точка
     */
    Point normalized() const {
        double n = norm();
        return {x / n, y / n, z / n};
    }
};

// Структура для представления окружности в 3D пространстве
struct Circle {
    Point center;
    double radius;
    Point normal;
};

// Нахождение ближайшей точки на круге к точке A
Point findClosestPointOnCircle(const Point& A, const Circle& circle);
#endif