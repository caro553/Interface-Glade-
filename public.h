/*#########################Structs############################*/

/*---View---*/

/*la structure suivante represente les elements (widgets) de la page main (page principale)*/
typedef struct {
  GtkWidget *window;
  GtkWidget *mainBox;
  GtkWidget *header;
  GtkWidget *headerBox;
  GtkWidget *buttonAdd;
  GtkWidget *buttonAbout;
  GtkWidget *search;
  GtkWidget *fixed;
  GtkWidget *view;
  GtkWidget *viewBox;
} MainView;

typedef struct {
  GtkWidget *addDialog;
  GtkWidget *boxAddDialog;
  GtkWidget *buttonBoxAddDialog;
  GtkWidget *agreeAddDialog;
  GtkWidget *cancelAddDialog;
  GtkWidget *gridAddDialog;
  GtkWidget *firstNameLabel;
  GtkWidget *lastNameLabel;
  GtkWidget *adressLabel;
  GtkWidget *zipCodeLabel;
  GtkWidget *typeLabel;
  GtkWidget *emailLabel;
  GtkWidget *numberLabel;
  GtkWidget *firstNameEntry;
  GtkWidget *lastNameEntry;
  GtkWidget *adressEntry;
  GtkWidget *zipCodeEntry;
  GtkWidget *typeEntry;
  GtkWidget *emailEntry;
  GtkWidget *numberEntry;  
} FormView;

typedef struct { 
  GtkWidget *aboutDialog;
  GtkWidget *boxAboutDialog;
  GtkWidget *buttonBoxAboutDialog;
} AboutView;

 
/*---Modele---*/

/*la structure suivante represente le corps (les donnees) d'un contacte pour que le modele puisse l'utiliser au moment de l'ajout ou la modification d'un contacte*/
typedef struct {
  gchar *firstNameValue[50];
  gchar *lastNameValue[50];
  gchar *adressValue[200];
  gchar *zipCodeValue[50];
  gchar *typeValue[15];
  gchar *emailValue[30];
  gchar *numberValue[100];
} ContactValues;



/*---Controller---*/
