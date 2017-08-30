#include <iostream>
#include <chrono>
#include <thread>
#include <string>

#define PMETHODINLIBRARY1(name) std::string name()
typedef PMETHODINLIBRARY1(METHODINLIBRARY1);
PMETHODINLIBRARY1(library1methodstub)
{
	return "DLL NOT LOADED";
}

#include <Windows.h>
HMODULE library1DLL;
METHODINLIBRARY1* loadLibrary1Method()
{
	return (METHODINLIBRARY1*)GetProcAddress(library1DLL, "getText");
}

int main(int argc, char* argv[])
{
	METHODINLIBRARY1* library1method;
	while (true)
	{
		CopyFileA("library1.dll", "library1_temp.dll", false);
		library1DLL = LoadLibraryA("library1_temp.dll");
		if (library1DLL)
			library1method = (METHODINLIBRARY1*)GetProcAddress(library1DLL, "getText");
		if (!library1methodstub)
			library1method = library1methodstub;

		std::cout << library1method() << std::endl;
		FreeLibrary(library1DLL);
		Sleep(3000);
	}

	return 0;
}