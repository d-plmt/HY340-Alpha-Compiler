GCC =gcc
FLEX =flex
all:
	@flex -o al.c al.l
	@gcc al.c -o al

clean:
	@rm -f al al.c
	@echo "Cleanup complete"

a:
	@rm -f al al.c
	@flex -o al.c al.l
	@gcc al.c -o al
	@echo "Executing program:"
	@./al tests/string_err2.alpha
	
