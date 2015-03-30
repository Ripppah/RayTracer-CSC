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

	return false;
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
	
	double discriminant = b * b - 4 * a * c;
        if(discriminant < 0){
                return intersection;
        }
        else{
                double root1 = (-b + sqrt(discriminant)) / (2 * a);
                double root2 = (-b - sqrt(discriminant)) / (2 * a);
                if (root1 > 0 && root2 > 0 && root1 < root2){
                        t_value = root1;
                        intersection = true;
                }else if (root2 > 0 && root1 <= 0) {
                        t_value = root2;
                        intersection = true;
                }else if (root1 > 0 && root2 <= 0){
                        t_value = root1;
                        intersection = true;
                }
        }

        Point3D intersectionPoint = rayObjectModel.point_at(t_value);

        if(ray.intersection.none || t_value < ray.intersection.t_value){
                intersection = true
                ray.intersection.point = modelToWorld * intersectionPoint;
                ray.intersection.normal = worldToModel.tranpose()*Vector3D(intersectionPoint[0], intersectionPoint[1], intersectionPoint[2]);
                ray.intersection.none = false;
                ray.intersection.t_value = t_value;
        }
        return intersection;
}

