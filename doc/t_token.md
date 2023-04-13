```c
typedef struct s_token  
{
   char             *str;  
   int              type;  
   struct s_token   *prev;  
   struct s_token   *next;  
}  t_token;
```