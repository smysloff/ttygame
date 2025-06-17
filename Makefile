all: clear build run

clear:
	@rm -rf a.out

build:
	@gcc *.c

run:
	@./a.out

.PHONY: all clear build run
