/*this project is realised by Tacherifte Aymen Chafik L2A*/

/*first we include the essential libs and header files*/

#include <gtk/gtk.h>
#include <glib.h>
#include <glib/gprintf.h>
#include "main.h"
#include "public.h"


/*#########################View############################*/

/*la partie suivante s'occupe uniquement de la presentation des differents parties d'affichage*/

/*concernant le builder j'ai choisi de le laisser hors de la structure pour etre plus generique (au cas ou on voudrait changer de main page on gardera toujours le meme builder)*/

GtkBuilder *builderMain;

/*##concernant les instances des structures de tout le code j'ai choisi de les laisser en public pour pouvoir leur acceder a partir de plusiers fonctions*/

/*ceci est une instance de la structure Mainview qui regroupe les elements de la page principale*/

MainView Contacts;

/*le keyfile suivant represente les contacts deja existant dans le fichiers qui contient ses derniers*/

GKeyFile *existingContacts;

/*la fonctions suivante s'occupe de la construction de la page main et de son  affichage a partir d'un fichier glade*/

void displayMain(gchar *fileName){
    
  builderMain = gtk_builder_new_from_file(fileName);
  Contacts.window = GTK_WIDGET( gtk_builder_get_object(builderMain,"window"));
  Contacts.mainBox = GTK_WIDGET( gtk_builder_get_object(builderMain,"mainBox"));
  Contacts.header = GTK_WIDGET( gtk_builder_get_object(builderMain,"header"));
  Contacts.headerBox = GTK_WIDGET( gtk_builder_get_object(builderMain,"headerBox"));
  Contacts.buttonAdd = GTK_WIDGET( gtk_builder_get_object(builderMain,"buttonAdd"));
  Contacts.buttonAbout = GTK_WIDGET( gtk_builder_get_object(builderMain,"buttonAbout"));
  Contacts.search = GTK_WIDGET( gtk_builder_get_object(builderMain,"search"));
  Contacts.fixed = GTK_WIDGET( gtk_builder_get_object(builderMain,"fixed"));
  Contacts.view = GTK_WIDGET( gtk_builder_get_object(builderMain,"view"));
  Contacts.viewBox = GTK_WIDGET( gtk_builder_get_object(builderMain,"viewBox"));
  /*dans la partie suivante on recupere les contacts du fichier ensuite on utilise le nom de chaque contacte comme des labels pour des bouttons que je cree pour le afficher dans le view et cela en passant par une boucle pour iterer sur les differents noms*/
  existingContacts = g_key_file_new();
  g_key_file_load_from_file(existingContacts, "chaf.txt", G_KEY_FILE_NONE, NULL);
  gsize *numGroups;
  gchar **groups;
  groups = g_key_file_get_groups(existingContacts, &numGroups);
  guint i;
  for (i = 0;i < numGroups;i++){
    GtkWidget *button[i];
    button[i] = gtk_button_new_with_label(groups[i]);
    gtk_box_pack_end(Contacts.viewBox, button[i], FALSE, FALSE, 2);
    gtk_widget_show(button[i]);
  } 
  gtk_builder_connect_signals(builderMain,NULL);
  gtk_widget_show(Contacts.window);
}

/*la partie suivante s'occupe de l'affichage du formilaire d'ajout d'un contacte*/

GtkBuilder *builderForm;

FormView AddForm;

void displayForm(gchar *fileName){

  builderForm = gtk_builder_new_from_file(fileName);
  AddForm.addDialog = GTK_WIDGET( gtk_builder_get_object(builderForm,"addDialog"));
  AddForm.boxAddDialog = GTK_WIDGET( gtk_builder_get_object(builderForm,"boxAddDialog"));
  AddForm.buttonBoxAddDialog = GTK_WIDGET( gtk_builder_get_object(builderForm,"buttonBoxAddDialog"));
  AddForm.agreeAddDialog = GTK_WIDGET( gtk_builder_get_object(builderForm,"agreeAddDialog"));
  AddForm.cancelAddDialog = GTK_WIDGET( gtk_builder_get_object(builderForm,"cancelAddDialog"));
  AddForm.gridAddDialog = GTK_WIDGET( gtk_builder_get_object(builderForm,"gridAddDialog"));
  AddForm.firstNameLabel = GTK_WIDGET( gtk_builder_get_object(builderForm,"firstNameLabel"));
  AddForm.lastNameLabel = GTK_WIDGET( gtk_builder_get_object(builderForm,"lastNameLabel"));
  AddForm.adressLabel = GTK_WIDGET( gtk_builder_get_object(builderForm,"adressLabel"));
  AddForm.zipCodeLabel = GTK_WIDGET( gtk_builder_get_object(builderForm,"zipCodeLabel"));
  AddForm.typeLabel = GTK_WIDGET( gtk_builder_get_object(builderForm,"typeLabel"));
  AddForm.emailLabel = GTK_WIDGET( gtk_builder_get_object(builderForm,"emailLabel"));
  AddForm.numberLabel = GTK_WIDGET( gtk_builder_get_object(builderForm,"numberLabel"));
  AddForm.firstNameEntry = GTK_WIDGET( gtk_builder_get_object(builderForm,"firstNameEntry"));
  AddForm.lastNameEntry = GTK_WIDGET( gtk_builder_get_object(builderForm,"lastNameEntry"));
  AddForm.adressEntry= GTK_WIDGET( gtk_builder_get_object(builderForm,"adressEntry"));
  AddForm.zipCodeEntry = GTK_WIDGET( gtk_builder_get_object(builderForm,"zipCodeEntry"));
  AddForm.typeEntry = GTK_WIDGET( gtk_builder_get_object(builderForm,"typeEntry"));
  AddForm.emailEntry = GTK_WIDGET( gtk_builder_get_object(builderForm,"emailEntry"));
  AddForm.numberEntry = GTK_WIDGET( gtk_builder_get_object(builderForm,"numberEntry"));
  gtk_builder_connect_signals(builderForm,NULL);
  gtk_widget_show(AddForm.addDialog);
}

/*la partie suivante s'occupe de l'affichege de la partie About*/

AboutView About;

GtkBuilder *builderAbout; 

void displayAbout(gchar *fileName){
  builderAbout= gtk_builder_new_from_file(fileName);
  About.aboutDialog = GTK_WIDGET( gtk_builder_get_object(builderAbout,"aboutDialog"));
  About.boxAboutDialog = GTK_WIDGET( gtk_builder_get_object(builderAbout,"boxAboutDialog"));
  About.buttonBoxAboutDialog = GTK_WIDGET( gtk_builder_get_object(builderAbout,"buttonBoxAboutDialog"));
  gtk_builder_connect_signals(builderAbout,NULL);
  gtk_widget_show(About.aboutDialog);
}

/*la fonction suivante permet de cacher un widget*/

void hideWidget(GtkWidget *widget){
  gtk_widget_hide(widget);
}


/*#########################Model############################*/

/*la partie suivante s'occupe uniquement de la manipulation des donnees de l'application */

/*ceci est une instance de ContactValues qui represente l'objet qui contien les donnees d'un contacte  */

ContactValues NewContact;

/*la fonction suivante utilise g_sprintf pour recuperer les champs des entry s et les stock dans des variables de typs gchar*/

void createValues(GtkEntry *firstName, GtkEntry *lastName, GtkEntry *adress, GtkEntry *zipCode, GtkEntry *type, GtkEntry *email, GtkEntry *number){

  g_sprintf(NewContact.firstNameValue,"%s", gtk_entry_get_text(firstName));
  g_sprintf(NewContact.lastNameValue,"%s", gtk_entry_get_text(lastName));
  g_sprintf(NewContact.adressValue,"%s", gtk_entry_get_text(adress));
  g_sprintf(NewContact.zipCodeValue,"%s", gtk_entry_get_text(zipCode));
  g_sprintf(NewContact.typeValue,"%s", gtk_entry_get_text(type));
  g_sprintf(NewContact.emailValue,"%s", gtk_entry_get_text(email));
  g_sprintf(NewContact.numberValue,"%s", gtk_entry_get_text(number));
}

/*la fonction suivante construit un objet GkeyFile pour contenir un contacte a partir de variables de type gchar qu'on lui passe en parametres*/

void createContact(GKeyFile *keyfile, gchar *firstName, gchar *lastName, gchar *adress, gchar *zipCode, gchar *type, gchar *email, gchar *number) {
  
  keyfile = g_key_file_new();
  gchar *values[7] = {firstName, lastName, adress, zipCode, type, email, number};
  gchar *keys[7] = {"firstName", "lastName", "adress", "zipCode", "type", "email", "number"};
  int i;
  for (i=0; i<7; ++i){
    g_key_file_set_value(keyfile, firstName, keys[i], values[i]);
  }
}

/*la fonction suivante permet de suprimer un contacte elle etait prevu pour etre executer quand l'utilisateur appuie sur le boutton delete*/

void removeContact(GKeyFile *keyfile, gchar *contact){
  g_key_file_remove_group (keyfile, contact, NULL);  
}

/*la fonction suivante permet de sauvegarder une liste de contacts elle etait prevu pour etre executer quand l'utilisateur appuie sur le boutton save*/

void saveList(GKeyFile *key, gchar *fileName){
  g_key_file_save_to_file(key, fileName, NULL);
}


/*#########################Controller############################*/

/*la fonction suivante lance l'applicatiion en passant par le View qui affiche la (window) principale */

void startApplication(){
  displayMain("main.glade");
}
 
/*cette fonction s'execute quand l'utilisateur appuie sur le boutton Add. elle passe par le View pour afficher le formulaire d'ajout*/

void getAddForm(GtkButton *button){ 
  displayForm("addform.glade");
}

/*cette fonction s'execute quand l'utilisateur appuie sur le boutton cancel du formulaire. elle passe par le View pour cacher la boite de dialog qui contient le furmulaire d'ajout */

void cancelAddForm(GtkButton *button){
  hideWidget(AddForm.addDialog);
}


/*cette fonction s'execute quand l'utilisateur appuie sur le boutton agree du formulaire. elle passe premierement par le model pour creer un objet contact ensuite elle passe par le View pour cacher la boite de dialog qui contient le furmulaire d'ajout a la fin de a creation du contact */

void addThisOne(GtkButton *button){
  createValues(AddForm.firstNameEntry, AddForm.lastNameEntry, AddForm.adressEntry, AddForm.zipCodeEntry, AddForm.typeEntry, AddForm.emailEntry, AddForm.numberEntry);
  createContact(existingContacts, NewContact.firstNameValue, NewContact.lastNameValue, NewContact.adressValue, NewContact.zipCodeValue, NewContact.typeValue, NewContact.emailValue, NewContact.numberValue);
  gtk_widget_destroy(AddForm.addDialog);
}

/*cette fonction s'execute quand l'utilisateur appuie sur le boutton About. elle passe par le View pour afficher la boite dialog qui contient des petits informations sur l'application avec un logo*/

void getAbout(GtkButton *button){
  displayAbout("About.glade");
}

/*la fonction suivante s'execute a l'appui sur le boutton close de la boite de dialog about et elle permet de cacher ce widjet*/
void hideAbout(){
  hideWidget(About.aboutDialog);
}

/*la fonction suivante permet de suiprimer un contacte en passant par le modele elle etait prevu pour le boutton delete de chaque contacte*/
void removeThisOne(){
  removeContact(existingContacts, "chafik");
}

/*la fonction suivante permet de sauvegarder une liste de contacts en passant par le modele. elle etait prevu pour etre executer quand l'utilisateur appuie sur le boutton save*/

void saveCurrentList(){
  saveList(existingContacts, "chaf.txt");
}



/*#########################Main############################*/

/*la fonction main permet d'initialiser gtk et lancer l'application en passant par le controller*/
int main(int argc, char *argv [])
    {
      gtk_init(&argc, &argv);
      startApplication();
      gtk_main();
      return 0;
    }





