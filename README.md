# Pipex

## About the project
The program should execute commands provided by user. Take file as an inout and output result of commands to a another file.

## What have I learned from the project
1. Working with processes
2. Understanding how bash / zsh work on a surface ground.
3. Working with Pipe

## Usage
### Mandatory part
1. make
2. ./pipex input cmd1 cmd2 output
	* input is the name of the file that you want the program to take
	* cmd1 is a command to be executed
	* cmd2 is a command to be executed
	* output is the name of the file that you want the program to put output to

example: ./pipex Makefile "grep pipex" "wc -c" output

The example is equal to: < Makefile grep "pipex" | wc -c > output 

This will count number of characters in all lines that include word "pipex" and put the result to a file output

### Bonus part
1. make bonus
2. ./pipex_bonus input cmd1 cmd2 cmd3 cmd4 ... output
	* input is the name of the file that you want the program to take
	* cmd1 is a command to be executed
	* cmd2 is a command to be executed
	* ...
	* output is the name of the file that you want the program to put output to

Bonus part can accept more commands. Also, you can use heredoc as input for commands.

example: ./pipex here_doc stop_word cat cat "wc -c" output

This will wait for user input. Only when 'stop_word' will be given on an empty line, the program will execute all the commands. In the end, the program will count number of characters in the user provided input and put it to output file
