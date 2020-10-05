#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct struttura{
	int info;
	struct struttura* next;
}head;

void add(struct struttura** l, int value){
	struct struttura* p = malloc(sizeof(struct struttura));

	p->info = value;
	p->next = (*l);
	(*l) = p;
}

void del(struct struttura** l, int value){
	struct struttura *p, *q;

	if((*l) == 0)
		return;

	for(p = (*l); (p->next != 0) && (p->info != value); p = p->next){
		q = p;
	}

	if(p->info == value){
		if(p == (*l))
			(*l) = p->next;
		else
			q->next = p->next;
		free(p);
	}
}

void stamp(struct struttura** l){
	struct struttura* p;

	if((*l) == 0){
		printf("lista vuota\n");
		return;
	}

	for(p = (*l); p->next != 0; p = p->next)
		printf("%d - ", p->info);
	printf("%d\n", p->info);
}

int main(){
	int i;
	struct struttura* testa;
	testa = NULL;

	stamp(&testa);
	del(&testa, 3);
	stamp(&testa);
	del(&testa, 4);
	stamp(&testa);

	for(i = 0; i < 5; i ++)
		add(&testa, i + 1);

	stamp(&testa);

	del(&testa, 1);
	stamp(&testa);
	del(&testa, 2);
	stamp(&testa);
	del(&testa, 6);
	stamp(&testa);
	del(&testa, 3);
	stamp(&testa);
	del(&testa, 5);
	stamp(&testa);
	del(&testa, 4);
	stamp(&testa);
	del(&testa, 10);
	stamp(&testa);

	return 0;
}
