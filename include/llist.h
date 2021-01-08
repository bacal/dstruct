/*	llist.h
 *
 *
 */

typedef struct llist_struct{
    void* data;
    struct llist_struct* next;
}llist;


llist* llist_create();
void llist_delete(llist* l);
void* llist_get(llist* l, int* index);
void llist_add(void* data, llist* l);
int llist_remove(llist* l, int* index);
llist* llist_end(llist* l);