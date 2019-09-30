import java.util.*;
public class RotateArray
{
    public static void main(String[] args)
    {
        Scanner in  = new Scanner(System.in);
        int arraySize = in.nextInt();
        int[] arr = new int[arraySize];
        for(int i=0;i<arr.length;i++)
        {
            arr[i] = in.nextInt();
        }
        int rotation = in.nextInt();
        arr = solve(arr,rotation);
        System.out.println(Arrays.toString(arr));
        in.close();
    }

    /**
     * this function contains the logic for rotating array to right side
     * Time Complexity: O(n*rotation)
     * Space Complexity: O(1)
     * @param arr
     * @param rotation
     * @return
     **/
    private static int[] solve(int[] arr, int rotation)
    {   
        for(int i=0;i<rotation;i++)
        {
            int temp = arr[0];
            int j = 0;
            for(j=0;j<arr.length-1;j++)
            {
                arr[j] = arr[j+1];
            }
            arr[j] = temp;
        }
        return arr;
    } 
}