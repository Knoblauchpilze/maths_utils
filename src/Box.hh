#ifndef    BOX_HH
# define   BOX_HH

# include "Size.hh"
# include "Vector2.hh"

namespace utils {

  template <typename CoordinateType>
  class Box {
    public:

      /**
       * @brief - Describes a box centered at coordinate (x, y) with the specified dimensions (width, height)
       * @param x - the x coordinate of the center.
       * @param y - the y coordinate of the center.
       * @param width - the width of the box.
       * @param height - the height of the box.
       */
      explicit
      Box(const CoordinateType& x = CoordinateType(),
          const CoordinateType& y = CoordinateType(),
          const CoordinateType& width = CoordinateType(),
          const CoordinateType& height = CoordinateType()) noexcept;

      /**
       * @brief - Creates a box with the specified center and dimensions. The default box created is not valid
       *          as both width and height are null.
       * @param center - a vector representing the coordinates of the center of the box to create.
       * @param width - the width of the box. This width will be distributed equally on both sides of the center.
       * @param height - the height of the box. This height will be distributed equally on both sides of the
       *                 center.
       */
      explicit
      Box(const Vector2<CoordinateType>& center,
          const CoordinateType& width = CoordinateType(),
          const CoordinateType& height = CoordinateType()) noexcept;

      /**
       * @brief - Creates a box with the specified center and dimensions.
       * @param x - the x coordinate of the center of the box to create.
       * @param y - the y coordinate of the center of the box to create.
       * @param dims - a measure of the dimensions of the box to create.
       */
      explicit
      Box(const CoordinateType& x,
          const CoordinateType& y,
          const Size<CoordinateType>& dims = Size<CoordinateType>()) noexcept;

      /**
       * @brief - Creates a box with the specified center and dimensions.
       * @param center - the center of the box to create.
       * @param dims - a measure of the dimensions of the box to create.
       */
      explicit
      Box(const Vector2<CoordinateType>& center,
          const Size<CoordinateType>& dims) noexcept;

      bool
      operator==(const Box<CoordinateType>& other) const noexcept;

      bool
      operator!=(const Box<CoordinateType>& other) const noexcept;

      bool
      valid() const noexcept;

      CoordinateType&
      x() noexcept;

      const CoordinateType&
      x() const noexcept;

      CoordinateType&
      y() noexcept;

      const CoordinateType&
      y() const noexcept;

      CoordinateType&
      w() noexcept;

      const CoordinateType&
      w() const noexcept;

      CoordinateType&
      h() noexcept;

      const CoordinateType&
      h() const noexcept;

      CoordinateType
      area() const noexcept;

      CoordinateType
      getLeftBound() const noexcept;

      CoordinateType
      getRightBound() const noexcept;

      CoordinateType
      getTopBound() const noexcept;

      CoordinateType
      getBottomBound() const noexcept;

      Vector2<CoordinateType>
      getCenter() const noexcept;

      Vector2<CoordinateType>
      getTopLeftCorner() const noexcept;

      Vector2<CoordinateType>
      getTopRightCorner() const noexcept;

      Vector2<CoordinateType>
      getBottomRightCorner() const noexcept;

      Vector2<CoordinateType>
      getBottomLeftCorner() const noexcept;

      CoordinateType
      getSurface() const noexcept;

      /**
       * @brief - Checks whether the input box is contained inside this box.
       * @param other - the other box to check for inclusion.
       * @return - `true` if the other box is contained inside this box, `false` otherwise.
       */
      bool
      contains(const Box<CoordinateType>& other) const noexcept;

      /**
       * @brief - Checks whether the input point is contained inside this box.
       * @param point - the point which should be checked for inclusion.
       * @return - `true` if the input `point` lies inside `this` box, `false` otherwise.
       */
      bool
      contains(const Vector2<CoordinateType>& point) const noexcept;

      /**
       * @brief - Similar to the `contains` method but include some sort of a threshold
       *          to make the comparison allow for values very close to being considered
       *          inside the box to actually be considered inside.
       * @param point - the point which should be checked for inclusion.
       * @param threshold - a value representing the threshold to actually exclude a point.
       * @return - `true` if the input `point` lies inside `this` box, `false` otherwise.
       */
      bool
      fuzzyContains(const Vector2<CoordinateType>& point,
                    CoordinateType threshold) const noexcept;

      /**
       * @brief - Checks whether `other` intersects `this` box. By default the intersection
       *          is not strict (i.e. if the boxes are touching an intersection is still
       *          reported). The user can modify this behavior using the input `strict`
       *          boolean.
       * @param other - the box which should be used to detect intersection with `this` box.
       * @param struct - `true` if touching boxes should not be reported as intersecting,
       *                 `false` otherwise.
       * @return - `true` if the `other` box intersects with `this` box, `false` otherwise.
       */
      bool
      intersects(const Box<CoordinateType>& other,
                 bool strict = false) const noexcept;

      /**
       * @brief - Checks whether `other` contains `this` box.
       * @param other - the box into which `this` box should be contained.
       * @return - `true` if the `other` box contains `this` box, `false` otherwise.
       */
      bool
      includes(const Box<CoordinateType>& other) const noexcept;

      /**
       * @brief - Retrieves the nearest point to the input 'point' belonging to this box.
       * @param point - the point for which a box point should be retrieved.
       * @return - a vector representing the closest point belonging to this box relatively to the input point.
       */
      Vector2<CoordinateType>
      getNearestPoint(const Vector2<CoordinateType>& point) const noexcept;

      std::string
      toString() const noexcept;

      Size<CoordinateType>
      toSize() const noexcept;

      /**
       * @brief - Builds a centered box from the input size. Also converts the coordinates of
       *          size into the required type to build the box. Might result in overflow.
       *          The input boolean allows to specify whether the center of the box should be
       *          set to the origin or to the center of the dimensions.
       * @param size - the size to convert.
       * @param setToOrigin - `true` if the center of the created box should be set to the origin,
       *                      `false` if it should be set to the center of the dimensions.
       * @return - a box with the same width and height than the input `size` and with a center
       *           corresponding to `(size.w() / 2; size.h() / 2)`.
       */
      template <typename OtherCoordinateType>
      static
      Box<CoordinateType>
      fromSize(const Size<OtherCoordinateType>& size,
               const bool setToOrigin = false) noexcept;

      /**
       * @brief - Used to produce a box similar in dimensions to `this` box but with center at
       *          the origin (i.e. `[0; 0]`).
       * @return - a box with same dimensions as `this` box but with a center at the origin.
       */
      Box<CoordinateType>
      toOrigin() const noexcept;

      Box<CoordinateType>
      scale(float factor) const noexcept;

      /**
       * @brief - Computes the box resulting in the intersection of `this` box with the input
       *          `other` box. The result might be an empty box if both `this` and `other` do
       *          not overlap. In this case the position of the returned box is set to be the
       *          midpoint of the positions of `other` and `this` with an empty area.
       * @param other - the box to intersect with `this` box.
       * @return - the intersection between the `other` and `this` box.
       */
      Box<CoordinateType>
      intersect(const Box<CoordinateType>& other) const noexcept;

    private:

      CoordinateType m_x;
      CoordinateType m_y;
      CoordinateType m_w;
      CoordinateType m_h;
  };

  using Boxf = Box<float>;
  using Boxi = Box<int>;

}

template <typename CoordinateType>
std::ostream&
operator<<(std::ostream& out, const utils::Box<CoordinateType>& box) noexcept;

template <typename CoordinateType>
std::ostream&
operator<<(const utils::Box<CoordinateType>& box, std::ostream& out) noexcept;

# include "Box.hxx"

#endif    /* BOX_HH */
