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

### Lab 2 - 6 oct 2026
- in memory-repository is allowed (not persistence yet)
- controller does not hold the repo, repo it is rather a parameter in controller
- view - scanner
- he will ask me to add more stuff to repo
- checked custom exceptions, different packages
- on the Seminar model
- divaC mode? to see how variables get changed
- try-catch in view -> continue to get input from user (don't put try catch pe tot switch-ul respectiv)

A1:
6. Intr-o livada cresc meri, peri si ciresi. Sa se afiseze toti pomii frunctiferi mai batrini de 3 ani.

! everything is checked exception apart from runtimeException (which is unchecked)
- checked is better - it will scream for help
- unckecked - compiler does not say anything
- runtime exceptions - usually for situations when the app should stop
- checked = compile-time
- unchecked = run-time

The photo of the exceptions

Example
- order exceptions from most specific to most generic
```
try{
	int result=10/0;
} catch (Exception e) {
	...
} catch (ArithmeticException e){
	...
} finally {
	// gets executed no matter what
	// ex: how many attempts to fill a field (elev, 2000 ori)
}
```


## Seminar 2 - 7 oct 2026
Build tools, versions
1) exceptions
- does not matter where i treat exceptions (controller maybe)
1) Build tools=transform source code into a runnable, deployable artifact
A face "deploy"
2) Version control systems=track code
piratat chestii - minecraft - that new suggested version of java is actually JRE
eliminat reclame yt
3) Gradle, Maven
gradle: more flexible, configurable, we can write code in it
gradle wrapper=a filter that make sure everything works fine with gradle
these commands with gradlew are incorporated in intelliJ:
```
./gradlew build
./gradelw assemble
./gradlew test
./gradlew clean

clean->build/assemble->test->bootJar
```

maven: more strict, for newer projects, values convention, enterprises
```
mvm compile
mvn package
mvn test
mvn clean
mvn install
```