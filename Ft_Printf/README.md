#### Like the previous project, we gonna check and learn the requirement before start coding! 

![from_subject](https://i.ibb.co/LzdVKN9P/Screenshot-from-2025-01-29-14-25-36.png)

# **Variadic Function**

### Explanation  

A **variadic function** is a function that accept **variable number of arguments**, it takes at least one fixed arguments and ellipsis (...) as the last parameter   
`return_type name (fixed_arg, ...);`  
This is useful when you don't know the exact number of arguments in advance.   
This is indicated by the parameter of the form `...`   

**Example :** `int printf (const char* format, ...);`   

## How Variadic function work 

To access the variadic arguments from the function body, you have to use the methods specified in the `stdarg` library.  
You need first to use the `<stdarg>` header, which provides macros and types for handling variable arguments.  


#### Key component :

>Ap : stand for argument pointer

+ **va_list :** Create the Variable Argument List, which holds the information needed by va_start, va_arg, va_end, and va_copy;

+ **va_start :** Enable access to variadic function argument, and initializes the **va_list** to point to the first variable arguments, following the named argument **ParmN** in :
  `void va_start (va_list Ap, ParmN);`   

+ **va_arg :** Retrieves the next argument from **va_list**. return type **T** that corresponds to the next parameter from the va_list **Ap** :
  `T va_arg (va_list Ap, T);`

+ **va_copy :** Make a copy of the variadic function arguments, the `va_copy` macro copies `src` to `dest` :
  `void va_copy (va_list dest, va_list src);`

+ **va_end :** Clean up the **va_list** after processing arguments.

### Difference between Cache memory, RAM, and Registers :

**Registers** stores the data before processing, **RAM** stores data during the process, and the **Cache Memory** stores the data after processing.

<p align="center" >
	<img src ="https://i.ibb.co/pvxZLJBR/image.png" width=450>
</p>


> Each type of process and how it's architecture is made, so there is not a standard for all the processes

___
**We gonna handle the case of the `x86_64` which used in intel and AMD processes and exactly  the`System V ABI`**   
___
### Cpu Registers


**Registers** Are small and ultra-fast storage units built inside the CPU, designed to hold temporary data, addresses or instructions.  
When you give instructions to the Cpu, it stores the instructions or data in the registers till the process is completed.  

### Types of Registers

There is a much types of registers depending on their function, the types we gonna need to understand are :  
+ **General-Purpose Registers (GPRs) :** 
+ **Floating-point Registers : **