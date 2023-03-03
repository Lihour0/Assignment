CC = g++
CCFLAGS = -Wall -Wextra -Wpedantic -Werror -std=c++2a -O3
SRC = $(wildcard *.cc || wildcard *.cpp)
OBJ = $(SRC:%.cc=%.o)

a.out: $(OBJ)
	$(CC) $(CCFLAGS) $^

clean:
	rm -f *.o a.out

