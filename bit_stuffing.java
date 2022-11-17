import java.util.*;
public class bit_stuffing
{
    public static void main(String[] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the message:-");
        String d1 = sc.nextLine();
        String remaining = new String();
        String output=new String();
        int counter = 0;
        for(int i=0;i<d1.length();i++)
        {
            //check for valid input
            if (d1.charAt(i)!='1' && d1.charAt(i)!='0')
            {
                System.out.println("Enter valid Binary values");
                return;
            }
            //count the number of 1's
            if(d1.charAt(i) == '1')
            {
                counter++;
                remaining = remaining + d1.charAt(i);
            }
            else
            {
                remaining = remaining + d1.charAt(i);
                counter = 0;
            }
            //test case if counter exceeds five 1's add 0 to it and then proceed to adding the remaining strings
            if(counter == 5)
            {
                remaining = remaining + '0';
                counter = 0;
            }
        }
        //add the flag at the starting amd ending of the string
        System.out.println("Flag--> 01111110");
        String new1="|01111110 | "+remaining+" | 01111110|";
        System.out.println("Stuffed data at intermediate site is:");

        for(int k=0;k<=(28+d1.length());k++)
        {
            System.out.print("-");
        }
        System.out.println();
        System.out.println(" "+new1);
        for(int k=0;k<=(28+d1.length());k++)
        {
            System.out.print("-");
        }
        System.out.println();
        counter=0;
        for(int i=0;i<remaining.length();i++)
        {

            if(remaining.charAt(i) == '1')
            {

                counter++;
                output = output + remaining.charAt(i);

            }
            else
            {
                output = output + remaining.charAt(i);
                counter = 0;
            }
            if(counter == 5)
            {
                if((i+2)!=remaining.length())
                {
                    output = output + remaining.charAt(i+2);
                }
                else
                {
                    output=output + '1';
                }
                i=i+2;
                counter = 1;
            }
        }
        System.out.println("Destuffed BIT is: "+output);
    }
}
