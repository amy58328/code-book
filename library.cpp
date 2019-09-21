library

#include<bits/stdc++.h>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include <algorithm>


compile.bat 內容 (input.in output.out)
	@echo off

	cls
	echo compiling
	g++ %1.cpp -o %1.exe -DDEBUG

	echo finish
	if %ERRORLEVEL% EQU 0 (
		%1.exe
	)

檔案裏面打
	#ifdef DEBUG
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	#endif

memset(Tree,0,sizeof(Tree)); //陣列set為0,(陣列名稱，值，陣列長度)
abs()// 絕對值