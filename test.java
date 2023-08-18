class TestExtends {
    public static void main(String[] args) {
    }
}
 
class Father{
    private int a = 3;
    double d = 3.0;
    Father() {}
    Father(int a) {
        this.a = a;
    }
    void show() {
        System.out.println(a + "\t" + d);
    }
    static int c = 5;
    
}
 
// class Son extends Father {
//     int s = 10;
//     void show() {
//         super.show();
//     }
//     static void stashow(final Son s) {
//         s.s = 20;
//     }
//     public static void main(String[] args) {
//         Son s = new Son();
//         stashow(s);
//         System.out.println(s.s);
//     }
// }
class A {
    static int a = 10;
    static {
        System.out.println("A class is initiated");
    }
    A() {};
}

class Main {
    public static void main(String[] args) {
        int[] a = new int[2];
        System.out.println(a.length);
        A a1 = new A();
        A a2 = new A();
    }
}