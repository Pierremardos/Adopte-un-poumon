#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED
void delete_main_window(int,char **,GtkWidget *);
void second_window(int,char **,GtkWidget *);
void second_window(int, char **,GtkWidget *);
void launch_program(GtkWidget *,GtkWidget *, gint);
int Hla(char);
char * convert_text (gchar *);
void creation_label (GtkWidget *,GtkWidget*,gchar*,gchar *, GtkWidget *);
//void firstWindow (GtkWidget *,int , char **,GtkWidget*,gchar*,gchar *);
void firstWindow (GtkWidget * MainWindow,int argc, char **argv,GtkWidget* mainLabel,gchar* convert_mainLabel,gchar * positionLabel);
void connexion(GtkWidget *,GtkWidget *);
void button_connexion(GtkWidget *,GtkWidget *,gint,GtkWidget *,GtkWidget *);
void validate_connexion(GtkWidget*,GtkWidget *,GtkWidget *,int ,char **);
void mysql();
void listUsers (char *,char *,GtkWidget *,GtkWidget *,int ,char **);
void main_program(int argc, char ** argv);
void display_error_message(GtkWidget * second_window,GtkWidget * main_box);
void toolbar_window(GtkWidget * window,GtkWidget * main_box);
void leave (gpointer , guint ,GtkWidget *);




#endif // LIBRARY_H_INCLUDED

