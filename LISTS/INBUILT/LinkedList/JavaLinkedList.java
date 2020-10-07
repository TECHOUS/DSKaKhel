import java.util.Iterator;
import java.util.LinkedList; 

public class JavaLinkedList{

     public static void main(String []args){
        LinkedList list = new LinkedList();
        list.add(2);
        list.add(6);
        list.add(3);
        list.add(4);
        
        System.out.println("Traverse Linked List");
        Iterator itr= list.iterator();
        while(itr.hasNext())
            System.out.println(itr.next());
        list.sort(null);
        
        System.out.println("Sorted Linked List");
        itr= list.iterator();
        while(itr.hasNext())
            System.out.println(itr.next());
     }
}
