BISON=bison
GCC =gcc
FLEX =flex
all:
	
	@bison parser.c parser.y
	@flex -o al.c al.l
	@gcc al.c parser.c -o al

clean:
	@rm -f al al.c parser.c
	@echo "Cleanup complete"

a:
	@rm -f al al.c parser.c
	@bison parser.c parser.y
	@flex -o al.c al.l
	@gcc al.c -o al
	@echo "Executing program:"
	@./al input.txt
	
