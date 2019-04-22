#ifndef    BOX_HXX_INCLUDED
# define   BOX_HXX_INCLUDED

# include "Box.hh"

namespace utils {

  template <typename CoordinateType>
  inline
  Box<CoordinateType>::Box(const CoordinateType& x,
                           const CoordinateType& y,
                           const CoordinateType& width,
                           const CoordinateType& height) noexcept :
    m_x(x),
    m_y(y),
    m_w(width),
    m_h(height)
  {}

  template <typename CoordinateType>
  inline
  bool
  Box<CoordinateType>::operator==(const Box<CoordinateType>& other) const noexcept {
    return
      fuzzyEqual(m_x, other.m_x) &&
      fuzzyEqual(m_y, other.m_y) &&
      fuzzyEqual(m_w, other.m_w) &&
      fuzzyEqual(m_h, other.m_h)
    ;
  }

  template <typename CoordinateType>
  inline
  bool
  Box<CoordinateType>::valid() const noexcept {
    return m_w != CoordinateType() && m_h != CoordinateType();
  }

  template <typename CoordinateType>
  inline
  CoordinateType&
  Box<CoordinateType>::x() noexcept {
    return m_x;
  }

  template <typename CoordinateType>
  inline
  const CoordinateType&
  Box<CoordinateType>::x() const noexcept {
    return m_x;
  }

  template <typename CoordinateType>
  inline
  CoordinateType&
  Box<CoordinateType>::y() noexcept {
    return m_y;
  }

  template <typename CoordinateType>
  inline
  const CoordinateType&
  Box<CoordinateType>::y() const noexcept {
    return m_y;
  }
  
  template <typename CoordinateType>
  inline
  CoordinateType&
  Box<CoordinateType>::w() noexcept {
    return m_w;
  }

  template <typename CoordinateType>
  inline
  const CoordinateType&
  Box<CoordinateType>::w() const noexcept {
    return m_w;
  }

  template <typename CoordinateType>
  inline
  CoordinateType&
  Box<CoordinateType>::h() noexcept {
    return m_h;
  }

  template <typename CoordinateType>
  inline
  const CoordinateType&
  Box<CoordinateType>::h() const noexcept {
    return m_h;
  }

  template <typename CoordinateType>
  inline
  CoordinateType
  Box<CoordinateType>::getLeftBound() const noexcept {
    return m_x - m_w / CoordinateType(2.0f);
  }

  template <typename CoordinateType>
  inline
  CoordinateType
  Box<CoordinateType>::getRightBound() const noexcept {
    return m_x + m_w / CoordinateType(2.0f);
  }

  template <typename CoordinateType>
  inline
  CoordinateType
  Box<CoordinateType>::getTopBound() const noexcept {
    return m_y + m_h / CoordinateType(2.0f);
  }

  template <typename CoordinateType>
  inline
  CoordinateType
  Box<CoordinateType>::getBottomBound() const noexcept {
    return m_y - m_h / CoordinateType(2.0f);
  }

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>
  Box<CoordinateType>::getCenter() const noexcept {
    return Vector2<CoordinateType>(m_x, m_y);
  }

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>
  Box<CoordinateType>::getTopLeftCorner() const noexcept {
    return Vector2<CoordinateType>(m_x - m_w / CoordinateType(2.0f), m_y + m_h / CoordinateType(2.0f));
  }

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>
  Box<CoordinateType>::getTopRightCorner() const noexcept {
    return Vector2<CoordinateType>(m_x + m_w / CoordinateType(2.0f), m_y + m_h / CoordinateType(2.0f));
  }

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>
  Box<CoordinateType>::getBottomRightCorner() const noexcept {
    return Vector2<CoordinateType>(m_x + m_w / CoordinateType(2.0f), m_y - m_h / CoordinateType(2.0f));
  }

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>
  Box<CoordinateType>::getBottomLeftCorner() const noexcept {
    return Vector2<CoordinateType>(m_x - m_w / CoordinateType(2.0f), m_y - m_h / CoordinateType(2.0f));
  }

  template <typename CoordinateType>
  inline
  CoordinateType
  Box<CoordinateType>::getSurface() const noexcept {
    return m_w * m_h;
  }

  template <typename CoordinateType>
  inline
  bool
  Box<CoordinateType>::contains(const Box<CoordinateType>& other) const noexcept {
    return other.getLeftBound() >=  getLeftBound() &&
           other.getRightBound() <= getRightBound() &&
           other.getTopBound() <= getTopBound() &&
           other.getBottomBound() >= getBottomBound();
  }

  template <typename CoordinateType>
  inline
  bool
  Box<CoordinateType>::intersects(const Box<CoordinateType>& other) const noexcept {
    return getLeftBound() <= other.getRightBound() ||
           getRightBound() >= other.getLeftBound() ||
           getTopBound() >= other.getBottomBound() ||
           getBottomBound() <= other.getTopBound();
  }

  template <typename CoordinateType>
  inline
  bool
  Box<CoordinateType>::isInside(const Box<CoordinateType>& other) const noexcept {
    return other.contains(*this);
  }

  template <typename CoordinateType>
  inline
  bool
  Box<CoordinateType>::isInside(const Vector2<CoordinateType>& point) const noexcept {
    return getLeftBound() <= point.x() &&
           getRightBound() >= point.x() &&
           getBottomBound() <= point.y() &&
           getTopBound() >= point.y();
  }

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>
  Box<CoordinateType>::getNearestPoint(const Vector2<CoordinateType>& point) const noexcept {
    return Vector2<CoordinateType>(
      getLeftBound() > point.x() ? getLeftBound() : (getRightBound() < point.x() ? getRightBound() : point.x()),
      getBottomBound() > point.y() ? getBottomBound() : (getTopBound() < point.y() ? getTopBound() : point.y())
    );
  }

  template <typename CoordinateType>
  inline
  std::string
  Box<CoordinateType>::toString() const noexcept {
    return std::string("[Box: ") +
           "pos: " + std::to_string(x()) + "x" + std::to_string(y()) + ", " +
           "dims: " + std::to_string(w()) + "x" + std::to_string(h()) + "]";
  }

  template <typename CoordinateType>
  inline
  Size<CoordinateType>
  Box<CoordinateType>::toSize() const noexcept {
    return Size<CoordinateType>(w(), h());
  }

  template <typename CoordinateType>
  template <typename OtherCoordinateType>
  inline
  Box<CoordinateType>
  Box<CoordinateType>::fromSize(const Size<OtherCoordinateType>& size) noexcept {
    return Box<CoordinateType>(
      static_cast<CoordinateType>(size.w() / static_cast<CoordinateType>(2)),
      static_cast<CoordinateType>(size.h() / static_cast<CoordinateType>(2)),
      static_cast<CoordinateType>(size.w()),
      static_cast<CoordinateType>(size.h())
    );
  }

}

template <typename CoordinateType>
std::ostream&
operator<<(const utils::Box<CoordinateType>& box, std::ostream& out) noexcept {
  return operator<<(out, box);
}

template <typename CoordinateType>
std::ostream&
operator<<(std::ostream& out, const utils::Box<CoordinateType>& box) noexcept {
  out << box.toString();
  return out;
}

#endif    /* BOX_HXX_INCLUDED */
