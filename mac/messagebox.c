#include "messagebox.h"
#include <gtk/gtk.h>

static void activate(GtkApplication *app, gpointer user_data);

int show_message_box(const char *title, const char *message, MessageBoxType type) {
    GtkApplication *app;
    int status;

    app = gtk_application_new("org.example.messagebox", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    // Pass the title, message, and type to the application
    g_object_set_data(G_OBJECT(app), "title", (gpointer)title);
    g_object_set_data(G_OBJECT(app), "message", (gpointer)message);
    g_object_set_data(G_OBJECT(app), "type", GINT_TO_POINTER(type));

    status = g_application_run(G_APPLICATION(app), 0, NULL);
    g_object_unref(app);

    return status;
}

static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *dialog;
    GtkDialogFlags flags;
    const char *title;
    const char *message;
    MessageBoxType type;
    GtkMessageType gtk_type;
    GtkButtonsType buttons;

    title = g_object_get_data(G_OBJECT(app), "title");
    message = g_object_get_data(G_OBJECT(app), "message");
    type = GPOINTER_TO_INT(g_object_get_data(G_OBJECT(app), "type"));

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), title);

    flags = GTK_DIALOG_DESTROY_WITH_PARENT | GTK_DIALOG_MODAL;

    switch (type) {
        case MB_INFO:
            gtk_type = GTK_MESSAGE_INFO;
            buttons = GTK_BUTTONS_OK;
            break;
        case MB_WARNING:
            gtk_type = GTK_MESSAGE_WARNING;
            buttons = GTK_BUTTONS_OK;
            break;
        case MB_ERROR:
            gtk_type = GTK_MESSAGE_ERROR;
            buttons = GTK_BUTTONS_OK;
            break;
        case MB_QUESTION:
            gtk_type = GTK_MESSAGE_QUESTION;
            buttons = GTK_BUTTONS_YES_NO;
            break;
        default:
            gtk_type = GTK_MESSAGE_INFO;
            buttons = GTK_BUTTONS_OK;
    }

    dialog = gtk_message_dialog_new(GTK_WINDOW(window),
                                    flags,
                                    gtk_type,
                                    buttons,
                                    "%s", message);

    gtk_dialog_run(GTK_DIALOG(dialog));
    gtk_widget_destroy(dialog);
    gtk_widget_destroy(window);
}
