/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:56:02 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/07 19:59:10 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR2_H
# define VECTOR2_H

# include <unistd.h>
# include <math.h>

typedef struct s_vec2 {
	double	x;
	double	y;
}				t_vec2;

/* The product vector will have its origin on the v's origin 
	and its end point at u's end point */
static inline t_vec2	add_vecs(t_vec2 v, t_vec2 u) {
	return ((t_vec2) { x: v.x + u.x,
					   y: v.y + u.y });
}

/* Invert v's direction and lessses its length in the length value of u */
static inline t_vec2 subt_vec2(t_vec2 v, t_vec2 u) {
	return ((t_vec2) { x: v.x + (-u.x),
					   y: v.y + (-u.y) });
}

/* Change vector's length to times v */
static inline void mult_vec2(t_vec2 *v, int times) {
	v->x *= times;
	v->y *= times;
}

/* MUST STUDY */

static inline void div_vec2(t_vec2 *v, int denominator) {
	v->x /= denominator;
	v->y /= denominator;
}

static inline float get_vec2_magnitude(t_vec2 v)
{	
	return (sqrt(pow(v.x, 2.0) +
				 pow(v.y, 2.0)));
}

/* Normalizes the vector to which v points to */
static inline void normalize_vec2(t_vec2 *v)
{
	double vec2_length;

	vec2_length = get_vec2_magnitude(*v);
	v->x /= vec2_length;
	v->y /= vec2_length;
}

/* Returns a new vector equal to v but with a magnitude of 1 */
static inline t_vec2 normalized_vec2(t_vec2 v)
{
	double vec2_length;

	vec2_length = get_vec2_magnitude(v);
	return ((t_vec2) { x: v.x /= vec2_length,
					   y: v.y /= vec2_length });
}

static inline t_vec2 copy_vec2(t_vec2 v)
{
	return ((t_vec2) { x: v.x,
					   y: v.y });
}

#endif // VECTOR2_H