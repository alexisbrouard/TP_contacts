
![Logo](https://cdn-images-1.medium.com/fit/t/1600/480/1*qtAvxb9Oz-9d3IIs_W1tcQ.png)


# TP Développement Logiciel avancé

Ce projet en développement logiciel avancé a pour but de proposer une application
permettant l'exportation d'une base de données en différents fichiers csv ou encore
la modification de cette même base ainsi que la suppression de données par critère.


## Créateurs

- [@alexisbrouard](https://github.com/alexisbrouard)
- [@CameronBGassedat](https://github.com/CameronBGassedat)




## Fonctionnalités implémentés

- Suppression de lignes selon les valeurs entrées
- Modification de lignes selon les valeurs entrés
- Exportation de données selon le bouton radio coché
- Affichage de statistiques globales
- Affichage de statistiques détaillées


## Comment utiliser l'application ?

### Suppresion de lignes selon les valeurs entrées

Il suffit de rentrer dans les champs les conditions de suppression comme :
"Facebook" dans le champ "Compagnie" et toutes les données associés à l'entreprise
seront supprimées.

### Modification de lignes selon les valeurs entrées

Il suffit de rentrer le nom d'une entreprise et de cliquer sur "MODIFIER" pour voir les entreprises de tous les utilisateurs modifiés.
Par la suite, des changements seront faits concernant l'UI ainsi que le code afin de modifier précisément une donnée dans un champ.

### Exportation des données selon le bouton radio coché

Il suffit de cocher un bouton radio et toutes les données associés à la catégorie
sélectionnée seront exportées sous forme de CSV générés par informations différentes
dans la catégorie. Par exemple, la catégorie "Entreprise" génerera un fichier CSV
pour chaque entreprise différente ainsi les personnes seront triés en étant lié à celle-ci.

### Affichage des statistiques globales

Il faut cliquer sur le bouton "AFFICHER STATS GLOBALES" qui compte le nombre de lignes
totales dans la base de données.

### Affichage des statistiques détaillées

Il faut cliquer sur le bouton "Afficher stats" de la catégorie que l'on souhaite et
le logiciel comptera le nombre d'informtations différentes dans la catégorie. Par
exemple, la catégorie "Entreprise" compte 15 entreprises, et affichera donc 15.

## Insérer des fichiers CSV en base de données

Si la base de données est vierge ou n'existe pas, le programme lancera automatiquement la création et l'insertion des fichiers en base, il faut donc :
- Que les fichiers csv se trouvent dans le répertoire : \AppData\Roaming\GUI-contacts
- Que les données soient au même format et comportent les mêmes champs

## Exportation de la base vers des fichiers CSV

Lors de l'exportation des fichiers, vous pourrez les retrouver ici :
- Build.../GUI-Contacts/
- Les fichiers sont triés avec : category-valeur.csv
