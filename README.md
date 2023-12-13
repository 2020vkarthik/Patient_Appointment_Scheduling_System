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
1. FCFS follows a non-preemptive approach, meaning, once the CPU lets a process take control, it won’t preempt until the job terminates.
1. It follows the criteria of arrival time for the selection process.
1. The processor selects the very first job in the ready queue, and it runs till completion.
1. It supports a pre-emptive and non-preemptive scheduling algorithm.
1. All the jobs execute on a first-come, first-serve basis.
1. Smaller processes take the lead in case of a tie.
1. The general wait time is quite high because of the modus operandi that FCFS follows.
1. The algorithm is feasible to use and implement in the long run.
1. The process is not very complicated, thus easy to understand.
1. Every implementation follows the First In First Out (FIFO) ready queue.

## Benefits of FCFS Scheduling
1. The algorithm is easy to understand and implement.
1. The process is simple, thus easy to handle and comprehend.
1. FCFS is a very fair algorithm since no priority is involved- the process that comes first gets served first.
1. The implementation follows the FIFO queue for organizing the data structure- thus simplifying all the processes.
1. FCFS doesn’t lead to any starvation.
1. The scheduling is non-preemptive. Thus, no project gets paused.
1. It is the most simplified form of CPU scheduling algorithm- easy to program and operate.
1. The FCFS algorithm is better for the processes with comparatively large burst time since it involves no context switch between the processes.

## Limitations of FCFS Scheduling
1. The FCFS method is poor in performance.
1. Its general wait time gets too high due to the non-preemptive scheduling.
1. Once a process gets allocated to the CPU, it never releases the CPU until the end of execution.
1. The Convoy effect takes place since smaller processes need to wait for one large project at the front to finish off first.
1. Since it doesn’t guarantee a short response time, it may not be appropriate for interactive systems.
1. FCFS doesn’t prioritize any process or its burst time.
1. The simplicity makes FCFS very inefficient.
1. This algorithm does not comply with the time-sharing systems.
