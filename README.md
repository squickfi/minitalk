# minitalk
A communication program in the form of a client and a server. The client sends massages to the server with SIGUSR1 and SIGUSR2 and the server gets them with signal() function and prints.
## Usage
There are two terminals needed
|Server|Client|
|--|--|
|./server|./client [server PID] [massage]|

#### More task conditions, if you want:
[en.subject.pdf](https://github.com/squickfi/minitalk/blob/master/en.subject.pdf)