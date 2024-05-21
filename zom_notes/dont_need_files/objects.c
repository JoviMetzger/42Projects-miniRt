/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   objects.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: smclacke <smclacke@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/25 16:13:52 by smclacke      #+#    #+#                 */
/*   Updated: 2024/05/21 17:54:01 by smclacke      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header/miniRT.h"


/** 
 * @todo this file can go no?
*/

// hit_data->d = discriminant; -> discriminant = b*b - 4*a*c;
// bool intersect_sphere(t_ray *ray, t_objs *sphere, t_hit_data *hit_data)
// {
//     double radius = sphere->diameter / 2;
// 	t_vec3	oc = minus(ray->place, sphere->center);
// 	hit_data->a = dot_product(ray->place, ray->vector);
// 	hit_data->b = 2.0 * dot_product(oc, ray->vector);
// 	hit_data->c = dot_product(oc, oc) - radius * radius;
// 	hit_data->d = hit_data->b * hit_data->b - 4 * hit_data->a * hit_data->c;
// 	if (hit_data->d >= 0)
// 		return (true);
// 	return (false);

// 	// double radius = sphere->diameter / 2;
// 	// t_vec3 oc = minus(sphere->center, ray->place);
// 	// hit_data->a = dot_product(ray->vector, ray->vector);
// 	// hit_data->b = 2.0 * dot_product(oc, ray->vector);
// 	// hit_data->c = dot_product(oc, oc) - radius * radius;
// 	// hit_data->d = hit_data->b * hit_data->b - 4 * hit_data->a * hit_data->c;
// 	// if (hit_data->d >= 0)
// 	// 	return true;
// 	// return false;
// }

//
// void intersect_plane(t_ray ray, t_plane plane, t_hit_data *hit_data)
// {

// }

//
// void intersect_cylinder(t_ray ray, t_cylinder cylinder, t_hit_data *hit_data)
// {

// }

// //
// void ft_create_intersection(t_data *data, t_hit_data *hit_data, t_ray ray)
// {
//     int i = 0;

//     while (i < data->total_obj_num)
//     {
//         intersect_sphere(&ray, &data->objects.sphere, hit_data);
//         // intersect_plane(&ray, &data->objects.plane, hit_data);
//         // intersect_cylinder(&ray, &data->objects.cylinder, hit_data);
//         i++;
//     }    
// }

// TEST FUNCTION,
// void ft_create_intersection(t_data *data, t_hit_data *hit_data, t_ray ray)
// {
//     int i = 0;

//     while (i < data->objs->i)
//     {
// 		if (data->objs[i].type == E_SPHERE)
// 			if (intersect_sphere(&ray, &data->objs[i], hit_data))
// 				return true;
// 		// else 
//         // 	return false;
//         // intersect_plane(&ray, &data->objects.plane, hit_data);
//         // intersect_cylinder(&ray, &data->objects.cylinder, hit_data);
//         i++;
//     }
// 	return false;
// }


// // ------------------- SOME TESTING ---------------------------
// static uint32_t	pythagoras(t_data *data, double x, double y)
// {
// 	double	mid_x = (double)data->mlx->width / 2;
// 	double	mid_y = (double)data->mlx->height / 2;
// 	double	a_len;
// 	double	b_len;

// 	a_len = fabs(x - mid_x);
// 	b_len = fabs(y - mid_y);
// 	return ((uint32_t)sqrt(a_len * a_len + b_len * b_len));
// }

// #define RADIUS 450

// void ft_testing(t_data *data, uint32_t x, uint32_t y)
// {
//     if (pythagoras(data, (double)x, (double)y) <= RADIUS)
//         mlx_put_pixel(data->image, x, y, ft_pixel(10, 0, 255));
//     else 
//         mlx_put_pixel(data->image, x, y, ft_pixel(0, 0, 0));
// }

// // ------------------------------------------------------------