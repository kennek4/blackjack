CC:=gcc
CFLAGS:=-std=c17 
PROJECT:=app
SRC_FILES:=$(wildcard *.c) 
OBJ_FILES:=$(SRC_FILES:.c=.o)
DEPS:=$(SRC_FILES:.c=.h)
HEADERS:=$(filter %.h, $(filter-out main%, $(DEPS)))

all: clean build

build: $(PROJECT)
	@echo "Build successful"

%.o: %.c $(HEADERS)
	@echo "Creating objects..."
	$(CC) $(CFLAGS) -c -o $@ $<

$(PROJECT): $(OBJ_FILES)
	@echo "Creating binary..."
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	rm -rf $(EXEC) $(OBJ_FILES)

.PHONY: build clean all
