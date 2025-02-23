# Compilador e comandos
CC := cc
RM := rm -rf

# Arquivos fontes e objetos
SRCS := get_next_line.c get_next_line_utils.c
OBJS := $(SRCS:.c=.o)

# Nome da biblioteca estática
LIBNAME := libgnl.a

# Regra padrão para compilar a biblioteca
all: $(LIBNAME)

$(LIBNAME): $(OBJS)
	ar rcs $(LIBNAME) $(OBJS)

# Regra de limpeza dos arquivos objetos
clean:
	$(RM) $(OBJS)

# Regra de limpeza completa (remove a biblioteca também)
fclean: clean
	$(RM) $(LIBNAME)

# Recompilar do zero (limpa e compila novamente)
re: fclean all

.PHONY: all clean fclean re
