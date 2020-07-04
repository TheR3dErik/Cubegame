#ifndef VOXELGAME_VECTOR_H
#define VOXELGAME_VECTOR_H

#include <iostream>
#include <cmath>
#include <cassert>

template <typename T, int N>
struct vector
{
    T data[N];
    T operator[](const int i) const { assert(0 <= i && i < N); return data[i]; }
    T& operator[](const int i) { assert(0 <= i && i < N); return data[i]; }
};

template <typename T>
struct vector <T, 4>
{
    union
    {
        struct
        {
            T x, y, z, w;
        };
        T data[4];
    };
    T operator[](const int& i) const { assert(0 <= i && i < 4); return data[i]; }
    T& operator[](const int& i) { assert(0 <= i && i < 4); return data[i]; }
};

template <typename T>
struct vector <T, 3>
{
    union
    {
        struct
        {
            T x, y, z;
        };
        T data[3];
    };
    T operator[](const int& i) const { assert(0 <= i && i < 3); return data[i]; }
    T& operator[](const int& i) { assert(0 <= i && i < 3); return data[i]; }

    vector& cross(const vector& other)
    {
        T newx = y * other.z - z * other.y;
        T newy = z * other.x - x * other.z;
        T newz = x * other.y - y * other.x;

        x = newx;
        y = newy;
        z = newz;

        return this;
    }
};

template <typename T>
struct vector <T, 2>
{
    union
    {
        struct
        {
            T x, y;
        };
        T data[2];
    };
    T operator[](const int& i) const { assert(0 <= i && i < 2); return data[i]; }
    T& operator[](const int& i) { assert(0 <= i && i < 2); return data[i]; }

    T cross(const vector& other)
    {
        return x * other.y - y * other.x;
    }
};

typedef vector<float, 4> vec4f;
typedef vector<double, 4> vec4d;
typedef vector<float, 3> vec3f;
typedef vector<double, 3> vec3d;
typedef vector<float, 2> vec2f;
typedef vector<double, 2> vec2d;

template <typename T, int N>
T len2(const vector<T, N>& v)
{
    T sum = 0;
    for (int i = 0; i < N; i++)
        sum += v[i] * v[i];
    return sum;
}

template <typename T, int N>
T len(const vector<T, N>& v)
{
    return sqrt(len2(v));
}

template <typename T, int N>
vector<T, N> normalize(const vector<T, N>& v)
{
    auto n = v;
    n /= len(v);
    return n;
}

template <typename T>
vector<T, 3> cross(const vector<T, 3>& a, const vector<T, 3>& b)
{
    return { a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x };
}

template <typename T, int N>
vector<T, N>& operator+=(vector<T, N>& a, const vector<T, N>& b)
{
    for (int i = 0; i < N; i++)
        a[i] += b[i];
    return a;
}

template <typename T, int N>
vector<T, N>& operator-=(vector<T, N>& a, const vector<T, N>& b)
{
    for (int i = 0; i < N; i++)
        a[i] -= b[i];
    return a;
}

template <typename T, int N>
vector<T, N>& operator*=(vector<T, N>& a, const T& b)
{
    for (int i = 0; i < N; i++)
        a[i] *= b;
    return a;
}

template <typename T, int N>
vector<T, N>& operator/=(vector<T, N>& a, const T& b)
{
    for (int i = 0; i < N; i++)
        a[i] /= b;
    return a;
}

template <typename T, int N>
vector<T, N> operator*(const vector<T, N>& a, const T& b)
{
    vector<T, N> newvec = a;
    for (int i = 0; i < N; i++)
        newvec[i] *= b;
    return newvec;
}

template <typename T, int N>
vector<T, N> operator*(const T& b, const vector<T, N>& a)
{
    return a*b;
}

template<typename T, int N>
T dot(vector<T, N> a, vector<T, N> b)
{
    T sum = 0;
    for (int i = 0; i < N; i++)
        sum += a[i] * b[i];
    return sum;
}

template <typename T, int N>
std::ostream& operator<<(std::ostream& s, const vector<T, N> op)
{
    for (int i = 0; i < N-1; i++)
        s << op[i] << ", ";
    s << op[N-1];
    return s;
}

#endif //VOXELGAME_VECTOR_H
