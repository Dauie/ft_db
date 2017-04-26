
#include "ft_db.h"

static t_enode *prep_addenode(t_dbnfo *db)
{
	t_enode *elem;

	if (!(elem = (t_enode *)db_memalloc(sizeof(t_tnode))))
		return (NULL);
	db_initenode(elem);
	strcpy(elem->ename, db->key_name);
	strcpy(elem->ename, db->key_name);
	time(&elem->emodtime);
	time(&elem->ecretime);
	elem->cmembr = db_tbldup(db->val, db->nval);
	return (elem);
}

void 		db_addenoden(t_enode **t_tree, t_dbnfo *db)
{
	t_trienode		tri;

	tri.ttmp = *t_tree;
	tri.elem = prep_addenode(db);
	if (tri.ttmp)
	{
		while (tri.ttmp)
		{
			tri.ntmp = tri.ttmp;
			if (tri.ttmp && strcmp(tri.elem->ename, tri.ttmp->ename) < 0)
			{
				tri.ttmp = tri.ttmp->left;
				if (!tri.ttmp)
					tri.ntmp->left = tri.elem;
			}
			else
			{
				tri.ttmp = tri.ttmp->right;
				if (!tri.ttmp)
					tri.ntmp->right = tri.elem;
			}
		}
	}
	else
		*t_tree = tri.elem;
	if (db->mode == ADD_TBL)
		db->mode = NRML;
}

