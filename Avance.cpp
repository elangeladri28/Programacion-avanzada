#include<Windows.h>
#include<iostream>
#include "resource.h"
using namespace std;

HINSTANCE hInstanceGlobal;
BOOL CALLBACK VentanaPrincipal(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK VentanaDeMenu(HWND, UINT, WPARAM, LPARAM);
int showMSG;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR cmdLine, int showCmd){

	hInstanceGlobal = hInstance;
	showMSG = showCmd;
	HWND hWnd;
	hWnd = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, VentanaPrincipal);
	if (!hWnd) {
		MessageBox(NULL, "No se pudo crear la ventana", "Error", MB_ICONERROR);
		return 1;
	}
	ShowWindow(hWnd, showCmd);
	UpdateWindow(hWnd);
	MSG message;
	ZeroMemory(&message, sizeof(MSG));
	while (GetMessage(&message, 0, 0, 0)) {
		TranslateMessage(&message);
		DispatchMessage(&message);
	}
	return(int)message.wParam;

}

//Los BOOL CALLBACK son las funciones que llevaran tus ventanas creadas con el cuadro de herramietas
//y lleva BOOL CALLBACK, un nombre y los siguientes parametros HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam

BOOL CALLBACK VentanaPrincipal(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam){

	switch (message){

	case WM_INITDIALOG:
	{
		MessageBox(NULL, "Ventana que aparece para perder el tiempo", "LOL", NULL);
		break;
	}
	case WM_COMMAND:{

	
		switch (LOWORD(wParam)){

		case IDC_BOTONSALIR:{
			DestroyWindow(hWnd);
			return TRUE;
			break;
			}
		case IDC_BOTONINICIAR: {
			HWND hWnd;
			hWnd = CreateDialog(hInstanceGlobal, MAKEINTRESOURCE(IDD_DIALOG4), NULL, VentanaDeMenu);
			ShowWindow(hWnd, showMSG);
			UpdateWindow(hWnd);
			break;
			}
		}
	
		break;
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		break; 
	}
	
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);

	}
	return 0;
	}
}

BOOL CALLBACK VentanaDeMenu(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {

	switch (message) {

	case WM_INITDIALOG:
	{
	}
	break;
	case WM_COMMAND: {

		switch (LOWORD(wParam)) {
			
		}
			break;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		break;

	case WM_DESTROY:{
		PostQuitMessage(0);
		return TRUE;
		break;
		}
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);

		}
		
	}
	return 0;
}
