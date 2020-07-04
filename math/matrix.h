#ifndef VOXELGAME_MATRIX_H
#define VOXELGAME_MATRIX_H

#include <iostream>
#include <cmath>
#include <cstring>
#include <cassert>

#include "vector.h"

// common functionality for all matrices
template <typename T, int R, int C>
struct basematrix
{
public:
    T data[R*C];
    explicit basematrix(const T d[R*C])
    {
        for (int i = 0; i < R*C; i++)
            data[i] = d[i];
    }
    basematrix() = default;

    T operator[](const int i) const { assert(0 <= i && i < R*C); return data[i]; }
    T& operator[](const int i) { assert(0 <= i && i < R*C); return data[i]; }

    T operator()(const int r, const int c) const { assert(0 <= r && r < R && 0 <= c && c < C); return data[r*C + c]; }
    T& operator()(const int r, const int c) { assert(0 <= r && r < R && 0 <= c && c < C); return data[r*C + c]; }
};

// standard matrices add nothing new
template <typename T, int R, int C>
struct matrix : basematrix<T, R, C>
{
    using basematrix<T,R,C>::basematrix;
};

// common functionality for all square matrices
template <typename T, int S>
struct basesquarematrix : basematrix<T, S, S>
{
    using basematrix<T,S,S>::basematrix;

    matrix<T, S, S>& identity()
    {
        for (int row = 0; row < S; row++)
        {
            for (int col = 0; col < S; col++)
            {
                (*this)(row, col) = (row == col);
            }
        }
        return static_cast<matrix<T,S,S>&>(*this);
    }

    matrix<T, S, S>& translate(const vector<T, S-1>& v)
    {
        for (int row = 0; row < S; row++)
        {
            for (int col = 0; col < S-1; col++)
            {
                (*this)(row, col) = (row == col);
            }
        }

        for (int row = 0; row < S-1; row++)
            (*this)(row, S-1) = v[row];

        (*this)(S-1, S-1) = 1;

        return static_cast<matrix<T,S,S>&>(*this);
    }

    matrix<T, S, S>& scale_same_dim(const vector<T, S>& v)
    {
        for (int row = 0; row < S; row++)
        {
            for (int col = 0; col < S; col++)
            {
                (*this)(row, col) = (row == col) * v[row];
            }
        }

        return static_cast<matrix<T,S,S>&>(*this);
    }

    matrix<T, S, S>& scale(const vector<T, S-1>& v)
    {
        for (int row = 0; row < S-1; row++)
        {
            for (int col = 0; col < S; col++)
            {
                (*this)(row, col) = (row == col) * v[row];
            }
        }

        for (int col = 0; col < S-1; col++)
            (*this)(S-1, col) = 0;

        (*this)(S-1, S-1) = 1;

        return static_cast<matrix<T,S,S>&>(*this);
    }
};

// standard square matrices add nothing new
template <typename T, int S>
struct matrix<T, S, S> : basesquarematrix<T, S>
{
    using basesquarematrix<T, S>::basesquarematrix;
};

// specific case of square matrices that are 4x4
template <typename T>
struct matrix<T, 4, 4> : basesquarematrix<T, 4>
{
    using basesquarematrix<T, 4>::basesquarematrix;
    matrix<T, 4, 4>& x_rotate(T angle)
    {
        angle = static_cast<T>(angle * 3.14159265358979323846 / 180.0);

        (*this)[0*4 + 0] = 1;
        (*this)[0*4 + 1] = 0;
        (*this)[0*4 + 2] = 0;
        (*this)[0*4 + 3] = 0;

        (*this)[1*4 + 0] = 0;
        (*this)[1*4 + 1] = static_cast<T>(cos(angle));
        (*this)[1*4 + 2] = -static_cast<T>(sin(angle));
        (*this)[1*4 + 3] = 0;

        (*this)[2*4 + 0] = 0;
        (*this)[2*4 + 1] = static_cast<T>(sin(angle));
        (*this)[2*4 + 2] = static_cast<T>(cos(angle));
        (*this)[2*4 + 3] = 0;

        (*this)[3*4 + 0] = 0;
        (*this)[3*4 + 1] = 0;
        (*this)[3*4 + 2] = 0;
        (*this)[3*4 + 3] = 1;
        return *this;
    }

    matrix<T, 4, 4>& y_rotate(T angle)
    {
        angle = static_cast<T>(angle * 3.14159265358979323846 / 180.0);

        (*this)[0*4 + 0] = static_cast<T>(cos(angle));
        (*this)[0*4 + 1] = 0;
        (*this)[0*4 + 2] = static_cast<T>(sin(angle));
        (*this)[0*4 + 3] = 0;

        (*this)[1*4 + 0] = 0;
        (*this)[1*4 + 1] = 1;
        (*this)[1*4 + 2] = 0;
        (*this)[1*4 + 3] = 0;

        (*this)[2*4 + 0] = -static_cast<T>(sin(angle));
        (*this)[2*4 + 1] = 0;
        (*this)[2*4 + 2] = static_cast<T>(cos(angle));
        (*this)[2*4 + 3] = 0;

        (*this)[3*4 + 0] = 0;
        (*this)[3*4 + 1] = 0;
        (*this)[3*4 + 2] = 0;
        (*this)[3*4 + 3] = 1;
        return *this;
    }

    matrix<T, 4, 4>& z_rotate(T angle)
    {
        angle = static_cast<T>(angle * 3.14159265358979323846 / 180.0);

        (*this)[0*4 + 0] = static_cast<T>(cos(angle));
        (*this)[0*4 + 1] = -static_cast<T>(sin(angle));
        (*this)[0*4 + 2] = 0;
        (*this)[0*4 + 3] = 0;

        (*this)[1*4 + 0] = static_cast<T>(sin(angle));
        (*this)[1*4 + 1] = static_cast<T>(cos(angle));
        (*this)[1*4 + 2] = 0;
        (*this)[1*4 + 3] = 0;

        (*this)[2*4 + 0] = 0;
        (*this)[2*4 + 1] = 0;
        (*this)[2*4 + 2] = 1;
        (*this)[2*4 + 3] = 0;

        (*this)[3*4 + 0] = 0;
        (*this)[3*4 + 1] = 0;
        (*this)[3*4 + 2] = 0;
        (*this)[3*4 + 3] = 1;
        return *this;
    }

    matrix<T, 4, 4>& perspective(T aspect, T fov, T near, T far)
    {
        fov = static_cast<T>(fov * 3.14159265358979323846 / 180.0);

        (*this)[0*4 + 0] = 1 / (aspect * static_cast<T>(tan(fov/2)));
        (*this)[0*4 + 1] = 0;
        (*this)[0*4 + 2] = 0;
        (*this)[0*4 + 3] = 0;

        (*this)[1*4 + 0] = 0;
        (*this)[1*4 + 1] = 1 / static_cast<T>(tan(fov/2));
        (*this)[1*4 + 2] = 0;
        (*this)[1*4 + 3] = 0;

        (*this)[2*4 + 0] = 0;
        (*this)[2*4 + 1] = 0;
        (*this)[2*4 + 2] = - (far + near) / (far - near);
        (*this)[2*4 + 3] = - 2 * (far * near) / (far - near);

        (*this)[3*4 + 0] = 0;
        (*this)[3*4 + 1] = 0;
        (*this)[3*4 + 2] = -1;
        (*this)[3*4 + 3] = 0;
        return *this;
    }
};

template <typename T, int L, int I, int R>
matrix<T, L, R> operator*(const matrix<T, L, I>& a, const matrix<T, I, R>& b)
{
    matrix<T, L, R> newmat {};

    for (int row = 0; row < L; row++)
    {
        for (int col = 0; col < R; col++)
        {
            T sum = 0;
            for (int i = 0; i < I; i++)
            {
                T lhs = a(row, i);
                T rhs = b(i, col);
                sum += lhs * rhs;
            }

            newmat(row, col) = sum;
        }
    }

    return newmat;
}

template<typename T, int R, int N>
vector<T, R> operator*(const matrix<T, R, N>& a, const vector<T, N>& b)
{
    vector<T, R> newvec{};
    for (int i = 0; i < R; i++)
    {
        T sum = 0;
        for (int j = 0; j < N; j++)
            sum += a(i,j) * b[j];
        newvec[i] = sum;
    }
    return newvec;
}

// assumes Nth component of vector is 1.
template<typename T, int R, int N>
vector<T, R-1> operator*(const matrix<T, R, N>& a, const vector<T, N-1>& b)
{
    vector<T, R-1> newvec{};
    for (int i = 0; i < R-1; i++)
    {
        T sum = 0;
        for (int j = 0; j < N-1; j++)
            sum += a(i,j) * b[j];
        sum += a(i, N-1);
        newvec[i] = sum;
    }
    return newvec;
}

template <typename T, int R, int C>
std::ostream& operator<<(std::ostream& s, matrix<T, R, C> m)
{
    for (int row = 0; row < R; row++)
    {
        for (int col = 0; col < C-1; col++)
        {
            s << m(row, col) << ", ";
        }
        s << m(row, C-1) << std::endl;
    }
    return s;
}

typedef matrix<float, 4, 4> mat4f;
typedef matrix<double, 4, 4> mat4d;
typedef matrix<float, 3, 3> mat3f;
typedef matrix<double, 3, 3> mat3d;
typedef matrix<float, 2, 2> mat2f;
typedef matrix<double, 2, 2> mat2d;

#endif //VOXELGAME_MATRIX_H
