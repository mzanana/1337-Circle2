<h1 align="center">GetNextLine</h1>

Like we did in our last project [Born2BeRoot](https://github.com/Zanana-med/Born2BeRoot?tab=readme-ov-file), we're going into the main subject PDF, and understand all the **requirement** to pass the GetNextLine project plus the bonus of course.

# Static Variable
<p align ="center">
	<img src="https://i.ibb.co/4p7Z2tF/image.png" width = "550">
</p>

**Syntax:**
```C
static Data_Type Var_Name = Var_Value;
```

**Local variable** is destroyed and lose its value when the function that contain this variable is over. The local variable stored on the **Stack** memory area.   

**Static variable** stored on the **data segment** in the memory, it has the ability to preserve its value, even if the variable out of its function scope!  


Let's see the difference between them using the next code
```c

# include <stdio.h>

int ft_static()
{
    static int cntr = 0;
    cntr++;
    return cntr;
}

int ft_local()
{
    int cnt = 0;
    cnt++;
    return cnt;
}

int main()
{
    printf("Local Variable : %d ", ft_local());
    printf("%d\n", ft_local());
    
    printf("Satic Variable : %d ", ft_static());
    printf("%d ", ft_static());
    return 0;
}
```

The output of this code is 
```
Local Variable  : 1 1
Static Variable : 1 2
```

The static variable initialized **once** and **live** till the end of the entire program.  
Also the static variable is **initialized** by default as **0** if not specify it. The local variables initialized by garbage value.  


# File Descriptor and System Calls

## File Descriptor 

### Definition 
When a program open a file, the Operating System return a file descriptor as non-negative unique integer that the program can use to perform operations on that file, such as reading, writing or closing it.

### File Descriptor Table
Fd **table** is a data structure specific to each process.  
Each process has its own FdTable, which contain the File descriptors and a pointer to an **entry** in the **File Table**.  
**Remember :** Every process has its **own** File descriptor table!  
<p align="center">
	<img src="https://i.ibb.co/w4dKwjX/File-table-and-inode-table-svg.png" width = "250">
</p>

### File Table Entry 
*File Table Entry* also named as *Global File Table* which is shared by all the processes, so different processes can share the same entry. Each **entry** stores information about the open file which contain the **OFFSET** (Current position withing the file), **ACCESS MODE** (read, write or read-write) and a **POINTER** to the vnode (Which hold the file metadata).  
<p align ="center">
	<img src="https://i.ibb.co/fHnp3sY/file-descriptors-example.png" width="500">
</p>

### Global Inode Table

The *global inode table* hold the metadata of each file in the filesystem, it stores critical information about each file, such filename, size, permissions, timestamp and a pointer to the actual data block on the storage device.
#### GLOBAL VIEW
<p align = "center">
	<img src="https://i.ibb.co/n16N30S/FY17-UAi-VUAAe-Fr-S.jpg" width="500">
</p>

The difference between the **access mode** and the **Permissions :**
+ **Access mode :** indicate how a specific process intend to interact with an open file ( it set at the time the file is opened by the process). The access mode can vary from process to another.   
  It can be only Read or Write or both of them (R - W - RW).

+ **Permissions :** Define the access rights for a file, controlling which users and groups are allowed to read, write or both. They are set at the file system level and are generally the same for all the processes.

### Standard File Descriptors


To explain them clearly we need to know what **data streams** mean :
**Data streams** are like roads that carry information "to" and "from" a computer program. You can see it as a bridge between the **user** and the **system**.
<p align="center">
	<img src="https://i.ibb.co/98fs9Fw/hq720.jpg" width = "400">
</p>

We have **three** standard file descriptors :
+ fd = 0 : Stdin the Standard Input. 
  When the user type something with the keyboard in a terminal environment, the program use the **stdin** to read the input of the user or other data source.  
  Its the input stream for reading data typed by user or input files.
  **Redirection :** `<`
  
+ fd = 1 : Stdout the Standard Output.
  Used by a program to send the output data to the terminal display, **stdout** like a bridge from the program to the user display.
  When running a command the system displays you the results using the **stdout**.
  **Redirection :** `command` `1>` or also `>` and then the file where you want the result to be saved, `ls 1> mzanana.txt` 
   
+ fd = 2 : Stderr the Standard Error.
  Also an output stream, but for errors messages, if the output contain a lot of line and errors and we want just to read the errors clearly.
  **Rediection :** `command` `2>` `fileDest`  
For example i want to combine the stdout and stderr : `command > output.txt 2> errors.txt`  

## System Calls

### Operating System and Kernel

+ **Operating system** act as the intermediary between the user and the computer hardware.
+ **Kernel** is the core of the **OS**, its the responsible to communicate  between the applications and the hardware of the computer .
<p align="center">
	<img src="https://i.ibb.co/q9jLCZz/what-is-kernel-8.png" width="250">
</p>

>How the kernel communicate with the hardware resources ?  
Using **drivers** in machine code so the **CPU** knows the exact instructions.

>How to **communicate** with the kernel ?  
When a program need access to the hardware or any system resources it make a **System Call** to the kernel.

### System Calls Definition

**A system call** is a programmatic way in which a computer program requests a service from the kernel of the operating system it is executed on.  
A computer program makes a system call when it requests the operating system’s kernel.  
<p align="center">
	<img src="https://i.ibb.co/4YPT2ff/img.png" width="350">
</p>

### Types of System Calls

<p align="center">
	<img src="https://i.ibb.co/SJ2HCkP/image.png" width="500">
</p>

+ **Process Control :** Operations like creating and controlling processes like `fork()`, `exec()`, `exit()`, `wait()`,  etc.
+ **File Management :** functions to work with files and directories like `open()`, `read()`, `write()`, `close()`, `unlink()`, etc.

In our project **Get_Next_Line** we gonna need the **file Management** type.  

### create()
**Syntax :**  
`int create(char *filename, mode_t mode);`

The `create` function defined inside **<fcntl.h>**, used to create a new file in C specifying the name and the permissions.

**Return value :** The first unused file descriptor and `-1` when an error.  
**Example :**
```C
#include <fcntl.h>

int main() {
    const char *filename = "example.txt";

    int fd = creat(filename, 0644);
}
```

### open()
**Syntax :**
`int open (const char* Path, int flags);`
+ **Path :** Preferred to specify the exact path beginning with `/`
+ **Flags :** To specify how you want to open the file like O_RDONLY, O_WRONLY, O_RDWR, O_APPEND to place the cursos at the end of the file.
  O_CREAT to create a file if it doesn't exit, and we add the mode to specify the file permissions, so the final syntax gonna be : `int open = (const char* Path int flags | O_CREAT,  mode_t mode`  

The open system call checks the file permissions and the access flags to ensure the process has the permission to open the file in the requested mode.   

When a file is opened, the **offset** is set to the beginning of the file to be adjusted with read() and write() sys calls.

### read()
**Syntax :**
`ssize_t read (int fd, void* buf, size_t cnt)`

+ **fd :** the file descriptor of the file we wanna read from;
+ **buf :** Buffer to read data from;
+ **cnt :** Length of the buffer.

**read()** defined inside **<unistd.h>**, used to read data from a file descriptor into a buffer in memory.

**Return value :** read() return the number of bytes been read on success, `0` on reaching the end of the file or `-1` on error occurred.

**Note !!**   
The buffer should be **large enough** to hols at least `cnt` bytes of data, if the buffer size is less than `cnt`, `read()` will not read the full `cnt` bytes, it will read up to the number of bytes that the **buffer can hold.** In this case **read()** gonna return the size of buffer which is the number of bytes actually read.

### write()
**Syntax :**
`ssize_t write (int fd, void* buf, size_t cnt);`

**`write()`** to write the `cnt` bytes from a buffer `buf` in memory to the file associated with the file descriptor `fd`.  
+ **cnt** should not be greater than INT_MAX
+ **cnt = 0** write() simply return 0

**Return value :** `write()` return the number of bytes written successfully, return `0` if `cnt = 0` or reaching the End Of File or `-1` on error.

**Keys Points :**
+ The file needs to be opened for **write** operation;
+ **buf** needs to be at least as long as **cnt** to not face the overflow;
+ **cnt** is the requested number of bytes to write, while the return value is the actual number of bytes written.  
  A partial **write** may occur for reasons like :
  - Disk is full.
  - Network issues (if `fd` is a socket).
  - File system or device restrictions.

