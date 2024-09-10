##
## EPITECH PROJECT, 2018
## Criterion unit test makefile
## File description:
## Compile the tests 
##

NAME	=	criterion

SRCS =			./tests.cpp								\
				./../src/factory.cpp                                   \
                ./../src/core.cpp                                      \
                ./../src/Type_Variable/int8.cpp                        \
                ./../src/Type_Variable/int16.cpp                       \
                ./../src/Type_Variable/int32.cpp                       \
                ./../src/Type_Variable/float.cpp                       \
                ./../src/Type_Variable/double.cpp                      \
				./../src/Type_Variable/bigdecimal.cpp					\
				./../src/mul.cpp										\
				./../src/add.cpp										\
				./../src/sub.cpp										\
                ./../src/Error.cpp										\
				./../src/Type_Variable/ZOperand.cpp						\
				./../src/parser.cpp										\
				./../src/utils.cpp


CXXFLAGS	+=	 -I ./../include/ -I ./../interface/ --coverage

OBJ_TEST	=	$(SRCS:.cpp=.o)


tests_run: $(OBJ_TEST)
	g++ -o $(NAME) $(OBJ_TEST) --coverage -lcriterion -lgcov
	./$(NAME)

clean:
	@rm -f $(OBJ_TEST)

fclean:
	@rm -f $(SRCS:%.cpp=%.gcno)
	@rm -f $(SRCS:%.cpp=%.gcda)
	@rm -f $(OBJ_TEST)
	@rm -f $(OBJ)
	@rm -f $(NAME)

re: fclean tests_run
