#include "CriticalSection.h"

CCriticalSection::CCriticalSection(void)
{
	//初始化
	::InitializeCriticalSection(&m_oCriSection);
}

CCriticalSection::~CCriticalSection(void)
{
	//反初始化
	::DeleteCriticalSection(&m_oCriSection);
}

BOOL CCriticalSection::Lock()
{
	//进入临界区
	::EnterCriticalSection(&m_oCriSection);

	return TRUE;
}

BOOL CCriticalSection::UnLock()
{
	//离开临界区
	::LeaveCriticalSection(&m_oCriSection);

	return TRUE;
}


//////////////////////////////////////////////////////////////////////////
CCriticalAutoLock::CCriticalAutoLock(CCriticalSection* pLock)
{
	if (pLock)
	{
		m_pLock = pLock;
		m_pLock->Lock();
	}
}

CCriticalAutoLock::~CCriticalAutoLock()
{
	if (m_pLock)
	{
		m_pLock->UnLock();
	}
}
