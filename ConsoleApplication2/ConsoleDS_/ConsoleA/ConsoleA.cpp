 //ConsoleApplication3.cpp : Defines the entry point for the console application.


#include "stdafx.h"
#include <string.h>
#include <Windows.h>

#include <mmdeviceapi.h>
#include <endpointvolume.h>

bool ChangeVolume(int nVolume)
{
	CoInitialize(NULL);

	IMMDeviceEnumerator *deviceEnumerator;
	HRESULT hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER,
		__uuidof(IMMDeviceEnumerator), (LPVOID *)&deviceEnumerator);
	IMMDevice *defaultDevice;

	hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
	deviceEnumerator->Release();

	IAudioEndpointVolume *endpointVolume;
	hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume),
		CLSCTX_INPROC_SERVER, NULL, (LPVOID *)&endpointVolume);
	defaultDevice->Release();

	hr = endpointVolume->SetMasterVolumeLevelScalar(nVolume / 100.0f, NULL);

	endpointVolume->Release();
	CoUninitialize();

	return FALSE;
}


class Call
{
public:
	Call();
	Call(const Call &);
	Call& operator = (const Call&) = delete;
	~Call();

private:
	//

};

Call::Call()
{
	//
	printf("Call is Constrator\n");
}

Call::Call(const Call &)
{
	printf("Copy is Call\n");
}

Call::~Call()
{
}


class MyClass:public Call
{
public:
	MyClass(int m, int n, Call * const c) :Number(m), Value(n) ,cl(c){}
	~MyClass();
	void show();
private:
	const int Number;
	int Value;
	Call * const cl;
};

void MyClass::show()
{
	//Value = 19;
	printf("N_%d_V_%d\n", Number, Value);
}

MyClass::~MyClass()
{
}


#include<stdio.h>
#include <stdlib.h>

//typedef int bool;

int compare(int x, int y)
{
	return x == y ? 1 : 0;
}

int value(int x, int(*compare)(int, int))
{
	//
	int number[10] = { 1,2,3,4,5,6,7,8,9,0 };

	//printf("%d", compare(number[4], number[5]));
	return compare(number[4], number[5]);
}

void test(int(*compare)(int x, int y))
{
	int(*fp)(int, int) = compare;
}

int add(int a, int b)
{
	return a+b;
}

typedef struct Node
{
	int Elem;
}Node, *LNList;


int value1(LNList *L)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->Elem = 100;

	*L = node;
	return 0;
}

int value2(LNList &L)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->Elem = 10;

	L = node;
	return 0;
}

int _(int *_, int *__)
{
	return *_;
}

int _tmain(int argc, _TCHAR* argv[])
{
	//Call cl;
	//MyClass ms(10, 100, &cl);
	//ms.show();

	//int p = 10;
	//int &number = p;
	//printf("%d__%d", &p, &number);
	//return 0;
	//printf("%d", compare(1, 1));
	//int *(compare)
	//value(1, compare);
	//int(*pfun)(int, int);
	//pfun = compare;
	//printf("%d\n",value(3, pfun));

	//LNList list = (LNList)malloc(sizeof(LNList));;
	//value1(&list);
	//value2(list);
	////HWND hwnd = GetCurrentObject();
	////SendMessage(hwnd, WM_APPCOMMAND, NULL, APPCOMMAND_VOLUME_UP);
	//GetCurrentVolue()
	ChangeVolume(40);
	
	return 0;
}
