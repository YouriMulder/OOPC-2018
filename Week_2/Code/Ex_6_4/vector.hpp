#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "ostream"

/// @file

/// \brief
/// Vector ADT
/// \details
/// This is a ADT that stores two integers representing a vector.
/// The x variable is the x coordinate of the vector.
/// The y variable is the y coordiante of the vector.
class Vector {
private:
  int x;
  int y;

public:
  /// \brief
  /// constructor from default and explicit values
  /// \details
  /// This constructor initializes a vector its x and y coordinates.
  /// the default value is 0 for both parameters.
  Vector(int x = 0, int y = 0);

  /// \brief
  /// Compare two vectors its x and y value
  /// \details
  /// This oprator== test wheter the coordinates of the vectors are the same.
  /// It only returns true when both vectors have the same x and y coordinates
  bool operator==(const Vector &rhs) const;

  /// \brief
  /// Add a vector by another vector
  /// \details
  /// this operator+ adds a vector by another vector
  /// This method returns a new vector containing the sumed coordinates.
  /// The sum of the x coordinates is the new vector its x coordinate.
  /// The sum of the y coordinates is the new vector its y coordinate.
  Vector operator+(const Vector &rhs) const;

  /// \brief
  /// Add vector into another vector
  /// \details
  /// This operator+= adds a vector into another vector.
  /// The sum of the vectors its coordinates get stored in the left vector.
  /// This method changes the values of the left vector!
  Vector &operator+=(const Vector &rhs);

  /// \brief
  /// Multiply a vector by another vector
  /// \details
  /// This operator* multiplies a vector by another vector.
  /// This method returns a new vector containing the multiplied coordinates.
  /// The multiplication of the x coordinates is the new vector its x coordinate
  /// The multiplication of the y coordinates is the new vector its y coordinate
  Vector operator*(const int rhs) const;

  /// \brief
  /// Multiply vector into another vector
  /// \details
  /// This operator*= multipies a vector into another vector.
  /// The multiplication of the vectors its coordinates get stored in the left.
  /// vector. This method changes the values of the left vector!
  Vector &operator*=(const int &rhs);

  /// \brief
  /// Write coordinates to ostream
  /// \details
  /// This operator<< writes the coordinates to ostream.
  /// This operator is mostly used for stringstreaming and printing.
  friend std::ostream &operator<<(std::ostream &lhs, const Vector &rhs);

  /// \brief
  /// Get x coordinate of a vector
  /// /details
  /// This is a getter.
  /// this method retuns the x coordinate of a vector
  int getX() const;

  /// \brief
  /// Get y coordinate of a vector
  /// /details
  /// This is a getter.
  /// This method retuns the y coordinate of a vector
  int getY() const;

  /// \brief
  /// Set x coordinate of a vector
  /// /details
  /// This is a setter.
  /// This method sets the x coordinate of a vector
  /// The given integer will be the new x coordinate of the vector
  void setX(int newX);

  /// \brief
  /// Set y coordinate of a vector
  /// /details
  /// This is a setter.
  /// This method sets the y coordinate of a vector
  /// The given integer will be the new y coordinate of the vector
  void setY(int newY);
};

/// \brief
/// Add a vector (returns the same vector)
/// \details
/// This operator+ adds a vector.
/// This method returns the vector on the right of the + operator.
Vector operator+(const Vector &rhs);

/// \brief
/// multiply a integer by a vector
/// \details
/// This operator* multiplies a integer by a vector.
/// The method returns a new vector.
/// The returned vector its x is the multiplication of the x coordinate and the
/// given integer and the y coordinate is the multiplication of the y coordinate
/// and the given integer.
Vector operator*(const int lhs, const Vector &rhs);
#endif // VECTOR_HPP
