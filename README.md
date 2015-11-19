# Boost.Dispatch

Boost.Dispatch is a Boost candidate library that aims at providing an idiomatic way to use tag
dispatching in a way functions can be extended or specialized, with each specialization being able
to be generic with the minimal amount of work required. With tag dispatching, it
becomes then possible to select the best specialization for the arguments provided, avoiding
the limitations inherent to unconstrained template function overloads.

Boost.Dispatch solves these problems through two related components:

  * An extensible hierarchy system that contains ready-made hierarchies and that
    can be easily extended. This provides a powerful and idiomatic way to define
    tags embedding arbitrary level of intentionality.

  * A dispatching mechanism built on top of the hierarchies and overloading,
    that automates the use of tag dispatching with one or all arguments.

## Sample Usage

### Type Hierarchies

Fundamental and standard types are automatically hierarchized using a recursive, bottom-up descriptive set of hierarchy tags that allow fine to coarse grain type discrimination. A sample
tag-dispatched function can then be written like:

```cpp
#include <boost/dispatch/hierarchy_of.hpp>
#include <boost/dispatch/hierarchy.hpp>

using namespace boost::dispatch;

// C call for float
template<typename T> T absolute_value(T t, scalar_<single_<T>> const&)
{
  return ::fabs(t);
}

// C call for double
template<typename T> T absolute_value(T t, scalar_<double_<T>> const&)
{
  return ::abs(t);
}

// Regular abs implementation for integers
template<typename T> T absolute_value(T t, scalar_<integer_<T>> const&)
{
  return t < 0 ? -t : t;
}

// abs is identity or unsigned value
template<typename T> T absolute_value(T t, scalar_<unsigned_<T>> const&)
{
  return t;
}

// User-level function
template<typename T> T absolute_value(T t)
{
  return absolute_value(t, hierarchy_of(t) );
}
```

### Tag-Dispatched Callable Object

COMING SOON

## More informations

* Repository    : https://github.com/numscale/boost.dispatch
* Documentation : http://numscale.github.io/boost.dispatch

## Continuous Integration

| Platform & Compiler | `master`| `develop`|
|---------------------|---------|----------|
| Linux clang & g++   | [![Build Status](https://travis-ci.org/numscale/boost.dispatch.png?branch=master)](https://travis-ci.org/numscale/boost.dispatch) | [![Build Status](https://travis-ci.org/numscale/boost.dispatch.png?branch=develop)](https://travis-ci.org/numscale/boost.dispatch) |
| OS X   clang    | [![Build Status](https://travis-ci.org/numscale/boost.dispatch.png?branch=master)](https://travis-ci.org/numscale/boost.dispatch) | [![Build Status](https://travis-ci.org/numscale/boost.dispatch.png?branch=develop)](https://travis-ci.org/numscale/boost.dispatch) |
| Windows  MSVC 2012 | [![Build status](https://ci.appveyor.com/api/projects/status/od5x8urfct3l52a6/branch/master?svg=true)](https://ci.appveyor.com/project/numscale/boost-dispatch/branch/master) | [![Build status](https://ci.appveyor.com/api/projects/status/od5x8urfct3l52a6/branch/develop?svg=true)](https://ci.appveyor.com/project/numscale/boost-dispatch/branch/develop) |
