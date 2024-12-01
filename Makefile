CC:=gcc
CFLAGS:=-std=c17 -Wall 
DEBUG_FLAGS:=--read-inline-info=yes 

PROJECT:=app.out
SRC_FILES=$(wildcard src/*.c) 
OBJ_FILES=$(SRC_FILES:.c=.o)

DEPS=$(SRC_FILES:.c=.h)
HEADERS=$(filter %.h, $(filter-out main%, $(DEPS)))

all: clean build

build: $(PROJECT)
	@echo "Build successful...\n"

%.o: %.c $(HEADERS)
	@echo "Creating objects...\n"
	$(CC) $(CFLAGS) -c -o $@ $<

$(PROJECT): $(OBJ_FILES)
	@echo "Creating binary...\n"
	$(CC) $(CFLAGS) -o $@ $^

debug:
	valgrind $(DEBUG_FLAGS) ./$(PROJECT)

clean: 
	rm -rf $(PROJECT) $(OBJ_FILES)

.PHONY: build clean all 
