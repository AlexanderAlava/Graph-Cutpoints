###############################################################################
##05/01/2017																                  Alexander Alava##
##makefile																				 					        U35432961##
##																															      		   ##
## This is the makefile for the file "cut_tester.cpp" and all its dependants ##
###############################################################################


cutpoints: cut_tester.o graph.o
		g++ -o cutpoints cut_tester.o graph.o

cut_tester.o: cut_tester.cpp graph.cpp graph.h
	g++ -c cut_tester.cpp graph.cpp

graph.o: graph.cpp graph.h
	g++ -c graph.cpp

clean:
	rm *.o	
