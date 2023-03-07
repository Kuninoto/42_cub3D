/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnuno-ca <nnuno-ca@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:24:57 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/06 16:30:15 by nnuno-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_HANDLERS_H
# define EVENT_HANDLERS_H

# include "data.h"
# include "events.h"

int	quit_cub3d(t_data *this);
int	on_keypress(int key, t_data *this);
int	on_mouseclick(int button, int x, int y, t_data *this);
int	mouse_handler(int x, int y, t_data *this);

#endif // EVENT_HANDLERS_H