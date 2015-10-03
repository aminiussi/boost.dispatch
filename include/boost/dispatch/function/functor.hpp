//==================================================================================================
/*
  Copyright 2012 - 2015 NumScale SAS

  Distributed under the Boost Software License, Version 1.0.
  (See accompanying file LICENSE.md or copy at http://boost.org/LICENSE_1_0.txt)
*/
//==================================================================================================
#ifndef BOOST_DISPATCH_FUNCTION_FUNCTOR_HPP_INCLUDED
#define BOOST_DISPATCH_FUNCTION_FUNCTOR_HPP_INCLUDED

#include <boost/dispatch/hierarchy/default_site.hpp>
#include <boost/dispatch/hierarchy_of.hpp>
#include <utility>

namespace boost { namespace dispatch
{
  /*!
    @ingroup group-api
    @brief Adaptable dispactch-enabled function object

    @tparam Tag
    @tparam Site
  **/
  template<typename Tag, typename Site = boost::dispatch::default_site<Tag>>
  struct functor
  {
    /*!

    **/
    template<typename Other, typename... Args> BOOST_FORCEINLINE
    auto on(Args&&... args) const
        -> decltype ( Tag::dispatch_to( Other()
                                      , boost::dispatch::hierarchy_of_t<Args>()...
                                      )( std::forward<Args>(args)...)
                    )
    {
      return Tag::dispatch_to ( Other()
                              , boost::dispatch::hierarchy_of_t<Args>()...
                              )( std::forward<Args>(args)...);
    }

    /*!
      @ingroup group-api
      @brief Architectural target rebinding

      Creates an instance of functor which shares current functor's tag but
      dispatched over a specific architecture hierarchy.

      @return a instance of functor dispatching specifically on architecture Other

      @tparam Other New architecture target to generate a functor for
    **/
    template<typename Other>
    static BOOST_FORCEINLINE functor<Tag,Other> rebind() { return {}; }

    /*!

    **/
    template<typename... Args> BOOST_FORCEINLINE
    auto operator()(Args&&... args) const
                      -> decltype ( Tag::dispatch_to( Site()
                                                    , boost::dispatch::hierarchy_of_t<Args>()...
                                                    )( std::forward<Args>(args)...)
                                  )
    {
      return Tag::dispatch_to ( Site()
                              , boost::dispatch::hierarchy_of_t<Args>()...
                              )( std::forward<Args>(args)...);
    }
  };
} }

#endif
