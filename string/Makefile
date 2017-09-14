# 头文件
INCLUDE =include/

# 源文件
SRC     =src/

# 测试文件
TEST    =test/

# 说明文档
DOC     =doc/

# 编译选项
CXXFLAGS= -Wall -g

# 头文件
INC_FLAGS = -I $(INCLUDE)

# 连接选项
LDFLAGS = -lcpptest

# 目标文件
OBJ     =$(TEST)string_test.o $(TEST)string.o $(TEST)stdexcept.o
##$(TEST)bignum.o 

all:string.o stdexcept.o string_test.o string_test cpptest astyle doxygen

# 编译
string.o:$(SRC)string.cpp
	g++ -c $(CXXFLAGS)  -o $(TEST)$@ $<
stdexcept.o:$(SRC)stdexcept.cpp
	g++ -c $(CXXFLAGS)  -o $(TEST)$@ $< 
string_test.o:$(TEST)string_test.cpp
	g++ -c $(CXXFLAGS) -o $(TEST)$@ $<
string_test:$(OBJ)
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) -o $(TEST)$@ $(OBJ) $(LDFLAGS)



##:.$(SRC)bignum.cpp
##	g++ $(CXXFLAGS) -c -o $(TEST)$@ $<

# 静态代码检测
cppcheck:
	cppcheck --enable=all $(SRC) $(INCLUDE)

# 测试
cpptest:
	$(TEST)string_test > $(TEST)test.html

# TODO 覆盖率测试

# TODO 代码统计

# 清空
clean:
	rm -f $(TEST)string_test.o
	rm -f $(TEST)string_test
	rm -f $(TEST)*.html
	rm -f $(DOC)html/*.*

# 格式化
astyle:
	astyle -A8 $(INCLUDE)*.h $(SRC)*.cpp

# 生成文档
doxygen:
	doxygen

