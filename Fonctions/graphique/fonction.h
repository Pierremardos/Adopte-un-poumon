#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED
void delete_main_window(int,char **,GtkWidget *);
void second_window(int,char **,GtkWidget *);
void second_window(int, char **,GtkWidget *);
void launch_program(GtkWidget *,GtkWidget *, gint);
int Hla(char);
char * convert_text (gchar *);
void creation_label (GtkWidget *,GtkWidget*,gchar*,gchar *, GtkWidget *);
void firstWindow (GtkWidget *,int , char **,GtkWidget*,gchar*,gchar *);
void connexion(GtkWidget *,GtkWidget *);
void button_connexion(GtkWidget *,GtkWidget *,gint,GtkWidget *,GtkWidget *);
void validate_connexion();





#endif // LIBRARY_H_INCLUDED
