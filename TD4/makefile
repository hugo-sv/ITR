td43: ../TD1/posixHelpers.cpp src/1/PosixThread.cpp src/1/Thread.cpp src/2/Mutex.cpp src/3/Semaphore.cpp src/3/Producer.cpp src/3/c.cpp 
	g++ -Wall -Wextra -O3 ../TD1/posixHelpers.cpp src/1/PosixThread.cpp src/1/Thread.cpp src/2/Mutex.cpp src/3/Semaphore.cpp src/3/Producer.cpp src/3/c.cpp -o build/semaphore -lrt -pthread


td42: ../TD1/posixHelpers.cpp src/1/PosixThread.cpp src/1/Thread.cpp src/2/IncrementerMut.cpp src/2/Mutex.cpp src/2/b.cpp 
	g++ -Wall -Wextra -O3 ../TD1/posixHelpers.cpp src/1/PosixThread.cpp src/1/Thread.cpp src/2/IncrementerMut.cpp src/2/Mutex.cpp src/2/b.cpp -o build/mutex -lrt -pthread

td41: ../TD1/posixHelpers.cpp src/1/PosixThread.cpp src/1/Thread.cpp src/1/Incrementer.cpp src/1/a.cpp
	g++ -Wall -Wextra -O3 ../TD1/posixHelpers.cpp src/1/PosixThread.cpp src/1/Thread.cpp src/1/Incrementer.cpp src/1/a.cpp -o build/posixthread -lrt -pthread

clean: 
	rm -rvf build/*