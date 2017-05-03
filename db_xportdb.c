#include "ft_db.h"

int		db_filetostring(intmax_t num, FILE *p_dbf, char *line)
{
	char *str;

	line = fscanf(p_dbf, "%s", &str);
	return (-1);
}

int		db_xportdb(t_tnode *t_tree)
{
	FILE *p_dbf;
	size_t len;
	char line[MXNAMLEN];

	len = 0;
	if (!(p_dbf = fopen("rtt.db", "rb+")))
	{
		printf("%s error %s trouble exporting db", G_TSYM, G_EDIV);
		return (-1);
	}
	db_ttreelen(t_tree, &len);
	db_filetostring(len, p_dbf, line);
	fclose(p_dbf);
	return (0);
}

