typedef char* string;


typedef struct config config;
struct config
{
    string pathImage;
    int width;
    int height;
};

void changes_files(GtkWidget *, config *);
void addConfigStruct(config *, string ,int , int );

