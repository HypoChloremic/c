## Declarations

### virtual



***Definition***

* Can be overridden by a sub-class



***Example***

```c#
public virtual void Start(){
    
}
```

The `Start` method can be overridden by a sub-class, that inherits from the current class. 

### public

***Definition***

* Method can be accessed by instance of the class



### protected

***Definition***

* Cn only be accessed by the class itself
* or can be accessed by the inherited class
* it cannot be accessed directly through the sub-class instance..



```c#
public class Father
{
   public virtual void A(){}
   protected virtual void B(){}
}

public class Son:Father
{
   public void C()
   {
     //Here you can access A & B method……
   }
}

Son s = new Son();
s.A();  //You can access this
s.B();  //No！You CANNOT！
```

