#include "vector.hpp"
#include "ostream"

Vector::Vector(int x, int y) : x(x), y(y) {}

bool Vector::operator==(const Vector &rhs) const {
  Vector lhs_tmp = *this;
  Vector rhs_tmp = rhs;

  return (lhs_tmp.x == rhs_tmp.x) && (lhs_tmp.y == rhs_tmp.y);
}

Vector Vector::operator+(const Vector &rhs) const {
  Vector temp = *this;
  temp += rhs;
  return temp;
}

Vector &Vector::operator+=(const Vector &rhs) {
  x += rhs.x;
  y += rhs.y;
  return *this;
}

Vector Vector::operator*(const int rhs) const {
  Vector temp = *this;
  temp *= rhs;
  return temp;
}

Vector &Vector::operator*=(const int &rhs) {
  x *= rhs;
  y *= rhs;
  return *this;
}

std::ostream &operator<<(std::ostream &lhs, const Vector &rhs) {
  return lhs << '[' << rhs.x << ',' << rhs.y << ']';
}

int Vector::getX() const { return x; }
int Vector::getY() const { return y; }

void Vector::setX(int newX) { x = newX; }
void Vector::setY(int newY) { y = newY; }

// outside the class
Vector operator+(const Vector &rhs) { return rhs; }

Vector operator*(const int lhs, const Vector &rhs) {
  Vector temp = rhs;
  temp.setX(temp.getX() * lhs);
  temp.setY(temp.getY() * lhs);
  return temp;
}
