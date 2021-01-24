#ifndef    COMPARISONUTILS_HXX
# define   COMPARISONUTILS_HXX

# include "ComparisonUtils.hh"

namespace utils {

  template <typename DataType>
  inline
  bool
  fuzzyEqual(const DataType& value1,
             const DataType& value2,
             const DataType& epsilon)
  {
    return std::abs(value1 - value2) < epsilon;
  }

  template <>
  inline
  bool
  fuzzyEqual(const int& value1,
             const int& value2,
             const int& epsilon)
  {
    return value1 == value2;
  }

  template <typename DataType>
  inline
  DataType
  clamp(const DataType& val,
        const DataType& min,
        const DataType& max)
  {
    return std::min(std::max(val, min), max);
  }

}

#endif    /* COMPARISONUTILS_HXX */
