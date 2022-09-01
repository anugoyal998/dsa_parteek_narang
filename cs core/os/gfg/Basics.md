# Basics

#### What is OS?
An operating system is a program that controls the execution of application programs and acts as an interface between the user of a computer and the computer hardware.

#### Functions of Operating system
* `Convenience:` An OS makes a computer more convenient to use.
* `Efficiency:` An OS allows the computer system resources to be used efficiently.
* `Throughput:` An OS should be constructed so that It can give maximum **throughput**.
* `Security:` The operating system uses password protection to protect user data and similar other techniques.
* `Memory Management:`
* `Processor Management:`
* `File Management:`

<img src="https://media.geeksforgeeks.org/wp-content/uploads/os.png">

#### Types of Operating Systems
* `Batch Operating System:` There is an operator which takes similar jobs having the same requirement and group them into batches.  
<img src="https://media.geeksforgeeks.org/wp-content/uploads/BatchOS.jpeg">

    * Advantages:
        * Multiple users can share the batch systems
        * very less idle time
        * easy to manage large work repeatedly in batch systems
    * Disadvantages:
        * hard to debug
        * costly
        * The other jobs will have to wait for an unknown time if any job fails
    * **Examples: Payroll System, Bank Statements**

* `Time-Sharing Operating Systems:` Each user gets the time of CPU as they use a single system. These systems are also known as Multitasking Systems. The task can be from a single user or different users also. The time that each task gets to execute is called quantum. After this time interval is over OS switches over to the next task.  
<img src="https://media.geeksforgeeks.org/wp-content/uploads/Time-Share.jpeg">
    * Advantages:
        * Each task gets an equal opportunity
        * CPU idle time can be reduced
    * Disadvantages:
        * Not reliabile
        * Insecure system
    * **Examples: Multics, Unix**

* `Distributed Operating System:` Various autonomous interconnected computers communicate with each other using a shared communication network. Independent systems possess their own memory unit and CPU. These are referred to as loosely coupled systems or distributed systems.  
<img src="https://media.geeksforgeeks.org/wp-content/uploads/Distributed.jpeg">
    * Advantages: 
        * No single point of failure
        * Load on host computer reduces
        * Scalable System
    * Disadvantages:
        * Master fails --> slaves fails
        * costly
    * **Eaxmples: LOCUS**

* `Network Operating System:` These systems run on a server and provide the capability to manage data, users, groups, security, applications, and other networking functions.  
<img src="https://media.geeksforgeeks.org/wp-content/uploads/Network-OS.jpeg">
    * Advantages:
        * remote access
        * stable systems
    * Disadvantages:
        * costly servers
    * **Eaxmples: Microsoft Windows Server 2003, Microsoft Windows Server 2008, UNIX, Linux, Mac OS X, Novell NetWare, and BSD**

* `Real-Time Operating System:` These types of OSs serve real-time systems. The time interval required to process and respond to inputs is very small. This time interval is called response time. Real-time systems are used when there are time requirements that are very strict like **missile systems, air traffic control systems, robots**, etc.  
    * Advantages:
        * Max Utilization
        * error free
        * real time updates
    * Disadvantages:
        * complex systems
        * can run limited tasks
    * **Examples: Scientific experiments, medical imaging systems, industrial control systems, weapon systems, robots, air traffic control systems, etc**

#### Difference between Multiprogramming, multitasking, multithreading and multiprocessing

* `Multiprogramming:` Multiprogramming is known as keeping multiple programs in the main memory at the same time ready for execution.
In a multi-programmed system, as soon as one job goes for an I/O task, the Operating System interrupts that job, chooses another job from the job pool (waiting queue), gives CPU to this new job and starts its execution. The previous job keeps doing its I/O operation while this new job does CPU bound tasks. Now say the second job also goes for an I/O task, the CPU chooses a third job and starts executing it. As soon as a job completes its I/O operation and comes back for CPU tasks, the CPU is allocated to it.

* `Multiprocessing:` Multiprocessing is the use of two or more CPUs (processors) within a single Computer system. 

* `Multitasking:` It refers to execution of multiple tasks (say processes, programs, threads etc.) at a time. n the modern operating systems, we are able to play MP3 music, edit documents in Microsoft Word, surf the Google Chrome all simultaneously, this is accomplished by means of multi tasking. The major way in which multitasking differs from multi programming is that multi programming works solely on the concept of context switching whereas multitasking is based on time sharing alongside the concept of context switching. **Here also basically a context switch is occurring but it is occurring so fast that the user is able to interact with each program separately while it is running. This way, the user is given the illusion that multiple processes/ tasks are executing simultaneously. But actually only one process/ task is executing at a particular instant of time. In multitasking, time sharing is best manifested because each running process takes only a fair quantum of the CPU time.**  
* `Multithreading:` Multi threading is an execution model that allows a single process to have multiple code segments (i.e., threads) running concurrently within the “context” of that process.


<img src="https://media.geeksforgeeks.org/wp-content/uploads/ram.png">

#### 32 bit and 64 bit computers
A **32-bit** system can access **2^32** different memory addresses, i.e **4 GB** of RAM or physical memory ideally, it can access more than 4 GB of RAM also. 
A **64-bit** system can access **2^64** different memory addresses, i.e actually **18-Quintillion bytes or 17,179,869,184 GB (16 exabytes)** of RAM. In short, any amount of memory greater than 4 GB can be easily handled by it.

#### What happens when we turn on computer?  
<img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/20201016104502/12331.png">

##### Funtions of BIOS

* `POST (Power On Self Test):` The Power On Self Test happens each time you turn your computer on.  
    * It initializes the various hardware devices. 
    * It is an important process to ensure that all the devices operate smoothly without any conflicts.
    * If there is no problem with this then POST continues to check other devices.
    * If some errors are found then an error message is displayed on the screen or a number of beeps are heard. 
    * These beeps are known as POST beep codes.

* `Master Boot Record:` The Master Boot Record (MBR) is a small program that starts when the computer is booting, in order to find the operating system (eg. Windows XP). This complicated process (called the Boot Process) starts with the POST (Power On Self Test) and ends when the Bios searches for the MBR on the Hard Drive, which is generally located in the first sector, first head, first cylinder (cylinder 0, head 0, sector 1). 

* `Init:` init is the last step of the kernel boot sequence. It is used to determine the initial run level of the system.

#### UEFI(Unified Extensible Firmware Interface) and how is it different from BIOS
UEFI replaces BIOS(Basic Input Output System).  
**Booting Process With UEFI :** Unlike BIOS, UEFI doesn’t look for the MBR in the first sector of the Boot Device. It maintains a list of valid boot volumes called EFI Service Partitions. During the POST procedure, the UEFI firmware scans all of the bootable storage devices that are connected to the system for a valid GUID Partition Table (GPT), which is an improvement over MBR. Unlike the MBR, GPT doesn’t contain a Boot-Loader. The firmware itself scans the GPT to find an EFI Service Partition to boot from, and directly loads the OS from the right partition. If it fails to find one, it goes back to the BIOS-type Booting process called ‘Legacy Boot’. 

