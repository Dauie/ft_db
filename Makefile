HEADER = ft_db.h

NAME = ft_db

SRC = db_addentry.c db_addnode.c db_cleartree.c db_deldb.c db_inistructs.c\
	  db_itoa.c db_loaddatabase.c db_memalloc.c db_printdb.c db_printtree.c \
	  db_savetree.c db_strjoin.c db_strsplit.c db_tbladdl.c db_tbldel.c \
	  db_tbldup.c db_tbllen.c db_treesearch.c db_ttreelen.c db_xportdb.c \
	  ft_db.c

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME):
	gcc -g -Wall -Wextra -Werror -c $(SRC)
	gcc -g -Wall -Wextra -Werror $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
