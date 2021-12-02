
/*#########################Declarations############################*/

/*EntryPoint*/

void startApplication();

/*View*/

void displayMain(gchar *fileName);
void displayForm(gchar *fileName);
void displayAbout(gchar *fileName);
void hideWidget(GtkWidget *widget);

/*Model*/

void createValues(GtkEntry *firstName, GtkEntry *lastName, GtkEntry *adress, GtkEntry *zipCode, GtkEntry *type, GtkEntry *email, GtkEntry *number);
void createContact(GKeyFile *keyfile, gchar *firstName, gchar *lastName, gchar *adress, gchar *zipCode, gchar *type, gchar *email, gchar *number);
void saveList(GKeyFile *key, gchar *fileName);
void removeContact(GKeyFile *keyfile, gchar *contact);

/*Controller*/

void getAddForm(GtkButton *button);
void getAbout(GtkButton *button);
void addThisOne(GtkButton *button);
void removeThisOne();
void saveCurrentList();
void hideAbout();
void cancelAddForm(GtkButton *button);

