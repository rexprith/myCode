CC      = g++
CFLAGS  = -Wall -g -Wdelete-non-virtual-dtor
LDFLAGS = 
OUTDIR  = bin

all: directories constructor_destructor vfunc pureVfunc abstractClass search2Sum

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

search2Sum: search2Sum.cpp
	@echo "Building search2Sum.cpp....."
	@$(CC) $(CFLAGS) search2Sum.cpp -o $(OUTDIR)/search2Sum

abstractClass: abstractClass.cpp
	@echo "Building abstractClass.cpp....."
	@$(CC) $(CFLAGS) abstractClass.cpp -o $(OUTDIR)/abstractClass

	
.PHONY: clean
clean:
	@echo "Cleaning all binaries and BIN directory....."
	@rm -rf $(OUTDIR)/*
	@rmdir $(OUTDIR)
