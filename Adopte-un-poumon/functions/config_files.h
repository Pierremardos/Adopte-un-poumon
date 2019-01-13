typedef char* string;


typedef struct config config;
struct config
{
    int width;
    int height;
    string nouveauPatient;
    string nouveauPoumon;
    string pathImage;
    string pathImage2;
};

void changes_files(GtkWidget *, config *);
void addConfigStruct(config *, int, int, string, string, string, string);

