CC = gcc
CFLAGS = -O2 --std=gnu99 -fpic -Wall -g 
SRCDIR = dstruct/src
INCDIR = dstruct/include/dstruct
LIBDIR = lib
SRCS = $(wildcard $(SRCDIR)/*.c)
TARGET = dstruct
LIBS = $(patsubst %.c,%,$(SRCS))
PROGS = $(patsubst dstruct/src/%,%,$(LIBS))

all: $(PROGS) 
	gcc -shared -Lstatic $(patsubst %,$(LIBDIR)/%.o,$(PROGS)) -o $(LIBDIR)/lib$(TARGET).so
%: $(SRCDIR)/%.c
	$(CC) $< -I $(INCDIR) -c $(CFLAGS) -o $(LIBDIR)/$@.o
demo: all
	$(CC) demo.c -I $(INCDIR) -L$(LIBDIR) -l$(TARGET) -o demo
	export LD_LIBRARY_PATH=$(LIBDIR)/
	
.PHONY: clean
clean:
	rm ./$(LIBDIR)/*.o
	rm ./$(LIBDIR)/lib$(TARGET).so
	rm demo
