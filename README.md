# ircbot
This is a simple bot for IRC developed entierely in C. It aims at being the most flexible possible, by separating the network and IRC processing tasks in the main executable, and loading a shared library which will act as the "AI" of the bot. 

## Installing

### Prerequisites
In order to compile the current AI, you need to have installed sqlite3, zlib, libcurl, libcrypto and libssl.
A youtube API key is also required. If you don't have one, you may comment the whole file `AI/src/youtube_title.c` leaving just youtube_title() return NULL. It won't break the AI, you will just be unable to retrieve the songs' titles.

### Compiling
Run:
    git clone https://github.com/Ethiraric/ircbot.git
    cd ircbot
    git submodule update --init
    make
This will compile both the AI and the main executable. You can use `make AI` to compile only the AI, or `make IRCbot` to compile the main executable.
Other Makefile rules are also available: `clean` will remove all object files, `fclean` will remove object files and the executables/libraries, `re` will run `fclean` then `all`.

## The code
There are almost no comment for now (I am alone to work on it for now), but I plan on adding them soon.

### The libIRC
This is currently a separated repository on github

### The main executable
It's the skeleton for the AI. It will load the AI, setup the network, receive standard input, socket input, split messages correctly, and call the AI when needed. The AI needs to have some symbols defined, so the executables know where to call (these are `#defined` in `main/include/ircbot.h` so they can be easily changed):
  * `irc_data_get`: This is like the constructor of your AI. It must return a pointer to a structure the executable will pass to the library each time it calls it. It is called when the library is loaded.
  * `irc_data_delete`: This is like the destructor. It is called when the library will be unloaded.
  * `irc_on_mess`: This will be called each time the executable will receive an IRC message. Since it has already parsed it, you may easily access the command arguments in the `t_ircconnection` structure fields.
  * `irc_stdin`: This will be called each time the executable will receive a line on the standard input.
  * `irc_nothing`: Every once in a while (every 0.1 second for now), the executable will call this function. In case you need your AI to do some things even if there is no message (a typical example is a cron-like system).

### The AI folder
This is my current implementation of the AI. The source directory contains all commands. `command_*.c` contains code for each command the bot understands when sent as a private message (either to the bot, or in a chan, both are the same in the IRC protocol). `in_*.c` are commands received through standard input. `mess_*.c` are the functions called when the bot receives an IRC message.

For instance, if the bot receives a message, `someone PRIVMSG #chan song`. The following functions will be called (in the right order): `irc_on_mess() -> handle_message() -> mess_privmsg() -> command_song()`. Note that commands do not start with '!'.

## Bugs and Suggestions
Feel free to report anything you think useful to florian.sabourin@epitech.eu.