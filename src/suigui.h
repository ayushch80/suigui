#ifndef SUIGUI_H
#define SUIGUI_H

#include <windows.h>
#include <stdbool.h>

void generateWindow(const char* windowName, int windowWidth, int windowHeight, bool resizable);
void addText(HWND hWnd, const char* text);

#endif /* SUIGUI_H */
