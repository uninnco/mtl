#include <iostream>
#include <stdexcept>
#include <string>
#include "cpptest.h"
#include "../include/vector.h"

using namespace mtl;

class VectorTest:public Test::Suite
{
public:
    VectorTest() {
        TEST_ADD(VectorTest::Init);
	TEST_ADD(VectorTest::push_back);
	TEST_ADD(VectorTest::at);
	TEST_ADD(VectorTest::pop_back);
	TEST_ADD(VectorTest::insert);
	TEST_ADD(VectorTest::erase);
    }
private:
    void Init() {
	try{
        vector<int> v;
        TEST_ASSERT_MSG(v.size() == 0,"向量初始大小为0");
        TEST_ASSERT_MSG(v.capacity() == 0,"向量初始容量为0");
	}catch(...){
		TEST_FAIL("unknown exception");
	}
    }
    void push_back(){
	try{
	vector<int> v;
	v.push_back(10);
        TEST_ASSERT_MSG(v.size() == 1,"向量大小为1");
        TEST_ASSERT_MSG(v.capacity() == 1,"向量容量为1");
	}catch(...){
		TEST_FAIL("unknown exception");
	}
    }
    void at(){
	try{
	vector<int> v;
	v.push_back(10);
	TEST_ASSERT(v.at(0) == 10);
        TEST_ASSERT_MSG(v.size() == 1,"向量大小为1");
	v.push_back(11);
	TEST_ASSERT(v.at(1) == 11);
        TEST_ASSERT_MSG(v.size() == 2,"向量大小为2");
	}catch(...){
		TEST_FAIL("unknown exception");
	}
    }
    void pop_back(){
	try{
	vector<int> v;
	TEST_THROWS_MSG(v.pop_back(),runtime_error,"对空向量执行pop_back操作");
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
        TEST_ASSERT_MSG(v.size() == 4,"向量大小为4");
	v.pop_back();
        TEST_ASSERT_MSG(v.size() == 3,"向量大小为3");
	TEST_ASSERT(v.at(0) == 1);
	TEST_ASSERT(v.at(1) == 2);
	TEST_ASSERT(v.at(2) == 3);
	TEST_THROWS(v.at(3),out_of_range);
	}catch(...){
		TEST_FAIL("unknown exception");
	}
    }
    void erase(){
	vector<int> v;
	// 向空向量删除0位置元素
	TEST_THROWS_MSG(v.erase(0),runtime_error,"对空向量在0位置删除");
	TEST_THROWS_MSG(v.erase(5),runtime_error,"对空向量在5位置删除");
        TEST_ASSERT_MSG(v.size() == 0,"向量大小为0");
	
	v.push_back(10);
	TEST_THROWS_MSG(v.erase(5),out_of_range,"对空向量在5位置删除");
        TEST_ASSERT_MSG(v.size() == 1,"向量大小为1");
	v.erase(0);	
        TEST_ASSERT_MSG(v.size() == 0,"向量大小为0");
	v.push_back(10);
	v.push_back(11);
	v.push_back(12);
	v.push_back(13);
	v.erase(0);	
	TEST_ASSERT(v[0]==11);
	TEST_ASSERT(v[1]==12);
	TEST_ASSERT(v[2]==13);
        TEST_ASSERT_MSG(v.size() == 3,"向量大小为3");
	v.erase(1);	
	TEST_ASSERT(v[0]==11);
	TEST_ASSERT(v[1]==13);
        TEST_ASSERT_MSG(v.size() == 2,"向量大小为2");
	v.erase(1);	
	TEST_ASSERT(v[0]==11);
        TEST_ASSERT_MSG(v.size() == 1,"向量大小为1");
    }

    void insert(){
	vector<int> v;
	try{
	//向空向量插入数据 
	TEST_THROWS_MSG(v.insert(5,10),runtime_error,"对空向量在0位置外执行insert");
        TEST_ASSERT_MSG(v.size() == 0,"向量大小为0");
	v.insert(0,100);
	TEST_ASSERT(v[0]==100);
        TEST_ASSERT_MSG(v.size() == 1,"向量大小为1");
	}catch(...){
		TEST_FAIL("unknown exception");
	}
	try{
	v.insert(1,200);
	TEST_ASSERT(v[0]==100);
	TEST_ASSERT(v[1]==200);
        TEST_ASSERT_MSG(v.size() == 2,"向量大小为2");	
	}catch(...){
		TEST_FAIL("unknown exception");
	}
	try{
	v.insert(1,300);
	TEST_ASSERT(v[0]==100);
	TEST_ASSERT(v[1]==300);
	TEST_ASSERT(v[2]==200);
        TEST_ASSERT_MSG(v.size() == 3,"向量大小为3");	
	TEST_THROWS_MSG(v.insert(5,10),out_of_range,"对向量在超过size位置执行insert");
        TEST_ASSERT_MSG(v.size() == 3,"向量大小为3");	
	}catch(...){
		TEST_FAIL("unknown exception");
	}
	
    }
};

int main()
{

    VectorTest test;
   // Test::TextOutput output(Test::TextOutput::Terse);
    //Test::TextOutput output(Test::TextOutput::Verbose);
    Test::HtmlOutput output;
    test.run(output,true);
    output.generate(std::cout, true, "VectorTest");
}

