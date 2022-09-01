# CPU Scheduling

#### Process
A process is a program in execution.

`What does a process look like in memory?`
<img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2015/06/process.png">  

* `Text Section:` Contains the code part
* `Data Section:` Contains the global variable.
* `Heap Section:` Dynamically allocated memory to process during its run time. 
* `Stack:` The stack contains temporary data, such as function parameters, returns addresses, and local variables.  

`Characteristics of a Process`
* Process Id:    A unique identifier assigned by the operating system
* Process State: Can be ready, running, etc.
* CPU registers
* Accounts information: Amount of CPU used for process execution, time limits, execution ID etc
* I/O status information
* CPU scheduling information


#### Context Switching
The process of saving the context of one process and loading the context of another process is known as Context Switching.

##### Q. Which of the following need not necessarily be saved on a context switch between processes? (GATE-CS-2000) 
(A) General purpose registers 
(B) Translation lookaside buffer 
(C) Program counter 
(D) All of the above 

Ans: (B) Translation lookaside buffer

##### Q. The time taken to switch between user and kernel modes of execution is t1 while the time taken to switch between two processes is t2. Which of the following is TRUE? (GATE-CS-2011) 
(A) t1 > t2 
(B) t1 = t2 
(C) t1 < t2 
(D) nothing can be said about the relation between t1 and t2. 

Ans: (C) t1 < t2

#### States of Process

<img src="https://media.geeksforgeeks.org/wp-content/uploads/20190604122001/states_modified.png">

* `New (Create)` – In this step, the process is about to be created but not yet created, it is the program which is present in secondary memory that will be picked up by OS to create the process.
* `Ready – New` -> Ready to run. After the creation of a process, the process enters the ready state i.e. the process is loaded into the main memory. The process here is ready to run and is waiting to get the CPU time for its execution. Processes that are ready for execution by the CPU are maintained in a queue for ready processes.
* `Run` – The process is chosen by CPU for execution and the instructions within the process are executed by any one of the available CPU cores.
* `Blocked or wait` – Whenever the process requests access to I/O or needs input from the user or needs access to a critical region(the lock for which is already acquired) it enters the blocked or wait state.
* `Terminated or completed` – Process is killed as well as PCB is deleted.
* `Suspend ready` – Process that was initially in the ready state but was swapped out of main memory(refer Virtual Memory topic) and placed onto external storage by scheduler is said to be in suspend ready state. The process will transition back to ready state whenever the process is again brought onto the main memory.
* `Suspend wait or suspend blocked` – Similar to suspend ready but uses the process which was performing I/O operation and lack of main memory caused them to move to secondary memory. When work is finished it may go to suspend ready.


#### Process Table and Process Control Block (PCB)
A process control block (PCB) contains information about the process, i.e. registers, quantum, priority, etc. The process table is an array of PCB’s, that means logically contains a PCB for all of the current processes in the system.  
<img src="https://media.geeksforgeeks.org/wp-content/uploads/process-table.jpg">

#### Process Scheduler
* `Long Term or job scheduler:` It brings the new process to the **‘Ready State’**. It controls **Degree of Multi-programming**, i.e., number of process present in ready state at any point of time.
* `Short term or CPU scheduler:` It is responsible for selecting one process from ready state for scheduling it on the running state. The **CPU scheduler** is responsible for ensuring there is no **starvation** owing to high burst time processes. **Dispatcher** is responsible for loading the process selected by Short-term scheduler on the CPU (Ready to Running State) Context switching is done by dispatcher only.
* `Medium-term scheduler:` It is responsible for suspending and resuming the process. It mainly does swapping (moving processes from main memory to disk and vice versa).

#### CPU Scheduling
CPU scheduling is the process of deciding which process will own the CPU to use while another process is suspended.

##### Terminoliges In CPU Scheduling 
* `Arrival Time(AT):` Time at which the process arrives in the ready queue.
* `Completion Time(CT):` Time at which process completes its execution.
* `Burst Time(BT):` Time required by a process for CPU execution.
* `Turn Around Time(TAT):` CT - AT
* `Waiting Time(WT):` TAT - BT

<img src="https://media.geeksforgeeks.org/wp-content/uploads/20220525174157/UntitledDiagram12.jpg">  
<p align="center">Different types of CPU Scheduling Algorithms</p>

#### CPU Scheduling Algorithms
* `First Come First Serve:` First come first serve scheduling algorithm states that the process that requests the CPU first is allocated the CPU first and is implemented by using **FIFO queue**.  

    * **Characteristics:**
        * FCFS supports non-preemptive and preemptive CPU scheduling algorithms.
        * FCFS is easy to implement and use.
        * This algorithm is not much efficient in performance, and the wait time is quite high.
    * **Advantages:**
        * Easy to implement
        * FIFO
    * **Disadvantages:**
        * FCFS suffers from Convoy effect.
        * High Avg Waiting Time.

<img src="https://media.geeksforgeeks.org/wp-content/uploads/os1.png">  
<img src="https://media.geeksforgeeks.org/wp-content/uploads/ghant-chart.png">  

* `Shortest Job First(SJF):` Shortest job first (SJF) is a scheduling process that selects the waiting process with the smallest execution time to execute next. Smalless Execution Time is not known it is estimated.
<img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/20200303163658/SJF.jpg">  
    * **Characteristics:**
        * Shortest Job first has the advantage of having a minimum average waiting time among all operating system scheduling algorithms.
        * It may cause starvation if shorter processes keep coming. This problem can be solved using the concept of ageing.
    * **Advantages:**
        * reduces avg waiting time.
        * SJF is generally used for long term scheduling.
    * **Disadvantages:**
        * Process Starvation

* `Longest Job First(LJF):` Longest Job First(LJF) scheduling process is just opposite of shortest job first (SJF), as the name suggests this algorithm is based upon the fact that the process with the largest burst time is processed first.
    * **Characteristics:**
        * CPU is always assigned to the process having largest burst time
        * If two processes have the same burst time then the tie is broken using FCFS 
        * LJF CPU Scheduling can be of both preemptive and non-preemptive types.
        

