OBJS = lsystem.o 
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
LIBS= -lGL -lGLU -lglut
lsystem : $(OBJS)
	    $(CC) $(LFLAGS) $(OBJS) -o lsystem $(LIBS)

lsystem.o : lsystem.h lsystem.cpp point.h 
	    $(CC) $(CFLAGS) lsystem.cpp
tar:
	    tar cfv lsystem.tar lsystem.h lsystem.cpp point.h 
