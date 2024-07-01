

#include "min.h"



int chacke_q(char *str,int x)
{
    int i =0;
    int l=0;
    while (x)
    {
        if(str[x]=='\'')
            i++;
        if(str[x]=='"')
            l++;
        x--;

    }
    if(i%2==0 && l%2==0)
        return 0;
    else
        return 1;
    
}




//   l"s" "hello  >>worde"'>'  "-l -a"> out
char *set_speece(char *str)
{
    char *re;
    int x =0;
    int i=0;
    while (str[x])
    {
        
        if((str[x]=='>' || str[x]=='<')&& !chacke_q(str,x))
        {
            while(str[x] && (str[x]=='<' || str[x]=='>'))
                x++;
            i++;
        }
        x++;
    }
    // printf("%d\n",x+(i*2));

    re = malloc(x+(i*2)+1);
    x =0;
    i =0;
    // printf("%s\n",str);
    while (str[x])
    {
        if(str[x] &&(str[x]=='>' || str[x]=='<')&& !chacke_q(str,x))
        {
            // printf("+");
            re[i++]=' ';
            while(str[x] && (str[x]=='<' || str[x]=='>'))
            {
                // printf("%c",str[x]);
                re[i++]=str[x];
                x++;
            }
            // printf("+");
            re[i++]=' ';
            
            
        }
        // printf("%c",str[x]);
        re[i++]=str[x];
        x++;
    }
    // printf("\n");
    re[i]='\0';
    // printf("%d\n",i);

    return re;



}


static	int	c_word(char  *s, char c)
{
	size_t	x;
	int		re;

	x = 0;
	re = 0;
	if (!s[x])
		return (0);
	if (s[x] && c == '\0')
		return (1);
	while (s[x] == c)
		x++;
	if (s[x] == '\0')
		return (0);
	while (s[x])
	{
		if (c == s[x] && c != s[x + 1] && x < ft_strlen(s) - 1 && !chacke_q(s,x))
			re++;
		x++;
	}
	return (re + 1);
}
static	char	*word(char  *s, char c, int *x)
{
	int		i;
	char	*re;
	int		j;

	i = 0;
	while (s[*x] == c)
		(*x)++;
	while (s[(*x) + i]  )
    {
        if(!chacke_q(s,*x +i) && s[(*x) + i] == c)
            break;
		i++;
    }
	re = malloc (i + 1);
	if (!re)
		return (NULL);
	j = 0;
	while (i > j)
		re[j++] = s[(*x)++];
	re[j] = '\0';
	return (re);
}

char **split_part(char *s)
{
	char	**re;
	int		x;
	int		j;
	int		t;

	x = 0;
	j = 0;
	if (!s)
		return (NULL);
	t = c_word(s, ' ');
    // printf("%d\n",t);
	re = (char **)malloc((1 + t) * sizeof(char *));
	if (!re)
		return (NULL);
	while (j < t)
	{
		re[j] = word(s, ' ', &x);
		// if (!re[j])
		// 	return (is_free(re));
		j++;
	}
	re[j] = NULL;
	return (re);

}




int main()
{
    char *str ="ls \"\" -a \"\" -l";
    char *str1 ="l\"s\" \"hello worde\"  \"-l -a\" \"\">\"\" out";
    char *str2 ="l\"s\"< \"hello  >> worde\"  \"-l -a\">> out >f";
   printf("%s\n", set_speece(str));
char ** str3 =split_part(set_speece(str));
int x =0;
while (str3[x])
{
    printf("%s\n",str3[x]);
    x++;
}


}