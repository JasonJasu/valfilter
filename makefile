#CXX = x86_64-w64-mingw32-g++					#<- Uncomment this for universal executable. Requires MSYS2
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./include
LDFLAGS = -static -static-libgcc -static-libstdc++

SRC = source/main.cpp source/random_utils.cpp source/text_utils.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = valfilter.exe

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC) $(LDFLAGS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
