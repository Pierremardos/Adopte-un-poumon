

//Typedef

typedef char* string;
typedef struct lung lung;
//Structures

// Prototype

double cptT(int height,int sex);
double ratioCptT(int height,int sex, double cptDonator);
double ratioCptR(double cptDonator, double cptPatient);
int validation(double ratioCpt);
double result_cpt(lung*);
