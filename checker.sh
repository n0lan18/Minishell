#!/bin/bash

# Colors
RESET="\033[0m"
BLACK="\033[30m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
BLUE="\033[34m"
MAGENTA="\033[35m"
CYAN="\033[36m"
WHITE="\033[37m"
BOLDBLACK="\033[1m\033[30m"
BOLDRED="\033[1m\033[31m"
BOLDGREEN="\033[1m\033[32m"
BOLDYELLOW="\033[1m\033[33m"
BOLDBLUE="\033[1m\033[34m"
BOLDMAGENTA="\033[1m\033[35m"
BOLDCYAN="\033[1m\033[36m"
BOLDWHITE="\033[1m\033[37m"

# Compile and set executable rights
make
chmod 755 minishell

# Init vars
TOTAL=0
SUCCESS=0

function exec_test()
{
  # Run minishell and bash
  # 2>&- allow to redirect stderr to /dev/null
	TEST1=$(./minishell -c "$@" 2>&-)
	EXIT_STATUS_1=$?
	TEST2=$(bash -c "$@" 2>&-)
	EXIT_STATUS_2=$?

	# Check if ✅or ❌
	if [ "$TEST1" == "$TEST2" ] && [ "$EXIT_STATUS_1" == "$EXIT_STATUS_2" ]; then
		printf " $BOLDGREEN%s$RESET" "✅ "
		((SUCCESS=SUCCESS+1))
	else
	  echo
		printf " $BOLDRED%s$RESET" "❌ "
	fi
	printf "$CYAN \"$@\" $RESET"

  # Compare outputs
	if [ "$TEST1" != "$TEST2" ]; then
	  echo
		printf $BOLDRED"Your output :%.20s\n$BOLDRED$TEST1%.20s$RESET\n"
		printf $BOLDGREEN"Expected output :%.20s\n$BOLDGREEN$TEST2%.20s$RESET"
	fi
  # Compare exit status
	if [ "$EXIT_STATUS_1" != "$EXIT_STATUS_2" ]; then
  		echo
  		printf $BOLDRED"Your exit status : $BOLDRED$EXIT_STATUS_1$RESET\n"
  		printf $BOLDGREEN"Expected exit status : $BOLDGREEN$EXIT_STATUS_2$RESET\n"
  fi

  echo
	((TOTAL=TOTAL+1))
	sleep 0.1
}

# ECHO TESTS
printf "\n$BOLDYELLOW%s$RESET\n" "ECHO TESTS"
exec_test "echo"
exec_test "echo caca"
exec_test "echo caca      pipi"
exec_test "    echo    caca      pipi"
exec_test 'echo "caca   pipi"'
exec_test "echo 'caca   pipi'"
exec_test 'ec"ho" caca'
exec_test "ec'ho' caca"
exec_test 'echo caca "" caca "" caca'
exec_test 'echo $USER'
exec_test 'echo $USER      $USER'
exec_test 'echo '\''$USER'\'''
exec_test 'echo $?'
exec_test 'echo $??'
exec_test 'echo "$"'
exec_test 'echo "$USER"'
exec_test 'echo "   $USER caca $USER"'
exec_test 'echo $USER--'
exec_test 'echo $USER@caca'
exec_test 'echo "$=CACA"'
exec_test 'echo $INEXISTINGVAR'
exec_test 'echo $USER_'
exec_test 'echo "$USER$USER$USER"'
exec_test 'echo "$?CACA"'
exec_test 'echo "$USERcaca"'
exec_test 'echo "$USER$USER=caca$USER"'
exec_test 'echo "hello world""test"'

# FIXME
#exec_test 'echo $INEXISTINGVAR caca'
#exec_test 'echo $101dalmatiens'

#exec_test "echo -n caca"
#exec_test "echo -n"
#exec_test "echo -n -n"
#exec_test "echo -n -n -n caca pipi"

# UNSET TESTS
printf "\n$BOLDYELLOW%s$RESET\n" "UNSET TESTS"
exec_test 'unset $USER'
exec_test 'unset $'
exec_test 'unset 101=dalmatiens'
exec_test 'unset _=caca'
exec_test 'unset $USER=caca'
exec_test 'unset $?'

# EXPORT TESTS
printf "\n$BOLDYELLOW%s$RESET\n" "EXPORT TESTS"
exec_test 'export $USER'
exec_test 'export $'
exec_test 'export 101=dalmatiens'
exec_test 'export _=caca'
exec_test 'export $USER=caca'
exec_test 'export $?'
exec_test 'export =caca'
exec_test 'export caca = pipi'

# PWD TESTS
printf "\n$BOLDYELLOW%s$RESET\n" "PWD TESTS"
exec_test 'pwd'
exec_test 'cd srcs; pwd'
exec_test 'cd caca; pwd'
exec_test 'cd ..; pwd'
exec_test 'cd .; pwd'
exec_test 'cd /Users ; pwd'

# EXECVE TESTS
#printf "\n$BOLDYELLOW%s$RESET\n" "EXECVE TESTS"
#exec_test 'ls'
#exec_test 'ls -l'
#exec_test 'clear'

# PRINT TOTAL
echo
echo
printf "(TEST $SUCCESS/$TOTAL)\n"