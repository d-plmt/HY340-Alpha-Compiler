GCC =gcc
FLEX =flex
all:
	$(FLEX) -o al.c scanner.l
	$(GCC) al.c -o al

clean:
	@rm -f al al.c
	@echo "Cleanup complete"

a:
	@rm -f al al.c
	$(FLEX) -o al.c scanner.l
	$(GCC) al.c -o al
	@echo "Executing program:"
	@./al input.txt output.txt
