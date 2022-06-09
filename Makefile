CPPFLAGS = -g -I.

libsrc = memory_manager_base.cpp memory_manager_best_fit.cpp memory_manager_first_fit.cpp
libobj = $(libsrc:.cpp=.o)
headers = memory_manager_base.h memory_manager_best_fit.h memory_manager_first_fit.h

all: execute $(libobj)

execute: execute.o $(libobj) $(headers)
	$(CXX) -o $@ execute.o $(libobj) $(LDFLAGS)

memory_manager_base.o : memory_manager_base.cpp $(headers)

memory_manager_best_fit.o : memory_manager_best_fit.cpp $(headers)

memory_manager_first_fit.o : memory_manager_first_fit.cpp $(headers)

.PHONY: clean
clean:
	rm -f execute execute.o $(libobj)