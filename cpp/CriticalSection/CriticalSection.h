#pragma once
#include <windows.h>

//��ͨ��
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


//�Զ���
class CCriticalAutoLock
{
public:
	CCriticalAutoLock(CCriticalSection* pLock);
	~CCriticalAutoLock();
	
private:
	CCriticalSection* m_pLock;
};