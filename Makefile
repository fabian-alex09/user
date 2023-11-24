
CXX=g++
OBJ_DIR = ./login
CXXFLAGS = -c 

output: main.o User.o UserManager.o
	g++ main.o User.o UserManager.o -o main

main.o: ./main.cpp
	$(CXX) $(CFLAGS) ./main.cpp

User.o: login/User.cpp login/User.h
	$(CXX) $(CFLAGS) login/User.cpp

UserManager.o: login/UserManager.cpp login/UserManager.h
	$(CXX) $(CFLAGS) login/UserManager.cpp

clean:
	rm *.o output

