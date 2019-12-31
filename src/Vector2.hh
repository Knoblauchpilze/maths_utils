#ifndef    VECTOR2_HH
# define   VECTOR2_HH

# include <iostream>

namespace utils {

  template <typename CoordinateType>
  class Vector2 {
    public:

      explicit
      Vector2(const CoordinateType& x = CoordinateType(),
              const CoordinateType& y = CoordinateType()) noexcept;

      Vector2(const Vector2<CoordinateType>& other) noexcept;

      Vector2<CoordinateType>&
      operator=(const Vector2<CoordinateType>& other) noexcept;

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

      CoordinateType
      length() const noexcept;

      CoordinateType
      lengthSquared() const noexcept;

      CoordinateType
      normalize() noexcept;

      Vector2<CoordinateType>&
      normalized() noexcept;

      CoordinateType
      operator*(const Vector2<CoordinateType>& other) const noexcept;

      bool
      operator==(const Vector2<CoordinateType>& other) const noexcept;

      bool
      operator!=(const Vector2<CoordinateType>& other) const noexcept;

      Vector2<CoordinateType>
      operator+(const Vector2<CoordinateType>& other) const noexcept;

      Vector2<CoordinateType>&
      operator+=(const Vector2<CoordinateType>& other) noexcept;

      Vector2<CoordinateType>
      operator-(const Vector2<CoordinateType>& other) const noexcept;

      Vector2<CoordinateType>
      operator-() const noexcept;

      Vector2<CoordinateType>&
      operator-=(const Vector2<CoordinateType>& other) noexcept;

      Vector2<CoordinateType>
      operator*(const CoordinateType& scale) const noexcept;

      Vector2<CoordinateType>&
      operator*=(const CoordinateType& scale) noexcept;

      Vector2<CoordinateType>
      operator/(const CoordinateType& scale) const noexcept;

      Vector2<CoordinateType>&
      operator/=(const CoordinateType& scale) noexcept;

      CoordinateType
      operator^(const Vector2<CoordinateType>& other) const noexcept;

      std::string
      toString() const noexcept;

      static
      Vector2<CoordinateType>
      max() noexcept;

      static
      Vector2<CoordinateType>
      min() noexcept;

      static
      Vector2<CoordinateType>
      minmax() noexcept;

      static
      Vector2<CoordinateType>
      maxmin() noexcept;

    private:

      CoordinateType m_x;
      CoordinateType m_y;
  };

  using Vector2f = Vector2<float>;
  using Vector2i = Vector2<int>;
}

template <typename CoordinateType>
std::ostream&
operator<<(std::ostream& out, const utils::Vector2<CoordinateType>& vec) noexcept;

template <typename CoordinateType>
std::ostream&
operator<<(const utils::Vector2<CoordinateType>& vec, std::ostream& out) noexcept;

template <typename CoordinateType>
utils::Vector2<CoordinateType>
operator*(const CoordinateType& scale, const utils::Vector2<CoordinateType>& vector) noexcept;

# include "Vector2.hxx"

#endif    /* VECTOR2_H */
