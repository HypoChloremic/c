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



### attributes

These are attributes. 

* An ***attribute*** is a declarative tag that is used to convey information to runtime about the behaviors of various elements 
  * like classes, 
  * methods, 
  * structures, 
  * enumerators, 
  * assemblies etc., 
* in your program. 
* You can add declarative information to a program by using an attribute. 
* A declarative tag is depicted by square ([ ]) brackets placed ***above the element*** it is used for.
* For example, attributes could be used to indicate 
  * ***whether a class is serializable***, or 
  * *which field in a database a particular property should be written to* 
  * and so on...

For example, let's look at this attribute:

```c#
 [OperationContract(IsOneWay = true, IsInitiating = false, IsTerminating = false)]
```

The attribute is [`OperationContract`](https://msdn.microsoft.com/en-us/library/system.servicemodel.operationcontractattribute(v=vs.110).aspx). And [`IsOneWay`](https://msdn.microsoft.com/en-us/library/system.servicemodel.operationcontractattribute.isoneway(v=vs.110).aspx), [`IsInitiating`](https://msdn.microsoft.com/en-us/library/system.servicemodel.operationcontractattribute.isinitiating(v=vs.110).aspx), [`IsTerminating`](https://msdn.microsoft.com/en-us/library/system.servicemodel.operationcontractattribute.isterminating(v=vs.110).aspx) are properties of this attribute.

> **OperationContract** - Indicates that a method defines an operation that is part of a service contract in a Windows Communication Foundation (WCF) application.
> **IsOneWay** - Gets or sets a value that indicates whether an operation returns a reply message.
> **IsInitiating** - Gets or sets a value that indicates whether the method implements an operation that can initiate a session on the server (if such a session exists).
> **IsTerminating** - Gets or sets a value that indicates whether the service operation causes the server to close the session after the reply message, if any, is sent.

You can use predefined attributes or create your own custom attribute.



