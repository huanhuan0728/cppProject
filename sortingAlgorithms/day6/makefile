# 定义编译器
CXX = clang++
# 定义编译选项
CXXFLAGS = -std=c++17 -Wall
# 目标可执行文件
TARGET1 = day6_program
TARGET2 = heapSort_program
# 源文件
SRC1 = day6.cpp
SRC2 = heapSort.cpp
# 生成的对象文件
OBJ1 = $(SRC1:.cpp=.o)
OBJ2 = $(SRC2:.cpp=.o)

# 默认目标：编译所有可执行文件
all: $(TARGET1) $(TARGET2)

# 编译 day4.cpp 生成 day4_program
$(TARGET1): $(OBJ1)
	$(CXX) $(CXXFLAGS) -o $(TARGET1) $(OBJ1)

# 编译 heapSort.cpp 生成 heapSort_program
$(TARGET2): $(OBJ2)
	$(CXX) $(CXXFLAGS) -o $(TARGET2) $(OBJ2)

# 编译源文件生成对象文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理所有生成的文件
clean:
	rm -f $(OBJ1) $(OBJ2) $(TARGET1) $(TARGET2)
