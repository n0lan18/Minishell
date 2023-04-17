```c
typedef struct s_data  
{  
   t_token     *token;  
   char        *rl_input;  
   char        **env;  
   char        *working_dir;
   t_command   *cmd;  
   pid_t       pid;  
}  t_data;
```