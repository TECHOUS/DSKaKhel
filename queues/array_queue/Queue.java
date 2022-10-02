import java.util.Scanner;
class ArrayQueue
{
    Scanner sn = new Scanner(System.in);
    int front=-1,rear=-1,len;
    int arr[];
    public ArrayQueue(int size)
    {
        arr=new int[size];
        len=size;
    }
    void insert()
    {
        System.out.println("Enter the element to be pushed");
        int value=sn.nextInt();
        if(rear==len-1)
        {
            System.out.println("Queue Overflow");
        }
        else
        {
            rear++;
            if(front==-1)front++;
            arr[rear]=value;
            System.out.println("Data pushed successfully");
        }
    }
    void delete() {
        if (front == -1) {
            System.out.println("Queue Underflow");
        }
        else {
           front--;
           if (rear==0)rear--;
            System.out.println("Value deleted successfully");
        }
    }
    void display()
    {
        if(front==-1) System.out.println("Queue is Empty");
        else
        {
            for(int i=front;i<=rear;i++){
                System.out.print(arr[i]+"\t");
            }
        }
        System.out.println();
    }
}

public class Queue {
    public static void main(String[] args) {
        Scanner sn = new Scanner(System.in);
        System.out.println("Enter the sixe for array");
        int size = sn.nextInt();
        ArrayQueue qtb = new ArrayQueue(size);
        int k = 1;
        while (k == 1) {
            System.out.println("Press 1 for insertion");
            System.out.println("Press 2 for deletion");
            System.out.println("Press 3 for display");
            int choice = sn.nextInt();
            switch (choice) {
                case 1:
                    qtb.insert();
                    break;
                case 2:
                    qtb.delete();
                    break;
                case 3:
                    qtb.display();
                    break;
                default:
                    System.out.println("Please enter a valid value");

            }
            System.out.println("Press 1 to continue or 0 to exit");
            k = sn.nextInt();
        }
    }
}
