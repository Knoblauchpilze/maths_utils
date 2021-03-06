#ifndef    BOX_HXX_INCLUDED
# define   BOX_HXX_INCLUDED

# include "Box.hh"

namespace utils {

  template <typename CoordinateType>
  inline
  Box<CoordinateType>::Box(const CoordinateType& x,
                           const CoordinateType& y,
                           const CoordinateType& width,
                           const CoordinateType& height) noexcept:
    m_x(x),
    m_y(y),
    m_w(width),
    m_h(height)
  {}

  template <typename CoordinateType>
  inline
  Box<CoordinateType>::Box(const Vector2<CoordinateType>& center,
                           const CoordinateType& width,
                           const CoordinateType& height) noexcept:
    m_x(center.x()),
    m_y(center.y()),
    m_w(width),
    m_h(height)
  {}

  template <typename CoordinateType>
  inline
  Box<CoordinateType>::Box(const CoordinateType& x,
                           const CoordinateType& y,
                           const Size<CoordinateType>& dims) noexcept:
    m_x(x),
    m_y(y),
    m_w(dims.w()),
    m_h(dims.h())
  {}

  template <typename CoordinateType>
  inline
  Box<CoordinateType>::Box(const Vector2<CoordinateType>& center,
                           const Size<CoordinateType>& dims) noexcept:
    m_x(center.x()),
    m_y(center.y()),
    m_w(dims.w()),
    m_h(dims.h())
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
  Box<CoordinateType>::operator!=(const Box<CoordinateType>& other) const noexcept {
    return !operator==(other);
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
  Box<CoordinateType>::area() const noexcept {
    return m_w * m_h;
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
    return Vector2<CoordinateType>(getLeftBound(), getTopBound());
  }

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>
  Box<CoordinateType>::getTopRightCorner() const noexcept {
    return Vector2<CoordinateType>(getRightBound(), getTopBound());
  }

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>
  Box<CoordinateType>::getBottomRightCorner() const noexcept {
    return Vector2<CoordinateType>(getRightBound(), getBottomBound());
  }

  template <typename CoordinateType>
  inline
  Vector2<CoordinateType>
  Box<CoordinateType>::getBottomLeftCorner() const noexcept {
    return Vector2<CoordinateType>(getLeftBound(), getBottomBound());
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
    return other.getLeftBound() >= getLeftBound() &&
           other.getRightBound() <= getRightBound() &&
           other.getTopBound() <= getTopBound() &&
           other.getBottomBound() >= getBottomBound();
  }

  template <typename CoordinateType>
  inline
  bool
  Box<CoordinateType>::contains(const Vector2<CoordinateType>& point) const noexcept {
    return
      getLeftBound() <= point.x() &&
      getRightBound() >= point.x() &&
      getBottomBound() <= point.y() &&
      getTopBound() >= point.y()
    ;
  }

  template <typename CoordinateType>
  inline
  bool
  Box<CoordinateType>::fuzzyContains(const Vector2<CoordinateType>& point,
                                     CoordinateType threshold) const noexcept
  {
    return
      getLeftBound() - threshold <= point.x() &&
      getRightBound() + threshold >= point.x() &&
      getBottomBound() - threshold <= point.y() &&
      getTopBound() + threshold >= point.y()
    ;
  }

  template <typename CoordinateType>
  inline
  bool
  Box<CoordinateType>::intersects(const Box<CoordinateType>& other,
                                  bool strict) const noexcept
  {
    // The `strict` value tells whether we should use `>=` or `>`
    // operators for comparisons.
    if (strict) {
      return !(
        getLeftBound() >= other.getRightBound() ||
        getRightBound() <= other.getLeftBound() ||
        getTopBound() <= other.getBottomBound() ||
        getBottomBound() >= other.getTopBound()
      );
    }

    return !(
      getLeftBound() > other.getRightBound() ||
      getRightBound() < other.getLeftBound() ||
      getTopBound() < other.getBottomBound() ||
      getBottomBound() > other.getTopBound()
    );
  }

  template <typename CoordinateType>
  inline
  bool
  Box<CoordinateType>::intersectsBottomLeft(const Box<CoordinateType>& other) const noexcept {
    if (other.getLeftBound() >= getRightBound()) {
      return false;
    }

    if (other.getRightBound() < getLeftBound()) {
      return false;
    }

    if (other.getBottomBound() >= getTopBound()) {
      return false;
    }

    if (other.getTopBound() < getBottomBound()) {
      return false;
    }

    return true;
  }

  template <typename CoordinateType>
  inline
  bool
  Box<CoordinateType>::includes(const Box<CoordinateType>& other) const noexcept {
    return other.contains(*this);
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
  Box<CoordinateType>::fromSize(const Size<OtherCoordinateType>& size,
                                const bool setToOrigin) noexcept
  {
    return Box<CoordinateType>(
      setToOrigin ? static_cast<CoordinateType>(0) : static_cast<CoordinateType>(size.w() / static_cast<CoordinateType>(2)),
      setToOrigin ? static_cast<CoordinateType>(0) : static_cast<CoordinateType>(size.h() / static_cast<CoordinateType>(2)),
      static_cast<CoordinateType>(size.w()),
      static_cast<CoordinateType>(size.h())
    );
  }

  template <typename CoordinateType>
  inline
  Box<CoordinateType>
  Box<CoordinateType>::toOrigin() const noexcept {
    return Box<CoordinateType>(
      static_cast<CoordinateType>(0),
      static_cast<CoordinateType>(0),
      m_w,
      m_h
    );
  }

  template <typename CoordinateType>
  Box<CoordinateType>
  Box<CoordinateType>::scale(float factor) const noexcept {
    return Box<CoordinateType>(
      m_x,
      m_y,
      m_w * factor,
      m_h * factor
    );
  }

  template <typename CoordinateType>
  Box<CoordinateType>
  Box<CoordinateType>::intersect(const Box<CoordinateType>& other) const noexcept {
    // Compute the box to intersect from the internal coordinates. First
    // we need to compute the width and height of the intersection if any.
    const CoordinateType overlappingW = std::min(getRightBound(), other.getRightBound()) - std::max(getLeftBound(), other.getLeftBound());
    const CoordinateType overlappingH = std::min(getTopBound(), other.getTopBound()) - std::max(getBottomBound(), other.getBottomBound());

    // Compute the center of this overlapping width and height. If one of
    // the dimension is negative it means that both boxes are not overlapping
    // along this direction and thus we return the midpoint along this axis.
    const float x = (
      overlappingW < CoordinateType(0) ?
      (other.m_x + m_x) / CoordinateType(2) :
      (std::max(getLeftBound(), other.getLeftBound()) + std::min(getRightBound(), other.getRightBound())) / CoordinateType(2)
    );
    const float y = (
      overlappingH < CoordinateType(0) ?
      (other.m_y + m_y) / CoordinateType(2) :
      (std::max(getBottomBound(), other.getBottomBound()) + std::min(getTopBound(), other.getTopBound())) / CoordinateType(2)
    );

    // Compute and return the intersection box.
    return utils::Box<CoordinateType>(
      x, y,
      std::max(CoordinateType(0), overlappingW), std::max(CoordinateType(0), overlappingH)
    );
  }

}

template <typename CoordinateType>
inline
std::ostream&
operator<<(std::ostream& out, const utils::Box<CoordinateType>& box) noexcept {
  out << box.toString();
  return out;
}

template <typename CoordinateType>
inline
std::ostream&
operator<<(const utils::Box<CoordinateType>& box, std::ostream& out) noexcept {
  return operator<<(out, box);
}

#endif    /* BOX_HXX_INCLUDED */
