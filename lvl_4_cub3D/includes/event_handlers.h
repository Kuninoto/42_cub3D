/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handlers.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roramos <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 23:24:57 by nnuno-ca          #+#    #+#             */
/*   Updated: 2023/03/14 20:45:38 by roramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_HANDLERS_H
# define EVENT_HANDLERS_H

# include "data.h"
# include "events.h"

int	quit_cub3d(t_data *this);
int	on_keypress(int key, t_data *this);
int	on_keyrelease(int key, t_data *this);
int	mouse_handler(int x, int y, t_data *this);

#endif // EVENT_HANDLERS_H