CXX      := -g++
CXXFLAGS := -I -Wall -Wextra -O3
LDFLAGS  := -lrt -pthread
BUILD    := ./build

%.o:%.c
	$(CXX) $(CXXFLAGS) $< -o $@  $(LDFLAGS)

td1: src/td1/posixHelpers.o src/td1/main_td1a.o src/td1/posixTimer.o src/td1/main_td1b.o src/td1/main_td1c.o src/td1/main_td1d.o
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td1_a.out src/td1/posixHelpers.o src/td1/main_td1a.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td1_b.out src/td1/posixHelpers.o src/td1/main_td1b.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td1_c.out src/td1/posixHelpers.o src/td1/main_td1c.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td1_d.out src/td1/posixHelpers.o src/td1/main_td1d.o $(LDFLAGS)

td2: src/td1/posixHelpers.o src/td2/withoutMutex.o src/td2/withPolicy.o src/td2/withMutex.o
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td2_a.out src/td1/posixHelpers.o src/td2/withoutMutex.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td2_b.out src/td1/posixHelpers.o src/td2/withPolicy.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td2_c.out src/td1/posixHelpers.o src/td2/withMutex.o $(LDFLAGS)

td3: src/td1/posixHelpers.o src/td3/Chrono.o src/td3/Timer.o src/td3/PeriodicTimer.o src/td3/CountDown.o src/td3/Calibrator.o src/td3/Looper.o src/td3/a.o src/td3/b.o src/td3/c.o
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td3_a.out src/td1/posixHelpers.o src/td3/Chrono.o src/td3/a.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td3_b.out src/td1/posixHelpers.o src/td3/Timer.o src/td3/PeriodicTimer.o src/td3/CountDown.o src/td3/b.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td3_c.out src/td1/posixHelpers.o src/td3/Timer.o src/td3/PeriodicTimer.o src/td3/Calibrator.o src/td3/Looper.o src/td3/c.o $(LDFLAGS)

td4: src/td1/posixHelpers.o src/td4/PosixThread.o src/td4/Thread.o src/td4/Mutex.o src/td4/AIncrementer.o src/td4/BIncrementer.o src/td4/Semaphore.o src/td4/CProducer.o src/td4/DProducer.o src/td4/a.o src/td4/b.o src/td4/c.o src/td4/d.o
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td4_a.out src/td1/posixHelpers.o src/td4/PosixThread.o src/td4/Thread.o src/td4/AIncrementer.o src/td4/a.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td4_b.out src/td1/posixHelpers.o src/td4/PosixThread.o src/td4/Thread.o src/td4/Mutex.o src/td4/BIncrementer.o src/td4/b.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td4_c.out src/td1/posixHelpers.o src/td4/PosixThread.o src/td4/Thread.o src/td4/Mutex.o src/td4/Semaphore.o src/td4/CProducer.o src/td4/c.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td4_d.out src/td1/posixHelpers.o src/td4/PosixThread.o src/td4/Thread.o src/td4/Mutex.o src/td4/DProducer.o src/td4/d.o $(LDFLAGS)

td6: src/td1/posixHelpers.o src/td4/PosixThread.o src/td4/Thread.o src/td4/Mutex.o  src/td4/Semaphore.o src/td6/ActiveCalc.o src/td6/ActiveObject.o src/td6/Calculator.o src/td6/Client.o src/td6/CrunchReq.o src/td6/Request.o src/td6/main.o
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td6.out  src/td1/posixHelpers.o src/td4/PosixThread.o src/td4/Thread.o src/td4/Mutex.o  src/td4/Semaphore.o src/td6/ActiveCalc.o src/td6/ActiveObject.o src/td6/Calculator.o src/td6/Client.o src/td6/CrunchReq.o src/td6/Request.o src/td6/main.o $(LDFLAGS)


clean: 
	rm -rvf build/*
	rm -f src/*/*.o