#ifndef    VECTOR_3_HXX
# define   VECTOR_3_HXX

# include <cmath>
# include "Vector3.hh"
# include <maths_utils/ComparisonUtils.hh>

namespace utils {

  template <typename CoordinateType>
  inline
  Vector3<CoordinateType>::Vector3(const CoordinateType& x,
                                   const CoordinateType& y,
                                   const CoordinateType& z) noexcept:
    m_x(x),
    m_y(y),
    m_z(z)
  {}

  template <typename CoordinateType>
  inline
  Vector3<CoordinateType>::Vector3(const Vector3<CoordinateType>& other) noexcept:
    m_x(other.m_x),
    m_y(other.m_y),
    m_z(other.m_z)
  {}

  template <typename CoordinateType>
  inline
  Vector3<CoordinateType>&
  Vector3<CoordinateType>::operator=(const Vector3<CoordinateType>& other) noexcept {
    m_x = other.x();
    m_y = other.y();
    m_z = other.z();

    return *this;
  }

  template <typename CoordinateType>
  inline
  CoordinateType&
  Vector3<CoordinateType>::x() noexcept {
    return m_x;
  }

  template <typename CoordinateType>
  inline
  const CoordinateType&
  Vector3<CoordinateType>::x() const noexcept {
    return m_x;
  }

  template <typename CoordinateType>
  inline
  void
  Vector3<CoordinateType>::setX(const CoordinateType& x) noexcept {
    m_x = x;
  }

  template <typename CoordinateType>
  inline
  CoordinateType&
  Vector3<CoordinateType>::y() noexcept {
    return m_y;
  }

  template <typename CoordinateType>
  inline
  const CoordinateType&
  Vector3<CoordinateType>::y() const noexcept {
    return m_y;
  }

  template <typename CoordinateType>
  inline
  void
  Vector3<CoordinateType>::setY(const CoordinateType& y) noexcept {
    m_y = y;
  }

  template <typename CoordinateType>
  inline
  CoordinateType&
  Vector3<CoordinateType>::z() noexcept {
    return m_z;
  }

  template <typename CoordinateType>
  inline
  const CoordinateType&
  Vector3<CoordinateType>::z() const noexcept {
    return m_z;
  }

  template <typename CoordinateType>
  inline
  void
  Vector3<CoordinateType>::setZ(const CoordinateType& z) noexcept {
    m_z = z;
  }

  template <typename CoordinateType>
  inline
  CoordinateType
  Vector3<CoordinateType>::length() const noexcept {
    return std::sqrt(lengthSquared());
  }

  template <typename CoordinateType>
  inline
  CoordinateType
  Vector3<CoordinateType>::lengthSquared() const noexcept {
    return m_x * m_x + m_y * m_y + m_z * m_z;
  }

  template <typename CoordinateType>
  inline
  CoordinateType
  Vector3<CoordinateType>::normalize() noexcept {
    const CoordinateType thisLength = length();
    if (!fuzzyEqual(thisLength, CoordinateType())) {
      m_x /= thisLength;
      m_y /= thisLength;
      m_z /= thisLength;
    }
    return thisLength;
  }

  template <typename CoordinateType>
  inline
  Vector3<CoordinateType>&
  Vector3<CoordinateType>::normalized() noexcept {
    normalize();
    return *this;
  }

  template <typename CoordinateType>
  inline
  CoordinateType
  Vector3<CoordinateType>::operator*(const Vector3<CoordinateType>& other) const noexcept {
    return m_x * other.m_x + m_y * other.m_y + m_z * other.m_z;
  }

  template <typename CoordinateType>
  inline
  bool
  Vector3<CoordinateType>::operator==(const Vector3<CoordinateType>& other) const noexcept {
    return (
      fuzzyEqual(m_x, other.m_x) &&
      fuzzyEqual(m_y, other.m_y) &&
      fuzzyEqual(m_z, other.m_z)
    );
  }

  template <typename CoordinateType>
  inline
  bool
  Vector3<CoordinateType>::operator!=(const Vector3<CoordinateType>& other) const noexcept {
    return !operator==(other);
  }

  template <typename CoordinateType>
  inline
  Vector3<CoordinateType>
  Vector3<CoordinateType>::operator+(const Vector3<CoordinateType>& other) const noexcept {
    Vector3<CoordinateType> sum(*this);
    sum += other;
    return sum;
  }

  template <typename CoordinateType>
  inline
  Vector3<CoordinateType>&
  Vector3<CoordinateType>::operator+=(const Vector3<CoordinateType>& other) noexcept {
    m_x += other.m_x;
    m_y += other.m_y;
    m_z += other.m_z;
    return (*this);
  }

  template <typename CoordinateType>
  inline
  Vector3<CoordinateType>
  Vector3<CoordinateType>::operator-(const Vector3<CoordinateType>& other) const noexcept {
    Vector3<CoordinateType> diff(*this);
    diff -= other;
    return diff;
  }

  template <typename CoordinateType>
  inline
  Vector3<CoordinateType>
  Vector3<CoordinateType>::operator-() const noexcept {
      Vector3<CoordinateType> minus;
      minus -= (*this);
      return minus;
  }

  template <typename CoordinateType>
  inline
  Vector3<CoordinateType>&
  Vector3<CoordinateType>::operator-=(const Vector3<CoordinateType>& other) noexcept {
    m_x -= other.m_x;
    m_y -= other.m_y;
    m_z -= other.m_z;
    return (*this);
  }

  template <typename CoordinateType>
  inline
  Vector3<CoordinateType>
  Vector3<CoordinateType>::operator*(const CoordinateType& scale) const noexcept {
    Vector3<CoordinateType> multiply(*this);
    multiply.m_x *= scale;
    multiply.m_y *= scale;
    multiply.m_z *= scale;
    return multiply;
  }

  template <typename CoordinateType>
  inline
  Vector3<CoordinateType>&
  Vector3<CoordinateType>::operator*=(const CoordinateType& scale) noexcept {
      m_x *= scale;
      m_y *= scale;
      return *this;
  }

  template <typename CoordinateType>
  inline
  Vector3<CoordinateType>
  Vector3<CoordinateType>::operator/(const CoordinateType& scale) const noexcept {
    Vector3<CoordinateType> divide(*this);
    divide.m_x /= scale;
    divide.m_y /= scale;
    divide.m_z /= scale;
    return divide;
  }

  template <typename CoordinateType>
  inline
  Vector3<CoordinateType>&
  Vector3<CoordinateType>::operator/=(const CoordinateType& scale) noexcept {
    m_x /= scale;
    m_y /= scale;
    m_z /= scale;
    return *this;
  }

  template <typename CoordinateType>
  inline
  Vector3<CoordinateType>
  Vector3<CoordinateType>::operator^(const Vector3<CoordinateType>& other) const noexcept {
    return Vector3<CoordinateType>(
      y() * other.z() - z() * other.y(),
      other.x() * z() - x() * other.z(),
      x() * other.y() - y() * other.x()
    );
  }

  template <typename CoordinateType>
  inline
  std::string
  Vector3<CoordinateType>::toString() const noexcept {
    return std::string("[Vector: ") + std::to_string(x()) + ", " + std::to_string(y()) + ", " + std::to_string(z()) + "]";
  }

  template <typename CoordinateType>
  inline
  Vector3<CoordinateType>
  Vector3<CoordinateType>::max() noexcept {
    return Vector3(
      std::numeric_limits<CoordinateType>::max(),
      std::numeric_limits<CoordinateType>::max(),
      std::numeric_limits<CoordinateType>::max()
    );
  }

  template <typename CoordinateType>
  inline
  Vector3<CoordinateType>
  Vector3<CoordinateType>::min() noexcept {
    return Vector3(
      std::numeric_limits<CoordinateType>::lowest(),
      std::numeric_limits<CoordinateType>::lowest(),
      std::numeric_limits<CoordinateType>::lowest()
    );
  }

}

template <typename CoordinateType>
inline
std::ostream&
operator<<(std::ostream& out, const utils::Vector3<CoordinateType>& vec) noexcept {
  out << vec.toString();
  return out;
}

template <typename CoordinateType>
inline
std::ostream&
operator<<(const utils::Vector3<CoordinateType>& vec, std::ostream& out) noexcept {
  return operator<<(out, vec);
}

template <typename CoordinateType>
inline
utils::Vector3<CoordinateType>
operator*(const CoordinateType& scale, const utils::Vector3<CoordinateType>& vector) noexcept {
  return vector * scale;
}

#endif    /* VECTOR_3_HXX */
