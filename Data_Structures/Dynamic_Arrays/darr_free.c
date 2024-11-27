#include "dynamic_array."

void	darr_free(t_dynamic_array *da)
{
	if (!da)
		return ;
	free(da->data);
	free(da);
}

void	darr_free_custom(t_dynamic_array *da, void (*del) (void *data))
{
	size_t i;
	void *next_el;

	if (!da)
		return ;
	i = 0;
	if (del != NULL)
	{
		while (i < da->len)
		{
			next_el = da->data + (i * da->data_size);
			del(next_el);
			i++;
		}
	}
	free(da->data);
	free(da);
}
