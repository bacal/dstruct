CC = gcc
CFLAGS = --std=gnu99 -fPIC -Wall 
SRCDIR = dstruct/src
INCDIR = dstruct/include/
LIBDIR = lib
SRCS = $(wildcard $(SRCDIR)/*.c)
TARGET = dstruct
LIBS = $(patsubst %.c,%,$(SRCS))
PROGS = $(patsubst dstruct/src/%,%,$(LIBS))

all: $(PROGS) 
	$(CC) -shared -Lstatic $(patsubst %,$(LIBDIR)/%.o,$(PROGS)) -o $(LIBDIR)/lib$(TARGET).so

%: $(SRCDIR)/%.c
	$(CC) $< -I $(INCDIR) -c $(CFLAGS) -o $(LIBDIR)/$@.o

.PHONY: demo
demo: all
	$(CC) demo.c -I $(INCDIR) -L$(LIBDIR) -Wl,-rpath,$(LIBDIR) -l$(TARGET) -o demo

.PHONY: clean
clean:
	rm ./$(LIBDIR)/*.o
	rm ./$(LIBDIR)/lib$(TARGET).so	
	rm ./demo
