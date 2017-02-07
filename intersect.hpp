#ifndef INTERSECT_HPP
#define INTERSECT_HPP

#include "simplex.hpp"

// returns true iff the intersection of the interiors of triangle_a and triangle_b is not empty

template <typename value_type>
bool intersect(const simplex<2, 3, value_type> &triangle_a, const simplex<2, 3, value_type> &triangle_b)
{
    return false ;
}

#endif
