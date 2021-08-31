CXX = g++

ROOTCFLAGS     = $(shell $(ROOTSYS)/bin/root-config --cflags)
ROOTLIBS       = $(shell $(ROOTSYS)/bin/root-config --libs)
ROOTGLIBS      = $(shell $(ROOTSYS)/bin/root-config --glibs)
ROOTLDFLAGS    = $(shell $(ROOTSYS)/bin/root-config --ldflags)
ROOTINCLUDEDIR = $(shell $(ROOTSYS)/bin/root-config --incdir)

CXXFLAGS  = -g -Wall -fPIC -Wno-deprecated -O3
#CXXFLAGS += -std=c++14

all: main log_gaussian_heap log_gaussian_vector

main: main.c
	$(CXX) -o $@ $< $(CXXFLAGS) $(ROOTCFLAGS) $(ROOTLIBS)

main_log_gaussian_lib: main_log_gaussian_lib.c log_gaussian_lib.so
	$(CXX) -std=c++14 -o $@ $< *.so $(CXXFLAGS) $(ROOTCFLAGS) $(ROOTLIBS) $(ROOTGLIBS) $(ROOTLDFLAGS) -I$(ROOTINCLUDEDIR) -std=c++14 

log_gaussian_heap: log_gaussian_heap.c
	$(CXX) $(CXXFLAGS) $(ROOTCFLAGS) $(ROOTLIBS) -o $@ $<

log_gaussian_vector: log_gaussian_vector.c
	$(CXX) -o $@ $< $(CXXFLAGS) $(ROOTCFLAGS) $(ROOTLIBS)

templateFunctionTest: templateFunctionTest.cc
	$(CXX) -o $@ $<

log_gaussian_lib.so: log_gaussian_lib.o templateFunctionTest.o
	$(CXX)  $(CXXFLAGS) -std=c++14 -o $@ -shared log_gaussian_lib.o templateFunctionTest.o

log_gaussian_lib.o: log_gaussian_lib.cc log_gaussian_lib.h
	$(CXX) $(CXXFLAGS) -std=c++14 -I. -c -o $@ $<

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
