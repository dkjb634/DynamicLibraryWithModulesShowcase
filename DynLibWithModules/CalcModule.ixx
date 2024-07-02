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