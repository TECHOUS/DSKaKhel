import java.util.*;
public class Hashmap{
    public static void main(String[] args){
        /**
         * Java Inbuilt HashMap
         * 
         * Methods
         * - put(key,value)
         * - get(key)
         * - containsKey(key)
         * - containsValue(value)
         * - remove(key)
         * 
         * - toString()
         * - entrySet()
         * - clear()
         * - keySet()
         * - values()
         * - compute(key, bifunction)
         **/
        HashMap<String, String> map = new HashMap<String, String>();
        map.put("key", "value");
        map.put("one","two");
        map.put("three", "four");
        map.put("five", "six");

        if(map.containsKey("key")){
            System.out.println(map.get("key"));
        }
        System.out.println(map.containsValue("six"));
        map.remove("one");
        System.out.println(map.toString());
        
        map.compute("key", (key,val)-> val.concat(" Updated"));
        // traverse the map
        for(Map.Entry<String, String> entry : map.entrySet()){
            System.out.println(entry.getKey() +" "+entry.getValue());
        }
        // get only keys
        System.out.println(map.keySet());

        // get only values
        System.out.println(map.values());

        // clearing a map
        map.clear();
        System.out.println(map);
    }
}