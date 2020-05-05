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
if (p_list != NULL) /* On v�rifie si notre liste a �t� allou�e */
{
struct node *p_new = malloc(sizeof *p_new); /* Cr�ation d'un
nouveau node */
if (p_new != NULL) /* On v�rifie si le malloc n'a pas �chou� */
{
p_new->data =gets(); /* On 'enregistre' notre donn�e */
p_new->p_next = NULL; /* On fait pointer p_next vers NULL */
if (p_list->p_tail == NULL) /* Cas o� notre liste est vide
(pointeur vers fin de liste � NULL) */
{p_new->p_prev = NULL; /* On fait pointer p_prev vers NULL
*/
p_list->p_head = p_new; /* On fait pointer la t�te de liste
vers le nouvel �l�ment */
p_list->p_tail = p_new; /* On fait pointer la fin de liste
vers le nouvel �l�ment */
}
else /* Cas o� des �l�ments sont d�j� pr�sents dans notre liste
*/
{
p_list->p_tail->p_next = p_new; /* On relie le dernier
�l�ment de la liste vers notre nouvel �l�ment (d�but du cha�nage) */
p_new->p_prev = p_list->p_tail; /* On fait pointer p_prev
vers le dernier �l�ment de la liste */
p_list->p_tail = p_new; /* On fait pointer la fin de liste
vers notre nouvel �l�ment (fin du cha�nage: 3 �tapes) */
}
p_list->length++; /* Incr�mentation de la taille de la liste */
}
}
return p_list; /* on retourne notre nouvelle liste */
}

int main()
{

}
