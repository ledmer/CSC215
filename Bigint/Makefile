CXX = g++
CXXFLAGS = -std=c++11 -g

test: bigint.cpp bigint.h test_bigint.cpp
	$(CXX) $(CXXFLAGS) -o test test_bigint.cpp bigint.cpp
	

clean:
	rm -f test