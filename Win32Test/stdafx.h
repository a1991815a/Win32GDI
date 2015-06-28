#ifndef __STDAFX__
#define __STDAFX__
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <map>
#include <vector>
#include <tchar.h>
using namespace std;

#define WM_PAINT_START (WM_USER + 1)
#define WM_PAINT_END (WM_USER + 2)

#define SAFE_DELETE_OBJ(A) do{ if(A) DeleteObject(A); A = NULL;} while(0)

#endif