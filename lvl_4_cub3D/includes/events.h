/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 15:19:46 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/14 15:26:46 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

// KEYS
#ifdef OS_LINUX
# define W 119
# define A 97
# define S 115
# define D 100
# define Q 113
# define E 101
# define R 114
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

# define SPACE 32

# define ESC 65307
# define TAB 65289
# define SHIFT 65505
# define CTRL 65507

#endif

#ifdef OS_MACOS
# define W 13
# define A 0
# define S 1
# define D 2
# define Q 12
# define E 14
# define R 15
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124

# define SPACE 49

# define ESC 53
# define TAB 48
# define SHIFT 257
# define CTRL 256

#endif


// MOUSE

# define LEFT_CLICK 1
# define WHEEL_CLICK 2
# define RIGHT_CLICK 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5

// EVENTS

# define KEYPRESS_EVENT 2
# define KEYRELEASE_EVENT 3
# define MOTION_NOTIFY 6
# define DESTROY_NOTIFY_EVENT 17

#endif // EVENTS_H