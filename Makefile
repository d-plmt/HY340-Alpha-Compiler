GCC =gcc
FLEX =flex
all:
	$(FLEX) -o test.c scanner.l
	$(GCC) test.c -o test

clean:
	@rm -f test test.c
	@echo "Cleanup complete"

a:
	@rm -f test test.c
	$(FLEX) -o test.c scanner.l
	$(GCC) test.c -o test
	@echo "Executing program:"
	@./test
