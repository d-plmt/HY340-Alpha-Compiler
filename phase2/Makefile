BISON=bison
GCC =gcc
FLEX =flex
all:
	@bison --yacc --defines --output=parser.c parser.y
	@flex --outfile=al.c al.l
	@gcc al.c parser.c -o al

clean:
	@rm -f al al.c parser.c
	@echo "Cleanup complete"

a:
	@rm -f al al.c parser.c
	@bison --yacc --defines --output=parser.c parser.y
	@flex --outfile=al.c al.l
	@gcc al.c parser.c -o al
	@echo "Executing program:"
	@./al input.txt
	
	
