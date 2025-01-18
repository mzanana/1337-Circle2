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

### File Descriptor 
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

We have **three** standard file descriptors :
+ fd = 0 : Stdin stand for Standard Input;
+ fd = 1 : Stdout stand for Standard Output;
+ fd = 2 : Stderr stand for Standard Error.

To explain them clearly we need to know what **data streams** mean :
**Data streams** are like roads that carry information "to" and "from" a computer program. You can see it as a bridge between the **user** and **the system**.