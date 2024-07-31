// This Code Is Only Useful In Windows, For Linux 
// Go to linux/messagebox.h

#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <windows.h>

// Message box types
#define MB_INFO     MB_OK | MB_ICONINFORMATION
#define MB_WARNING  MB_OK | MB_ICONWARNING
#define MB_ERROR    MB_OK | MB_ICONERROR
#define MB_QUESTION MB_YESNO | MB_ICONQUESTION

// Function prototypes
void showMessageBox(const char* title, const char* message, unsigned int type);
int showQuestionBox(const char* title, const char* message);

#endif // MESSAGEBOX_H
