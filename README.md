
* * *


 # Description:

 Philosophers is a project at 42school, that is an instruction to the concept of multithreading. The project is a concept where a number of Philosophers dine at a table and each Philosopher has a fork on ether side of him. He must pick up two forks to eat but so does the Philosopher next to him so the forks must be protected by mutex locks. Once the Philosopher has two forks he then spends a certain amount of time eating (a time predetermined by the #2 arg) then he spends a certain amount of time sleeping (predetermined by the #3 arg) and then the rest of the time thinking. A number of times the Philosophers must eat may be passed but is optional.




 # Instructions:

 ### Compilation Instructions:

 `make `  or `make all`  Compile whole project.

 `make re `        Recompile whole project.

 `make fclean `        Remove all obj files (obj directory) and executable.

 `make clean `        Remove only all obj files (and obj directory).

 ### \- Philosophers Use Instructions:

 (If **Not** Compiled see above instructions to compile first.)

 Run `./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [<number_of_times_each_philosopher_must_eat>]`        in cli to start/execute The Philosophers simulation.






 # Resources:

 ##### Ai:

Ai was used to Help understand some concepts of the project like understanding what data must be mutex protected and what data does not require mutexes. Ai was also used to diagnose an issue where memory was being freed before all the threads were rejoined. In that case the chatgpt was given a printf debug lock and helped determine the issue after the (tactic of staring at the code till I find the bug was exhausted!!!).

 ##### Other resources used:

 \- [Youtube "Short introduction to threads (pthreads)"](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)

 \- [Philosophers Visualizer "By rom98759"](https://rom98759.github.io/Philosophers-visualizer/)

 \- [Youtube "The Dining Philosophers Problem"](https://www.youtube.com/watch?v=FYUi-u7UWgw)

 \- [Wikipedia "Deadlock"](https://en.wikipedia.org/wiki/Deadlock)

 \- [Wikipedia "Race Condition"](https://en.wikipedia.org/wiki/Race_condition)

