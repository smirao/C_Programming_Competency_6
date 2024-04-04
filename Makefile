# https://stackoverflow.com/questions/18136918/how-to-get-current-relative-directory-of-your-makefile
# https://stackoverflow.com/questions/1814270/gcc-g-option-to-place-all-object-files-into-separate-directory

# VARS
ROOT_DIR=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))

MAIN=main
TEST=tests
OUT=$(ROOT_DIR)/bin/$(MAIN)
OUTT=$(ROOT_DIR)/bin/$(TEST)
CC=gcc
CFLAGS= -std=c11 -c -Wall 
PFLAGS= -lm
ODIR=$(ROOT_DIR)/obj
SDIR=$(ROOT_DIR)/src
TDIR=$(ROOT_DIR)/tests
IDIR=$(ROOT_DIR)/head
BDIR=$(ROOT_DIR)/bin

NOHFILES := main 
NOHFILEST := unit_tests 
HFILES := matrix matrixutils

_OBJS = $(NOHFILES) $(HFILES)

OFILES = $(patsubst %, $(ODIR)/%.o,$(_OBJS))

all: $(patsubst %, %.o,$(NOHFILES)) $(patsubst %, %.o,$(NOHFILEST)) $(patsubst %, %.o,$(HFILES)) main tests


# o files
main.o: $(ROOT_DIR)/main.c
	$(CC) $(CFLAGS) $(ROOT_DIR)/main.c -o $(ODIR)/main.o 

unit_tests.o: $(TDIR)/unit_tests.c
	$(CC) $(CFLAGS) $(TDIR)/unit_tests.c -o $(ODIR)/unit_tests.o 


matrix.o: $(SDIR)/matrix.c $(IDIR)/matrix.h
	$(CC) $(CFLAGS) $(SDIR)/matrix.c -o $(ODIR)/matrix.o 

matrixutils.o: $(SDIR)/matrixutils.c $(IDIR)/matrixutils.h
	$(CC) $(CFLAGS) $(SDIR)/matrixutils.c -o $(ODIR)/matrixutils.o 


# executables
main: $(OFILES)
	$(CC) $(patsubst %, $(ODIR)/%.o,$(HFILES)) $(patsubst %, $(ODIR)/%.o,$(NOHFILES)) -o $(OUT)

tests: $(OFILES)
	$(CC) $(patsubst %, $(ODIR)/%.o,$(HFILES)) $(patsubst %, $(ODIR)/%.o,$(NOHFILEST)) -o $(OUTT)

# extra commands
clean:
	rm $(ODIR)/*.o
	rm $(BDIR)/*

test:
	$(ROOT_DIR)/bin/tests

run: 
	$(ROOT_DIR)/bin/main

# make clean; make && clear && ./bin/main