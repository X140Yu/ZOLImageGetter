#pragma once
#include <windows.h>

//ÆÕÍ¨Ëø
class CCriticalSection
{
public:
	CCriticalSection(void);
	~CCriticalSection(void);

	BOOL Lock();
	BOOL UnLock();
private:
	CRITICAL_SECTION	m_oCriSection;
};


//×Ô¶¯Ëø
class CCriticalAutoLock
{
public:
	CCriticalAutoLock(CCriticalSection* pLock);
	~CCriticalAutoLock();
	
private:
	CCriticalSection* m_pLock;
};