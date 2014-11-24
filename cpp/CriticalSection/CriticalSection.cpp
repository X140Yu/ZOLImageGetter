#include "CriticalSection.h"

CCriticalSection::CCriticalSection(void)
{
	//��ʼ��
	::InitializeCriticalSection(&m_oCriSection);
}

CCriticalSection::~CCriticalSection(void)
{
	//����ʼ��
	::DeleteCriticalSection(&m_oCriSection);
}

BOOL CCriticalSection::Lock()
{
	//�����ٽ���
	::EnterCriticalSection(&m_oCriSection);

	return TRUE;
}

BOOL CCriticalSection::UnLock()
{
	//�뿪�ٽ���
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
