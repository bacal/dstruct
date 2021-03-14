CC = gcc
CFLAGS = --std=gnu99 -g -Og -fPIC -Wall 
SRCDIR = dstruct/src
INCDIR = dstruct/include/
LIBDIR = lib
TARGET = dstruct

all: $(LIBDIR)/dstruct.so

$(LIBDIR)/dstruct.so: $(LIBDIR)/llist.o $(LIBDIR)/bst.o $(LIBDIR)/dllist.o $(LIBDIR)/stack.o $(LIBDIR)/dyarray.o 
	$(CC) $^ -shared -Lstatic -o $(LIBDIR)/lib$(TARGET).so

demo: all demo.c
	$(CC) demo.c -I $(INCDIR) -g -L$(LIBDIR) -Wl,-rpath,$(LIBDIR) -l$(TARGET) -o demo

$(LIBDIR)/bst.o: $(SRCDIR)/bst.c
	$(CC) $^ -I $(INCDIR) -c $(CFLAGS) -o $@

$(LIBDIR)/dllist.o:$(SRCDIR)/dllist.c
	$(CC) $^ -I $(INCDIR) -c $(CFLAGS) -o $@

$(LIBDIR)/llist.o: $(SRCDIR)/llist.c
	$(CC) $^ -I $(INCDIR) -c $(CFLAGS) -o $@

$(LIBDIR)/stack.o: $(SRCDIR)/stack.c
	$(CC) $^ -I $(INCDIR) -c $(CFLAGS) -o $@

$(LIBDIR)/dyarray.o: $(SRCDIR)/dyarray.c
	$(CC) $^ -I $(INCDIR) -c $(CFLAGS) -o $@

clean:
	rm ./$(LIBDIR)/*.o
	rm ./$(LIBDIR)/lib$(TARGET).so	
	rm -f ./demo
