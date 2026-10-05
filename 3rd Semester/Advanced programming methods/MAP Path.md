### Lab 1

Please read the lab rules and Lab 1 PDF, and make sure you have a working Git installation and IDE set up. I recommend IntelliJ IDEA Ultimate, which should be available for free through your university account.

primitive types: int, float, char, boolean
class wrappers: Integer, Float, Character, Boolean
String

Why class when we have primitive types?
- a class comes with additional things:
	- can create objects
	- comes with methods
	- we have our arguments taken as an array of strings

Objects can be null, primitives cannot be null.

```
ArrayList<Int> list=new ArrayList<>();
```

```
//package src;  
  
import java.util.ArrayList;  
  
public class MyClass {  
    public static void main(String[] args){  
        System.out.println("Hello world!");  
        for(int i=0;i<args.length;i++) {  
            //i++;  
            System.out.println(args[i]);  
        }  
            /*  
            primitive types: int, float, char, boolean            Integer, Float, Character, Boolean            String             */  
            Integer a=10; // on the heap  
            int b=a; // on the stack  
            String x="xyz";  
            Integer y=Integer.parseInt(args[1]); // returns a primitive int (from the class)  
            Float z=Float.parseFloat(args[2]); // returns a primitive float (from the class)  
            System.out.println(y+z);  
  
        // create an array of primitive type  
        int[] arr=new int[3]; // predefined space  
        arr[0]=1;  
        arr[1]=2;  
        int arr1[]={1,2,3}; // predefined space  
  
        ArrayList<Integer> list=new ArrayList<>(); // we cannot put primitive types (so no Int, but Integer)  
        list.add(100);  
        list.add(200);  
        for(int i=0; i<list.size(); i++){  
            System.out.println(list.get(i));  
        }  
          
        // for-each  
        for(Integer i:list){  
            System.out.println(i);  
        }  
    }  
}
```

### Seminar 1
Apple, Book, Cake Java app:
https://github.com/miagiurgiu/Seminar1MAP/tree/master

### Lecture 1 - 5 oct 2026
