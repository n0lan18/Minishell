```c
typedef struct s_command  
{  
   char               *name;  
   char               *path;  
   char               **args;    
   struct s_command   *next;  
   struct s_command   *prev;  
}  t_command;
```
