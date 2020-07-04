#include "Camera.h"

Camera::Camera(const vec3f& position): position{position}, pitch{0}, yaw{0}, roll{0} {}

void Camera::view_matrix(mat4f &mat) const
{
    mat4f temp{};
    mat.identity();

    temp.x_rotate(-pitch);
    mat = mat * temp;

    temp.y_rotate(-yaw);
    mat = mat * temp;

    temp.z_rotate(-roll);
    mat = mat * temp;

    temp.translate(-1.0f * position);
    mat = mat * temp;
}

void Camera::direction_vector(vec3f &vec) const
{
    mat4f temp{};
    vec = {0, 0, -1};

    temp.x_rotate(pitch);
    vec = temp * vec;

    temp.y_rotate(yaw);
    vec = temp * vec;
}

void Camera::left_vector(vec3f &vec) const
{
    direction_vector(vec);
    float temp = vec.x;

    vec.x = vec.z;
    vec.y = 0;
    vec.z = -temp;

    normalize(vec);
}

void Camera::right_vector(vec3f &vec) const
{
    direction_vector(vec);
    float temp = vec.x;

    vec.x = -vec.z;
    vec.y = 0;
    vec.z = temp;

    normalize(vec);
}
