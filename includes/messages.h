/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cauvray <cauvray@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 01:03:05 by cauvray           #+#    #+#             */
/*   Updated: 2025/02/13 20:02:04 by cauvray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# define USAGE_ERROR_MSG			"Usage: ./cub3d <map.cub>"
# define MALLOC_ERROR_MSG			"Malloc error."
# define INVALID_MAP_MSG			"Map is invalid."
# define INVALID_PATH_MSG			"Path is invalid."
# define INVALID_CHAR_MSG			"Invalid char in map."
# define DUPLICATE_START_MSG		"Player start is duplicate."
# define MISSING_COMPONENT_MSG		"Component is missing."
# define EMPTY_LINE_IN_MAP_MSG		"Empty line in map"
# define INVALID_MAP_LINE_MSG		"Line in map is invalid"
# define INVALID_TEXTURE_LINE_MSG	"Line in textures is invalid"
# define INVALID_MAP_EXT_MSG		"Map must be .cub extension"
# define CANNOT_OPEN_FILE_MSG		"Map file can't be opened."
# define MAP_BEFORE_TEXTURES_MSG	"Map must be after the textures."

# define MISSING_TEXTURE_MSG		"texture is missing."
# define MISSING_COLOR_MSG			"color is missing."
# define INVALID_TEXTURE_MSG		"texture is invalid."
# define INVALID_COLOR_MSG			"color is invalid."
# define INVALID_TEXTURE_EXT_MSG	"texture must be .png."
# define DUPLICATE_TEXTURE_MSG		"texture is duplicate."
# define DUPLICATE_COLOR_MSG		"color is duplicate."

# define INVALID_ANIM_FILE			"Anim file is invalid"
# define TEXTURE_LOAD_ERROR_MSG		"Unable to load texture "
# define OPEN_READ_FILE_ERROR_MSG	"Unable to open or read file: "
# define INVALID_ANIM_TEXTURE		"Invalid anim texture at index "
#endif
