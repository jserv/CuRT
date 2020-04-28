CuRT : Compat Unicellular Real-Time operating system.

Features
--------
  * Preemptive Multi-threading
  * Priority-base Round-Robin Scheduling
  * Thread Management
  * Semaphore Management Support
  * IPC: mailbox, message queue


Licensing
---------
  Revised BSD License.  Please check the file LICENSE.txt for details.


Supported Hardware
------------------
  * Marvell/Intel Xscale PXA25x platforms
  * Emulated ARM PXA environment by QEMU


Building and Testing
--------------------
  * ARM Toolchain from CodeSourcery: [Sourcery G++](https://www.mentor.com/embedded-software/sourcery-tools/sourcery-codebench/editions/lite-edition/)
  * Download "arm-linux" toolchain and set up the required path.
  * Prepare QEMU as ARM system emulator (version >= 0.9.1)
  * Execute the following commands to build CuRT and sample application
    ```shell
    $ make && cd app/shell
    ```
  * Install built CuRT image into NAND flash:
    ```shell
    $ ./prepare-flash
    ```
  * Launch CuRT via QEMU:
    ```shell
    $ ./run-connex
    ```
  * Type "help" to get information from shell
    ```shell
    $ help
    ```

Internals
---------
  * Thread state:
      - RUNNING
      - READY
      - EVENT_WAIT
      - BLOCK
      - DELAY
      - TERMINATE

  * Scheduling policy
    The scheduler is called in the following two cases:
    - SCHED_TIME_EXPIRE : when thread's time_quantum value is 0.
    - SCHED_THREAD_REQUEST : Request the execution for higher priority thread.

   defined in prio_exist_flag
  ```
   		----------------------------------------------------------------
   		|0|1|0|0|0|0|0|0|0|0|1|0|0|0|0|0|0|0|0|0|1|0|0|0|0|0|0|0|0|0|0|1|
   		----------------------------------------------------------------
      		|                 |                   |                     |
      		|                 |                   |                     |
  		ready_list[1]     ready_list[11]    ready_list[21]         ready_list[31]
                                                                        |
                                                                    Idle thread
```
