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

td2: src/td1/posixHelpers.o src/td2/withoutMutex.o src/td2/withPolicy.o src/td2/withMutex.o
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td2_a.out src/td1/posixHelpers.o src/td2/withoutMutex.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td2_b.out src/td1/posixHelpers.o src/td2/withPolicy.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td2_c.out src/td1/posixHelpers.o src/td2/withMutex.o $(LDFLAGS)

td4: src/td1/posixHelpers.o src/td4/PosixThread.o src/td4/Thread.o src/td4/Mutex.o src/td4/IncrementerMut.o src/td4/AIncrementer.o src/td4/Semaphore.o src/td4/SemaProducer.o src/td4/FifoProducer.o src/td4/a.o src/td4/b.o src/td4/c.o src/td4/d.o
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td4_a.out src/td1/posixHelpers.o src/td4/PosixThread.o src/td4/Thread.o src/td4/AIncrementer.o src/td4/a.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td4_b.out src/td1/posixHelpers.o src/td4/PosixThread.o src/td4/Thread.o src/td4/Mutex.o src/td4/IncrementerMut.o src/td4/b.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td4_c.out src/td1/posixHelpers.o src/td4/PosixThread.o src/td4/Thread.o src/td4/Mutex.o src/td4/Semaphore.o src/td4/SemaProducer.o src/td4/c.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td4_d.out src/td1/posixHelpers.o src/td4/PosixThread.o src/td4/Thread.o src/td4/Mutex.o src/td4/FifoProducer.o src/td4/d.o $(LDFLAGS)

clean: 
	rm -rvf build/*
	rm -f src/*/*.o