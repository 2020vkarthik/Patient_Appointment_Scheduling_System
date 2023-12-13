# Patient_Appointment_Scheduling_System
This is based on various CPU scheduling algorithm. It provides the insight of which CPU scheduling algorithm will be best for the given
patient appointment scenario. we could see the appointment issuing order for the given patient list and their info.

# Algorithms used-
1. FCFS
1. SJF
1. Priority
1. Round Robin


# FCFS algorithm
The full form of FCFS Scheduling is First Come First Serve Scheduling.

FCFS Scheduling algorithm automatically executes the queued processes and requests in the order of their arrival. It allocates the job that first arrived in the queue to the CPU, then allocates the second one, and so on. FCFS is the simplest and easiest CPU scheduling algorithm, managed with a FIFO queue. FIFO stands for First In First Out. The FCFS scheduling algorithm places the arriving processes/jobs at the very end of the queue. So, the processes that request the CPU first get the allocation from the CPU first. As any process enters the FIFO queue, its Process Control Block (PCB) gets linked with the queue’s tail. As the CPU becomes free, the process at the very beginning gets assigned to it. Even if the CPU starts working on a longer job, many shorter ones have to wait after it. The FCFS scheduling algorithm works in most of the batches of operating systems.

## Characteristics of FCFS Scheduling
FCFS follows a non-preemptive approach, meaning, once the CPU lets a process take control, it won’t preempt until the job terminates.
It follows the criteria of arrival time for the selection process.
The processor selects the very first job in the ready queue, and it runs till completion.
It supports a pre-emptive and non-preemptive scheduling algorithm.
All the jobs execute on a first-come, first-serve basis.
Smaller processes take the lead in case of a tie.
The general wait time is quite high because of the modus operandi that FCFS follows.
The algorithm is feasible to use and implement in the long run.
The process is not very complicated, thus easy to understand.
Every implementation follows the First In First Out (FIFO) ready queue.
## Benefits of FCFS Scheduling
The algorithm is easy to understand and implement.
The process is simple, thus easy to handle and comprehend.
FCFS is a very fair algorithm since no priority is involved- the process that comes first gets served first.
The implementation follows the FIFO queue for organizing the data structure- thus simplifying all the processes.
FCFS doesn’t lead to any starvation.
The scheduling is non-preemptive. Thus, no project gets paused.
It is the most simplified form of CPU scheduling algorithm- easy to program and operate.
The FCFS algorithm is better for the processes with comparatively large burst time since it involves no context switch between the processes.
## Limitations of FCFS Scheduling
The FCFS method is poor in performance.
Its general wait time gets too high due to the non-preemptive scheduling.
Once a process gets allocated to the CPU, it never releases the CPU until the end of execution.
The Convoy effect takes place since smaller processes need to wait for one large project at the front to finish off first.
Since it doesn’t guarantee a short response time, it may not be appropriate for interactive systems.
FCFS doesn’t prioritize any process or its burst time.
The simplicity makes FCFS very inefficient.
This algorithm does not comply with the time-sharing systems.
