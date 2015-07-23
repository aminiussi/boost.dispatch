//==================================================================================================
/*!
  @file

  Defines the relative error testing related helpers

  @copyright 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)

**/
//==================================================================================================
#ifndef NSTEST_UNIT_DETAIL_RELATIVE_HPP_INCLUDED
#define NSTEST_UNIT_DETAIL_RELATIVE_HPP_INCLUDED

#include <nstest/unit/detail/approx.hpp>
#include <nstest/unit/detail/reldist.hpp>
#include <string>

namespace nstest
{
  namespace detail
  {
    struct relative_measure
    {
      template<typename T, typename U>
      auto operator()(T const& data, U const& ref) const -> decltype(reldist(data,ref))
      {
        using nstest::reldist;
        return reldist(data,ref);
      }

      template<typename Stream> static void to_stream(Stream& s, double v)
      {
        s.precision(2);
        s << " (" << std::fixed << v*100. << " %)\n";
      }
    };
  }

  // Perform relative distance computation and report
  template<typename R> using relative_ = approx_<detail::relative_measure, R>;

  // Simple relative_ constructor like call
  template<typename R> inline relative_<R> relative(R const& t, double n) { return {t,n/100.}; }
}

#endif
