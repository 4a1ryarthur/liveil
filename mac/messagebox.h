#ifndef MESSAGEBOX_H
#define MESSAGEBOX_H

#include <gtk/gtk.h>

// Message box types
typedef enum {
    MB_INFO,
    MB_WARNING,
    MB_ERROR,
    MB_QUESTION
} MessageBoxType;

// Function to display a message box
int show_message_box(const char *title, const char *message, MessageBoxType type);

#endif // MESSAGEBOX_H
