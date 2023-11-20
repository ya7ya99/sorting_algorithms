#include	"sort.h"
#include	<stdio.h>

/**
	*	merge	-	Merges	two	subarrays	into	a	single	sorted	subarray
	*	@array:	The	array	to	be	sorted
	*	@left:	Pointer	to	the	left	subarray
	*	@right:	Pointer	to	the	right	subarray
	*	@size_l:	Size	of	the	left	subarray
	*	@size_r:	Size	of	the	right	subarray
	*/
void	merge(int	*array,	int	*left,	int	*right,	size_t	size_l,	size_t	size_r)
{
	size_t	i	=	0,	j	=	0,	k	=	0;

	printf("Merging...\n[left]:	");
	print_array(left,	size_l);
	printf("[right]:	");
	print_array(right,	size_r);

	while	(i	<	size_l	&&	j	<	size_r)
	{
	if	(left[i]	<=	right[j])
	{
	array[k]	=	left[i];
	i++;
	}
	else
	{
	array[k]	=	right[j];
	j++;
	}
	k++;
	}

	while	(i	<	size_l)
	{
	array[k]	=	left[i];
	i++;
	k++;
	}

	while	(j	<	size_r)
	{
	array[k]	=	right[j];
	j++;
	k++;
	}

	printf("[Done]:	");
	print_array(array,	size_l	+	size_r);
}

/**
	*	merge_sort	-	Sorts	an	array	of	integers	in	ascending	order	using
	*	the	Merge	sort	algorithm.
	*	@array:	The	array	to	be	sorted
	*	@size:	The	size	of	the	array
	*/
void	merge_sort(int	*array,	size_t	size)
{
	size_t	middle;
	int	*left,	*right;
	size_t	i;

	if	(array	==	NULL	||	size	<=	1)
	return;

	middle	=	size	/	2;

	left	=	malloc(middle	*	sizeof(int));
	right	=	malloc((size	-	middle)	*	sizeof(int));

	if	(!left	||	!right)
	{
	free(left);
	free(right);
	return;
	}

	/*	Copy	data	to	temporary	arrays	left[]	and	right[]	*/
	for	(i	=	0;	i	<	middle;	i++)
	left[i]	=	array[i];

	for	(i	=	middle;	i	<	size;	i++)
	right[i	-	middle]	=	array[i];

	merge_sort(left,	middle);
	merge_sort(right,	size	-	middle);

	merge(array,	left,	right,	middle,	size	-	middle);

	/*	Free	the	auxiliary	arrays	*/
	free(left);
	free(right);
}


