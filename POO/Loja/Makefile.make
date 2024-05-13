EXECUTAVEL = Loja_Roupas
CC = g++
CFLAGS = -Wall -std=c++11
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
all: $(EXECUTAVEL)
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
$(EXECUTAVEL): $(OBJS)
	$(CC) $(OBJS) -o $@
clean:
	rm -f $(OBJS) $(EXECUTAVEL)
