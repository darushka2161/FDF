/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choyda <chyoda@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 14:25:23 by choyda            #+#    #+#             */
/*   Updated: 2022/04/27 14:25:25 by choyda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "key_macos.h"
#include <stdlib.h>

/*
** Close window with 'X'
*/

int	ft_close(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	myfree(MAIN_PAD_ESC, fdf);
	exit(0);
}

/*
** Connect functions-controllers to window
*/

void	setup_controls(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, (1L << 0), key_press, fdf);
	mlx_hook(fdf->win, 17, 0, ft_close, fdf);
	mlx_hook(fdf->win, 4, (1L << 2), mouse_press, fdf);
}
