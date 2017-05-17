CPPFLAGS = -std=c++11

all: prolog

prolog: rule.o fact.o read_util.o rule.o prolog.o
		g++ $(CPPFLAGS) rule.o fact.o read_util.o prolog.o -o prolog

rule.o: rule.cpp
		g++ $(CPPFLAGS) -c rule.cpp

fact.o: fact.cpp
		g++ $(CPPFLAGS) -c fact.cpp

read_util.o: read_util.cpp
		g++ $(CPPFLAGS) -c read_util.cpp

prolog.o: prolog.cpp
		g++ $(CPPFLAGS) -c prolog.cpp

clean:
		rm -rf *.o hello
