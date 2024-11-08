# Stacks and Reverse Polish Notations Calculators

In this project a web interface is provided to input and visualise your stack/RPN. In order for it to work, you must implement the functions found in main.cpp.
To run the web interface you will need python 3 installed (as in the last worksheet - note you do not need to install it again) : https://www.python.org/downloads/

## Running the project
In one terminal window start the server by navigating into the client directory and running the python server:
```cd client```
```python3 -m http.server```

Note: Python will then block the terminal while it runs the server. Use split terminal in vscode to get two running side by side!

Open main.cpp is VS Code and CTRL/CMD-Shift-B to build.
You can then run your exe:
```
./main.exe

#or for OSX
./main
```
Open a browser and point it at one of the following url's (to use local port 8000)
or try clicking [here](http://localhost:8000/)
```
http://localhost:8000/

127.0.0.1:8000

http://[::]:8000/
```

You can navigate to the repective pages for the tasks.

Type message in RPN expression and see infix evaluation, graph, and your result.

To Stop your program running, click the terminal and press ctrl+c

## Don't forget!

Launch VS Code from the Developer Command prompt
Open this directory (worksheet5_tasks) in VS code, not a parent directory
Compile/Build with ctrl+shift+b or cmd+shift+b, then run the new exe!

