class Homework9
{
    private native void print();

    public static void main(String[] args)
    {
        new Homework9().print();
    }
    static
    {
        System.loadLibrary("Homework9");
    }
}
// https://docs.oracle.com/javase/7/docs/technotes/guides/jni/spec/design.html