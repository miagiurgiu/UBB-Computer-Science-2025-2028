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
- checked = compile-time -> compiler 
- unchecked = run-time -> compiler does not force me to handle them

Exceptions:
![[Pasted image 20261010153409.png]]
![[IMG_2412.heic]]

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
*Live notes*:

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
- Groovy
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
- XML configuration
- build time might get longer on larger projects => you know it's the time to switch to gradle
```
mvm compile
mvn package
mvn test
mvn clean
mvn install
```

4) Dependency = external library needed for a program to compile/run
- transitive dependencies = dependency depending on other libraries
- version conflict
- usually the bigger version unless there are breaking changes

5) Version control
- see git diagram
- the build folder should not be on git -> gitignore
- gradlew file should be on git

*After notes:*
Build tool=
- source code + dependencies => runnable, deployable artifact
Artifact=
- BUILD artifacts = files created during compilation/building
- SOURCE CODE = .py, .js, .java
Deploy=
- make the code accessible to the world
- ex: push to GitHub (to remote)
Build pipeline=
- when to take someone else's code from remote and you want to run it on your own computer
- you make a series of steps 
- resolve dependencies = set up properly
Version control=
- tracks changes over time
- collaboration
- combine/compare/revert
- ! never contain build/ or target/ directories
Git=
- free, open-source, distributed VCS

Gradle vs Maven

|                    | Gradle                           | Maven                    |
| ------------------ | -------------------------------- | ------------------------ |
| Configuration file | build.gradle (Groovy/Kotlin DSL) | pom.xml (XML)            |
| *!Model*           | Flexible                         | Rigid                    |
| Style              | Configurable                     | Convention               |
| Speed              | Faster on large projects         | Slower on large projects |
| Usage              |                                  |                          |
| Output dir         | build/                           | target/                  |
| Extra files        | yes (settings.gradle)            | no                       |
| Code dir           | src/main/java                    |                          |
| Non-code dir       | src/main/resources               |                          |
*!MODEL means order in which the operations run: 
- in MAVEN, the order if FIXED (linear): validate->compile->test->package->verify->install->deploy
	- ex: if you run the test phase, it will run every phase before it
	- this makes it rigid
- in GRADLE, the order is FLEXIBLE (DAG)
	- builds a graph of the tasks
	- you can skip steps
	- this makes it flexible

Gradle commands:
- gradlew 
![[Pasted image 20261010141315.png|608]]

Maven commands:
- mvn
![[Pasted image 20261010141521.png|612]]

Git:
- init: normal folder -> git project
- status: what's going on rn
- add: changed file -> waiting room (“I want this change in my next save.”)
- commit: saves everything from waiting room 
- push: my commits -> server
- fetch: get what's new on the server without touching my files 
- pull: fetch + merge = get what's new on the server + add to my current branch
- checkout: switch to another branch
- merge/rebase:
	- merge - combines two branches (non-destructive)
	- rebase - puts the commits on my branch on top of the other branch (risky)
	- never rebase a branch others work from
- gitignore: build/ (gradle's generated output dir), target/ (maven's generated output dir), "*.iml" (IDE-specific for intelliJ), "*.class" (compiled Java bytecode file) 
![[Pasted image 20261010141650.png|609]]

Git commands:
- git
![[Pasted image 20261010141853.png|610]]

![[Pasted image 20261010142013.png|607]]



### A1 - WHAT I LEARNED:
- interface fields are 'public static final' by default, so you will never encounter 'String name' or 'int age' inside an interface
- getters/setters should be in the interface and the classes that implement that interface should override those getters/setters -> because you will work with the interface Tree in Repo/Controller, not with AppleTree/PearTree etc.
- getAll() method from memory repository with static list returns a COPY of the original list (we manually get a copy of the original list using 'System.arraycopy())'
- = new Scanner(System.in) for reading from keyboard
- print instead of println if i want no endl after the printed thing
