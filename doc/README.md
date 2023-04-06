# 🖥 Minishell

Minishell is a 42 school team project to create a basic shell program in C. It implements redirections and pipes, as well as environment variable expansions and the cd, echo, env, exit, export, pwd and unset builtin commands.

---
## 🚀 Roadmap

✅ Afficher un prompt en l’attente d’une nouvelle commande

✅ Ne pas utiliser plus d’une variable globale. Réfléchissez-y car vous devrez justifier son utilisation

❌ Posséder un historique fonctionnel.

❌ Chercher et lancer le bon exécutable (en se basant sur la variable d’environnement PATH, ou sur un chemin relatif ou absolu).

❌ Ne pas interpréter de quotes (guillemets) non fermés ou de caractères spéciaux non demandés dans le sujet, tels que \ (le backslash) ou ; (le point-virgule).

❌ Gérer ’ (single quote) qui doit empêcher le shell d’interpréter les méta-caractères présents dans la séquence entre guillemets.

❌ Gérer " (double quote) qui doit empêcher le shell d’interpréter les méta-caractères présents dans la séquence entre guillemets sauf le $ (signe dollar).

❌ Implémenter les redirections :

❌ < doit rediriger l’entrée.

❌ > doit rediriger la sortie.

❌ << doit recevoir un délimiteur et lire l’input donné jusqu’à rencontrer une ligne contenant le délimiteur. Cependant, l’historique n’a pas à être mis à jour !

❌ >> doit rediriger la sortie en mode append.

❌ Implémenter les pipes (caractère |). La sortie de chaque commande de la pipeline est connectée à l’entrée de la commande suivante grâce à un pipe.

❌ Gérer les variables d’environnement (un $ suivi d’une séquence de caractères) qui doivent être substituées par leur contenu.

❌ Gérer $? qui doit être substitué par le statut de sortie de la dernière pipeline exécutée au premier plan.

❌ Gérer ctrl-C, ctrl-D et ctrl-\ qui doivent fonctionner comme dans bash

❌ En mode interactif :

❌ ctrl-C affiche un nouveau prompt sur une nouvelle ligne.

❌ ctrl-D quitte le shell.

❌ ctrl-\ ne fait rien.

❌ Votre shell doit implémenter les builtins suivantes :

❌ echo et l’option -n

❌ cd uniquement avec un chemin relatif ou absolu

❌ pwd sans aucune option

❌ export sans aucune option

❌ unset sans aucune option

❌ env sans aucune option ni argument\

❌ exit sans aucune option