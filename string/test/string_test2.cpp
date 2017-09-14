#include <iostream>
#include "../include/string.h"
#include "../include/stdexcept.h"

using namespace std;
int main(){
	mtl::string str1;	
	mtl::string str2("efgh");
	
	str1 = "abcd";
	cout <<"str1+str2 "<<str1+str2<<endl;
	mtl::string str3("ijkl");
	bool t = (str1.c_str()==NULL)?true:false;
	cout <<"str1 is null " << boolalpha <<t<< noboolalpha << " str1.size "<< str1.size()<<endl;
	str1 = "abcd";
	cout <<"str1+str2 "<<str1+str2<<endl;
	str1 = "abcd";
	str1+=str2;
	cout << "str1+=str2 "<<str1 <<endl;
	cout <<"str1.substr(0,4) "<< str1.substr(0,4)<<" sub.size() "<<str1.substr(0,4).size()<<endl;
	cout <<"str1.substr(1,2) "<< str1.substr(1,2)<<" sub.size() "<<str1.substr(1,2).size()<<endl;
	cout <<"str1.append(str3) "<< str1.append(str3)<<endl;
	cout <<"str[i]";
	for(size_t i = 0; i < str1.size();i++){
		cout << str1[i];
	}
	cout << endl;
	cout <<"str.c_str()" <<str2.c_str()<<endl;
	str1.resize(13,'c');
	cout <<"str1.resize(13,'c') "<< str1 <<endl;
	str1.resize(8);
	cout << "str1.resize(8) "<<str1 <<endl;
	str1.resize(15,'x');
	cout <<"str1.resize(15,'x') "<<str1 <<endl;
	str1 = "abcd";
	str1.insert(2,str2,2,2);
	cout << "str1:insert1 "<< str1;
	cout <<" "<< str1.size()<<endl;
	str1="abcd";
	str1.insert(2,"efgh",0,2);
	cout << "str1:insert2: "<< str1;
	cout <<" "<< str1.size()<<endl;
	str1="abcd";
	str1.insert(4,"efgh",0,4);
	cout << "str1:insert3: "<< str1;
	cout <<" "<< str1.size()<<endl;
	str1="abcd";
	str1.insert(4,"efgh");
	cout << "str1:insert4: "<< str1;
	cout <<" "<< str1.size()<<endl;
	str1="abcd";
	str1.insert(4,4,'e');
	cout << "str1:insert5: "<< str1;
	cout <<" "<< str1.size()<<endl;
	str1="abcd";
	str1.insert(4,4,'e');
	str1.insert(4,4,'e');
	cout << "str1:insert5: "<< str1;
	cout <<" "<< str1.size()<<endl;
	str1.erase(0,12);
	cout << "str1.erase: "<< str1<<"size "<< str1.size()<<endl;
	str1="abcd";
	str1.replace(0,4,str2);
	cout <<"str1:replace: "<<str1<<" size: "<<str1.size()<<endl;
	str1.erase(0,4);
	cout << "str1.erase: "<< str1<<"size "<< str1.size()<<endl;
	str1="abcd";
	str2="efgh";
	
	mtl::string str6(str1,2,4);
	cout <<"str6: "<< str6<<endl;
	str1.replace(0,4,str2,2,2);
	cout <<"str1:replace: "<<str1<<" size: "<<str1.size()<<endl;
	str1="abcd";
	str1.replace(0,4,"qwerboom",4);
	cout <<"str1:replace: "<<str1<<" size: "<<str1.size()<<endl;
	str1="abcd";
	str1.replace(0,4,4,'a');
	cout <<"str1:replace: "<<str1<<" size: "<<str1.size()<<endl;
	str1.clear();
	if(str1.c_str() == NULL){
		cout <<"str 为空 "<<boolalpha << true << noboolalpha<<endl;
	}
	cout << str1 <<"size: "<< str1.size()<<endl;
	mtl::string::iterator it = str1.begin();
	while(it !=str1.end()){
	cout <<" it :" << *it<<endl;
	it++;
	}
	//mtl::string::iterator  it3 =str1.cbegin();
	//while(it3 !=str1.cend()){
//	cout <<" it3 :" << *it<<endl;
//	it3++;
//	}
	mtl::string::reverse_iterator it2 = str1.rbegin();
	while(it2!=str1.rend())
	cout <<" rbegin :" << *(it2++)<<endl;
	mtl::string::reverse_iterator it3 = str1.rend();
	cout <<" rend :" << *(it3++)<<endl;
	str1.push_back('b');
	cout <<"push_back: " <<str1<<endl;
	str1 = "abcd";
	cout <<"str1.find(\"cd\",3): "<< str1.find("cd",3)<<endl;
//	str1 = "abcd";
//	cout <<"str1.find(\"cd\",5)(超出位置): "<< str1[str1.find("cd",5)]<<endl;
	str1 = "abcd";
	cout <<"str1.find(c,0): "<< str1[str1.find('c',0)]<<endl;
		
}
