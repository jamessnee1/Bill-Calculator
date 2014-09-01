
main: bill.o util.o
	@echo making all files...
	@gcc -Wall -o main bill.o util.o -g

    
bill.o: bill.c bill.h
	@echo making bill.o
	@gcc -c -g bill.c
    
util.o: util.c
	@echo making util.o
	@gcc -c -g util.c

clean:
	rm -f *.o main