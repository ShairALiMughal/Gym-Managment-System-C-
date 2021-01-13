#ifdef _WIN32
#include"main.cpp"
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	try{
	
we();Sleep(500); 
loding();cout<<"\n\n\n";
welcome();
system("pause");
hotleinfo();
system("pause");
login();

}
catch (exception& e)
{
	login();
}
}
