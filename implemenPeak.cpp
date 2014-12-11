from http://stackoverflow.com/questions/4288643/how-do-i-peek-the-next-element-on-a-java-scanner/4288861#4288861

java中的Iterator类，包含了hasNext(), next(), remove()三个方法，现在需要写个新的类继承Iterator，新的类要支持peek方法


public class PeekableIterator<T> extends Iterator<T>
{
    private T next;
    public PeekableIterator<T>()
    {
      super();
      next = super.hasNext()?super.next():null;
    }

    //http://blog.csdn.net/scarecrow_ss/article/details/5957300
    public void remove()
    {
        //unsupported operation
        //next = (super.hasNext() ? super.next() : null)
    }
    
    public boolean hasNext()
    {
        return (next != null);
    }

    public T next()
    {
        T current = next;
        next = (super.hasNext() ? super.next() : null)
        return current;
    }

    public T peek()
    {
        return next;
    }
}
