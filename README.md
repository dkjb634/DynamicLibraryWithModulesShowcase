There are Dynamic Library and Console Application projects in solution.
The library project contains module definition and module implementation files:
*CalcModule.ixx:*
```
export module CalcModule;

#ifndef MY_DLL_EXPORT
#define MY_DLL_EXPORT __declspec(dllexport)
#endif

export int MY_DLL_EXPORT Foo()
{
    return 1;
}

export class MY_DLL_EXPORT Calculator
{
public:
    static int Sum(int a, int b);
};
```
*CalcModule.cpp:*
```
module CalcModule;

int Calculator::Sum(int a, int b)
{
    return a+b;
}
```

The Console Application project utilizes the referenced module:
```
import CalcModule;

#include <iostream>

int main(int argc, char* argv[])
{
    std::cout << Calculator::Sum(5,5);
    return 0;
}
```

To make such a setup work, the following properties should be adjusted for the library consumer project: (pathes are relative to the consumer .vcxproj file)
* *Linker->General->Additional Library Directories* - should point to the folder with .dll and .lib files (*../x64/Debug/*);
* *Linker->Input->Additional Dependencies* - should point to the .lib file (*$(CoreLibraryDependencies);%(AdditionalDependencies);../x64/Debug/DynLibWithModules.lib*);
* *C/C++->Command Line* - add the `/reference "../DynLibWithModules/x64/Debug/CalcModule.ixx.ifc"` to the command line;

After doing this, project builds and runs fine;
