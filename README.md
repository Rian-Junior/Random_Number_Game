# 🎮 Welcome to the Guessing Game! 🎮

Are you ready to test your skills and challenge your luck? Our **Guessing Game** is simple and exciting:

## How to Play:
- A **secret number** will be randomly generated.
- Your goal is to **guess the number** based on the provided hints.
- Choose from three difficulty levels:
  - **Easy:** 15 attempts
  - **Medium:** 10 attempts
  - **Hard:** 5 attempts
- As each level increases, so does the excitement and challenge!

## Features:
- 🔢 **Customizable levels**: Challenge yourself with more or fewer attempts!
- 🧠 **Develop your strategies**: You will receive hints if the number is higher or lower.
- 🏆 **Score based on accuracy**: The closer you get to the secret number, the more points you accumulate!

## Objective:
This game was mainly developed as a tool to **test programming logic**. While playing, you will be challenged to think strategically, evaluate probabilities, and make decisions based on the hints given.

---

**Enjoy the game and challenge your friends!**

## Requirements:

- **Operating System**: Linux, macOS, or Windows with WSL (Windows Subsystem for Linux) installed.

- **C Compiler**: You must have **gcc** (GNU Compiler Collection) installed on your system.
  - On Linux, you can install **gcc** with the following command:

    ```bash
    sudo apt install build-essential
    ```

  - On macOS, you can install the **Xcode Command Line Tools** with the command:

    ```bash
    xcode-select --install
    ```

  - On Windows (with WSL), make sure **gcc** is installed by following the Linux installation procedure.

- **Text Editor**: Any editor that allows you to view and modify `.c` files, such as Visual Studio Code, Sublime Text, or Vim.

## How to install

To compile and run the game on your computer:

1. Open the terminal and navigate to the directory where you want to clone the repository.
2. Run the following commands:

```bash
cd Downloads
git clone https://github.com/Rian-Junior/Random_Number_Game.git
cd Random_Number_Game
gcc -o RandomGame Random_Number_Game.c
./RandomGame
