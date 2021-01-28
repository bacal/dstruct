CC = gcc
CFLAGS = --std=gnu99 -fPIC -Wall 
SRCDIR = dstruct/src
INCDIR = dstruct/include/dstruct
LIBDIR = lib
SRCS = $(wildcard $(SRCDIR)/*.c)
TARGET = dstruct
LIBS = $(patsubst %.c,%,$(SRCS))
PROGS = $(patsubst dstruct/src/%,%,$(LIBS))

all: $(PROGS) 
	gcc -shared -Lstatic $(patsubst %,$(LIBDIR)/%.o,$(PROGS)) -Wl,-rpath $(LIBDIR) -o $(LIBDIR)/lib$(TARGET).so
%: $(SRCDIR)/%.c
	$(CC) $< -I $(INCDIR) -c $(CFLAGS) -o $(LIBDIR)/$@.o
demo: all
	$(CC) demo.c -I $(INCDIR) -L$(LIBDIR) -l$(TARGET) -o demo
	
.PHONY: clean
clean:
	rm ./$(LIBDIR)/*.o
	rm ./$(LIBDIR)/lib$(TARGET).so
	rm demo
