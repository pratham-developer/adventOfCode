package day2;

import java.io.BufferedReader;
import java.io.FileReader;

class q2 {
    public static void main(String[] args) {
        try {
            // READING THE INPUT FILE
            BufferedReader reader = new BufferedReader(new FileReader("day2/input.txt"));
            String temp;
            int count = 0;//COUNT VARIABLE
            while ((temp = reader.readLine()) != null) {
                String[] nums = temp.split(" ");
                if(isValid(nums)){//IF VALID, INCREMENT COUNT
                    count++;
                } else { 
                    //IF INVALID, GET A MODIFIED ARRAY BY REMOVING EACH ELEMENT ONCE USING A LOOP
                    //IF ANYTIME, THE MODIFIED ARRAY BECOMES VALID, INCREMENT COUNT, BREAK THE LOOP
                    String[] modded = new String[nums.length - 1];
                    for (int i = 0; i < nums.length; i++) {
                        modifiedArray(nums, modded, i);
                        if (isValid(modded)) {
                            count++;
                            break;
                        }
                    }
                }
            }
            System.out.println(count);//PRINTING THE FINAL COUNT
            reader.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    static boolean isValid(String[] nums){
        int i = 1;
        while(i<nums.length-1){
            int n1 = Integer.parseInt(nums[i-1]);//VALUE AT i-1
            int n2 = Integer.parseInt(nums[i]);//VALUE at i
            int n3 = Integer.parseInt(nums[i+1]);//VALUE at i+1
            int d1 = n2-n1;//diff1
            int d2 = n3-n2;//diff2
            boolean check = !((d1>0)^(d2>0));//xnor of (d1>0) & (d2>0)
            d1 = Math.abs(d1);
            d2 = Math.abs(d2);
            if(!check || (d1<1 || d1>3 || d2<1 || d2>3)){ //Valid conditions
                return false; //if invalid then return false
            }
            i++;
        }
        return true;//if loop ends then valid
    } 

    static void modifiedArray(String[] nums, String[] array, int index) {
        //FUNCTION TO GET THE MODIFIED ARRAY BY REMOVING ELEMENT AT AN INDEX
        int i = 0;
        while (i < index) {
            array[i] = nums[i];
            i++;
        }
        i++;
        while (i < nums.length) {
            array[i - 1] = nums[i];
            i++;
        }
    }

}
