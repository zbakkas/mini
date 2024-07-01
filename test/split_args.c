

#include "min.h"


int chacke_q(char *str,int x)
{
    int i =0;
    char q = '\0';
    // printf("ss==%s=\n",str);
    while (str[i] && x> i )
    {
    
        if(str[i]=='\'')
        {
            q ='\'';
            break;
        }
        if (str[i]=='"')
        {
            q ='"';
            break;
        }
        i++;
        
    }
    i =0;
    while (x)
    {
        if(ft_strlen(str)>=x)
        {
        if(str[x]&& str[x]==q)
            i++;
        // if(str[x]=='"')
        //     l++;
        }
        x--;

    }
    if(str[0]==q)
        i++;
    if(i%2==0)
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
    int l =0;
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
        if(str[x] &&(str[x]=='>' || str[x]=='<')&& !chacke_q(str+l,x))
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
            l =x;
            
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
    int l =0;
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
        // printf("s===%s\n",s+l);
		if (c == s[x] && c != s[x + 1] && x < ft_strlen(s) - 1 && !chacke_q(s+l,x-l))
        {
			re++;
            l = x;
        }
		x++;
	}
	return (re + 1);
}
static	char	*word(char  *s, char c, int *x)
{
	int		i;
	char	*re;
	int		j=0;
    char    q;

	i = 0;
	while (s[*x] == c)
		(*x)++;
    // printf("s==%s\n",s+*x);
    while(s[*x+i])
    {
        if(s[*x+i]=='"'||s[*x+i]=='\'')
        {
            q=s[*x+i];
            break;
        }
        i++;
    }
    i=0;
	while (s[(*x) + i] )
    {


        if(!chacke_q(s+*x,i) && s[(*x) + i] == c)
            break;
        if(s[(*x) + i] == q)
            j++;
  

		i++;
    }
    printf("%d , %d\n",i,j);
	re = malloc ((i -j)+ 1);
	if (!re)
		return (NULL);
	j = 0;
	while (i)
    {
        if(s[*x]!=q)
		    re[j++] = s[(*x)];
        (*x)++;
        i--;
    }
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
    char *str0 ="ls \"\" -a \"\" -l";
    char *str1 ="l\"s\"> \"hello  <'worde\"  \"-l -a\" \"\">\"\" 'out'";
    char *str2 ="l\"s\"< 'hello  \">> worde'  \"-l -a\">> out >f";
    char *str3 ="'cat'< \" min '2\" -e";
    printf("%s\n",str1);
   printf("%s\n", set_speece(str1));
char ** str =split_part(set_speece(str1));
int x =0;
while (str[x])
{
    printf("%s\n",str[x]);
    x++;
}


}