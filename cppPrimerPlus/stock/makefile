CXX = clang++
CXXFLAGS = -std=c++17 -Wall
TARGET = stock_program

# 定义所有需要编译的 .cpp 文件（排除头文件）
SRCS = stock00.cpp usestock0.cpp
OBJS = $(SRCS:.cpp=.o)  # 将 .cpp 替换为 .o

# 默认构建目标
all: $(TARGET)

# 链接所有 .o 文件生成可执行文件
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# 编译每个 .cpp 文件为 .o 文件
%.o: %.cpp stock00.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	rm -f $(TARGET) $(OBJS)