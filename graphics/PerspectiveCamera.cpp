#include "PerspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera(vec3f position, float aspect, float fov, float near,
                                     float far) : Camera(position), aspect_ratio{aspect}, near{near}, far{far}
{
    set_fov(fov);
}

void PerspectiveCamera::projection_matrix(mat4f &mat)
{
    mat.perspective(aspect_ratio, fov, near, far);
}
