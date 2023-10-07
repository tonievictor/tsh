# Simple Shell

## Overview

A simple Unix shell written in C that supports both interactive and non-interactive modes. It can execute a variety of commands, handle signals, and more.

## Features

- **Interactive Mode:** Run the shell interactively, accepting user commands in real-time.
- **Non-Interactive Mode:** Execute commands from a pipe (file and script support coming soon).
- **Command Execution:** Supports a variety of Unix commands.
- **Signal Handling:** Properly handles signals to ensure robust execution.

## Getting Started

### Prerequisites

- This shell requires a Unix-like operating system.
- You'd need a C compiler, preferably gcc.

### Installation

- **Clone the repository**

```bash
git clone https://github.com/Tonie-NG/simple_shell.git
```

- **Change directory to the project:**

```bash
cd simple_shell
```

### Compiling

- **Compile the shell using the following command:**

```bash
gcc *.c -o simple_shell
```

For more strictness, you could use this:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o simple_shell
```

## Usage

1. Interactive Mode:

   - Simply run the executable, and the shell will start accepting commands.

```bash
./simple_shell
```

2. Non-Interactive Mode:

   - Provide a valid command using echo and pipe it to the executable file.

```bash
echo "/bin/ls" | ./simple_shell
```

## Examples

1. **Interactive Mode:**

   - To start the shell:

   ```bash
   ./simple_shell
   ```

   - Provide the command path:

     ```bash
     $ /bin/ls
     $ /bin/ls -l
     ```

   - You can also provide the command, and the shell handles the full path:
     ```bash
     $ ls
     $ pwd
     $ exit
     ```

2. **Non-interactive mode:**

   - Provide the command path via pipe:

   ```bash
   echo "/bin/ls" | ./simple_shell
   ```

   - Provide the command and the shell handles the path

   ```bash
   echo "ls" | ./simple_shell
   ```

