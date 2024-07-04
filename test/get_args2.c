#include "min.h"

char *get_cmd2(char **str)
{
    char *re;
    if(!str||!str[0])
        return NULL;
    if(ft_strncmp(str[0],"<",2)==0||ft_strncmp(str[0],">",2)==0||ft_strncmp(str[0],"<<",3)==0||ft_strncmp(str[0],">>",3)==0)
    {
        if(str[2])
            re =str[2];
        else
            return NULL;
    }
    else
        re = str[0];


    return re;
}




char **get_flags2(char **str)
{
    char **re;
    int i =3;
    int c =0;
    if(!str||!str[0])
        return NULL;

    if(ft_strncmp(str[0],"<",2)==0||ft_strncmp(str[0],">",2)==0||ft_strncmp(str[0],"<<",3)==0||ft_strncmp(str[0],">>",3)==0)
    {
        i=3;
        // printf("%s\n",str[i] ? str[i]:"(null)");
        if( ft_tostrlen(str)<=i)
            return NULL;
        while (str[i])
        {
        // printf("ff\n");
            if(str[i][1]&& str[i][1]=='-'&&(str[i][0]=='"' ||str[i][0]=='\''))
                c++;
            else if(str[i][0]=='-')
                c++;
            i++;
        }
            
    }
    else
    {
        i = 1;
        while (str[i])
        {
            if(str[i][1]&& str[i][1]=='-'&&(str[i][0]=='"' ||str[i][0]=='\''))
                c++;
            else if(str[i][0]=='-')
                c++;
            i++;
        }

    }
    // printf("%d\n",c);


    re = (char **)malloc((1 + c) * sizeof(char *));
    i =0;
    c =0;

    // while (x<c)
    // {
    //     printf("%s\n",str[0]);
    if(ft_strncmp(str[0],"<",2)==0||ft_strncmp(str[0],">",2)==0||ft_strncmp(str[0],"<<",3)==0||ft_strncmp(str[0],">>",3)==0)
    {
        i=3;
        while (str[i])
        {
            if(str[i][1]&& str[i][1]=='-'&&(str[i][0]=='"' ||str[i][0]=='\''))
                re[c++]=str[i];
            else if(str[i][0]=='-')
                re[c++]=str[i];
            i++;
        }
            
    }
    else
    {
        i = 1;
        while (str[i])
        {
            // printf("i==%d\n",i);
            //  printf("%s\n",str[i]);
            if(str[i][1]&& str[i][1]=='-'&&(str[i][0]=='"' ||str[i][0]=='\''))
            {
                re[c++]=str[i];
            }
            else if(str[i][0]=='-')
            {
                
                re[c++]=str[i];
            }
            i++;
        }

    }
       
    // }
    

    re[c]=NULL;
    
    


    return re;
}



char **get_args(char **str)
{
    char **re;
    return re;
}

int main()
{
    char *str0 ="ls \"\" -a \"\" -l";
    char *str1 ="l\"s\"> \"hello  <'worde\"  \"-l -a\" \"\">\"\" 'out'";
    char *str2 ="l\"s\"< 'hello  \">> worde'  \"-l -a\">> out >f";
    char *str3 ="<'cat'\"<\" \" min '2\" -e";

    char *str4 = "cat file > out >>out1 << stop out2 > out3 -e";
    printf("%s\n",str4);
//    printf("%s\n", set_speece(str3));
char ** str =split_part(set_speece(str4));
int x =0;
while (str[x])
{
    printf("%s\n",str[x]);
    x++;
}
printf("x==%d\n",x);
printf("--------------------\n");
printf("cmd=%s\n",get_cmd2(str) ? get_cmd2(str):"(null)");
char **flags=get_flags2(str);
x =0;
while (flags && flags[x])
{
    printf("flag%d =%s\n",x,flags[x]);
    x++;
}
get_args(str);


}
