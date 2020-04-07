td3/b: ../TD1/posixHelpers.cpp ./b/PeriodicTimer.cpp ./b/Countdown.cpp ./b/Timer.cpp ./b/b.cpp
	g++ -Wall -Wextra -O3 ../TD1/posixHelpers.cpp ./b/PeriodicTimer.cpp ./b/CountDown.cpp ./b/Timer.cpp ./b.cpp -o build/countdown -lrt

td3/a: ./a/Chrono.cpp ./a/a.cpp ../TD1/posixHelpers.cpp
	g++ -Wall -Wextra -O3 ./a/Chrono.cpp ../TD1/posixHelpers.cpp ./a/a.cpp -o build/chrono -lrt

clean: 
	rm -rvf build/*