
//Typedef

typedef char* string;

typedef struct lung lung;
//Structures
struct lung
{
    string last_name;
    string first_name;
    string sex;
    string old;
    string blood_type;
    string height;
    string weight;
    string hla;
    string plasmapherese;
    string smoke;
    string enter_bloc;
    string clamping;
    string notes;

};
// Prototype

void addLungsWindow(int, char **,GtkWidget *);
void formLungs(GtkWidget *,GtkWidget *);
void button_addLungs(GtkWidget *, GtkWidget *, GtkWidget *, GtkWidget *, GtkWidget *, GtkWidget *, GtkWidget *,GtkWidget *, GtkWidget *, GtkWidget *, GtkWidget *, GtkWidget *,GtkWidget *,GtkWidget *,GtkWidget *);
void addLungsStruct(lung *,string,string,string, string,string, string, string, string, string, string,string,string,string);





