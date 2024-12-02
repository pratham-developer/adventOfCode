import java.util.*;
import java.io.*;

class q1{
    public static void main(String[] args) {
        try{
            //READING THE INPUT FILE
            BufferedReader reader = new BufferedReader(new FileReader("input.txt"));
            String temp;

            //STORING THE INPUT THE TWO LISTS
            ArrayList<Integer> list1 = new ArrayList<Integer>();
            ArrayList<Integer> list2 = new ArrayList<Integer>();
            while((temp=reader.readLine())!=null){
                String[] arr = temp.split("   ");
                list1.add(Integer.parseInt(arr[0]));
                list2.add(Integer.parseInt(arr[1]));
            }

            //SORTING THE TWO LISTS
            Collections.sort(list1);
            Collections.sort(list2);
            int ans=0;

            //ADDING THE ABSOLUTE DIFFERENCE IN List1[i] & List2[j] TO THE ANSWER
            for(int i=0;i<list1.size();i++){
                ans+=Math.abs(list1.get(i)-list2.get(i));
            }
            System.out.println(ans);
            reader.close();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}