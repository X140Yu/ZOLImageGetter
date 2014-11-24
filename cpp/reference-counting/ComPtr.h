#pragma once
#ifdef _WIN64
	typedef __int64		GPI_V_TYPE;
#else
	typedef int			GPI_V_TYPE;
#endif

template<typename T>
class CComPtr
{
public:
	CComPtr()
	{
		ptr = NULL;
	};
	CComPtr(T * apValue)
	{
		ptr = apValue;
		if((ptr))
			(ptr)->AddRef();
	};
	CComPtr(const CComPtr<T>& aoSrc)
	{
		ptr = aoSrc.ptr;
		if(ptr)
			(ptr)->AddRef();
	};
	~CComPtr(void)
	{
		if((ptr))
			(ptr)->Release();
		ptr = NULL;
	};

public:
	CComPtr& operator = (const CComPtr<T>& aoSrc)
	{
		if(ptr != aoSrc.ptr)
		{
			if(ptr)
				(ptr)->Release();
			ptr = aoSrc.ptr;
			if(ptr)
				(ptr)->AddRef();
		}
		return *this;
	};
	CComPtr& operator = (T * apValue)
	{
		if((ptr))
			(ptr)->Release();
		ptr = apValue;
		if((ptr))
			(ptr)->AddRef();
		return *this;
	};
	CComPtr& operator = (int aiValue)
	{
		if((ptr))
			(ptr)->Release();
		ptr = (T*)(INT_PTR)aiValue;
		if((ptr))
			(ptr)->AddRef();
		return *this;
	};
	CComPtr& operator = (__int64 aiValue)
	{
		if((ptr))
			(ptr)->Release();
		ptr = (T*)(INT_PTR)aiValue;
		if((ptr))
			(ptr)->AddRef();
		return *this;
	};

public:
	bool operator == (T * apValue)
	{
		return ((ptr) == (apValue));
	};
	bool operator == (GPI_V_TYPE aiValue)
	{
		return ((GPI_V_TYPE)(INT_PTR)ptr == (aiValue));
	};
	bool operator != (T * apValue)
	{
		return ((ptr) != (apValue));
	};
	bool operator != (GPI_V_TYPE aiValue)
	{
		return ((GPI_V_TYPE)(INT_PTR)ptr != (aiValue));
	};
	bool operator ! ()
	{
		return (ptr == NULL ?  true : false);
	};
	T& operator * () const
	{
		return *ptr;
	};
	T* operator -> () const
	{
		return ptr;
	};

	//T** operator & ()
	//{
	//	return &ptr;
	//};

public:
	operator void ** ()
	{
		return (void**)(&ptr);
	};
	operator void * ()
	{
		return ptr;
	};
	operator T ** ()
	{
		return &ptr;
	};
	operator T * ()
	{
		return ptr;
	};
	operator GPI_V_TYPE ()
	{
		return (GPI_V_TYPE)(INT_PTR)ptr;
	};
	
public:
	template<typename C_T>
	C_T * ToBaseP()
	{
		return (C_T*)ptr;
	};
	template<typename C_T>
	C_T ** ToBasePP()
	{
		return (C_T**)&ptr;
	}

public:
	T * ptr;
};
