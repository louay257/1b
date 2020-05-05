#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
struct node
{
int data;
struct node *p_next;
struct node *p_prev;
};



typedef struct dlist
{
size_t length;
struct node *p_tail;
struct node *p_head;
} Dlist;
Dlist *list = NULL;




 Dlist *dlist_new(void)
{
Dlist *p_new = malloc(sizeof *p_new);
if (p_new != NULL)
{
p_new->length = 0;
p_new->p_head = NULL;
p_new->p_tail = NULL;
}
return p_new;
}




Dlist *dlist_append(Dlist *p_list, int data)
{
if (p_list != NULL) /* On vérifie si notre liste a été allouée */
{
struct node *p_new = malloc(sizeof *p_new); /* Création d'un
nouveau node */
if (p_new != NULL) /* On vérifie si le malloc n'a pas échoué */
{
p_new->data =gets(); /* On 'enregistre' notre donnée */
p_new->p_next = NULL; /* On fait pointer p_next vers NULL */
if (p_list->p_tail == NULL) /* Cas où notre liste est vide
(pointeur vers fin de liste à NULL) */
{p_new->p_prev = NULL; /* On fait pointer p_prev vers NULL
*/
p_list->p_head = p_new; /* On fait pointer la tête de liste
vers le nouvel élément */
p_list->p_tail = p_new; /* On fait pointer la fin de liste
vers le nouvel élément */
}
else /* Cas où des éléments sont déjà présents dans notre liste
*/
{
p_list->p_tail->p_next = p_new; /* On relie le dernier
élément de la liste vers notre nouvel élément (début du chaînage) */
p_new->p_prev = p_list->p_tail; /* On fait pointer p_prev
vers le dernier élément de la liste */
p_list->p_tail = p_new; /* On fait pointer la fin de liste
vers notre nouvel élément (fin du chaînage: 3 étapes) */
}
p_list->length++; /* Incrémentation de la taille de la liste */
}
}
return p_list; /* on retourne notre nouvelle liste */
}

int main()
{

}
