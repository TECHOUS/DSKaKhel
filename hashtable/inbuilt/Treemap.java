import java.util.*;
public class Treemap{
    public static void main(String[] args){
        /**
         * TreeMap sorted map
         * 
         * Methods
         * - put(key,value)
         * - putIfAbsent(key,value)
         * - get(key)
         * - getOrDefault(key,default)
         * 
         * - containsKey(key)
         * - remove(key)
         * - isEmpty()
         * - clear()
         * 
         * - descendingKeySet()
         * - keySet()
         * - firstEntry()
         * - firstKey()
         * - pollFirstEntry()
         * - pollLastEntry()
         **/
        TreeMap<Integer, String> map = new TreeMap<Integer, String>();
        map.put(10, "ten");
        map.put(3, "three");
        map.put(5, "five");
        map.put(50, "fifty");

        System.out.println(map);
        System.out.println(map.get(5));
        System.out.println(map.containsKey(10));
        System.out.println(map.containsValue("three"));
        System.out.println(map.getOrDefault(30, "hello"));
        System.out.println(map.isEmpty());

        map.putIfAbsent(30, "thirty");
        System.out.println(map);

        map.remove(5);
        System.out.println(map.descendingKeySet());
        map.pollFirstEntry();
        System.out.println(map.descendingMap());
        map.pollLastEntry();
        System.out.println(map.keySet());
        System.out.println(map.firstEntry());
        System.out.println(map.firstKey());
        
        map.clear();
        System.out.println(map);
    }   
}