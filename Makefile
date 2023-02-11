.PHONY:     			all $(NAME) clear mkbuild lib minilibx clear clean fclean re sanitize

NAME					= fdf

BUILD_DIR				= build/
	
HEADER_DIR				= header/
HEADER_FILE				= fdf.h

DIR						= src/
SRC			 			= 	main.c mlx_draw.c parsing_map.c map_utilities.c window_manager.c key_hook.c parsing_map_utils.c memory_management.c
							
OBJECTS			    	= $(SRC:%.c=$(BUILD_DIR)%.o)
	
LIBFT					= libft.a
LIB_DIR					= libft/

	
GCC						= gcc
CFLAGS					= -Wall -Werror -Wextra
SANITIZE				= $(CFLAGS) -g3 -fsanitize=address

RM 						= rm -rf
CLEAR					= clear

MINILIB					= libmlx.a

#MINILIB_DIR				= minilibx_macos/
#MAC						= -framework OpenGL -framework AppKit

MINILIB_DIR			= minilibx_linux/
LINUX					= -Lminilibx_linux -L/usr/lib -Iminilibx_linux -lXext -lX11 -lm -lz

$(BUILD_DIR)%.o:		$(DIR)%.c $(HEADER_DIR)/$(HEADER_FILE)
						@mkdir -p $(@D)
						$(GCC) $(CFLAGS) -I$(HEADER_DIR) -I$(LIB_DIR) -I$(MINILIB_DIR) -I/usr/include -Imlx_linux -O3 -c $< -o $@

all: 					clear mkbuild lib minilibx $(HEADER_DIR) $(NAME) 
						
mkbuild:
						@mkdir -p build

clear:
						$(CLEAR)
						
$(NAME): 				$(OBJECTS) $(LIB_DIR)$(LIBFT)
						$(GCC) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(MINILIB_DIR)$(MINILIB) $(LINUX)

sanit :					$(OBJECTS) $(LIB_DIR)$(LIBFT)
						$(GCC) $(SANITIZE) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(MINILIB_DIR)$(MINILIB) $(LINUX)

lib:
						@make -C $(LIB_DIR)


minilibx:
						@make -C $(MINILIB_DIR)
						
clean:					
						@${RM} $(OBJECTS)
						@make clean -C $(LIB_DIR)
						@make clean -C $(MINILIB_DIR)
						@${RM} $(BUILD_DIR)

fclean:					clean
						@${RM} ${NAME}
						@make fclean -C $(LIB_DIR)
						@make fclean -C $(MINILIB_DIR)

re:						fclean all
						$(MAKE) all