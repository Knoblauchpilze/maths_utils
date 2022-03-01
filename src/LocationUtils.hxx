#ifndef    LOCATION_UTILS_HXX
# define   LOCATION_UTILS_HXX

# include <cmath>
# include "LocationUtils.hh"

namespace utils {

  inline
  float
  d(float x1, float y1, float x2, float y2) noexcept {
    return std::sqrt(d2(x1, y1, x2, y2));
  }

  template <typename T>
  inline
  float
  d(const Vector2<T>& p1, const Vector2<T>& p2) noexcept {
    return std::sqrt(d2(p1, p2));
  }

  inline
  float
  d2(float x1, float y1, float x2, float y2) noexcept {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  }

  template <typename T>
  inline
  float
  d2(const Vector2<T>& p1, const Vector2<T>& p2) noexcept {
    return d2(p1.x(), p1.y(), p2.x(), p2.y());
  }

  inline
  float
  angleFromDirection(float xDir, float yDir, float threshold) noexcept {
    // Normalize the input direction and handle
    // pathological cases.
    float l = d(0.0f, 0.0f, xDir, yDir);
    if (l < threshold) {
      return 0.0f;
    }

    xDir /= l;
    yDir /= l;

    float theta = std::atan2(yDir, xDir);

    // As per this link: http://www.cplusplus.com/reference/cmath/atan2/
    // the value returned is in the interval `]-pi, pi]` (even though it
    // is not clear if the interval is open in `-pi`) so as we want the
    // value in the range `[0; 2pi[` we need to add `pi`.
    return utils::clamp(theta + 3.1415926535f, 0.0f, 6.283185307f);
  }

  inline
  float
  angleFromDirection(const Point2f& p1,
                     const Point2f& p2,
                     float threshold) noexcept
  {
    return angleFromDirection(p2.x() - p1.x(), p2.y() - p1.y(), threshold);
  }

  inline
  float
  isInCone(const Point2f& o,
           float xDir,
           float yDir,
           float theta,
           const Point2f& p) noexcept
  {
    // Compute the angle between the point and the
    // origin of the cone.
    float angle = angleFromDirection(o, p);

    // Compute the angle directing the cone.
    float coneAngle = angleFromDirection(xDir, yDir);

    // In order for the point to lie in the cone we
    // should have the angle within `theta / 2` of
    // the cone supporting angle.
    return std::abs(angle - coneAngle) < theta / 2.0f;
  }

  inline
  bool
  toDirection(const Point2f& s,
              const Point2f& t,
              float& xD,
              float& yD,
              float& dist,
              float threshold) noexcept
  {
    // Compute the direction and compute
    // the length and a unit vector from
    // there.
    xD = t.x() - s.x();
    yD = t.y() - s.y();

    dist = d(s, t);
    bool notZeroLength = (dist > threshold);

    if (notZeroLength) {
      xD /= dist;
      yD /= dist;
    }

    return notZeroLength;
  }

}

#endif    /* LOCATION_UTILS_HXX */
