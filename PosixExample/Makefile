CC = g++
CFLAGS = -Wall -g
LFLAGS = -lpthread -lrt
OUTDIR = ./bin
OBJ = ./obj

all: directories posixThreadExample posixMqueueExample posixSemaExample


.PHONY = directories

directories:
	@echo "creating bin directory for binary files"
	@mkdir -p $(OUTDIR)

posixThreadExample: posixThreadExample.cpp
	@echo "Building PosixThreadExample...."
	@$(CC) $(CFLAGS) $(LFLAGS) posixThreadExample.cpp $(LFLAGS) -o $(OUTDIR)/posixThreadExample

posixMqueueExample: posixMqueueExample.cpp
	@echo "Building PosixMqueueExample...."
	@$(CC) $(CFLAGS) $(LFLAGS) posixMqueueExample.cpp $(LFLAGS) -o $(OUTDIR)/posixMqueueExample

posixSemaExample: posixSemaExample.cpp
	@echo "Building PosixSemaExample...."
	@$(CC) $(CFLAGS) $(LFLAGS) posixSemaExample.cpp -o $(OUTDIR)/posixSemaExample

.PHONY = clean
clean:

	@echo "Deleting binaries...."
	@rm -rf $(OUTDIR)/*
	@rm -rf $(OBJ)/*
	@rmdir $(OUTDIR)
