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

td2: src/td1/posixHelpers.o src/td2/main_td2a.o src/td2/main_td2b.o src/td2/main_td2c.o
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td2_a.out src/td1/posixHelpers.o src/td2/main_td2a.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td2_b.out src/td1/posixHelpers.o src/td2/main_td2b.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td2_c.out src/td1/posixHelpers.o src/td2/main_td2c.o $(LDFLAGS)

td3: src/td1/posixHelpers.o src/td3/Chrono.o src/td3/Timer.o src/td3/PeriodicTimer.o src/td3/CountDown.o src/td3/Calibrator.o src/td3/Looper.o src/td3/main_td3a.o src/td3/main_td3b.o src/td3/main_td3c.o
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td3_a.out src/td1/posixHelpers.o src/td3/Chrono.o src/td3/main_td3a.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td3_b.out src/td1/posixHelpers.o src/td3/Timer.o src/td3/PeriodicTimer.o src/td3/CountDown.o src/td3/main_td3b.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td3_c.out src/td1/posixHelpers.o src/td3/Timer.o src/td3/PeriodicTimer.o src/td3/Calibrator.o src/td3/Looper.o src/td3/main_td3c.o $(LDFLAGS)

td4: src/td1/posixHelpers.o src/td4/PosixThread.o src/td4/Thread.o src/td4/Mutex.o src/td4/AIncrementer.o src/td4/BIncrementer.o src/td4/Semaphore.o src/td4/CProducer.o src/td4/DProducer.o src/td4/main_td4a.o src/td4/main_td4b.o src/td4/main_td4c.o src/td4/main_td4d.o
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td4_a.out src/td1/posixHelpers.o src/td4/PosixThread.o src/td4/Thread.o src/td4/AIncrementer.o src/td4/main_td4a.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td4_b.out src/td1/posixHelpers.o src/td4/PosixThread.o src/td4/Thread.o src/td4/Mutex.o src/td4/BIncrementer.o src/td4/main_td4b.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td4_c.out src/td1/posixHelpers.o src/td4/PosixThread.o src/td4/Thread.o src/td4/Mutex.o src/td4/Semaphore.o src/td4/CProducer.o src/td4/main_td4c.o $(LDFLAGS)
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td4_d.out src/td1/posixHelpers.o src/td4/PosixThread.o src/td4/Thread.o src/td4/Mutex.o src/td4/DProducer.o src/td4/main_td4d.o $(LDFLAGS)

td6: src/td1/posixHelpers.o src/td4/PosixThread.o src/td4/Thread.o src/td4/Mutex.o  src/td4/Semaphore.o src/td6/ActiveCalc.o src/td6/ActiveObject.o src/td6/Calculator.o src/td6/Client.o src/td6/CrunchReq.o src/td6/Request.o src/td6/main_td6.o
	$(CXX) $(CXXFLAGS) -o $(BUILD)/td6.out  src/td1/posixHelpers.o src/td4/PosixThread.o src/td4/Thread.o src/td4/Mutex.o  src/td4/Semaphore.o src/td6/ActiveCalc.o src/td6/ActiveObject.o src/td6/Calculator.o src/td6/Client.o src/td6/CrunchReq.o src/td6/Request.o src/td6/main_td6.o $(LDFLAGS)


clean: 
	rm -rvf build/*
	rm -f src/*/*.o