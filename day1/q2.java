import java.util.*;
import java.io.*;

class q2{
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

            //COUNTING THE FREQUENCY FOR List1[i] in LIST2
            //ADDING List1[i]*frequency to the answer
            int ans = 0;
            for(int i: list1){
                int count = 0;
                for(int j:list2){
                    if(j==i){
                        count++;
                    }
                }
                ans+=i*count;
            }
            System.out.println(ans);
            reader.close();
        }catch(Exception e){
            e.printStackTrace();
        }
    }
}