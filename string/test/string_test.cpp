#include <iostream>
#include "../include/string.h"
#include "../include/stdexcept.h"
#include "/usr/local/include/cpptest.h"

using namespace mtl;
class Stringtest:public Test::Suite{
public:
	Stringtest(){
		TEST_ADD(Stringtest::Init);
		TEST_ADD(Stringtest::Add)
		TEST_ADD(Stringtest::Insert);
		TEST_ADD(Stringtest::Replace);
		TEST_ADD(Stringtest::Iterator);
		TEST_ADD(Stringtest::Find);
		TEST_ADD(Stringtest::Erase);
		TEST_ADD(Stringtest::Push_back);
		TEST_ADD(Stringtest::Compare);
		TEST_ADD(Stringtest::Compare_func);
	}
private:
	void Init(){
		try{
			mtl::string str1;
			TEST_ASSERT_MSG(str1.size() == 0,"大小为0");
			TEST_ASSERT_MSG(str1.length() == 0,"大小为0");
			TEST_ASSERT_MSG(str1.empty() == 1,"string为空");
			str1.push_back('a');
			TEST_ASSERT_MSG(str1.size() == 1,"大小为1");
			TEST_ASSERT_MSG(str1.length() == 1,"大小为1");
			TEST_ASSERT_MSG(str1.empty() == false,"string非空");
			str1.clear();
			TEST_ASSERT_MSG(str1.size() == 0,"大小为0");
			TEST_ASSERT_MSG(str1.length() == 0,"大小为0");
			TEST_ASSERT_MSG(str1.empty() == 1,"string为空");
			str1.push_back('a');
			str1.erase(0,1);	
			TEST_ASSERT_MSG(str1.size() == 0,"大小为0");
			TEST_ASSERT_MSG(str1.length() == 0,"大小为0");
			TEST_ASSERT_MSG(str1.empty() == 1,"string为空");
			mtl::string str2("abcd");
			TEST_ASSERT_MSG(str2.size() == 4,"大小为4");
			TEST_ASSERT_MSG(str2.length() == 4,"大小为4");
			TEST_ASSERT_MSG(str2.empty() == 0,"string不为空");
			TEST_ASSERT_MSG(str2[0] == 'a',"str1[0]为a");
			TEST_ASSERT_MSG(str2[1] == 'b',"str2[0]为b");
			TEST_ASSERT_MSG(str2[2] == 'c',"str1[0]为c");
			TEST_ASSERT_MSG(str2[3] == 'd',"str1[0]为d");
			mtl::string str3("apple",2,3);	
			TEST_ASSERT_MSG(str3.size() == 3,"大小为3");
			TEST_ASSERT_MSG(str3.length() == 3,"大小为3");
			TEST_ASSERT_MSG(str3.empty() == 0,"string不为空");
			TEST_ASSERT_MSG(str3[0] == 'p',"str3[0]为p");
			TEST_ASSERT_MSG(str3[1] == 'l',"str3[0]为l");
			TEST_ASSERT_MSG(str3[2] == 'e',"str3[0]为e");
			mtl::string str4("abcdefgh",4);
			TEST_ASSERT_MSG(str4.size() == 4,"大小为4");
			TEST_ASSERT_MSG(str4.length() == 4,"大小为4");
			TEST_ASSERT_MSG(str4.empty() == 0,"string不为空");
			TEST_ASSERT_MSG(str4[0] == 'a',"str1[0]为a");
			TEST_ASSERT_MSG(str4[1] == 'b',"str2[0]为b");
			TEST_ASSERT_MSG(str4[2] == 'c',"str1[0]为c");
			TEST_ASSERT_MSG(str4[3] == 'd',"str1[0]为d");
		
		}catch(...){
			TEST_FAIL("unknown exception");
		}
	}
	void Add(){
		try{
			mtl::string str1("abcd");
			mtl::string str2("efgh");
			TEST_ASSERT_MSG(str1.size() == 4,"大小为4");
			TEST_ASSERT_MSG(str1[0] == 'a',"str1[0]为a");
			TEST_ASSERT_MSG(str1[1] == 'b',"str1[1]为b");
			TEST_ASSERT_MSG(str1[2] == 'c',"str1[2]为c");
			TEST_ASSERT_MSG(str1[3] == 'd',"str1[3]为d");
			str1+=str2;
			TEST_ASSERT_MSG(str1.size() == 8,"大小为8");
			TEST_ASSERT_MSG(str1[0] == 'a',"str1[0]为a");
			TEST_ASSERT_MSG(str1[1] == 'b',"str1[1]为b");
			TEST_ASSERT_MSG(str1[2] == 'c',"str1[2]为c");
			TEST_ASSERT_MSG(str1[3] == 'd',"str1[3]为d");
			TEST_ASSERT_MSG(str1[4] == 'e',"str2[3]为e");
			TEST_ASSERT_MSG(str1[5] == 'f',"str1[3]为f");
			TEST_ASSERT_MSG(str1[6] == 'g',"str1[3]为g");
			TEST_ASSERT_MSG(str1[7] == 'h',"str1[3]为h");
		}catch(...){
			TEST_FAIL("unknown exception");	
		}
	}
	void Insert(){
		try{
			mtl::string str1("abcd");
			str1.insert(2,"efgh",0,2);
			TEST_ASSERT_MSG(str1.size() == 6,"大小为6");
			TEST_ASSERT_MSG(str1[0] == 'a',"str1[0]为a");
			TEST_ASSERT_MSG(str1[1] == 'b',"str1[1]为b");
			TEST_ASSERT_MSG(str1[2] == 'e',"str1[2]为e");
			TEST_ASSERT_MSG(str1[3] == 'f',"str1[3]为f");
			TEST_ASSERT_MSG(str1[4] == 'c',"str1[4]为c");
			TEST_ASSERT_MSG(str1[5] == 'd',"str1[5]为d");
			str1.insert(4,"efgh",2,2);
			TEST_ASSERT_MSG(str1.size() == 8,"大小为8");
			TEST_ASSERT_MSG(str1[0] == 'a',"str1[0]为a");
			TEST_ASSERT_MSG(str1[1] == 'b',"str1[1]为b");
			TEST_ASSERT_MSG(str1[2] == 'e',"str1[2]为e");
			TEST_ASSERT_MSG(str1[3] == 'f',"str1[3]为f");
			TEST_ASSERT_MSG(str1[4] == 'g',"str1[4]为g");
			TEST_ASSERT_MSG(str1[5] == 'h',"str1[5]为h");
			TEST_ASSERT_MSG(str1[6] == 'c',"str1[6]为c");
			TEST_ASSERT_MSG(str1[7] == 'd',"str1[7]为d");
			str1 = "abcd";	
			str1.insert(4,string("efgh"));
			TEST_ASSERT_MSG(str1.size() == 8,"大小为8");
			TEST_ASSERT_MSG(str1[0] == 'a',"str1[0]为a");
			TEST_ASSERT_MSG(str1[1] == 'b',"str1[1]为b");
			TEST_ASSERT_MSG(str1[2] == 'c',"str1[2]为c");
			TEST_ASSERT_MSG(str1[3] == 'd',"str1[3]为d");
			TEST_ASSERT_MSG(str1[4] == 'e',"str1[4]为e");
			TEST_ASSERT_MSG(str1[5] == 'f',"str1[5]为f");
			TEST_ASSERT_MSG(str1[6] == 'g',"str1[6]为g");
			TEST_ASSERT_MSG(str1[7] == 'h',"str1[7]为h");
			str1 = "abcd";	
			str1.insert(4,"efgh");
			TEST_ASSERT_MSG(str1.size() == 8,"大小为8");
			TEST_ASSERT_MSG(str1[0] == 'a',"str1[0]为a");
			TEST_ASSERT_MSG(str1[1] == 'b',"str1[1]为b");
			TEST_ASSERT_MSG(str1[2] == 'c',"str1[2]为c");
			TEST_ASSERT_MSG(str1[3] == 'd',"str1[3]为d");
			TEST_ASSERT_MSG(str1[4] == 'e',"str1[4]为e");
			TEST_ASSERT_MSG(str1[5] == 'f',"str1[5]为f");
			TEST_ASSERT_MSG(str1[6] == 'g',"str1[6]为g");
			TEST_ASSERT_MSG(str1[7] == 'h',"str1[7]为h");
			str1 = "abcd";	
			str1.insert(4,4,'e');
			TEST_ASSERT_MSG(str1.size() == 8,"大小为8");
			TEST_ASSERT_MSG(str1[0] == 'a',"str1[0]为a");
			TEST_ASSERT_MSG(str1[1] == 'b',"str1[1]为b");
			TEST_ASSERT_MSG(str1[2] == 'c',"str1[2]为c");
			TEST_ASSERT_MSG(str1[3] == 'd',"str1[3]为d");
			TEST_ASSERT_MSG(str1[4] == 'e',"str1[4]为e");
			TEST_ASSERT_MSG(str1[5] == 'e',"str1[5]为e");
			TEST_ASSERT_MSG(str1[6] == 'e',"str1[6]为e");
			TEST_ASSERT_MSG(str1[7] == 'e',"str1[7]为e");
		}catch(...){
			TEST_FAIL("unknown exception");	
		}
	}
	void Replace(){
		try{
			mtl::string str1("abcd");
			mtl::string str2("1234");
			str1.replace(2,2,str2);
			TEST_ASSERT_MSG(str1.size()==6,"大小为6");
			TEST_ASSERT_MSG(str1[0] == 'a',"str1[0]为a");
			TEST_ASSERT_MSG(str1[1] == 'b',"str1[1]为b");
			TEST_ASSERT_MSG(str1[2] == '1',"str1[0]为1");
			TEST_ASSERT_MSG(str1[3] == '2',"str1[0]为2");
			TEST_ASSERT_MSG(str1[4] == '3',"str1[1]为3");
			TEST_ASSERT_MSG(str1[5] == '4',"str1[1]为4");
			str1 = "abcd";
			str1.replace(2,2,str2,0,2);	
			TEST_ASSERT_MSG(str1.size()==4,"大小为4");
			TEST_ASSERT_MSG(str1[0] == 'a',"str1[0]为a");
			TEST_ASSERT_MSG(str1[1] == 'b',"str1[1]为b");
			TEST_ASSERT_MSG(str1[2] == '1',"str1[0]为1");
			TEST_ASSERT_MSG(str1[3] == '2',"str1[0]为2");
			str1 = "abcd";
			str1.replace(1,2,"efgh",3);
			TEST_ASSERT_MSG(str1.size()==5,"大小为5");
			TEST_ASSERT_MSG(str1[0] == 'a',"str1[0]为a");
			TEST_ASSERT_MSG(str1[1] == 'e',"str1[0]为e");
			TEST_ASSERT_MSG(str1[2] == 'f',"str1[0]为f");
			TEST_ASSERT_MSG(str1[3] == 'g',"str1[0]为g");
			TEST_ASSERT_MSG(str1[4] == 'd',"str1[0]为d");
			
			str1 = "abcd";
			str1.replace(3,1,4,'x');
			TEST_ASSERT_MSG(str1.size() == 7,"大小为7");
			TEST_ASSERT_MSG(str1[0] == 'a',"str1[0]为a");
			TEST_ASSERT_MSG(str1[1] == 'b',"str1[1]为b");
			TEST_ASSERT_MSG(str1[2] == 'c',"str1[2]为c");
			TEST_ASSERT_MSG(str1[3] == 'x',"str1[2]为x");
			TEST_ASSERT_MSG(str1[4] == 'x',"str1[2]为x");
			TEST_ASSERT_MSG(str1[5] == 'x',"str1[2]为x");
			TEST_ASSERT_MSG(str1[5] == 'x',"str1[2]为x");
			
		}catch(...){
			TEST_FAIL("unknown exception");	
		}
	}
	void Iterator(){
		try{
			mtl::string str1("abcd");
			mtl::string::iterator it =str1.begin();
			TEST_ASSERT_MSG(*(it++) == 'a',"it == a ");
			TEST_ASSERT_MSG(*(it++) == 'b',"it == b");
			TEST_ASSERT_MSG(*(it++) == 'c',"it == c");
			TEST_ASSERT_MSG(*(it++) == 'd',"it == d");
		}catch(...){
			TEST_FAIL("unknown exception");	
		}
	
	}
	void Find(){
		try{
			mtl::string str1("abcdefgh");
			mtl::string str2("efgh");
			TEST_ASSERT_MSG(str1[str1.find(str2,0)]=='e',"find true");
			TEST_ASSERT_MSG(str1[str1.find('e',3)] == 'e',"find true");
			TEST_ASSERT_MSG(str1[str1.find("efgl",0,3)]=='e',"find true");
			//size_t n = -1;
			//TEST_ASSERT_MSG(str1[str1.find(str2,5)]!='e'and str1.find(str2,5)== n,"find true");
			
		}catch(...){
			TEST_FAIL("unknown exception");	
		}
	}
	void Erase(){
		try{
			mtl::string str1("abcdefgh");
			str1.erase(4,4);
			TEST_ASSERT_MSG(str1.size() == 4,"大小为4");
			TEST_ASSERT_MSG(str1[0] == 'a',"str1[0]为a");
			TEST_ASSERT_MSG(str1[1] == 'b',"str1[1]为b");
			TEST_ASSERT_MSG(str1[2] == 'c',"str1[2]为c");
			TEST_ASSERT_MSG(str1[3] == 'd',"str1[3]为d");
			
		}catch(...){
			TEST_FAIL("unknown exception");	
		}
	}
	void Push_back(){
		try{
			mtl::string str1;
			str1.push_back('a');
			TEST_ASSERT_MSG(str1.size() == 1,"大小为1");
			TEST_ASSERT_MSG(str1[0] == 'a',"str1[0]为a");
			str1.push_back('b');
			TEST_ASSERT_MSG(str1.size() == 2,"大小为2");
			TEST_ASSERT_MSG(str1[1] == 'b',"str1[1]为b");
			str1.push_back('c');
			TEST_ASSERT_MSG(str1.size() == 3,"大小为3");
			TEST_ASSERT_MSG(str1[2] == 'c',"str1[2]为c");
			str1.push_back('d');
			TEST_ASSERT_MSG(str1.size() == 4,"大小为4");
			TEST_ASSERT_MSG(str1[3] == 'd',"str1[3]为d");
			
		}catch(...){
			TEST_FAIL("unknown exception");	
		}
	}
	void Compare(){
		try{
			mtl::string str1("abcd");
			mtl::string str2("abcd");
			TEST_ASSERT_MSG(str1==str2,"str1==str2");
			str2="abcc";
			TEST_ASSERT_MSG(str1>=str2,"str1>=str2");
			str2="abce";
			TEST_ASSERT_MSG(str1<=str2,"str1<=str2");
			TEST_ASSERT_MSG(str1!=str2,"str1!=str2");
			
		}catch(...){
			TEST_FAIL("unknown exception");	
		}
	}
	void Compare_func(){
		try{
			mtl::string str1("green apple");
			mtl::string str2("red apple");
			TEST_ASSERT_MSG(str1.compare(str2)!= 0,"green apple is not red apple");
			TEST_ASSERT_MSG(str1.compare(6,5,"apple") == 0,"still,green apple is an  apple");
			TEST_ASSERT_MSG(str2.compare(str2.size()-5,5,"apple") == 0,"and red apple is also an  apple");
			TEST_ASSERT_MSG(str1.compare(6,5,str2,4,5) == 0,"and red apple is also an  apple");
		}catch(...){
			TEST_FAIL("unknown exception");
		}
	}

};
int main(){
	Stringtest string_test;
	Test::HtmlOutput output;
	string_test.run(output,true);
	output.generate(std::cout,true,"Stringtest");
}
