#include <cstdint>

typedef uint8_t u8;
typedef int32_t i32; 

template<typename T>
class Matrix44 {
    public: 
        Matrix44() {}
        const T *operator [] (u8 i) const {return m[i];}
        T *operator [] (u8 i) {return m[i];}
        T m [4][4] = {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}, {0, 0, 0, 1}};
};

// access: Matrix44 mat; 
// mat[0][3] = 1.f;

int main() {

}
