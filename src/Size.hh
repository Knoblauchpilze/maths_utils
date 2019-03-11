#ifndef    SIZE_HH
# define   SIZE_HH

namespace utils {
  namespace maths {

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

      public:

      private:

        DimsType m_w;
        DimsType m_h;

    };

    using Sizef = Size<float>;
    using Sizei = Size<int>;

  }
}

# include "Size.hxx"

#endif    /* SIZE_HH */
