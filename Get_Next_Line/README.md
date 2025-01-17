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

