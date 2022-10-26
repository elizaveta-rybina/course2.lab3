#include "Vector.h"

Point::Point() : x(0), y(0) {}

Point::Point(double val) : x(val), y(val) {}

Point::Point(double x, double y) : x(x), y(y) {}

Point& Point::operator+=(const Point& other)
{
	x += other.x;
	y += other.y;
	return *this;
}

Point& Point::operator-=(const Point& other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}

Point Point::operator+(const Point& other)
{
	return Point(x + other.x, y + other.y);
}

Point Point::operator-(const Point& other)
{
	return Point(x - other.x, y - other.y);
}

void Point::operator=(const Point& other)
{
	x = other.x;
	y = other.y;
}

void Point::Transfer(const double& dx, const double& dy)
{
	x += dx;
	y += dy;
}

double getDistanceBetween(Point& first, Point& second)
{
	return sqrt((second.x - first.x)*(second.x - first.x) + (second.y - first.y)* (second.y - first.y));
}

std::ostream& operator<<(std::ostream& os, const Vector& vector)
{
	Vector vector2 = Vector(vector).Normalize();
	os << "{" << vector2.end.x << ", " << vector2.end.y << "}";
	return os;
}

std::istream& operator>>(std::istream& is, Vector& vector)
{
	vector.begin.x = 0;
	vector.begin.y = 0;
	is >> vector.end.x >> vector.end.y;
	return is;
}

Vector::Vector() : begin(), end() {}

Vector::Vector(Point begin, Point end) :
	begin(begin),
	end(end)
{}

Vector::Vector(Point point) :
	begin(Point()),
	end(point)
{}

Point Vector::getBegin()
{
	return begin;
}

Point Vector::getEnd()
{
	return end;
}

void Vector::setBegin(Point &point)
{
	begin = point;
}

void Vector::setEnd(Point& point)
{
	end = point;
}

void Vector::setBeginEnd(Point& begin, Point& end)
{
	begin = begin;
	end = end;
}

void Vector::Transfer(Point &point)
{
	begin += point;
	end += point;
}

void Vector::Transfer(double& dx, double& dy)
{
	begin.Transfer(dx, dy);
	end.Transfer(dx, dy);
}

void Vector::SwapDirection()
{
	std::swap(begin, end);
}

double Vector::getTan()
{
	return (end.y - begin.y)/(end.x - begin.y);
}

const double Vector::getLength() 
{
	return getDistanceBetween(begin, end);
}

double Vector::getProjectionOx()
{
	return end.x - begin.x;
}

double Vector::getProjectionOy()
{
	return end.y - begin.y;
}

Vector Vector::Normalize()
{
	return Vector(Point(end.x - begin.x, end.y - begin.y));
}

double Vector::operator*(const Vector& other)
{
	Vector vector1 = Vector(*this).Normalize();
	Vector vector2 = Vector(other).Normalize();
	return vector1.end.x * vector2.end.x + vector1.end.y * vector2.end.y;
}

Vector Vector::operator+(const Vector& other)
{
	return Vector(begin + other.begin, end + other.end);
}

bool Vector::isColenear(const Vector& other)
{
	Vector vector1 = Vector(*this).Normalize();
	Vector vector2 = Vector(other).Normalize();
	return vector1.end.x * vector2.end.y == vector2.end.x * vector1.end.y;
}

bool Vector::Compare(const Vector& other)
{
	if (this == &other) {
		return true;
	}
	Vector vector2(other);
	if (!isColenear(other)) {
		return false;
	}
	if ((*this * other > 0) && (getLength() == vector2.getLength())) {
		return true;
	}
	return false;
}

bool Vector::operator==(const Vector& other)
{
	return Compare(other);
}

bool Vector::operator!=(const Vector& other)
{
	return !Compare(other);
}

