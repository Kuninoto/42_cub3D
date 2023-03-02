/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:56:02 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/02 12:30:25 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR3_H
# define VECTOR3_H

# include <unistd.h>
# include <math.h>

typedef struct s_vec3 {
	float	x;
	float	y;
	float	z;
}				t_vec3;

/* The product vector will have its origin on the v's origin 
	and its end point at u's end point */
static inline t_vec3	add_vecs(t_vec3 v, t_vec3 u) {
	return ((t_vec3) {x: v.x + u.x,
					  y: v.y + u.y,
				 	  z: v.z + u.z});
}

/* Invert v's direction and lessses its length in the length value of u */
static inline t_vec3 subt_vec3(t_vec3 v, t_vec3 u) {
	return ((t_vec3) {x: v.x + (-u.x),
					  y: v.y + (-u.y),
					  z: v.z + (-u.z)});
}

/* Change vector's length to times v */
static inline void mult_vec3(t_vec3 *v, int times) {
	v->x *= times;
	v->y *= times;
	v->z *= times;
}

/* MUST STUDY */

static inline t_vec3 div_vec3(t_vec3 *v, int denominator) {
	v->x /= denominator;
	v->y /= denominator;
	v->z /= denominator;
}

static inline float dot_vec3_product(t_vec3 v, t_vec3 u)
{
	return (v.x * u.x + 
			v.y * u.y +
			v.z * v.z);
}

static inline t_vec3 cross_vec3_product(t_vec3 v, t_vec3 u)
{
	return ((t_vec3) { x: (v.y * u.z) - (v.z * u.y),
					   y: (v.z * u.x) - (v.x * u.z),
					   z: (v.x * u.y) - (v.y * u.x)});
}

static inline float get_vec3_magnitude(t_vec3 v)
{	
	return (sqrt(pow(v.x, 2.0) +
				 pow(v.y, 2.0) +
				 pow(v.z, 2.0)));
}

/* Normalizes the vector to which v points to */
static inline void normalize_vec3(t_vec3 *v)
{
	float vec3_length;

	vec3_length = get_vec3_magnitude(*v);
	v->x /= vec3_length;
	v->y /= vec3_length;
	v->z /= vec3_length;
}

/* Returns a new vector equal to v but with a magnitude of 1 */
static inline t_vec3 normalized_vec3(t_vec3 v)
{
	float vec3_length;

	vec3_length = get_vec3_magnitude(v);
	return ((t_vec3) { x: v.x /= vec3_length,
					   y: v.y /= vec3_length,
					   z: v.z /= vec3_length,
					 });
}

static inline t_vec3 copy_vec3(t_vec3 v)
{
	return ((t_vec3) {x: v.x,
					  y: v.y,
					  z: v.z});
}

#endif // VECTOR3_H
