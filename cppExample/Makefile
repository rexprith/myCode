CC      = g++
CFLAGS  = -Wall -g -Wdelete-non-virtual-dtor
LDFLAGS = 
OUTDIR  = bin

all: directories constructor_destructor vfunc pureVfunc

.PHONY: directories

directories:
	@echo "Creating BIN directory....."
	@mkdir -p $(OUTDIR)

constructor_destructor: constructor_destructor.cpp
	@echo "Building constructor_destructor.cpp....."
	@$(CC) $(CFLAGS) constructor_destructor.cpp -o $(OUTDIR)/constructor_destructor

pureVfunc:pureVfunc.cpp
	@echo "Building pureVfunc.cpp....."
	@$(CC) $(CFLAGS) pureVfunc.cpp -o $(OUTDIR)/pureVfunc

vfunc: vfunc.cpp
	@echo "Building vfunc.cpp....."
	@$(CC) $(CFLAGS) vfunc.cpp -o $(OUTDIR)/vfunc


.PHONY: clean
clean:
	@echo "Cleaning all binaries and BIN directory....."
	@rm -rf $(OUTDIR)/*
	@rmdir $(OUTDIR)