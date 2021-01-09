#include<iostream>
#include<iomanip>
#include<string>
#include<io.h>
#include<fcntl.h>
#include <codecvt>
using namespace std;
typedef basic_ostream<char16_t> u16ostream;
typedef basic_streambuf<char16_t> u16streambuf;
u16ostream u16cout(reinterpret_cast<u16streambuf*>(wcout.rdbuf()));
typedef basic_ostream<char8_t> u8ostream;
typedef basic_streambuf<char8_t> u8streambuf;
u8ostream u8cout(reinterpret_cast<u8streambuf*>(wcout.rdbuf()));
using namespace std;
wostream& operator<<(wostream& os,char8_t c8){
	os<<(char)c8;
	return os;
}
wostream& operator<<(wostream& os,const char8_t *c8){
	_setmode(_fileno(stdout),_O_WTEXT);
	u8string c8s(c8);
	std::wstring_convert<std::codecvt_utf8<wchar_t>> cvtr;
	string sss{};
	for(auto i : c8s){
		sss.append(1,(char)i);
	}
	wstring ll;
	try{
	
	ll=cvtr.from_bytes(sss);}
	catch(...){
		os.fill(ios::badbit);
		return os;
	}
	os<<ll;
	_setmode(_fileno(stdout),_O_TEXT);
	return os;
}
wostream& operator<<(wostream& os,u8string c8){
	os<<c8.c_str();
	return os;
}
u8ostream& operator<<(u8ostream& os,char8_t c8){
	os<<(char)c8;
	return os;
}
u8ostream& operator<<(u8ostream& os,const char8_t *c8){
	_setmode(_fileno(stdout),_O_WTEXT);
	u8string c8s(c8);
	std::wstring_convert<std::codecvt_utf8<wchar_t>> cvtr;
	string sss{};
	for(auto i : c8s){
		sss.append(1,(char)i);
	}
	wstring ll;
	try{
	
	ll=cvtr.from_bytes(sss);}
	catch(...){
		os.fill(ios::badbit);
		return os;
	}
	wcout<<ll;// It cannot raise any problems so I used wcout :-) 
	_setmode(_fileno(stdout),_O_TEXT);
	return os;
}
u8ostream& operator<<(u8ostream& os,u8string c8){
	os<<c8.c_str();
	return os;
}
