/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apayet <alex-rdc@live.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:06:33 by apayet            #+#    #+#             */
/*   Updated: 2022/07/07 13:20:37 by apayet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

/**
 * @brief Get the error array object from the struct data
 * 
 * @return int** 
 */
int				**get_error_array(void);

/**
 * @brief Set the error state object
 * 			When a error occur this function is call with the right enum 
 * 			=> typedef enum e_error
 * 
 * @param enum_error 
 * @return t_error_state* 
 */
t_error_state	*set_error_state(unsigned int enum_error);

/**
 * @brief This function return a value
 * 			if equals to 0 || NO_ERROR
 * 			if equals to 1 || ERROR
 * @return int boolean representationn
 */
int				is_error(void);

#endif