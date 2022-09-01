# System Structure

#### Kernel in Operating Systems
Kernel is the core part of an operating system that manages system resources. It also acts as a bridge between the application and hardware of the computer. It is one of the first programs loaded on start-up (after the Bootloader).  
<img src="https://media.geeksforgeeks.org/wp-content/uploads/kernel.jpeg">

<img src="https://media.geeksforgeeks.org/wp-content/uploads/box-2-1.jpg">

#### Microkernel
In a microkernel, the user services and kernel services are implemented in different address spaces. The user services are kept in user address space, and kernel services are kept under kernel address space, thus also reduces the size of kernel and size of an operating system as well.  
In Microkernel Architecture, only the most important services are inside the kernel and the rest of the OS services are present inside the system application program.

#### Monolithic Kernel
In a Monolithic Kernel, the user services and kernel services are implemented in same address spaces. It increases the size of the kernel, thus increases the size of the operating system as well. If any service fails the entire system crashes, and it is one of the drawbacks of this kernel.

* Advantages:
    * it provides CPU scheduling, memory management, file management, and other operating system functions through system calls.    
    * single large process running entirely in a single address space.
    * It is a single static binary file. Examples of some Monolithic Kernel-based OSs are Unix, Linux, Open VMS, XTS-400, z/TPF.
* Disadvantages:
    * single point of failure
    * hard to extend

<img src="https://media.geeksforgeeks.org/wp-content/uploads/Difference.jpeg">


#### System Calls
System calls is a way for programs to interact with the operating system.  
`Services Provided by System Calls :`
* Process creation and management
* Main memory management
* File Access, Directory and File system management
* Device handling(I/O)
* Protection
* Networking  

`Types of System Calls:` There are five types of system calls  
* `Process control:` end, abort, create, terminate, allocate and free memory.
* `File management:` create, open, close, delete, read file etc.
* Device management
* Information maintenance
* Communication

<img src="https://media.geeksforgeeks.org/wp-content/uploads/dual_mode.jpeg">
<p align="center">Switching b/w User Mode and Kernel Mode</p>

#### Privileged and Non-Privileged Instructions in Operating System

* `Privileged Instructions:` The Instructions that can run only in Kernel Mode are called Privileged Instructions.  
* `Non-Privileged Instructions:` The Instructions that can run only in User Mode are called Non-Privileged Instructions.


