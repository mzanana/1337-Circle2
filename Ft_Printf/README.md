#### Like the previous project, we gonna check and learn the requirement before start coding! 

![from_subject](https://i.ibb.co/LzdVKN9P/Screenshot-from-2025-01-29-14-25-36.png)

## WHAT IS **VARIADIC** ??  

A **variadic function** is a function that accept **variable number of arguments**.  
This is useful when you don't know the exact number of arguments in advance.  

## How Variadic function work 

You need first to use the \<stdarg> header, which provides macros and types for handling variable arguments.  

### Key component :

+ **va_list :** Type to hold the variable arguments.  
+ **va_start :** Initializes the **va_list** to point to the first variable arguments
