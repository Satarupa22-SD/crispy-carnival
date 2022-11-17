/**
 * 6. Write a computer program that encode a dataword into a codeword and decode a codeword to determine whether the codeword is in error for checksum.
 * Created by Satarupa Deb Btech/6011/20
 * CheckSum.java
 */
import java.util.Scanner;
public class CheckSum
{
    public static void main(String[] args)
    {
        System.out.println("---------- Checksum ----------");

        System.out.println("ENCODE");
        Scanner sc = new Scanner(System.in);
        System.out.println("Dataword: ");
        System.out.print("Please enter length of each segment: ");
        int length = sc.nextInt();
        String temp = sc.nextLine();
        System.out.print("Segment 1: ");
        String seg1 = sc.nextLine();
        if(seg1.length() != length)
        {
            System.out.println("Wrong length!! Please try again");
            System.exit(0);
        }
        System.out.print("Segment 2: ");
        String seg2 = sc.nextLine();
        if(seg1.length() != length)
        {
            System.out.println("Wrong length!! Please try again");
            System.out.println("Both Segments have to have the same legnth.");
            System.exit(0);
        }

        DataWord segment1 = new DataWord(seg1);
        DataWord segment2 = new DataWord(seg2);

        String checkSum = encode(segment1,segment2);
        System.out.println("Codeword: " + segment1.getData() + " " + segment2.getData() + " " + checkSum);
        System.out.println();

        System.out.println("DECODE");
        System.out.print("Received Codeword (input received checksum): " + segment1.getData() + " " +segment2.getData() + " ");
        String ReCheckSum = sc.nextLine();
        decode(segment1,segment2,ReCheckSum);
    }


    public static String encode(DataWord seg1,DataWord seg2)
    {
        int summation,sumwrap;
        int s[] = new int[1000];
        int w[] = new int[1000];
        String sum = "";
        String wrap = "";
        String checkSum = "";
        String temp1 = "";
        String temp2 = "";
        int segment1 = Integer.parseInt(seg1.getData(), 2);
        int segment2 = Integer.parseInt(seg2.getData(), 2);
        summation = segment1+segment2;
        int i = 0;
        while (summation > 0)
        {
            s[i] = summation%2;
            summation = summation/2;
            i++;
        }
        for(int j = i-1 ; j >= 0 ; j--)
        {
            sum += Integer.toString(s[j]);
        }
        System.out.println("Sum: " + sum);

        if(sum.length() > seg1.getLength())
        {
            for(int j = 0 ; j < sum.length()-seg1.getLength() ; j++)
            {
                temp1 += sum.charAt(j);
            }
            for(int k = sum.length()-seg1.getLength() ; k < sum.length() ; k++)
            {
                temp2 += sum.charAt(k);
            }
            int warp1 = Integer.parseInt(temp1,2);
            int warp2 = Integer.parseInt(temp2,2);
            sumwrap = warp1+warp2;
            //System.out.println(sumwrap);
            int h = 0;
            while (sumwrap > 0)
            {
                w[h] = sumwrap%2;
                sumwrap = sumwrap/2;
                h++;
            }
            for(int x = h-1 ; x >= 0 ; x--)
            {
                wrap += Integer.toString(w[x]);
            }
            System.out.println("Wrapped sum: " + wrap);

            for(int y = 0 ; y < wrap.length() ; y++)
            {
                if(wrap.charAt(y) == '0')
                {
                    checkSum += '1';
                }
                else
                {
                    checkSum += '0';
                }
            }
        }
        else
        {
            for(int z = 0 ; z < seg1.getLength() ; z++)
            {
                if(sum.charAt(z) == '0')
                {
                    checkSum += '1';
                }
                else
                {
                    checkSum += '0';
                }
            }
        }
        System.out.println("checkSum: " + checkSum);
        return checkSum;
    }


    public static void decode(DataWord seg1, DataWord seg2, String cs)
    {
        int summation,sumwrap;
        int s[] = new int[1000];
        int w[] = new int[1000];
        String sum = "";
        String wrap = "";
        String temp1 = "";
        String temp2 = "";
        String checkSum = "";
        int segment1 = Integer.parseInt(seg1.getData(), 2);
        int segment2 = Integer.parseInt(seg2.getData(), 2);
        int checkS = Integer.parseInt(cs,2);
        summation = segment1+segment2+checkS;
        int i = 0;
        while (summation > 0)
        {
            s[i] = summation%2;
            summation = summation/2;
            i++;
        }
        for(int j = i-1 ; j >= 0 ; j--)
        {
            sum += Integer.toString(s[j]);
        }
        System.out.println("Segment1: " + seg1.getData());
        System.out.println("Segment2: " + seg2.getData());
        System.out.println("Received Checksum: " + cs);
        System.out.println("Sum: " + sum);
        if(sum.length() > seg1.getLength())
        {
            for(int j = 0 ; j < sum.length()-seg1.getLength() ; j++)
            {
                temp1 += sum.charAt(j);
            }
            for(int k = sum.length()-seg1.getLength() ; k < sum.length() ; k++)
            {
                temp2 += sum.charAt(k);
            }
            int warp1 = Integer.parseInt(temp1,2);
            int warp2 = Integer.parseInt(temp2,2);
            sumwrap = warp1+warp2;
            //System.out.println(sumwrap);
            int h = 0;
            while (sumwrap > 0)
            {
                w[h] = sumwrap%2;
                sumwrap = sumwrap/2;
                h++;
            }
            for(int x = h-1 ; x >= 0 ; x--)
            {
                wrap += Integer.toString(w[x]);
            }
            System.out.println("Wrapped sum: " + wrap);

            for(int y = 0 ; y < wrap.length() ; y++)
            {
                if(wrap.charAt(y) == '0')
                {
                    checkSum += '1';
                }
                else
                {
                    checkSum += '0';
                }
            }
        }
        else
        {
            for(int z = 0 ; z < seg1.getLength() ; z++)
            {
                if(sum.charAt(z) == '0')
                {
                    checkSum += '1';
                }
                else
                {
                    checkSum += '0';
                }
            }
        }
        System.out.println("checkSum: " + checkSum);
        System.out.println();
        if(Integer.parseInt(checkSum) == 0)
        {
            System.out.println("Syndrome: 0");
            System.out.println("***The codeword isn't in error");
        }
        else
        {
            System.out.println("Syndrome: non-zero");
            System.out.println("***The codeword is in error");
        }
    }
}
