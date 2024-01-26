
CXX=g++
INC_DIR = ./includes
CXXFLAGS = -c 
OBJECTS = main.o User.o UserManager.o

$(OBJECTS) = *.o: *c *h



output: main.o User.o UserManager.o
	g++ main.o User.o UserManager.o -o main

main.o: ./main.cpp
	$(CXX) -c ./main.cpp

User.o: ./includes/User.cpp ./includes/User.h
	$(CXX) $(CXXFLAGS) ./includes/User.cpp

UserManager.o: ./includes/UserManager.cpp ./includes/UserManager.h
	$(CXX) $(CXXFLAGS) ./includes/UserManager.cpp

%.o : %.cpp %.h
	$(CXX) -o $@ $< $(CXXFLAGS)

clean:
	rm *.o output

