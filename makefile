CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./include

SRC = source/main.cpp source/random_utils.cpp source/text_utils.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = valfilter

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) -o $(EXEC)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)

