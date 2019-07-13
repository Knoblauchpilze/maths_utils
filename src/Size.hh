#ifndef    SIZE_HH
# define   SIZE_HH

# include <iostream>

namespace utils {

  template <typename DimsType>
  class Size {
    public:

      explicit
      Size(const DimsType& width = DimsType(),
            const DimsType& height = DimsType());

      ~Size() = default;

      bool
      operator==(const Size& rhs) const noexcept;

      bool
      operator!=(const Size& rhs) const noexcept;

      Size
      operator+(const Size& rhs) const noexcept;

      Size
      operator-(const Size& rhs) const noexcept;

      Size
      operator*(const float& scale) const noexcept;

      bool
      compareWithTolerance(const Size& rhs,
                           const DimsType& tolerance) const noexcept;

      DimsType&
      w() noexcept;

      const DimsType&
      w() const noexcept;

      DimsType&
      h() noexcept;

      const DimsType&
      h() const noexcept;

      bool
      isEmpty() const noexcept;

      bool
      isNull() const noexcept;

      bool
      isValid() const noexcept;

      void
      transpose() noexcept;

      static
      Size
      max() noexcept;

      std::string
      toString() const noexcept;

      /**
       * @brief - Transforms this size into a new size where dimensions have the specified type.
       *          Note that overflow is possible or more generally the chosen type might not be
       *          able to accurately represent this box.
       * @return - a new box whith coordinates of the specified type.
       */
      template <typename OtherDimsType>
      Size<OtherDimsType>
      toType() const;

      /**
       * @brief - Used to determine whether both dimensions of the `other` size are smaller than
       *          the dimensions of `this` size.
       * @param other - the size with which `this` should be compared.
       * @return - true if both the `w` and `h` dimension of `this` are larger than `other` and
       *           false otherwise.
       */
      bool
      contains(const Size<DimsType>& other) const noexcept;

    public:

    private:

      DimsType m_w;
      DimsType m_h;

  };

  using Sizef = Size<float>;
  using Sizei = Size<int>;

}

template <typename DimsType>
std::ostream&
operator<<(const utils::Size<DimsType>& size, std::ostream& out) noexcept;

template <typename DimsType>
std::ostream&
operator<<(std::ostream& out, const utils::Size<DimsType>& size) noexcept;

template <typename DimsType>
utils::Size<DimsType>
operator*(const float& scale, const utils::Size<DimsType>& size) noexcept;

# include "Size.hxx"

#endif    /* SIZE_HH */
