TARGET	=		abstractVM

SRC		=	    ./src/main.cpp									    \
				./src/factory.cpp									\
				./src/core.cpp										\
				./src/Type_Variable/int8.cpp						\
                ./src/Type_Variable/int16.cpp                       \
                ./src/Type_Variable/int32.cpp                       \
                ./src/Type_Variable/float.cpp                       \
                ./src/Type_Variable/double.cpp                      \
				./src/utils.cpp										\
				./src/parser.cpp									\
				./src/Error.cpp										\
				./src/Type_Variable/ZOperand.cpp					\
				./src/Type_Variable/bigdecimal.cpp					\
				./src/add.cpp										\
				./src/mul.cpp										\
				./src/sub.cpp

OBJ		=		$(SRC:.cpp=.o)

CFLAGS	=		-I ./include/

RM 		=		rm -rf

all:	$(OBJ)
		g++ -o $(TARGET) $(OBJ) $(CFLAGS) -lcriterion -lgcov --coverage

clean:
		$(RM) $(OBJ)

fclean:	clean
		$(RM) $(TARGET)
		@rm -f $(SRC:%.cpp=%.gcno)
		@rm -f $(SRC:%.cpp=%.gcda)
		@rm -f tests/tests.gcda
		@rm -f tests/tests.gcno
		@rm -f tests/tests.o
		@rm -f tests/criterion

re:	fclean	all


tests_run:
	cd tests/ && $(MAKE)
	cd ../
	@gcovr --exclude "tests/" --sort-uncovered --branches
	@gcovr --exclude "tests/" --sort-uncovered --print-summary
