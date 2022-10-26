#pragma once
#include <cmath>
#include <algorithm>
#include <iostream>

struct Point
{
    double x, y;
    Point();
    Point(double val);
    Point(double x, double y);
    Point& operator += (const Point& other);
    Point& operator -= (const Point& other);
    Point operator + (const Point& other);
    Point operator - (const Point& other);
    void operator = (const Point& other);
    void Transfer(const double& dx, const double& dy);
};

//Функция для расстояния между двумя точками
double getDistanceBetween(Point& first, Point& second);

class Vector {
private:
    Point begin, end;
public:
    Vector();
    Vector(Point begin, Point end);
    Vector(Point point);
    Point getBegin();
    Point getEnd();
    void setBegin(Point &point);
    void setEnd(Point& point);
    void setBeginEnd(Point& begin, Point& end);
    void Transfer(Point &point);
    void Transfer(double& dx, double& dy);
    void SwapDirection();
    double getTan();
    const double getLength();
    double getProjectionOx();
    double getProjectionOy();
    void scaling(double scale);
    Vector Normalize();
    double operator * (const Vector& other);
    Vector operator + (const Vector& other);
    bool isColenear(const Vector& other);
private:
    bool Compare(const Vector& other);
public: 
    bool operator == (const Vector& other);
    bool operator != (const Vector& other); 
    friend std::ostream& operator << (std::ostream& os, const Vector& vector);
    friend std::istream& operator >> (std::istream& is, Vector& vector);
};
