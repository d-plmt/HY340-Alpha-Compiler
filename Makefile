GCC =gcc
FLEX =flex
all:
	$(FLEX) -o test.c scanner.l
	$(GCC) test.c -o test

clean:
	@rm test test.c
	@echo "Cleanup complete"

