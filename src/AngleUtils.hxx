#ifndef    ANGLE_UTILS_HXX
# define   ANGLE_UTILS_HXX

# include "AngleUtils.hh"

namespace utils {

  inline
  constexpr float
  degToRad(float deg) noexcept {
    return deg * 3.1415926535f / 180.0f;
  }

  inline
  constexpr float
  radToDeg(float rad) noexcept {
    return rad * 180.0f / 3.1415926535f;
  }

}

#endif    /* ANGLE_UTILS_HXX */
