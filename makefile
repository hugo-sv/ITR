CXX      := -g++
CXXFLAGS := -I ./includes/ -Wall -Wextra -O3
LDFLAGS  := -lrt -pthread
BUILD    := ./build

%.o:%.c
	$(CXX) $(CXXFLAGS) $< -o $@  $(LDFLAGS)

td1: src/td1/posixHelpers.o src/td1/posixHelpers.test.o src/td1/posixTimer.o src/td1/posixTimer.test.o src/td1/IncrC.o src/td1/mesureExecution.o
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td1_a.out src/td1/posixHelpers.o src/td1/posixHelpers.test.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td1_b.out src/td1/posixHelpers.o src/td1/posixTimer.test.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td1_c.out src/td1/posixHelpers.o src/td1/IncrC.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td1_d.out src/td1/posixHelpers.o src/td1/mesureExecution.o $(LDFLAGS)

clean: 
	rm -rvf build/*
	rm -f src/*/*.o