
main: bill.o
	@echo making all files
	@g++ -o main bill.o -Wall -g

clean:
	rm -f *.o main