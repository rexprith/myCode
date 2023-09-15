CC = g++
CFLAGS = -Wall -g
LFLAGS = -lpthread -lrt
OURDIR = ./BIN
all: posixThreadExample posixMqueueExample posixSemaExample

.PHONY = directories

directories:
	mkdir -p $(OUTDIR)
posixThreadExample:
	$(CC) $(CFLAGS) posixThreadExample.cpp $(LFLAGS) -o $(OUTDIR)/posixThreadExample

posixMqueueExample:
	$(CC) $(CFLAGS) posixMqueueExample.cpp $(LFLAGS) -o $(OUTDIR)/posixMqueueExample

posixSemaExample:
	$(CC) $(CFLAGS) posixSemaExample.cpp $(LFLAGS) -o $(OUTDIR)/posixSemaExample

clean:
	rm -rf $(OUTDIR)\*
