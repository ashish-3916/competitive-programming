import java.util.*;


// interface abstraction ecapsulation interitance polymorphism
class Emp {
    static String manager; // variable  is static for all the objects of the class

    static { // to initilaise static variables better declare under this then declaring in constructor
        manager = "sanchit";
        System.out.println("this is static");
    }

    int id, salary;

    Emp() {
    }

    Emp(int x, int y, String s) {
        id = x;
        salary = y;
        manager = s;
        System.out.println("this is constructor");
    }

    void print() {
        System.out.println(id + " " + salary + " " + manager);
    }

    static class Inner1 {
        public void print() {
            System.out.println("inner class 1");
        }
    }

    class Inner {
        public void print() {
            System.out.println("inner class");
        }
    }
}

//---------------------------------------------------------------------------------------------------------------------------------------------
class Add {
    public int add(int... i) {
        int ans = 0;
        for (int j : i) ans += j;
        return ans;
    }
}

//----------------------------------------------------INHERITANCE-----------------------------------------------------------------------------------------
class Calculator { // super /parent/ base
    public Calculator() {
        System.out.println("this is Grandparent");
    }

    public Calculator(int param) {
        System.out.println("this is Grandparent with param");
    }

    public int add(int x, int y) {
        return x + y;
    }
}

class CalAdv extends Calculator { // sub / child / derieved
    public CalAdv() {
        System.out.println("this is parent");
    }

    public CalAdv(int param) {
        super();
        System.out.println("this is parent with param");
    }

    public int sub(int x, int y) {
        return x - y;
    }
}

class CalVeryAdv extends CalAdv {
    public CalVeryAdv() {
        super();  // it there by default in every constructor
        System.out.println("this is child");
    }

    public CalVeryAdv(int param) {
        super(param); // but we can modify the type of constructor we want for the parent
        System.out.println("this is child with param");
    }

    public int multi(int x, int y) {
        return x * y;
    }
}

//--------------------------------------------------------- ENCAPSULATION ------------------------------------------------------------------------------------
// used to bind the variables to the methods
// can be used to check if passwords are correct or not, check if user is logged in or not.
class Student {
    private int rollNo;
    private String name;

    // public getter and setters to get and set the variables
    public int getRollNo() {
        return rollNo;
    }

    public void setRollNo(int r) {
        rollNo = r;
    }

    public String getName() {
        return name;
    }

    public void setName(String s) {
        name = s;
    }
}

// // ----------------------------------------- THREADS ----------------------------------------------------
class Hi extends Thread {
    public void run() {
        for (int i = 1; i < 5; i++) {
            System.out.println("Hi");
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}

class Hello extends Thread {
    public void run() { // we need to have run method by default to make sure the thread works
        for (int i = 1; i < 5; i++) {
            System.out.println("Hello");
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}

// // ----------------------------------------- RUNNABLE INTERFACE ----------------------------------------------------
class Bye implements Runnable {
    public void run() { // we need to have run method by default to make sure the thread works
        for (int i = 1; i < 5; i++) {
            System.out.println("BYE");
            try {
                Thread.sleep(1000);//  Thread methods need try and catch
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}

class GoodNight implements Runnable {
    public void run() { // we need to have run method by default to make sure the thread works
        for (int i = 1; i < 5; i++) {
            System.out.println("GoodNight");
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}
class Comp implements Comparator<Integer> {
    public int compare(Integer a, Integer b) {
        return a % 2 > b % 2 ? 1 : -1;
    }
}

public class Main {
    static int i = 1; // we can only access static variable in static method

    public static void main(String[] args) {
// // ----------------------------------------- DATA STRUCTURES  ----------------------------------------------------
//        int a1[] = new int[4];
//        a1[3] = 1;
//
//        int a2[][] = new int[4][]; // jagged arrays
//        a2[0] = new int[5];
//        a2[1] = new int[11];
//
//        ArrayList<Integer> a3 = new ArrayList<>();
//        a3.add(2);
//        a3.add(22);
//        a3.add(222);
//        for (int i : a3) System.out.println(i);
//        System.out.println(a3.get(0)); // not a3[0]
//        a3.set(2, 90); // not a3[2] = 90 ;
//        a3.remove(0);
//        for (int i : a3) System.out.println(i);


//        Stack<Integer> s1 = new Stack<>();
//        s1.push(10);
//        s1.push(20);
//        s1.push(30);
//        System.out.println(s1);
//        System.out.println(s1.peek());// similar to top;
//        System.out.println(s1.pop()); // removes top and also gives the top element
//        System.out.println(s1);

//         // queue  -> addLast , removeFirst , getLast , getFirst.....
//        ArrayDeque<Integer> dq = new ArrayDeque<>();
//        dq.addFirst(2);
//        dq.addLast(3);
//        dq.addFirst(1);
//        dq.addLast(4);
//        System.out.println(dq);
//        System.out.println(dq.getFirst());
//        System.out.println(dq.getLast());

        // string  are immuatable , that is we can't change
//        String s = "Hi this is me learning JAVA for the first time";
//        s += '.'; // complexity is O(N) since strings are immutable and we can't change . It created new copy.
//        s += 10000000;
//        System.out.println(s);
//        String[] parts = s.split(" ");
//        for (int i = 0; i < parts.length; i++) System.out.println(parts[i]);
//        for (int i = 0; i < s.length(); i++) System.out.print(s.charAt(i) + " ");
////        s.charAt(0) = 'a'; this wont work;
//        System.out.println(s.substring(1, 11)); // start and ending index;
//        String x = "abcd";
//        String y = new String("abcd");
//        System.out.println(x.equals(y)); // don't use x==y ?
//        System.out.println(x == y); // don't use x==y ?

        // StringBuilder -> charAt() , setCharAt()  , insert() , deleteCharAt() , append()
//        StringBuilder s = new StringBuilder("hello");

//        // HashMap
//        HashMap<String, Integer> hm = new HashMap<>();
//        hm.put("ashish", 1);
//        hm.get("ashish");
//        System.out.println(hm.get("rohit"));
//        System.out.println(hm.containsKey("ashish"));
////        hm["rohit"] = 5;
//        for (String S : hm.keySet()) {
//            System.out.println(S + " " + hm.get(S));
//        }

        // Priority Queue
//
//        PriorityQueue<Integer> pq1 = new PriorityQueue<Integer>(); // min prioiry queue
//        PriorityQueue<Integer> pq2 = new PriorityQueue<Integer>(Collections.reverseOrder()); // max prioiry queue
//        for (int i = 0; i < 10; i++) pq2.add(i);
//        while (pq2.size() > 0) {
//            System.out.println(pq2.poll());
//            // peek -> to give top , remove -> to remove top ;
//        }


// // ----------------------------------------- COLLECTIONS AND GENERICS ----------------------------------------------------
//        // collection > list > array
//        // collection doesn't have indexes;
//        Collection a1 = new ArrayList();
//        a1.add(1);
//        a1.add("ashish");
//        for (Object o : a1) System.out.println(o);
//        Collection<Integer> a2 = new ArrayList<Integer>();
//        a2.add(1);
//
//        List<Integer> a = new ArrayList<>(); // mutable (we can change the value of it)
//        for (int i = 0; i < 4; i++)
//            a.add(4 - i);
//        Collections.sort(a);
//        System.out.println(a);
//         ArrayList<Integer> arr = new ArrayList<>();
//         for (int i = 0; i < 6; i++) arr.add(i);
//         System.out.println(arr);
//         Comparator<Integer> c = new Comp();
//         Collections.sort(arr, c);
// //        Collections.sort(arr, new Comparator<Integer>() {
// //            public int compare(Integer a, Integer b) {
// //                return a % 2 > b % 2 ? 1 : 0;
// //            }
// //        });
// //      Collections.sort(arr, (a, b) -> a % 2 > b % 2 ? 1 : -1);
//         System.out.println(arr);


//        Set<Integer> b = new HashSet<>();
//        Set<Integer> c = new TreeSet<>();
//        Map<Integer, String> m1 = new HashMap<>();
//        Map<Integer, String> m2 = new TreeMap<>();
// // ----------------------------------------- RUNNABLE INTERFACE ----------------------------------------------------
//        Bye o3 = new Bye();
//        GoodNight o4 = new GoodNight();
//        Thread t1 = new Thread(o3); // link the object with thread
//        Thread t2 = new Thread(o4);
//        t1.start();
//        t2.start();
//
//        /// priority of threads
//        System.out.println(t1.getPriority());
//        System.out.println(t2.getPriority());

        // if we need to stop main to stop executring the rest of code , we need to wait for t1 and t2 to join in
//        System.out.println(t1.isAlive());
//        try {
//            t1.join();
//        } catch (InterruptedException e) {
//            throw new RuntimeException(e);
//        }
//        try {
//            t2.join();
//        } catch (InterruptedException e) {
//            throw new RuntimeException(e);
//        }
//        System.out.println(t1.isAlive());

// // ----------------------------------------- THREADS ----------------------------------------------------
        // we can create threads in 2 ways : using class extend thread , using Runnable Interface
//        Hi o1 = new Hi();
//        Hello o2 = new Hello();
//        // start thread to run them parallely
//        o1.start();
//        o2.start();
// // ----------------------------------------- EXCEPTION HANDLING ----------------------------------------------------
//        try {
//            System.out.println("before exception");
//            int i = 9 / 0; // all the critical section of the code goes here
//            System.out.println("after exception");
//        } catch (Exception e) {
//            System.err.println(e);
//        } finally {
//            System.out.println("this code runs despite of exception occurs or not");
//        }
// // ----------------------------------------- MODIFIERS ----------------------------------------------------
//       final abstract private public protected
//       we can't use private/protected keyword with class, we can use it for inner class
//       public keyword helps use the class outside the package we can't use default classes outside the package
//       Private : Specific Class
//       Default : Specific Package
//       Public : Any class or package
//       Protected : Subsiding Class
//       Abstract : we can't create object of that class
//       same goes with the variables.
// // ----------------------------------------- WRAPPER CLASSS ----------------------------------------------------
        // better use primitive types only, there are only some use case where only wrapper classes are allowed like in some framework like Hibernate
//        int i = 5; // primitive datatype
//        Integer ii = new Integer(i); // wrapper class  - boxing
//        int j = ii.intValue(); // unboxing
//        Integer x = i; // auto wrapping
//        System.out.println(i + " " + ii);
//        String s = "123";
//        int n = Integer.parseInt(s);
//        System.out.println(n);

// // ----------------------------------------- ENCAPSULATION ----------------------------------------------------
// binding data with methods
//        Student s = new Student();
//        s.setName("ashish");
//        s.setRollNo(13);
//        System.out.println(s.getName() + " " + s.getRollNo());
// // ----------------------------------------- INHERITANCE ----------------------------------------------------
//        if we make class 'final' then we can't extend that class
//        CalVeryAdv c1 = new CalVeryAdv();
//        int sum = c1.add(1, 2);
//        int diff = c1.sub(1, 2);
//        int prod = c1.multi(1, 2);
//        System.out.println(sum + " " + diff + " " + prod);
//
//        CalVeryAdv c2 = new CalVeryAdv(3);
        // we can't achieve multiple inheritance directly in classes in java , there is ambiguity if class A extends both B and C and both classes{A, B} have same methods/functions
        // child class method overrides the parent class method     @Override
// // ----------------------------------------- ARRAY DEMO ----------------------------------------------------
//        int arr[] = new int[4];
//        Scanner scanner = new Scanner(System.in);
//        for (int i = 0; i < 4; i++)
//            arr[i] = scanner.nextInt();
//        for (int i : arr)
//            System.out.print(i + " ");
//        Add obj = new Add();
//        System.out.println(obj.add(1, 2, 3, 423, 4235, 235));

// // ----------------------------------------- CLASS DEMO ----------------------------------------------------
//        System.out.println(i);
//        Emp ashish = new Emp(1, 1000, "ritik");
//        ashish.print();
//        Emp rohit = new Emp(2, 2000, "mohan");
//        ashish.print();
//        rohit.print();
//        Emp.manager = "aryan"; // we don't need objects to call static variables, we can direlty call via class
//        ashish.print();
//        rohit.print();
//        Emp.Inner obj1 = ashish.new Inner(); // nested member class
//        obj1.print();
//        Emp.Inner1 obj2 = new Emp.Inner1(); // nested static class
//        obj2.print();

        // Number i = 5;
        //        System.out.println(i);
        //        i = 5.5;
        //        System.out.println(i);
    }
}


