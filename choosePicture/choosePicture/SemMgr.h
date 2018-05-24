/*************************************************
  Copyright (C), 2010-2020, moemillab.
  File name:      SemMgr.h
  Author:  cslong   Date: 2014Äê4ÔÂ22ÈÕ14:55:05
  Description:    
  Others:        
*************************************************/
#ifndef __SEM__MGR_H__
#define __SEM__MGR_H__


#ifdef WIN32
#include "windows.h"

class SemMgr
{
public:    
    SemMgr(HANDLE seg)
    {
       m_sem = seg;
       WaitForSingleObject(m_sem, INFINITE);
    }
    ~SemMgr()
    {
		ReleaseSemaphore(m_sem,1,NULL);
    }
private:    
    HANDLE  m_sem;
};

#else
#include<semaphore.h>
class SemMgr
{
public:    
    Semgr(sem_t seg)
    {
        m_sem = seg;
        sem_wait(&m_sem);
    }
    ~SegMgr()
    {
        sem_post(&m_sem);
    }
private:    
    sem_t m_sem;
};

#endif
#endif
