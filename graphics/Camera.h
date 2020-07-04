//
// Created by s on 7/2/20.
//

#ifndef VOXELGAME_CAMERA_H
#define VOXELGAME_CAMERA_H

#include "../math/vector.h"
#include "../math/matrix.h"

class Camera
{
public:
    vec3f position;
    float pitch, yaw, roll;

    Camera(const vec3f& position);
    virtual ~Camera() = default;

    virtual void projection_matrix(mat4f& mat) = 0;
    void view_matrix(mat4f& mat) const;
    void direction_vector(vec3f& vec) const;
    void left_vector(vec3f& vec) const;
    void right_vector(vec3f& vec) const;
};


#endif //VOXELGAME_CAMERA_H
