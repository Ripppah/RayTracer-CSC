/***********************************************************
     Starter code for Assignment 3

     This code was originally written by Jack Wang for
		    CSC418, SPRING 2005

		implements scene_object.h

***********************************************************/

#include <cmath>
#include <iostream>
#include "scene_object.h"

bool UnitSquare::intersect( Ray3D& ray, const Matrix4x4& worldToModel,
                const Matrix4x4& modelToWorld ) {
        // TODO: implement intersection code for UnitSquare, which is
        // defined on the xy-plane, with vertices (0.5, 0.5, 0), 
        // (-0.5, 0.5, 0), (-0.5, -0.5, 0), (0.5, -0.5, 0), and normal
        // (0, 0, 1).
        //
        // Your goal here is to fill ray.intersection with correct values
        // should an intersection occur.  This includes intersection.point, 
        // intersection.normal, intersection.none, intersection.t_value.   
        //
        // HINT: Remember to first transform the ray into object space  
        // to simplify the intersection test.

        //Transform ray to object space
        Ray3D rayObjectSpace = Ray3D(worldToModel * ray.origin, worldToModel * ray.dir);
        //point = ray.origin + t_value * ray.origin
        //point for unitsquare is (0, 0, 0)
        double t_value = -rayObjectSpace.origin[2] / rayObjectSpace.dir[2];

        Point3D intersectionPoint = rayObjectModel.point_at(t_value);
        bool intersection = false;

        if(ray.intersection.none || t_value < ray.intersection.t_value){
                intersection = true
                ray.intersection.point = modelToWorld * intersectionPoint;
                ray.intersection.normal = worldToModel.tranpose()*Vector3D(0, 0, 1);
                ray.intersection.none = false;
                ray.intersection.t_value = t_value;
        }
        return intersection;
}

bool UnitSphere::intersect( Ray3D& ray, const Matrix4x4& worldToModel,
                const Matrix4x4& modelToWorld ) {
        // TODO: implement intersection code for UnitSphere, which is centred 
        // on the origin.  
        //
        // Your goal here is to fill ray.intersection with correct values
        // should an intersection occur.  This includes intersection.point, 
        // intersection.normal, intersection.none, intersection.t_value.   
        //
        // HINT: Remember to first transform the ray into object space  
        // to simplify the intersection test.

        Ray3D rayObjectSpace = Ray3D(worldToModel * ray.origin, worldToModel * ray.dir);
        //unitSphere is radius of 1 and center at (0, 0, 0)
        double cx = rayObjectSpace.origin[0];
        double cy = rayObjectSpace.origin[1];
        double cz = rayObjectSpace.origin[2];
        double dx = rayObjectSpace.dir[0];
        double dy = rayObjectSpace.dir[1];
        double dz = rayObjectSpace.dir[2];

        double a = dx * dx + dy * dy + dz * dz;
        double b = 2 * dx * cx + 2 * dy * cy + 2 * dz * cz;
        double c = cx * cx + cy * cy + cz * cz - 1;
}

