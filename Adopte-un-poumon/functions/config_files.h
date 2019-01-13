typedef char* string;


typedef struct config config;
struct config
{
    int width;
    int height;
    string nouveauPatient;
    string nouveauPoumon;
    string pathImage;
};

void changes_files(GtkWidget *, config *);
void addConfigStruct(config *, int, int, string, string, string);

