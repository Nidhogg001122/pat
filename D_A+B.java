package pat;

import java.util.*;

public class Main {
    public static void main(String [] args){
        Scanner scanner=new Scanner(System.in);
        int A= scanner.nextInt(),B= scanner.nextInt(),D= scanner.nextInt();
        int c=A+B,i=0,j=0;
        int [] result=new int[31];
        do{
            result[i++]=c%D;
            c/=D;
        }while(c!=0);
        for(j=i-1;j>=0;j--) {
            System.out.print(result[j]);
        }
    }
}
