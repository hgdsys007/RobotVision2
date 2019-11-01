/*! \file ZCVCORE_TIME.h
\brief ZCVCORE_TIME.h document.
*/

/**********************************************************************************************
-----------------------------------------------------------------------------------------------
Name :                  ZCVCORE_Time.h
Description :           Framework
Revision :              V1.0
Module :                ZIVS
System :                ZIVS
Language :              ANSI C
Develop Environment :   MSVC, CODEBLOCKS
Running Environment :   Windows, Linux
------------------------------------------------------------------------------------------------
Creation Data :         <01-01-2013  17:00>
Chief Editor :          <Zeng Jianping>
Participant :           <������>
Audit :                 <�����>
Edit Log :              <�༭��¼>
Release :               <01-01-2013>
------------------------------------------------------------------------------------------------
Copyright (C) 2013, ZIVS Corporation, All Rights Reserved.
------------------------------------------------------------------------------------------------
***********************************************************************************************/


#ifndef _ZCVCORE_TIME_H_
#define _ZCVCORE_TIME_H_

#include "ZCVCORE_Common.h"


//! \defgroup group_zcv_time ʱ��ͳ��
//! \ingroup group_zcv
//!  ʱ��ͳ�����������뺯��
//! \{
//! \}


//! \ingroup group_zcv_time
//! \{

//! \brief ʱ��ͳ�ƴ�ӡ�ꡣ
//! \param func           ����ʱ��ͳ�Ƶĺ�������
//! \param _name          ��ӡʱ������ʾ������
#if defined __GNUC__

#define ZCV_TIME_IN( func, _name )                                          \
    {                                                                       \
	struct timeval start, end;                                              \
    double time_s, time_e, time_u;										    \
	gettimeofday( &start, NULL );                                           \
	func;                                                                   \
	gettimeofday( &end, NULL );												\
    time_s = 1000000.0*start.tv_sec + start.tv_usec;                        \
    time_e = 1000000.0*end.tv_sec + end.tv_usec;                            \
    time_u = time_e - time_s;                                               \
	printf( "%s time %f ms \n", _name, time_u/1000 );                       \
    }

#else

#define ZCV_TIME_IN( func, _name )                                          \
    {                                                                       \
	LARGE_INTEGER start, end, freq;                                         \
    double time_s, time_e, time_f, time_u;									\
	QueryPerformanceCounter( &start );                                      \
	func;                                                                   \
	QueryPerformanceCounter( &end );										\
	QueryPerformanceFrequency( &freq );                                     \
    time_s = start.QuadPart ;                                               \
    time_e = end.QuadPart ;                                                 \
    time_f = freq.QuadPart;                                                 \
    time_u = (time_e-time_s)/time_f;                                        \
	printf( "%s time %f ms \n", _name, time_u*1000 );                       \
    }

#endif

//! \brief ����ʱ���������ݵ�ʵʱ��ӡģʽ��
//! \param flag           �Ƿ��ӡ������̨
//! 	                  - 0: ����ӡ
//! 	                  - 1: ��ӡ
ZCVAPI void TimeStatSetPrint( int flag );

//! \brief ����ʱ���������ݵļ�¼ͳ��ģʽ��
//! \param flag           �Ƿ���¼����ݽ��м�¼��ͳ��
//! 	                  - 0: ����¼��ͳ��
//! 	                  - 1: ��¼��ͳ��
ZCVAPI void TimeStatSetStatis( int flag );

//! \brief ���ʱ�����ĵļ�¼��ͳ�����ݡ�
ZCVAPI void TimeStatClearStatis();

//! \brief ����ʱ�����ĵļ�¼���ݽ���ͳ�Ƽ��㡣
ZCVAPI void TimeStatCalculate();

//! \brief ��ʱ���������ݵ�ͳ�ƽ����ӡ���ļ����߿���̨��
//! \param filnam         ����ļ�·����Ч���ӡ���ļ��������ӡ������̨
ZCVAPI void TimeStatPrintStatis( char *filnam );

//! \brief ʱ�����ļ�¼�Ŀ�ʼ��ʱ������
//! \return double        ��ʱ��ʼ����ʼʱ��
ZCVAPI double TimeStatTimeBegin();

//! \brief ʱ�����ļ�¼��ֹͣ��ʱ������
//! \param uname          ����Ƭ�λ��ߺ��������Ʊ�ʶ
//! \param time_s         ��ʱ��ʼ����ʼʱ�䣬�ɺ�����TimeStatTimeBegin������
ZCVAPI void TimeStatTimeEnd( char *uname, double time_s );

//! \}


#ifdef __cplusplus
extern "C"
{
#endif


///////////////////////////////////////////////////////////////////////////////////////////////////
// ʱ�������������

typedef struct
{
	uint32_t time;
	uint32_t date;
} ZSYSTIME;

// time from 1-1-1970
typedef struct
{
	uint32_t sec;	// ��
	uint32_t msec;	// ����
} TIMEF1970;

// ʱ�������������
///////////////////////////////////////////////////////////////////////////////////////////////////


#ifdef __cplusplus
}
#endif


#endif

