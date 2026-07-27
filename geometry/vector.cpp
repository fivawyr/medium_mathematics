#include <iostream>
#include <cstdint>

using namespace std;

typedef int32_t i32;
typedef float f32;
typedef double f64;

/*
 * Before learning templates, I always implemented a simple vector as a struct.
 * That approach is perfectly valid, but a templated vector class has several
 * advantages:
 *
 *  - The vector can be instantiated with different data types
 *    (e.g. Vec3<int>, Vec3<float>, Vec3<double>) without duplicating code.
 *  - Constructors provide convenient initialization and sensible default values.
 *  - Vec3(const T& xx) initializes all three coordinates with the same value.
 *  - A class can later be extended easily with operators and member functions
 *    (addition, subtraction, normalization, dot product, ...).
 *
 * Note:
 * The main difference between a struct and a class in C++ is that struct members
 * are public by default, whereas class members are private by default.
 */


template<typename T> class Vec3 {
    public: // public members -> same as struct but we could them private (no need for vectors)
        Vec3() : x(T(0)), y(T(0)), z(T(0)) {} // Default constructor for 0 as standard value 
        Vec3(const T &xx) : x(xx),  y(xx), z(xx) {} // single-value constructor same value for all coords
        Vec3(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {} // three-value ... more flexible 
        T x, y, z;

        T length() {
            return sqrt((x * x) + (y * y) + (z * z));
        }

        T dot(const Vec3<T> &v) const {
            return x * v.x + y * v.y + z * v.z;

        }

        Vec3<T> &normalize() {
            T len = length(); 
            if (len > 0) {
                T invLen = 1 / len;
                x *= invLen, y *= invLen, z *= invLen;
            }
            return *this;
        }


};

/* 
 * I use this approve for transformation because the importance of respecting the difference between 
 * vectors, normals and points are so crucial, the template class helps to avoid issues 
 */

typedef Vec3<f32> Vec3f;

int main() {
    cout << "Hello Vector" << "\n";
}

