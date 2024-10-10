#pragma once

#ifdef _WIN32

#define NOMINMAX 1
#include <windows.h>
#include <shellapi.h>
#include <mmsystem.h>
#include <direct.h>

#define strcasecmp _stricmp
#define strncasecmp _strnicmp
#define getcwd _getcwd
#define vsnprintf _vsnprintf
#define vswprintf _vsnwprintf

/*
void printf(const char* fmt, va_list argPtr)
{
	char aStr[256];
	sprintf(aStr, fmt, argPtr);
	OutputDebugStringA(aStr);
}
*/

#define ThreadIdf DWORD

#else

#include <wctype.h>
#include <string.h>
#include <stdint.h>
#define _stricmp strcasecmp
#define _cdecl
typedef uint8_t BYTE;
typedef uint16_t WORD;
typedef uint32_t DWORD;
typedef uint64_t QWORD;
typedef uint32_t UINT;
typedef int64_t __int64;
typedef int INT;
typedef long LONG;
typedef unsigned long ULONG;
typedef LONG WINBOOL;
typedef void* HANDLE;
typedef WORD* LPWORD;
typedef DWORD* LPDWORD;
typedef char CHAR;
typedef CHAR* LPSTR;
typedef const CHAR* LPCSTR;
typedef wchar_t WCHAR;
typedef WCHAR TCHAR;
typedef WCHAR* LPWSTR;
typedef TCHAR* LPTSTR;
typedef const WCHAR* LPCWSTR;
typedef const TCHAR* LPCTSTR;
typedef HANDLE* LPHANDLE;
typedef HANDLE HWND;

#define ThreadIdf void*

typedef struct tagRECT {
	LONG left;
	LONG top;
	LONG right;
	LONG bottom;
} RECT, * PRECT, * NPRECT, * LPRECT;

typedef struct _GUID {
	unsigned long  Data1;
	unsigned short Data2;
	unsigned short Data3;
	unsigned char  Data4[8];
} GUID;

void* GetCurrentThreadId()
{
	return (void*)pthread_self();
}

#define GetTickCount SDL_GetTicks
#define LPCRITICAL_SECTION pthread_mutex_t*
#define CRITICAL_SECTION CRITICAL_SECTION

#define EnterCriticalSection pthread_mutex_trylock
#define LeaveCriticalSection pthread_mutex_unlock

#define InitializeCriticalSection(x) pthread_mutex_init(x, 0)
#define DeleteCriticalSection pthread_mutex_destroy

#endif