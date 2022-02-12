NAME = libft.a				//링크후에 생성될 파일 이름

CC = gcc				//컴파일러 gcc
CFLAG = -Wall -Wextra -Werror		//컴파일에 필요한 각종옵션

RM = rm -f				//삭제 옵션

AR = ar					//파일들을 모아 아카이브(라이브러리)파일로 압축을 해주는 명령어의 매크로입니다.
					//.c파일도 압축이 가능하지만 목적에 맞게 사용하기 위해서는 오브젝트파일(.o)파일만을 압축하여 라이브러리 파일을 만듭니다.
ARFlAGS = crs				//src에있는 파일들을 아카이브에 넣는다는 옵션

INCLUDE = ./libft.h

SRCS = ft_atoi.c	\
       ft_bzero.c 	\
       ft_calloc.c	\
       ft_isalpha.c	\
       ft_isalnum.c	\
       ft_isascii.c	\
       ft_isdigit.c	\
       ft_isprint.c	\
       ft_itoa.c	\
       ft_memchr.c	\
       ft_memcmp.c	\
       ft_memcpy.c	\
       ft_memmove.c	\
       ft_memset.c	\
       ft_putchar_fd.c	\
       ft_putendl_fd.c	\
       ft_putnbr_fd.c	\
       ft_putstr_fd.c	\
       ft_strchr.c	\
       ft_strdup.c	\
       ft_strjoin.c	\
       ft_strlcat.c	\
       ft_strlcpy.c	\
       ft_strlen.c	\
       ft_strncmp.c	\
       ft_strmapi.c	\
       ft_strrchr.c	\
       ft_strtrim.c	\
       ft_strnstr.c	\
       ft_striteri.c	\
       ft_substr.c	\
       ft_tolower.c	\
       ft_toupper.c	\
       ft_split.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)					//make는 Makefile을 순차적으로 읽어서 가장 처음에 나오는 규칙을 수행하게 된다. 
						//여기서 all 이란 더미타겟(dummy target)이 바로 첫 번째 타겟으로써 작용하게 된다. 
						//관습적으로 all이란 타겟을 정의해 두는 것이 좋다. 
						//결과 파일이 많을 때도 all의 의존 관계(dependency)로써 정의해 두면 꽤 편리하다.

$(NAME) : $(OBJS)				//libft.a : 변한된 object파일들을 libft.a에 압축 
	    $(AR) $(ARFLAGS) $@ $^		//$@현재 타겟의 이름, 현재 타겟의 종속 항목 리스트

$(OBJS) : $(INCLUDE)				//헤더파일 

clean :						//오브젝트파일삭제
	$(RM) $(OBJS)

fclean : clean					//오브젝트파일과 라이브러리 파일 삭제
	$(RM) $(NAME)

%.o : %.c					//.c파일을 .o파일로 컴파일
	$(CC) $(CFLAG) -c $< -o $@		//$< 현재의 목표파일보다 더 최근에 갱신된 파일 이름

re : fclean all					//fclean후 all타겟 삭제

.PHONY: re clean fclean all
