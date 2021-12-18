#Chris Lemke
#Lab 10

lab10: lab10.o ParseCmd.o RunExtCmd.o ProcessCmd.o Redirection.o
	gcc -Wall lab10.o ParseCmd.o RunExtCmd.o ProcessCmd.o Redirection.o -o lab10

lab10.o: lab10.c lab9_10.h
	gcc -c lab10.c

ParseCmd.o: ParseCmd.c lab9_10.h
	gcc -c ParseCmd.c

RunExtCmd.o: RunExtCmd.c lab9_10.h
	gcc -c RunExtCmd.c

ProcessCmd.o: ProcessCmd.c lab9_10.h
	gcc -c ProcessCmd.c

Redirection.o: Redirection.c lab9_10.h
	gcc -c Redirection.c

clean:
	rm *.o lab10

run:
	./lab10