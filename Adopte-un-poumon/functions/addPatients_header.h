

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

void zerofgets(string str, int size);
void mysql(string request);
void addPatientStruct(string name, string surname, string birth, string dateInscription, string height, string weight, string bloodType, string HLA, string plasmapherese, string smoke);
