<h1 align="center">Ft_Printf</h1>

### Like the previous project, we gonna check and learn the requirement before start coding! 

![from_subject](https://i.ibb.co/LzdVKN9P/Screenshot-from-2025-01-29-14-25-36.png)

# **Variadic Function**

### Explanation  

A **variadic function** is a function that accept **variable number of arguments**, it takes at least one fixed arguments and ellipsis (...) as the last parameter   
`return_type name (fixed_arg, ...);`  
This is useful when you don't know the exact number of arguments in advance.   
This is indicated by the parameter of the form `...`   

**Example :** `int printf (const char* format, ...);`   


### Difference between Cache memory, RAM, and Registers :

**Registers** stores the data before processing, **RAM** stores data during the process, and the **Cache Memory** stores the data after processing.

<p align="center" >
	<img src ="https://i.ibb.co/pvxZLJBR/image.png" width=450>
</p>

___
**Each type of process and how it's architecture is made, so there is not a standard for all the processes**
___


### Cpu Registers

**Registers** Are small and ultra-fast storage units built inside the CPU, designed to hold temporary data, addresses or instructions.  
When you give instructions to the Cpu, it stores the instructions or data in the registers till the process is completed.  

> We gonna handle the case of the `x86_64` which used in intel and AMD processes and exactly  the`System V ABI   

### Types of Registers

There is a much types of registers depending on their function, the types we gonna need to understand are :  
+ **General-Purpose Registers (GPRs) :** The maximum of arguments can be stored on the gp register is **6 Arguments** (RDI, RSI, RDX, RCX, R8, R9). The gp Registers temporarily store data values like integers, And they are 64 bits wide, meaning they can hold values between 0 and 2^64-1. They hold function parameters passed to functions.  

+ **Floating-point Registers :** The maximum number of arguments that can be stores on the fp register is **8 Arguments** (`XMM0`–`XMM7`). Those registers are part of the SSE which provides single instuctionm multiple data, These registers are used for floating point arithmetic as addition, multiplication, and comparison.  

## How Variadic function work 

To access the variadic arguments from the function body, you have to use the methods specified in the `stdarg` library.  
You need first to use the `<stdarg.h>` header, which provides macros and types for handling variable arguments.  
#### Key component :

>Ap : stand for argument pointer

### **va_list :** 
The `va_list` create the Variable Argument List, which holds the information needed by va_start, va_arg, va_end, and va_copy. it's actually a **struct** that tracks where the next argument is.  
The arguments are stored on the stack after the registers are full, so the va_list just track the places of the arguments not store the arguments inside it.  