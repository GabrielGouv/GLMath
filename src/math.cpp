#include <iostream>
#include <cmath>
#include <stdexcept>

namespace GLMath {

    class MatrixIndexOutOfBoundsException: public std::exception {

    private:
        const char* msg;

    public:

        explicit MatrixIndexOutOfBoundsException(const char* msg) {
            this->msg = msg;
        }

        const char* what() const throw() {
            return msg;
        }

    };

    class VectorIndexOutOfBoundsException: public std::exception {

    private:
        const char* msg;

    public:

        explicit VectorIndexOutOfBoundsException(const char* msg) {
            this->msg = msg;
        }

        const char* what() const throw() {
            return msg;
        }

    };

    struct Vector3D {

    private:

        const char* MSG_VEC3_IOOB_EX = "Trying to access a Vector3D position out of bounds. Make sure the index entered is between 0-2";

    public:

        float x;
        float y;
        float z;

        Vector3D() = default;

        Vector3D(const float x, const float y, const float z) {
            this->x = x;
            this->y = y;
            this->z = z;
        }

        float& operator [] (const int i) {
            if (i >= 0 && i <= 2) {
                return ((&this->x)[i]);
            }
            throw VectorIndexOutOfBoundsException(MSG_VEC3_IOOB_EX);
        }

        const float& operator [] (const int i) const {
            if (i >= 0 && i <= 2) {
                return ((&this->x)[i]);
            }
            throw VectorIndexOutOfBoundsException(MSG_VEC3_IOOB_EX);
        }

        Vector3D& operator *= (float s) {
            this->x *= s;
            this->y *= s;
            this->z *= s;
            return *this;
        }

        Vector3D operator /= (float s) {
            s = 1.0f / s;
            this->x = s;
            this->y = s;
            this->z = s;
            return *this;
        }

        Vector3D operator += (const Vector3D& v) {
            this->x += v.x;
            this->y += v.y;
            this->z += v.z;
            return *this;
        }

        Vector3D operator -= (const Vector3D& v) {
            this->x -= v.x;
            this->y -= v.y;
            this->z -= v.z;
            return *this;
        }

        bool isZero() {
            return this->x == 0.0f && this->y == 0.0f && this->z == 0.0f;
        }

//    Vector3D forward() {
//        this->x = 1.0f;
//        return *this;
//    }

    };

    inline Vector3D operator * (const Vector3D& v, float s) {
        return {v.x * s, v.y * s, v.z * s};
    }

    inline Vector3D operator / (const Vector3D& v, float s) {
        s = 1.0f / s;
        return {v.x * s, v.y * s, v.z * s};
    }

    inline Vector3D operator - (const Vector3D& v) {
        return {-v.x, -v.y, -v.z};
    }

    inline Vector3D operator + (const Vector3D& a, const Vector3D& b) {
        return {a.x + b.x, a.y + b.y, a.z + b.z};
    }

    inline Vector3D operator - (const Vector3D& a, const Vector3D& b) {
        return {a.x - b.x, a.y - b.y, a.z - b.z};
    }

    inline float Magnitude(const Vector3D& v) {
        return std::sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
    }

    inline Vector3D Normalize(const Vector3D& v) {
        return v / Magnitude(v);
    }

    struct Matrix3D {

    private:

        const char* MSG_MAT3_IOOB_EX = "Trying to access a Matrix3D position out of bounds. Make sure the entered indexes are between 0-2";
        float m[3][3] {};

    public:

        Matrix3D() = default;

        Matrix3D(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22) {
            this->m[0][0] = m00; this->m[0][1] = m01; this->m[0][2] = m02;
            this->m[1][0] = m10; this->m[1][1] = m11; this->m[1][2] = m12;
            this->m[2][0] = m20; this->m[2][1] = m21; this->m[2][2] = m22;
        }

        Matrix3D(const Vector3D& v1, const Vector3D& v2, const Vector3D& v3) {
            this->m[0][0] = v1.x; this->m[0][1] = v1.y; this->m[0][2] = v1.z;
            this->m[1][0] = v2.x; this->m[1][1] = v2.y; this->m[1][2] = v2.z;
            this->m[2][0] = v3.x; this->m[2][1] = v3.y; this->m[2][2] = v3.z;
        }

        float& operator () (int i, int j) {
            if (i >= 0 && i <= 2 && j >= 0 && j <= 2) {
                return this->m[j][i];
            }
            throw MatrixIndexOutOfBoundsException(MSG_MAT3_IOOB_EX);
        }

        const float& operator () (int i, int j) const {
            if (i >= 0 && i <= 2 && j >= 0 && j <= 2) {
                return this->m[j][i];
            }
            throw MatrixIndexOutOfBoundsException(MSG_MAT3_IOOB_EX);
        }

        Vector3D& operator [] (int j) {
            if (j >= 0 && j <= 2) {
                return (*reinterpret_cast<Vector3D *>(this->m[j]));
            }
            throw MatrixIndexOutOfBoundsException(MSG_MAT3_IOOB_EX);
        }

        const Vector3D& operator [] (int j) const {
            if (j >= 0 && j <= 2) {
                return (*reinterpret_cast<const Vector3D *>(this->m[j]));
            }
            throw MatrixIndexOutOfBoundsException(MSG_MAT3_IOOB_EX);
        }

    };

}


