#ifndef    VECTOR2_HXX_INCLUDED
# define   VECTOR2_HXX_INCLUDED

# include <cmath>
# include "Vector2.hh"
# include "ComparisonUtils.hh"

namespace utils {

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>::Vector2(const CoordinateType& x,
                                   const CoordinateType& y) noexcept:
    m_x(x),
    m_y(y)
  {}

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>::Vector2(const Vector2<CoordinateType>& other) noexcept:
    m_x(other.m_x),
    m_y(other.m_y)
  {}

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>&
  Vector2<CoordinateType>::operator=(const Vector2<CoordinateType>& other) noexcept {
    m_x = other.x();
    m_y = other.y();

    return *this;
  }

  template <typename CoordinateType>
  inline
  CoordinateType&
  Vector2<CoordinateType>::x() noexcept {
    return m_x;
  }

  template <typename CoordinateType>
  inline
  const CoordinateType&
  Vector2<CoordinateType>::x() const noexcept {
    return m_x;
  }

  template <typename CoordinateType>
  inline
  void
  Vector2<CoordinateType>::setX(const CoordinateType& x) noexcept {
    m_x = x;
  }

  template <typename CoordinateType>
  inline
  CoordinateType&
  Vector2<CoordinateType>::y() noexcept {
    return m_y;
  }

  template <typename CoordinateType>
  inline
  const CoordinateType&
  Vector2<CoordinateType>::y() const noexcept {
    return m_y;
  }

  template <typename CoordinateType>
  inline
  void
  Vector2<CoordinateType>::setY(const CoordinateType& y) noexcept {
    m_y = y;
  }

  template <typename CoordinateType>
  inline
  CoordinateType
  Vector2<CoordinateType>::length() const noexcept {
    return std::sqrt(lengthSquared());
  }

  template <typename CoordinateType>
  inline
  CoordinateType
  Vector2<CoordinateType>::lengthSquared() const noexcept {
    return m_x * m_x + m_y * m_y;
  }

  template <typename CoordinateType>
  inline
  CoordinateType
  Vector2<CoordinateType>::normalize() noexcept {
    const CoordinateType thisLength = length();
    if (!fuzzyEqual(thisLength, CoordinateType())) {
      m_x /= thisLength;
      m_y /= thisLength;
    }
    return thisLength;
  }

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>&
  Vector2<CoordinateType>::normalized() noexcept {
    normalize();
    return *this;
  }

  template <typename CoordinateType>
  inline
  CoordinateType
  Vector2<CoordinateType>::operator*(const Vector2<CoordinateType>& other) const noexcept {
    return m_x * other.m_x + m_y * other.m_y;
  }

  template <typename CoordinateType>
  inline
  bool
  Vector2<CoordinateType>::operator==(const Vector2<CoordinateType>& other) const noexcept {
    return (
      fuzzyEqual(m_x, other.m_x) &&
      fuzzyEqual(m_y, other.m_y)
    );
  }

  template <typename CoordinateType>
  inline
  bool
  Vector2<CoordinateType>::operator!=(const Vector2<CoordinateType>& other) const noexcept {
    return !operator==(other);
  }

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>
  Vector2<CoordinateType>::operator+(const Vector2<CoordinateType>& other) const noexcept {
    Vector2<CoordinateType> sum(*this);
    sum += other;
    return sum;
  }

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>&
  Vector2<CoordinateType>::operator+=(const Vector2<CoordinateType>& other) noexcept {
    m_x += other.m_x;
    m_y += other.m_y;
    return (*this);
  }

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>
  Vector2<CoordinateType>::operator-(const Vector2<CoordinateType>& other) const noexcept {
    Vector2<CoordinateType> diff(*this);
    diff -= other;
    return diff;
  }

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>
  Vector2<CoordinateType>::operator-() const noexcept {
      Vector2<CoordinateType> minus;
      minus -= (*this);
      return minus;
  }

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>&
  Vector2<CoordinateType>::operator-=(const Vector2<CoordinateType>& other) noexcept {
    m_x -= other.m_x;
    m_y -= other.m_y;
    return (*this);
  }

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>
  Vector2<CoordinateType>::operator*(const CoordinateType& scale) const noexcept {
    Vector2<CoordinateType> multiply(*this);
    multiply.m_x *= scale;
    multiply.m_y *= scale;
    return multiply;
  }

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>&
  Vector2<CoordinateType>::operator*=(const CoordinateType& scale) noexcept {
      m_x *= scale;
      m_y *= scale;
      return *this;
  }

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>
  Vector2<CoordinateType>::operator/(const CoordinateType& scale) const noexcept {
    Vector2<CoordinateType> divide(*this);
    divide.m_x /= scale;
    divide.m_y /= scale;
    return divide;
  }

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>&
  Vector2<CoordinateType>::operator/=(const CoordinateType& scale) noexcept {
    m_x /= scale;
    m_y /= scale;
    return *this;
  }

  template <typename CoordinateType>
  inline
  CoordinateType
  Vector2<CoordinateType>::operator^(const Vector2<CoordinateType>& other) const noexcept {
      return m_x * other.m_y - m_y * other.m_x;
  }

  template <typename CoordinateType>
  inline
  std::string
  Vector2<CoordinateType>::toString() const noexcept {
    return std::string("[Vector: ") + std::to_string(x()) + ", " + std::to_string(y()) + "]";
  }

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>
  Vector2<CoordinateType>::max() noexcept {
    return Vector2(
      std::numeric_limits<CoordinateType>::max(),
      std::numeric_limits<CoordinateType>::max()
    );
  }

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>
  Vector2<CoordinateType>::min() noexcept {
    return Vector2(
      std::numeric_limits<CoordinateType>::lowest(),
      std::numeric_limits<CoordinateType>::lowest()
    );
  }

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>
  Vector2<CoordinateType>::minmax() noexcept {
    return Vector2(
      std::numeric_limits<CoordinateType>::lowest(),
      std::numeric_limits<CoordinateType>::max()
    );
  }

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>
  Vector2<CoordinateType>::maxmin() noexcept {
    return Vector2(
      std::numeric_limits<CoordinateType>::max(),
      std::numeric_limits<CoordinateType>::lowest()
    );
  }

}

template <typename CoordinateType>
inline
std::ostream&
operator<<(std::ostream& out, const utils::Vector2<CoordinateType>& vec) noexcept {
  out << vec.toString();
  return out;
}

template <typename CoordinateType>
inline
std::ostream&
operator<<(const utils::Vector2<CoordinateType>& vec, std::ostream& out) noexcept {
  return operator<<(out, vec);
}

template <typename CoordinateType>
inline
utils::Vector2<CoordinateType>
operator*(const CoordinateType& scale, const utils::Vector2<CoordinateType>& vector) noexcept {
  return vector * scale;
}

#endif    /* VECTOR2_HXX_INCLUDED */
