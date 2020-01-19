#ifndef    VECTOR_3_HH
# define   VECTOR_3_HH

# include <iostream>

namespace utils {

  template <typename CoordinateType>
  class Vector3 {
    public:

      explicit
      Vector3(const CoordinateType& x = CoordinateType(),
              const CoordinateType& y = CoordinateType(),
              const CoordinateType& z = CoordinateType()) noexcept;

      Vector3(const Vector3<CoordinateType>& other) noexcept;

      Vector3<CoordinateType>&
      operator=(const Vector3<CoordinateType>& other) noexcept;

      CoordinateType&
      x() noexcept;

      const CoordinateType&
      x() const noexcept;

      void
      setX(const CoordinateType& x) noexcept;

      CoordinateType&
      y() noexcept;

      const CoordinateType&
      y() const noexcept;

      void
      setY(const CoordinateType& y) noexcept;

      CoordinateType&
      z() noexcept;

      const CoordinateType&
      z() const noexcept;

      void
      setZ(const CoordinateType& z) noexcept;

      CoordinateType
      length() const noexcept;

      CoordinateType
      lengthSquared() const noexcept;

      CoordinateType
      normalize() noexcept;

      Vector3<CoordinateType>&
      normalized() noexcept;

      CoordinateType
      operator*(const Vector3<CoordinateType>& other) const noexcept;

      bool
      operator==(const Vector3<CoordinateType>& other) const noexcept;

      bool
      operator!=(const Vector3<CoordinateType>& other) const noexcept;

      Vector3<CoordinateType>
      operator+(const Vector3<CoordinateType>& other) const noexcept;

      Vector3<CoordinateType>&
      operator+=(const Vector3<CoordinateType>& other) noexcept;

      Vector3<CoordinateType>
      operator-(const Vector3<CoordinateType>& other) const noexcept;

      Vector3<CoordinateType>
      operator-() const noexcept;

      Vector3<CoordinateType>&
      operator-=(const Vector3<CoordinateType>& other) noexcept;

      Vector3<CoordinateType>
      operator*(const CoordinateType& scale) const noexcept;

      Vector3<CoordinateType>&
      operator*=(const CoordinateType& scale) noexcept;

      Vector3<CoordinateType>
      operator/(const CoordinateType& scale) const noexcept;

      Vector3<CoordinateType>&
      operator/=(const CoordinateType& scale) noexcept;

      Vector3<CoordinateType>
      operator^(const Vector3<CoordinateType>& other) const noexcept;

      std::string
      toString() const noexcept;

      static
      Vector3<CoordinateType>
      max() noexcept;

      static
      Vector3<CoordinateType>
      min() noexcept;

    private:

      CoordinateType m_x;
      CoordinateType m_y;
      CoordinateType m_z;
  };

  using Vector3f = Vector3<float>;
  using Vector3i = Vector3<int>;
}

template <typename CoordinateType>
std::ostream&
operator<<(std::ostream& out, const utils::Vector3<CoordinateType>& vec) noexcept;

template <typename CoordinateType>
std::ostream&
operator<<(const utils::Vector3<CoordinateType>& vec, std::ostream& out) noexcept;

template <typename CoordinateType>
utils::Vector3<CoordinateType>
operator*(const CoordinateType& scale, const utils::Vector3<CoordinateType>& vector) noexcept;

# include "Vector3.hxx"

#endif    /* VECTOR_3_HH */
