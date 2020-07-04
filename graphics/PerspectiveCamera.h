//
// Created by s on 7/2/20.
//

#ifndef VOXELGAME_PERSPECTIVECAMERA_H
#define VOXELGAME_PERSPECTIVECAMERA_H

#include "Camera.h"

class PerspectiveCamera: public Camera
{
private:
    float fov;
public:
    float aspect_ratio, near, far;

    PerspectiveCamera(vec3f position, float aspect, float fov, float near,
                      float far);

    inline float get_fov() const { return fov; }
    inline void set_fov(float f) { if (f > 0 && f < 180) this->fov = f; }

    void projection_matrix(mat4f& mat) override;
};


#endif //VOXELGAME_PERSPECTIVECAMERA_H
