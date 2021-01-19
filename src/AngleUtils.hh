#ifndef    ANGLE_UTILS_HH
# define   ANGLE_UTILS_HH

namespace utils {

  /**
   * @brief - Used to convert the input degrees value into an
   *          angle expressed in radians.
   * @param deg - the degrees value to convert.
   * @return - the corresponding radians value.
   */
  constexpr float
  degToRad(float deg) noexcept;

  /**
   * @brief - Used to convert the input radians value into an
   *          angle expressed in degrees.
   * @param rad - the radians value to convert.
   * @return - the corresponding degrees value.
   */
  constexpr float
  radToDeg(float rad) noexcept;

}

# include "AngleUtils.hxx"

#endif    /* ANGLE_UTILS_HH */
