#ifndef    COMPARISONUTILS_HH
# define   COMPARISONUTILS_HH

# include <limits>

namespace utils {

  template <typename DataType>
  bool
  fuzzyEqual(const DataType& value1,
             const DataType& value2,
             const DataType& epsilon = std::numeric_limits<DataType>::min());

  template <typename DataType>
  DataType
  clamp(const DataType& val,
        const DataType& min,
        const DataType& max);

}

# include "ComparisonUtils.hxx"

#endif    /* COMPARISONUTILS_HH */
