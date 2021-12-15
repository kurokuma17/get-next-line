# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/14 20:12:59 by trnguyen          #+#    #+#              #
#    Updated: 2021/12/13 20:35:24 by trnguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

SRCS		=	ft_putchar.c ft_putstr.c ft_putnbr.c ft_putendl.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
				ft_bzero.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
				ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c \
				ft_strlen.c ft_strlcat.c ft_strcmp.c ft_strncmp.c \
				ft_isdigit.c ft_isascii.c ft_isalpha.c ft_isalnum.c \
				ft_isprint.c ft_toupper.c ft_tolower.c ft_atoi.c ft_strdup.c \
				ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
				ft_strstr.c ft_strnstr.c ft_strchr.c ft_strrchr.c \
				ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
				ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
				ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
				ft_lstnew.c ft_lstadd.c ft_lstdelone.c \
				ft_lstiter.c ft_lstdel.c ft_lstmap.c \
				ft_lstsize.c ft_lstadd_back.c ft_lstlast.c \
				ft_strndup.c ft_isspace.c ft_strcspn.c \
				ft_islower.c ft_isupper.c ft_isblank.c ft_iscntrl.c \
				ft_isgraph.c ft_isxdigit.c ft_strlowcase.c ft_strupcase.c \
				ft_strcapitalize.c

OBJS		=	$(SRCS:.c=.o)

CC			=	@ gcc

RM			=	rm -f

CFLAGS		=	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):
			@ $(CC) $(CFLAGS) -c $(SRCS)
			@ ar rc $(NAME) $(OBJS)
			@ ranlib $(NAME)

clean:
			@ $(RM) $(OBJS)

fclean:		clean
			@ $(RM) $(NAME)

re:			fclean all
