# https://stackoverflow.com/questions/18136918/how-to-get-current-relative-directory-of-your-makefile
# https://stackoverflow.com/questions/1814270/gcc-g-option-to-place-all-object-files-into-separate-directory

# VARS
ROOT_DIR=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

MAIN=main
TEST=test
OUT=$(ROOT_DIR)/bin/$(MAIN)
CC=gcc
CFLAGS= -std=c11 -c -Wall
PFLAGS= -lm
ODIR=$(ROOT_DIR)/obj
SDIR=$(ROOT_DIR)/src
TDIR=$(ROOT_DIR)/tests
IDIR=$(ROOT_DIR)/head
BDIR=$(ROOT_DIR)/bin

NOHFILES := main 
HFILES := matrix matrixutils

_OBJS = $(NOHFILES) $(HFILES)
$(info $(_OBJS))
OFILES = $(patsubst %, $(ODIR)/%.o,$(_OBJS))

all: $(patsubst %, %.o,$(NOHFILES)) $(patsubst %, %.o,$(HFILES)) $(MAIN)

# o files
main.o: $(ROOT_DIR)/main.c
	$(CC) $(CFLAGS) $(ROOT_DIR)/main.c -o $(ODIR)/main.o 
$(call add_target, $(MAIN))

matrix.o: $(SDIR)/matrix.c $(IDIR)/matrix.h
	$(CC) $(CFLAGS) $(SDIR)/matrix.c -o $(ODIR)/matrix.o 

matrixutils.o: $(SDIR)/matrixutils.c $(IDIR)/matrixutils.h
	$(CC) $(CFLAGS) $(SDIR)/matrixutils.c -o $(ODIR)/matrixutils.o 


# executables
$(MAIN): $(OBJS)
	$(CC) $(OFILES) -o $(OUT)

# extra commands
clean:
	rm $(ODIR)/*.o
	rm $(BDIR)/*

run: 
	$(ROOT_DIR)/bin/main

# make clean; make && clear && ./bin/main