CXX=g++
INC=/usr/local/include
LIB=-lcudd

main: main.cpp
	$(CXX) -Wall -std=c++14 -o main main.cpp -I$(INC) $(LIB)
