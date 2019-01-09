

//Typedef

typedef char* string;

typedef struct patient patient;
//Structures
struct patient
{
    string name;
    string surname;
    string birth;
    string dateInscription;
    string height;
    string weight;
    string bloodType;
    string HLA;
    string plasmapherese;
    string smoke;
};
// Prototype

void mysql(string);
void addPatientStruct(string, string, string, string, string, string, string, string, string, string);
void addPatientStructWindow(int,char **,GtkWidget *);
string query();
