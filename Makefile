CXX = g++

CXXFLAGS = -Wall -Werror -Wextra

SOURCES = main.cpp \
		  Token.cpp \
		  Tokenizer.cpp \
		  Analyzer.cpp \
		  Reducer.cpp \

OBJECTS = $(SOURCES:.cpp=.o)

NAME = computor

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
