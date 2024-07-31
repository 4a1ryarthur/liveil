#include "messagebox.h"

int main() {
    // Initialize GTK
    gtk_init(NULL, NULL);

    // Show different types of message boxes
    show_message_box("Information", "This is an information message.", MB_INFO);
    show_message_box("Warning", "This is a warning message.", MB_WARNING);
    show_message_box("Error", "This is an error message.", MB_ERROR);
    show_message_box("Question", "Do you want to continue?", MB_QUESTION);

    return 0;
}
