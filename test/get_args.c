


#include "min.h"

static char get_q(char *str)
{
    char q = '\0';
    int x =0;
    while (str[x])
    {
        if(str[x]=='\'')
            q = '\'';
        if(str[x]=='"')
            q='"';
        if(str[x]=='\''||str[x]=='"')
            return q;  
        x++;
    }
    return q;
}
//<<file" "  ls" k"
char *get_cmd(char *str)
{
    char *re;
    int x =0;
    int i =0;
    int j =0;
    bool in_quotes = false;
    while (str[x] && str[x] == ' ')
        x++;

    if (str[x]=='<' || str[x]=='>')
    {
        while (str[x] && str[x] != ' ')
            x++;
        while (str[x] && str[x] == ' ')
            x++;
        while (str[x])
        {
            if((str[x] == ' ' || str[x] =='<' || str[x]=='>' ))
                break;

            x++;
        }


        
    }
    while (str[x] && str[x] == ' ')
        x++;

    printf("%s\n",str+x);
    while (str[x+j])
    {
        if (str[x+j] == get_q(str) ) 
            in_quotes = !in_quotes;
        if((str[x+j] == ' ' || str[x+j] =='<' || str[x+j]=='>' )&& !in_quotes)
            break;
        // x++;
        j++;
    }
   
// printf("%s,%d\n",str+x,j);



    
    
    // printf()
    re =malloc(j +1);
    while (i < j)
    {
        re[i++]=str[x++];
        // i++;
    }
    re[i] ='\0';
    return re;
}


// static int count_flags(char *str)
// {
//     int re =0;
//     int x =0;
//     while (str[x])
//     {
//         if(str[x]=='-' && str[x+1] && str[x+1]!='-')
//             re++;
//         x++;
//     }
//     return re;
// }
// static char *get_flag(char *str,int *x)
// {
//     char *re;
//     int i=0;
//     int j =0;
//     // printf("%s\n",str);
//     while (str[*x])
//     {
//         if(str[*x]=='-')
//             break;
//         (*x)++;
//     }
//     while (str[*x+i])
//     {
//         if(str[*x+i] == ' ' || str[*x+i] =='<' || str[*x+i]=='>')
//             break;
//         i++;
//     }
//     re =malloc(i +1);
//     while (i--)
//     {
//         re[j++] =str[(*x)++];
//     }
//     re[j]='\0';

//     return re;
// }
// //ls -a -l  >out    //ls > out -l
// char **get_flages(char *str)
// {
//     char **re;
//     int j =0;
//     int x =0;
//     int c = count_flags(str);
//     // printf("ff\n");
//     re = (char **)malloc(c +1*sizeof(char *));
//     printf("%d\n",c);
//     while (c--)
//     {
//        re[j]=get_flag(str,&x);
//     //    str+=ft_strlen(re[j]);
//         j++;
//     }
//     // printf("j ==%d\n",j);

//     re[j]=NULL;

//     return re;
// }



static int count_flags(char *str) {
    int re = 0;
    int x = 0;
    while (str[x]) {
        if (str[x] == '-' && str[x + 1] && str[x + 1] != '-') {
            re++;
        }
        x++;
    }
    return re;
}

static char *get_flag(char *str, int *x) {
    char *re;
    int i = 0;
    int j = 0;

    // Find the start of the flag
    while (str[*x]) {
        if (str[*x] == '-') {
            break;
        }
        (*x)++;
    }

    // Find the length of the flag
    while (str[*x + i]) {
        if (str[*x + i] == ' ' || str[*x + i] == '<' || str[*x + i] == '>') {
            break;
        }
        i++;
    }

    re = malloc(i + 1);


    while (i--) {
        re[j++] = str[(*x)++];
    }
    re[j] = '\0';

    return re;
}

char **get_flages(char *str) {
    char **re;
    int j = 0;
    int x = 0;
    int c = count_flags(str);


    re = (char **)malloc((c + 1) * sizeof(char *));
    // printf("%d\n",c);

    while (c>j) {
        re[j] = get_flag(str, &x);
        j++;
    }

    re[j] = NULL;

    return re;
}




// grep -l "t.txtk" out1
// grep out -e '[o,g]'

static int get_count_arg(char *str)
{
    int x =0;
    int i =0;
    // while (str[x])
    // {
    //     if(str[x] == ' ' || str[x] =='<' || str[x]=='>')
    //         break;
    //     x++;
    // }
    // while (str[x] && str[x] == ' ')
    //     x++;
    while (str[x])
    {
        if(str[x]=='-')
        {
            while (str[x])
            {
                if(str[x] == ' ' || str[x] =='<' || str[x]=='>')
                    break;
                x++;
            }
            
        }
        i++;
        x++;
        
    }
    return i;
}


char *get_argumants(char *str)
{
    char *re;
    int x =0;
    int i =0;
    while (str[x] && str[x] == ' ')
        x++;
    while (str[x])
    {
        if(str[x] == ' ' || str[x] =='<' || str[x]=='>')
            break;
        x++;
    }
    while (str[x] && str[x] == ' ')
        x++;

    int c = get_count_arg(str+x);
    // printf("c ==%d\n",c);
    re =malloc(c+1);

    while (str[x])
    {
        if(str[x]=='-')
        {
            while (str[x])
            {
                if(str[x] == ' ' || str[x] =='<' || str[x]=='>')
                    break;
                x++;
            }
            // while (str[x] && str[x] == ' ')///
                // x++;///
            
        }
        re[i]=str[x];
        i++;
        x++;
        
    }
    re[i]='\0';
    return re;
}


// int main()
// {
//     int x =0;
//     char * str =get_cmd(" <<file" "  ls\" k\"");
//     printf("-%s-\n",str);
//     // while (str[x])
//     // {
//     //        printf("%s\n",str[x++]);

//     // }
    
// }