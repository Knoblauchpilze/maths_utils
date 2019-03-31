#ifndef    SIZE_HH
# define   SIZE_HH

# include <iostream>

namespace utils {

  template <typename DimsType>
  class Size {
    public:

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

      bool
      fuzzyEqual(const Size& rhs,
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

# include "Size.hxx"

#endif    /* SIZE_HH */
