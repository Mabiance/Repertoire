#include <stdio.h>
#include <stdlib.h> // ????????????????????

int show_repo(FILE *fp) // ??????????????????
{
	int i, id = 0;
	char nom[100], prenom[100], mail[100], num[100];

	for (i=0; i<5; i=i+1) 
	{
		fscanf(fp, "%d  %s %s  %s  %s", &id, &nom, &prenom, &mail, &num);
		printf("%d  %s  %s  %s  %s\n", id, nom, prenom, mail, num);
	}
	return (0);
}

int add_user(FILE *fp)
{
	int id = 0;
    char nom[100], prenom[100], mail[100], num[100];

	printf("id: ");
	scanf("%d", &id);
	printf("nom: ");
	scanf("%s", &nom);
	printf("prenom: ");
	scanf("%s", &prenom);
	printf("@: ");
	scanf("%s", &mail);
	printf("numero: ");
	scanf("%s", &num);
	fprintf(fp, "\n%d", id);
	fprintf(fp, " ");
	fprintf(fp, "%s", nom);
	fprintf(fp, " ");
	fprintf(fp, "%s", prenom);
	fprintf(fp, " ");
	fprintf(fp, "%s", mail);
	fprintf(fp, " ");
	fprintf(fp, "%s", num);
	return (0);
}

int delete_user(FILE *fp) // ???????????????????????
{
	int id = 0, choix = 0, i = 0;
	char del, nom[100], prenom[100], mail[100], num[100];

	printf("Veuillez saisir l'id de la personne à supprimer :\n");
	scanf("%d", &choix);
	while (i != -1) {
		i = fscanf(fp, "%d  %s  %s  %s  %s", &id, &nom, &prenom, &mail, &num);
		printf("%d\n", id, choix-1);
		if (id == choix-1) {
			del = fgetc(fp);
			printf("%c\n", del);
			while (del != '\n') {
				fputc('\0', fp);
				del = fgetc(fp);
			}
			return (0);
		}
	}
	return (0);
}

int show_user(FILE *fp)
{
	int id = 0, choix = 0, i = 0;
	char nom[100], prenom[100], mail[100], num[100];

	printf("Veuillez saisir l'id de la personne :\n");
	scanf("%d", &choix);
	while (i != -1) {
		i = fscanf(fp, "%d  %s  %s  %s  %s", &id, &nom, &prenom, &mail, &num); // ???????????? (i =
		if (choix == id) {
			printf("%d  %s  %s  %s  %s\n", id, nom, prenom, mail, num);
			break;
		}
	}
	return (0);
}

int main(void)
{
	FILE *fp;
	int choix = 0;

	system("color df");
	printf("\t\t\t\tMENU\n\n");
	printf("\t\t1) Visualiser le repertoire\n\n");
	printf("\t\t2) Ajouter un contact au repertoire\n\n");
	printf("\t\t3) Supprimer tout le contenu du repertoire\n\n");
	printf("\t\t4) Afficher un contact\n\n");
	printf("\t\t5) Supprimer un contact\n\n");
	printf("Votre choix : ");
	scanf("%d", &choix);
	while (choix < 1 || choix > 5) {
		printf("Erreur : veuillez choisir un nombre entre 1 et 5\n");
		printf("Votre choix : ");
		scanf("%d", &choix);
	}
	switch (choix) {
	case 1:
		fp = fopen("monrepertoire.txt", "r");
		show_repo(fp);
		fclose(fp);
		break;
	case 2:
		fp = fopen("monrepertoire.txt", "a+");
		add_user(fp);
		fclose(fp);
		break;
	case 3:
		fp = fopen("monrepertoire.txt", "w+");
		fclose(fp);
		break;
	case 4:
		fp = fopen("monrepertoire.txt", "r");
		show_user(fp);
		fclose(fp);
		break;
	case 5:
		fp = fopen("monrepertoire.txt", "a+");
//		delete_user(fp); pas fini pour l'instant j'y reflechis
		break;
	}
	return (0);
}
