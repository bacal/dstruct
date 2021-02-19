CC = gcc
CFLAGS = --std=gnu99 -g -O2 -fPIC -Wall 
SRCDIR = dstruct/src
INCDIR = dstruct/include/
LIBDIR = lib
TARGET = dstruct

all: dstruct.so

dstruct.so: llist.o bst.o dllist.o stack.o dyarray.o 
	$(CC) $(LIBDIR)/dyarray.o \
		  $(LIBDIR)/bst.o \
		  $(LIBDIR)/dllist.o \
		  $(LIBDIR)/stack.o \
		  $(LIBDIR)/llist.o \
	  	-shared -Lstatic -o $(LIBDIR)/lib$(TARGET).so


.PHONY: demo
demo: all
	$(CC) demo.c -I $(INCDIR) -g -L$(LIBDIR) -Wl,-rpath,$(LIBDIR) -l$(TARGET) -o demo

.PHONY: bst.o
bst.o:
	$(CC) $(SRCDIR)/$(patsubst %.o,%.c,$@) -I $(INCDIR) -c $(CFLAGS) -o $(LIBDIR)/$@

.PHONY: dllist.o
dllist.o:
	$(CC) $(SRCDIR)/$(patsubst %.o,%.c,$@) -I $(INCDIR) -c $(CFLAGS) -o $(LIBDIR)/$@

.PHONY: llist.o
llist.o:
	$(CC) $(SRCDIR)/$(patsubst %.o,%.c,$@) -I $(INCDIR) -c $(CFLAGS) -o $(LIBDIR)/$@

.PHONY: stack.o
stack.o:
	$(CC) $(SRCDIR)/$(patsubst %.o,%.c,$@) -I $(INCDIR) -c $(CFLAGS) -o $(LIBDIR)/$@

.PHONY: dyarray.o
dyarray.o:
	$(CC) $(SRCDIR)/$(patsubst %.o,%.c,$@) -I $(INCDIR) -c $(CFLAGS) -o $(LIBDIR)/$@

.PHONY: clean
clean:
	rm ./$(LIBDIR)/*.o
	rm ./$(LIBDIR)/lib$(TARGET).so	
	rm ./demo
