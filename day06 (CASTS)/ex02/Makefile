NAME = Identify

C_RED = "\033[31m"
C_GREEN = "\033[32m"
C_YELLOW = "\033[33m"
C_BLUE = "\033[36m"
C_BASE = "\033[00m"

CXX = clang++
CXXFLAGS = -Wall -Werror -Wextra

SRC =	main.cpp \
		Base_A_B_C.cpp \

INC =	Base_A_B_C.hpp \

OBJ = $(SRC:.cpp=.o)


all: $(NAME)

$(NAME): Makefile $(OBJ)
		@$(CXX) $(OBJ) -o $(NAME)
		@echo $(C_GREEN)"[$(NAME)] $(NAME) Ready ✔" $(C_BASE)

%.o: %.cpp $(INC)
		@$(CXX) $(CXXFLAGS) -o $@ -c $<
		@echo "[$(NAME)] file =" $(C_BLUE){ $< } $(C_BASE)

clean:
		@rm -rf $(OBJ)
		@echo $(C_YELLOW) "[$(NAME)] OBJ Files Cleaned" $(C_BASE)

fclean: clean
		@/bin/rm -f $(NAME)
		@echo $(C_RED) "[$(NAME)] $(NAME) Deleted" $(C_BASE)

re: fclean all
