Projet interface graphique "application pour la gestion des contacts"

CA contacts est une application utile pour gérer les contacts. vous pouvez ajouter de nouveaux contacts qui peuvent contenir différentes informations, vous pouvez également regarder, modifier ou supprimer vos contacts et tout cela avec une manipulation facile

CA contacts : juste un nom qui veut dire (C -> Contacts, A -> Aymen).

Conditions prealables
Glib   version : 2.58.3
Gtk    version : 3.24.5

Pour installer Glib executer la commande  suivante :
  apt-get install libgtk2.0-dev

Pour installer Gtk executer la commande  suivante :
  apt-get install libgtk-3-dev

Testes:

Pour la partie teste je joint un make file dans mon compte rendu donc il suffit d'exucuter la commande : "make main" pour compiler ensuite "./main" pour demarer l'application.

Repartition du projet :

pour la repartiotion de mon projet j'ai utiliser un design pattern MVC "model-view-controller". 

1 -  pour la partie view j'ai construit les fonctions generiques "generique seulment pour les parametres" suivantes qui s'occupent seulment de l'affichages et en se basant sur des fichiers glade :

//displayMain : s'occupp de l'affichage principale "main layout". et utilise un objet GkeyFile pour stocker les contacts au moment de l'affichage. apres avoir charger ces contacts a partir d'un fichier texte. 

//displayForm : s'occupe de l'affichage du formulaire qui est sous forme de boite de dialog et qui permet d'ajouter un contacte. 

//displayAbout : s'occupe d'afficher la boite de dialog qui contient des informations sur l'application.

//hideWidget : s'occupe de cacher un widget.

- pour chaque partie de l'affichiage j'ai utiliser une structure approprier.

2 - la partie model qui est le corps de l'applications j'ai choisi le GKeyFile pour pouvoir stocker les contacts pendent l'implementations de l'application en le chargant depuis un fichiers existant afin de les remettre dans le fichiers initiale a la fermeture de l'application avec les modifications si il y a eu quelque unes. pour cela j'ai construit les fonctions generiques "seulment en parametres" suivantes :

//createValues : cette fonction permet de recuperer le texte insere dans les entry et stock dans des variables de type gchar.

//ceateContact : cette fonction prend en parametre les renseignements du contacte et un objet GKeyFile vide afin de construire cette objet en lui affectant les coordonnees du contacte.

//removeContact : cette fonction permet de supprimer un contact du GKeyFile principale.
saveAddedContacts : cette fonction enregiste le contact dans le fichier principale donc elle permet de confirmer l'ajout du contacte dans la liste.

//saveList : cette fonction permet d'enregistrer un objet Gkeyfile dans un fichier texte elle etait prevu pour un bouttonn intituler de save et qui se trouve dans la page principale 

3 - le controller qui fait le lien entre les deux partie precedente et l'utilisateur. ou d'une autre facon le controlleur prend les demandes de l'utilisateur par example "boutton" ensuite selon cette demande il l'a transmit soit a la pertie view ou la partie modele pour que cette derniere execute cette demande et rend le resultat au controller qui a son tour rend le resultat a l'utilisateur. 

concernant les fonctions utilise dans cette partie j'ai construit des fonctions qui contientes des appeles des fonctions des deux partie precedente "viex" et "modele". 

## Partie manquante ##
-- dans la partie view --
- une boita de dialogue qui contient les donnees d'un contacte et qui contient aussi deux bouttons "delete" pour suprimer ce contacte et "edit" pour pouvoir modifier les donnees de ce contact.

- le boutton save pour sauvegarder la liste courante des contactes au cas ou il y a des modification.

--dans la partie modele--

- la fonction qui permet de modifier un objet GKeyFile.

- la fonction qui s'occupe de la recherche d'un contacte.

--dans la partie controller--

- la fonction qui rend le boutton intituler du contacte cliquable pour afficher ces donnees.

- la fonction qui rend le boutton "delete" (prevu) cliquable pour supprimer le contacte.

- la fonction qui rend le boutton "edit" (prevu) cliquable pour modifier le contacte.

- la fonction appeler dans la call-back "destroy" du window qui demande a l'utilisateur de quitter directement ou sauvegarder avant de quitter les moddification si il se trouve. 

- la fonction qui fait le lien pour rechercher un contact.
