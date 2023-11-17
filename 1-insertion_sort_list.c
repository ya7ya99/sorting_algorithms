#include	"sort.h"

/**
	*	swap	-	Swaps	two	nodes	in	a	doubly	linked	list
	*	@a:	First	node	to	swap
	*	@b:	Second	node	to	swap
	*/
void	swap(listint_t	*a,	listint_t	*b)
{
	if	(a->prev)
	a->prev->next	=	b;
	if	(b->next)
	b->next->prev	=	a;

	a->next	=	b->next;
	b->prev	=	a->prev;
	b->next	=	a;
	a->prev	=	b;
}

/**
	*	insertion_sort_list	-	Sorts	a	doubly	linked	list	of	integers
	*	in	ascending	order	using	the	Insertion	sort	algorithm
	*	@list:	Pointer	to	the	head	of	the	linked	list
	*/
void	insertion_sort_list(listint_t	**list)
{
	listint_t	*current,	*temp;

	if	(list	==	NULL	||	*list	==	NULL	||	(*list)->next	==	NULL)
	return;


	current	=	(*list)->next;

	while	(current	!=	NULL)
	{
	temp	=	current;

	while	(temp->prev	!=	NULL	&&	temp->n	<	temp->prev->n)
	{
	swap(temp->prev,	temp);
	if	(temp->prev	==	NULL)
	*list	=	temp;
	print_list(*list);
	}

	current	=	current->next;
	}
}
