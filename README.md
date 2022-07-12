# MiniShell

![linux](https://user-images.githubusercontent.com/47386839/178318860-ccc09a6f-db4b-477a-86fd-dc7b5aa74164.gif)

## Description
A C project that mimics the linux shell terminal with built-in commands like echo, cd, ls, grep and many more. It also supports piping and redirectional operations with extended capacity of history caching

## Concepts Used
Most of the linux commands were written from scratch using C while using making use of forking and threading new processes for child commands. It also makes sure to avoid any memory leaks which were checked using Valgrind for linux. Environment Variables expansion was made possible using paths.

## How to use
1. Download the entire code as ZIP file and extract it in a suitable location. 
2. Navigate to the project directory and run 'make' command.
3. Run the command './minishell'.
4. Enjoy.

# Screenshots
![Screenshot from 2022-07-11 22-50-49](https://user-images.githubusercontent.com/47386839/178417315-b076eb5c-34a9-4f02-9ce8-9df81f8790e3.png)

