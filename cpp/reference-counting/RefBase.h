#pragma once
#include "Common.h"
#include "CriticalSection.h"
class CRefBase
{
public:
	CRefBase()
	{
		m_lRefCount = 0;
	}
	virtual ~CRefBase()
	{
	}

public:
	virtual long AddRef()
	{
		long lRef = 0;
		m_oLock.Lock();
		lRef = m_lRefCount++;
		m_oLock.UnLock();

		return lRef;
	}
	virtual void Release()
	{
		m_oLock.Lock();
		m_lRefCount--;
		m_oLock.UnLock();

		if (0 == m_lRefCount)
		{
			delete this;
		}
	}

private:
	long m_lRefCount;			//引用计数
	CCriticalSection m_oLock;	//引用计数锁
};