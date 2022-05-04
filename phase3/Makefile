BISON=bison
GCC =gcc
FLEX =flex
all:
	@bison -v --yacc --defines --output=parser.c parser.y
	@flex --outfile=al.c al.l
	@gcc symT.c al.c parser.c -o al

clean:
	@rm -f al al.c parser.c parser.h 
	@echo "Cleanup complete"

a:
	@rm -f al al.c parser.c parser.h
	@bison --yacc --defines --output=parser.c parser.y
	@flex --outfile=al.c al.l
	@gcc symT.c al.c parser.c -o al
	@echo "Executing program:"
	@./al test.txt
	
	
