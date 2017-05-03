#include "ft_db.h"

void	db_filetostring(intmax_t num, FILE *p_dbf, char **content)
{
	const char *tmp;

	while (fscanf(p_dbf, "%s", content) != EOF)
	{
		tmp = strjoin(content, " , ");
		strdel(content);
		content = strdup(tmp);
		strdel(tmp);
	}
}

int		db_xportdb(t_tnode *t_tree)
{
	FILE *p_dbf;
	size_t len;
	char content[MXNAMLEN];
	struct stat st = {0};

	len = 0;
	if (!(p_dbf = fopen("rtt.db", "rb+")))
	{
		printf("%s error %s trouble exporting db", G_TSYM, G_EDIV);
		return (-1);
	}
	db_ttreelen(t_tree, &len);
	db_filetostring(len, p_dbf, &content);
	if (stat("newdir", &st) == -1)
		mkdir("newdir");
	snprintf(content, sizeof(content), "newdir/exported.db", getpid());
	fclose(p_dbf);
	return (0);
}

