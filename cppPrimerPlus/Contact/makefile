CXX = clang++
CXXFLAGS = -std=c++17 -Wall
TARGET = books_project

# 定义需要编译的cpp文件
SRCS = books.cpp
OBJS = $(SRCS:.cpp=.o);

# 默认构建目标文件
all: ${TARGET}

# 链接所有.o文件生成可执行文件
${TARGET}:${OBJS}
	$(CXX) $(CXXFLAGS) $^ -o $@

# 编译每个.cpp文件为.o文件
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理生成的文件
clean:
	rm -f $(TARGET) $(OBJS)
