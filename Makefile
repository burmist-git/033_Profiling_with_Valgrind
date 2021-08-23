CXX  = g++

ROOTCFLAGS  = $(shell $(ROOTSYS)/bin/root-config --cflags)
ROOTLIBS    = $(shell $(ROOTSYS)/bin/root-config --libs)

CXXFLAGS  = -g -Wall -fPIC -Wno-deprecated -O3
#CXXFLAGS += $(ROOTCFLAGS)
#CXXFLAGS += $(ROOTLIBS)
CXXFLAGS += -std=c++14

#INCLUDE = -I.

all: main log_gaussian_heap log_gaussian_vector

main: main.c
	$(CXX) -o $@ $< $(CXXFLAGS) $(ROOTCFLAGS) $(ROOTLIBS)

main_log_gaussian_lib: main_log_gaussian_lib.c
	$(CXX) -o $@ $< *.so $(CXXFLAGS) $(ROOTCFLAGS) $(ROOTLIBS)

log_gaussian_heap: log_gaussian_heap.c
	$(CXX) -o $@ $< $(CXXFLAGS) $(ROOTCFLAGS) $(ROOTLIBS)

log_gaussian_vector: log_gaussian_vector.c
	$(CXX) -o $@ $< $(CXXFLAGS) $(ROOTCFLAGS) $(ROOTLIBS)

templateFunctionTest: templateFunctionTest.cc
	$(CXX) -o $@ $<

log_gaussian_lib.so: log_gaussian_lib.o templateFunctionTest.o
	$(CXX) -o $@ -shared log_gaussian_lib.o templateFunctionTest.o

log_gaussian_lib.o: log_gaussian_lib.cc log_gaussian_lib.h
	$(CXX) $(CXXFLAGS) -I. -c -o $@ $<

templateFunctionTest.o: templateFunctionTest.cc
	$(CXX) $(CXXFLAGS) -I. -c -o $@ $<

.PHONY : clean
clean:
	rm -f *~
	rm -f .*~
	rm -f *.o
	rm -f *.so
	rm -f main
	rm -f log_gaussian_heap
	rm -f log_gaussian_vector
	rm -f main_log_gaussian_lib
	rm -f templateFunctionTest
