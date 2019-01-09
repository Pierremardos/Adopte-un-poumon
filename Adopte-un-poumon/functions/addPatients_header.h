

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
    int  height;
    int weight;
    string bloodType;
    string HLA;
    string plasmapherese;
    int smoke;
};
// Prototype

void zerofgets(string str, int size);
void mysql(string request);
void addPatientStruct(string name, string surname, string birth, string dateInscription, int height, int weight, char bloodType[3], string HLA, string plasmapherese, int smoke);
