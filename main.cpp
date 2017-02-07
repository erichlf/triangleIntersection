#include "intersect.hpp"

#include <iostream>
#include <cstdlib>

template <typename value_type>
value_type random(const value_type &maximum)
{
    return maximum * rand() / RAND_MAX ;
}

template <typename value_type>
point<3, value_type> make_random_point3(const value_type &maximum)
{
    return make_point(random(maximum), random(maximum), random(maximum)) ;
}

// generates a triangle in 3-dimensions whose vertices are uniformly spread within cube (0, 0, 0).(maximum, maximum, maximum)

template <typename value_type>
simplex<2, 3, value_type> make_random_simplex23(const value_type &maximum)
{
    return make_simplex(make_random_point3(maximum), make_random_point3(maximum), make_random_point3(maximum)) ;
}

int main(int argc, const char *argv[])
{
    typedef double coord_type ;
    typedef point<3, coord_type> point3_type ;
    typedef simplex<2, 3, coord_type> simplex23_type ;

    const point3_type p1 = make_point(1.0, 2.0, 3.0),
                      p2 = make_point(2.0, 3.0, 4.0),
                      p3 = make_point(3.0, 4.0, 5.0) ;

    std::cout << "p1: " << p1 << std::endl ;
    std::cout << "p2: " << p2 << std::endl ;
    std::cout << "p3: " << p3 << std::endl ;

    const simplex23_type triangle_a = make_simplex(p1, p2, p3),
                         triangle_b = make_random_simplex23(1.0) ;

    std::cout << "triangle_a: " << triangle_a << std::endl ;
    std::cout << "triangle_b: " << triangle_b << std::endl ;
    std::cout << "intersect: " << intersect(triangle_a, triangle_b) << std::endl ;

    return 0 ;
}
