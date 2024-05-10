/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   triangle.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/08 18:00:14 by smclacke      #+#    #+#                 */
/*   Updated: 2024/05/10 15:13:03 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/miniRT.h"

// Triangle

// Definition:
//  C is a vertex of our choice
//  V is a normal of the plane on which the triangle lies
//  V1 is a vector from vertex C to vertex C1 (V1=C1-C)
//  V2 is a vector from vertex C to vertex C2 (V2=C2-C)

// To hit a triangle we first hit a plane on which it lies, in the same manner as we hit a regular plane. 
// Then the two other triangle vertices give us a point to calculate two coefficients that tell us where 
// exactly we are on the triangle.

//    t = - X|V / D|V
//    P = C + V1*p + V2*q
// Solution:

//    P - C = V1*p + V2*q
//    [ Px-Cx ] = [ V1.x V2.x ] * [ p ]
//    [ Py-Cy ]   [ V1.y V2.y ]   [ q ]
// To calculate p and q we don't need the whole V1 and V2 vectors, we just need their x and y values 
// (or z are good as well). We yet have to calculate an inverse of the matrix in the above equation, 
// but this is a precalculation step.
// To determine whether the point P we hit actually lies within the triangle, we just have to ensure 
// that the scalar values p, q and their sum are within range [0,1].

// If we hit the triangle, we can use the p and q values to calculate (smooth) normals and to calculate 
// texture coordinates. Usually triangles build up bigger meshes, so we don't have to worry about flipping 
// the surface normal if we hit it from the back (like in case of a plane).

// A triangle for raytracing actually takes a little bit more space than for a regular scanline rendering 
// algorithm (e.g. OpenGL). That's because we have one more vector (V) and we have to keep original V1 and 
// V2 for rotations and scaling from frame to frame. We also have to calculate the inverse matrix per frame, 
// what takes additional time. What's more, we have to adapt a special hit test scheme for meshes, so that we 
// don't waste cycles on testing all triangles in a mesh. Perhaps a bounding volume hierarchy is a solution. 
// Nevertheless every additional thing takes up memory, and that's why triangles are not the most efficient 
// objects for raytracing, especially in complex scenes.

bool		intersect_triangle(t_ray *ray, t_objs *tri, t_obj_data *obj_data)
{
	t_vec3	vec1;
	t_vec3	vec2;
	t_vec3	pvec;
	t_vec3	tvec;
	t_vec3	normal;
	float	dir;

	vec1 = minus(tri->point2, tri->point1);
	vec2 = minus(tri->point3, tri->point1);

	normal = cross_product(vec1, vec2);
	dir = dot_product(normal, ray->vector);

	// pvec = cross_product(ray->vector, vec2);

	if (fabs(dir) < EPSILON)
		return (false);
		
	obj_data->a = -dot_product(normal, tri->point1);
	obj_data->t = -(dot_product(ray->place, normal) + obj_data->a) / dir;
	
	if (obj_data->t < EPSILON || !check_closest(obj_data))
		return (false);

	if (quadratic(obj_data))
	{
		ray->place = normal;
	
	}

	
		
	// obj_data->c = 1 / obj_data->t;
	// tvec = minus(ray->place, tri->point1);
	// obj_data->a = dot_product(vec1, pvec) * obj_data->c;
	// if (obj_data->a < 0 || obj_data->a > 1)
	// 	return (false);
	// tvec = cross_product(tvec, vec1);
	// obj_data->b = dot_product(ray->vector, tvec) * obj_data->c;
	// if (obj_data->b < 0 || obj_data->a + obj_data->b > 1)
	// 	return (false);
	// obj_data->t = dot_product(vec2, tvec) * obj_data->c;
	return (true);
}


// bool		intersect_triangle(t_ray *ray, t_objs *tri, t_obj_data *obj_data)
// {
// 	t_vec3	vec1;
// 	t_vec3	vec2;
// 	t_vec3	pvec;
// 	t_vec3	tvec;
// 	t_vec3	normal;

// 	vec1 = minus(tri->point2, tri->point1);
// 	vec2 = minus(tri->point3, tri->point1);

	// normal = mult_vecvec(vec1, vec2);

// 	pvec = cross_product(ray->vector, vec2);
// 	obj_data->t = dot_product(vec1, pvec);

// 	if (fabs(obj_data->t) < EPSILON)
// 		return (false);
// 	obj_data->c = 1 / obj_data->t;
// 	tvec = minus(ray->place, tri->point1);
// 	obj_data->a = dot_product(vec1, pvec) * obj_data->c;
// 	if (obj_data->a < 0 || obj_data->a > 1)
// 		return (false);
// 	tvec = cross_product(tvec, vec1);
// 	obj_data->b = dot_product(ray->vector, tvec) * obj_data->c;
// 	if (obj_data->b < 0 || obj_data->a + obj_data->b > 1)
// 		return (false);
// 	obj_data->t = dot_product(vec2, tvec) * obj_data->c;
// 	return (true);
// }
