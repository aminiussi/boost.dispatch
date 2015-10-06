Design Rationale {#rationale}
================

@tableofcontents

@section main-rationale Rationale of Boost.Dispatch

----------------------------------------------------------------------------------------------------

The objective of Boost.Dispatch is to allow a flexible, scalable and easily extensible system
for writing functions and functors dispatching using a generic Tag Dispatching system. This
section will discuss what are the current options and why Boost.Dispatch helps making this idiom
more generic and usable.

@subsection main-free-function Free function dispatching

Let us consider a fairly artificial scenario, but representative of things that are quite common
in generic programming: we want to define a unary function `f`, for all built-in arithmetic types,
that implements different algorithms depending on the actual type of the argument. For example,
consider that `f` returns 0 if its argument is a floating point value, returns 1 if it is a signed
integer or return 2 otherwise. You could do this using *SFINAE* and `boost::enable_if` in
the following way:

@snippet rationale.cpp basic

The SFINAE approach clearly doesn't scale in terms of programming, since all
overloads must be mutually exclusive, but also in terms of compilation times,
since SFINAE-based overload resolution is linear.

Another solution, which is heralded by the Standard Template Library itself
is to use a technique known as Tag Dispatching:

@snippet rationale.cpp tagdispatching

By using a hierarchy of types bound by inheritance, it's possible to make use
of the best-match feature of C++ overloading to introduce specializations
without requiring them to be mutually exclusive. The `iterator_category`
system of standard iterators is a good example of that.

Doing this in a clean, concise, reusable and idiomatic manner is however of some
difficulty, which is why that is only done in an ad-hoc way in practice.

@subsection main-dispatch Boost.Dispatch in action

Boost.Dispatch solves these problems through two related components:

  * An extensible hierarchy system that contains ready-made hierarchies and that
    can be easily extended. This provides a powerful and idiomatic way to define
    tags embedding arbitrary level of intentionality.

  * A dispatching mechanism built on top of the hierarchies and overloading,
    that automates the use of tag dispatching with one or all arguments.

Here is what the free function example looks like when written with Boost.Dispatch:

@snippet rationale.cpp boost

Notice how the second specialization applies to any integral type, including
unsigned ones. However, since there is also a specialization for unsigned types,
the latter gets preferred, since `unsigned_` is a refinement of `integer_`
in the built-in hierarchies.

