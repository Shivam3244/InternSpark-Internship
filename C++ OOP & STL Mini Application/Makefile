CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra

TARGET = student_manager

all:
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET) students.txt
