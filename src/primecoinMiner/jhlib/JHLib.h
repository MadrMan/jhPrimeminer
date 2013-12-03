

#ifndef __JHSYSTEMLIB
#define __JHSYSTEMLIB

#include<math.h>
#include<algorithm>
#ifdef _WIN32
#include<Windows.h>
#define TLSVARIABLE __declspec(thread)
#else
#include<pthread.h>
#include<cstdlib>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netinet/tcp.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/select.h>
#include<sys/time.h>
#include<stdio.h>
#include<errno.h>
#include<netdb.h>
#define RtlCopyMemory memcpy
#define RtlZeroMemory(X, Y) memset((X), 0, (Y))
#define __fastcall __attribute__((fastcall))
#define DWORD unsigned int
#define BOOL int
#define SOCKET int
#define TLSVARIABLE __thread
#define __debugbreak() {}
#define OutputDebugString(x) printf("%s", (x))
#define ExitProcess exit
#define _ADDRESSOF(v) (&reinterpret_cast<const char &>(v))
#define _strdup strdup
#define closesocket close
#define SOCKET_ERROR -1
#define SOCKADDR_IN sockaddr_in
#define SOCKADDR sockaddr
#define ADDR_ANY INADDR_ANY
#define _getch getch
#define BYTE unsigned char
#define HANDLE pthread_t
#define LPVOID void*
#define TerminateThread(h, x) pthread_cancel(x)
#define CloseHandle(x) {}
#define ULONGLONG unsigned long long
typedef void* (*LPTHREAD_START_ROUTINE)(void* lpThreadParameter);
inline HANDLE CreateThread(LPVOID, size_t stackSize, LPTHREAD_START_ROUTINE a3, LPVOID params, DWORD dwFlags, DWORD* pdwThreadID)
{
	HANDLE threadId;
	pthread_create(&threadId, nullptr, a3, params);
	return threadId;
}

inline void Sleep(int x) 
{
	struct timespec ts = {0 / 1000, (x * 1000000) % 1000000000};
	nanosleep(&ts, nullptr);
}
inline ULONGLONG GetTickCount64()
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC_RAW, &ts);
	return ts.tv_sec * 1000 + ts.tv_nsec / 1000000;
}
inline DWORD GetTickCount()
{
	return (DWORD)GetTickCount64();
}

#endif

using std::min;
using std::max;

typedef unsigned long long 	uint64;
typedef signed long long	sint64;

typedef unsigned int 	uint32;
typedef signed int 		sint32;

typedef unsigned short 	uint16;
typedef signed short 	sint16;

typedef unsigned char 	uint8;
typedef signed char 	sint8;


#define JHCALLBACK	__fastcall

void* _ex1_malloc(int size);
void* _ex1_realloc(void* old, int size);
void _ex1_free(void* p);

void _ex2_initialize();

void* _ex2_malloc(int size, char* file, sint32 line);
void* _ex2_realloc(void* old, int size, char* file, sint32 line);
void _ex2_free(void* p, char* file, sint32 line);
void _ex2_analyzeMemoryLog();

// memory validator
//#define malloc(x) _ex1_malloc(x)
//#define realloc(x,y) _ex1_realloc(x,y)
//#define free(x) _ex1_free(x)

// memory logger
//#define MEMORY_LOGGER_ACTIVE			1
//#define MEMORY_LOGGER_ANALYZE_ACTIVE	1

#ifdef MEMORY_LOGGER_ACTIVE
#define malloc(x) _ex2_malloc(x,__FILE__,__LINE__)
#define realloc(x,y) _ex2_realloc(x,y,__FILE__,__LINE__)
#define free(x) _ex2_free(x,__FILE__,__LINE__)
#endif

#include"./streamWrapper.h"
#include"./fastString.h"
#include"./hashTable.h"
#include"./fastSorter.h"
#include"./fileMgr.h"
#include"./sData.h"
#include"./bmp.h"
#include"./tgaLib.h"
#include"./fMath.h"
#include"./packetBuffer.h"
#include"./msgQueue.h"
#include"./simpleList.h"
#include"./customBuffer.h"
#include"./critSec.h"

/* error */
#define assertFatal(condition, message, errorCode) if( condition ) { OutputDebugString(message);  ExitProcess(errorCode); } 


#endif
