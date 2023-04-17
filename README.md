# Minishell

See documentation [here](https://github.com/n0lan18/Minishell/tree/master/doc)

---

## Project doesn't compile? 😢

1. Try to install readline with brew
```
brew install readline
```

2. Locate the installation of readline. For me it was in: `/opt/homebrew/opt/realdine`

4. Replace the path with the path of your readline in the `Makefile`

```
-L $(HOME)/.brew/opt/readline/lib -I $(HOME)/.brew/opt/readline/include
```

Example
```
-L /opt/homebrew/opt/realdine/lib -I /opt/homebrew/opt/realdine/include
```