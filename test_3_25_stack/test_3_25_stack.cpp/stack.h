
#include<iostream>
#include<string>

using namespace std;

struct _TrueType
{
	bool Get()
	{
		return true;
	}
};
struct _FalseType
{
	bool Get()
	{
		return false;
	}
};
template<typename T>
struct TypeTraits
{
	typedef _FalseType isPODType;
};
template<>
struct TypeTraits<unsigned int>
{
	typedef _TrueType isPODType;
};
template<>
struct TypeTraits<signed int>
{
	typedef _TrueType isPODType;
};
template<>
struct TypeTraits<unsigned char>
{
	typedef _TrueType isPODType;
};
template<>
struct TypeTraits<signed char>
{
	typedef _TrueType isPODType;
};
template<>
struct TypeTraits<float>
{
	typedef _TrueType isPODType;
};
template<>
struct TypeTraits<double>
{
	typedef _TrueType isPODType;
};
template<>
struct TypeTraits<long>
{
	typedef _TrueType isPODType;
};