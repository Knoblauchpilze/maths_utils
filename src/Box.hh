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
       * @return - true if the other box is contained inside this box, false otherwise.
       */
      bool
      contains(const Box<CoordinateType>& other) const noexcept;

      /**
       * @brief - Checks whether the input box intersects this box.
       * @param other - the other box to check for inclusion.
       * @return - true if the other box is contained inside this box, false otherwise.
       */
      bool
      intersects(const Box<CoordinateType>& other) const noexcept;

      /**
       * @brief - Checks whether the input box contains this box.
       * @param other - the box into which this box should be contained.
       * @return - true if the other box contains this box, false otherwise.
       */
      bool
      isInside(const Box<CoordinateType>& other) const noexcept;

      /**
       * @brief - Checks whether the input point is inside this box.
       * @param point - the input point to check for inclusion in this box.
       * @return - true if the point lies inside this box, false otherwise.
       */
      bool
      isInside(const Vector2<CoordinateType>& point) const noexcept;

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
       * @param setToOrigin - true if the center of the created box should be set to the origin,
       *                      false if it should be set to the center of the dimensions.
       * @return - a box with the same width and height than the input `size` and with a center
       *           corresponding to `(size.w() / 2; size.h() / 2)`.
       */
      template <typename OtherCoordinateType>
      static
      Box<CoordinateType>
      fromSize(const Size<OtherCoordinateType>& size,
               const bool setToOrigin = false) noexcept;

      Box<CoordinateType>
      scale(const float& factor) const noexcept;

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
operator<<(const utils::Box<CoordinateType>& box, std::ostream& out) noexcept;

template <typename CoordinateType>
std::ostream&
operator<<(std::ostream& out, const utils::Box<CoordinateType>& box) noexcept;

# include "Box.hxx"

#endif    /* BOX_HH */
