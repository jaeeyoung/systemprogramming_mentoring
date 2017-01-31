.SUFFIXES : .c .o


OBJECTS = main.o read.o write.o
SRCS = main.c read.c write.c

CC = gcc
CFLAGS = -g -c
INC = -I/home/raxix/include

$(TARGET) : $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS)

%.o : %.c io.h
	$(CC) $(INC) $(CFLAGS) $<

clean :
	rm -rf $(OBJECTS) $(TARGET) core
