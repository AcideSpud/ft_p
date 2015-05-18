.PHONY: all, $(SERVEUR), $(CLIENT), clean, fclean, re
SRC_PATH	= ./src/

SRC_SERV	= serveur.c		\
			  error_serv.c	\
			  hub_serv.c	\
			  ls_cd_serv.c	\
			  tool.c		\
			  put_serv.c	\


SRC_CLIENT	= client.c		\
			  error_client.c\
			  get_client.c	\
			  put_client.c	\
			  hub_client.c	\
			  tool.c		\
			  pwd_quit_cd_ls_client.c\

OBJ_PATH	= ./obj/
INC_PATH	= ./includes/

LIB_PATH	= ./libft/
LIB_NAME	= libft.a

SERVEUR		= serveur
CLIENT		= client

CC 			= gcc
CFLAGS		= -Werror -Wall -Wextra

OBJ_SERV	= $(SRC_SERV:.c=.o)
OBJ_CLIENT	= $(SRC_CLIENT:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_SERV))
OBJ_S = $(addprefix $(OBJ_PATH), $(OBJ_SERV))
OBJ_C = $(addprefix $(OBJ_PATH), $(OBJ_CLIENT))
LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))
INC = ./includes/ft_p.h

all: $(SERVEUR) $(CLIENT)

$(SERVEUR)	: $(OBJ_S)
	@make -C $(LIB_PATH)
	@$(CC) $(CFLAGS)  $(LIB) -o $(SERVEUR) $(OBJ_S)
	@echo "$(SERVEUR) : executable file compiled successfully"

$(CLIENT)	:	$(OBJ_C)
	@make -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $(LIB) -o $(CLIENT) $(OBJ_C)
	@echo "$(CLIENT) : executable file compiled successfully"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC)
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -I$(INC_PATH) -I$(LIB_PATH)/includes -o $@ -c $<

clean:
	@make -C $(LIB_PATH) clean
	@rm -f $(OBJ_S)
	@rm -f $(OBJ_C)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo '' > /dev/null
	@echo "$(NAME) : object files deleted successfully"

fclean: clean
	@rm -f $(LIB)
	@echo "$(LIB_NAME) : library file deleted succesfully"
	@rm -f $(SERVEUR)
	@rm -f $(CLIENT)
	@echo "$(SEVEUR) : executable file deleted successfully"
	@echo "$(CLIENT) : executable file deleted successfully"

re: fclean all
