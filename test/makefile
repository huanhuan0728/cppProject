# Makefile

# 变量定义
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I/Users/xuhuanlu/Desktop/cppProject/Class  # 添加QuickSort.h的路径
LDFLAGS = 

# 项目目标
TARGET = quickSortTest

# 源文件路径

#SRC = /Users/xuhuanlu/Desktop/cppProject/test/quickSortTest.cpp
SRC = quickSortTest.cpp /Users/xuhuanlu/Desktop/cppProject/Class/QuickSort.cpp

# 相对路径
#SRC = quickSortTest.cpp ../Class/QuickSort.cpp

# 目标文件
OBJ = $(SRC:.cpp=.o)

# 默认目标
all: $(TARGET)

# 链接目标
$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

# 编译源文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理目标文件和可执行文件
clean:
	rm -f $(OBJ) $(TARGET)

# 伪目标
.PHONY: all clean
