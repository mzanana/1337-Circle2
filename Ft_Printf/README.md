#### Like the previous project, we gonna check and learn the requirement before start coding! 

![from_subject](https://i.ibb.co/LzdVKN9P/Screenshot-from-2025-01-29-14-25-36.png)

## WHAT IS **VARIADIC** ??  

A **variadic function** is a function that accept **variable number of arguments**, it takes at least one fixed arguments and ellipsis(...) as the last parameter   
`return_type name (fixed_arg, ...);`  
This is useful when you don't know the exact number of arguments in advance.   
This is indicated by the parameter of the form `...`   

**Example :** `int printf (const char* format, ...);`   

## How Variadic function work 

To access the variadic arguments from the function body, `stdarg` library helps us using types defined on it.  
You need first to use the \<stdarg> header, which provides macros and types for handling variable arguments.  

### Key component :

>Ap : stand for argument pointer

+ **va_list :** Holds the information needed by va_start, va_arg, va_end, and va_copy, a type to hold the variable arguments;

+ **va_start :** Enable access to variadic function argument, and initializes the **va_list** to point to the first variable arguments, following the named argument **ParmN** in :
  `void va_start (va_list Ap, ParmN);`   

+ **va_arg :** Retrieves the next argument from **va_list**. Expand to an expression of type **T** that corresponds to the next parameter from the va_list **Ap** :
  `T va_arg (va_list Ap, T);`

+ **va_copy :** Make a copy of the variadic function arguments, the `va_copy` macro copies `src` to `dest` :
  `void va_copy (va_list dest, va_list src);`

+ **va_end :** Clean up the **va_list** after processing arguments.
