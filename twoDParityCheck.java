
import javax.swing.*;
import java.sql.SQLOutput;
import java.util.*;
public class twoDParityCheck
{
    public static void main(String[]args)
    {
        System.out.println("---------- 2D Parity Check----------");
        System.out.println("ENCODE");
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the String: ");
        String ipt= sc.nextLine();
        System.out.print("Input number of block: ");
        int n = sc.nextInt();
        String temp = sc.nextLine();
        System.out.print("Input length of each block: ");
        int length = sc.nextInt();
        temp = sc.nextLine();
        String[] data = new String[n];
        int count = 0;
        while(count < n)
        {
            System.out.print("Block "+(count+1)+": ");
            data[count] = sc.nextLine();
            if(data[count].length() != length)
            {
                System.out.println("Wrong input!! you must input "+length+" bits");
                System.exit(0);
            }
            count++;
        }
        String codeWord[] = encode(data);

        System.out.println();
        System.out.println();
        System.out.println("CHECK IT CAN DETECT AN EVEN NUMBER OF ERRORS");
        System.out.println("Received codeword: ");
        String[] ReCodeWord = new String[n];
        count = 0;
        while(count < n)
        {
            System.out.print("Block "+(count+1)+": ");
            ReCodeWord[count] = sc.nextLine();
            if(ReCodeWord[count].length() != length+1)
            {
                System.out.println("Wrong input!! you must input "+(length+1)+" bits");
                System.exit(0);
            }
            ReCodeWord[count] = ReCodeWord[count].substring(0,ReCodeWord[count].length()-1);
            count++;
        }
        checkError(codeWord,ReCodeWord);
    }

    public static String[] encode(String[] dataWord)
    {
        int count = 0;
        char rRowBit[] = new char[dataWord.length];
        while(count<dataWord.length)
        {
            rRowBit[count] = dataWord[count].charAt(0);
            for(int i = 1 ; i < dataWord[count].length() ; i++)
            {
                if(rRowBit[count] == dataWord[count].charAt(i))
                {
                    rRowBit[count] = '0';
                }
                else
                {
                    rRowBit[count] = '1';
                }
            }
            dataWord[count] += rRowBit[count];
            count++;
        }
        System.out.print("Row parities: ");
        String RowBit = "";
        for(int i = 0 ; i<rRowBit.length ; i++)
        {
            RowBit += rRowBit[i];
            System.out.print(rRowBit[i]);
        }
        System.out.println();

        count = 0;
        char rColBit[] = new char[dataWord[0].length()];
        String ColBit = "";
        while(count<dataWord[0].length())
        {
            rColBit[count] = dataWord[0].charAt(count);
            for(int i = 1 ; i < dataWord.length ; i++)
            {
                //System.out.println(dataWord[i].charAt(count));
                if(rColBit[count] == dataWord[i].charAt(count))
                {
                    rColBit[count] = '0';
                }
                else
                {
                    rColBit[count] = '1';
                }
            }
            count++;
        }
        System.out.print("Column parities: ");
        for(int i = 0 ; i<rColBit.length ; i++)
        {
            ColBit += rColBit[i];
            System.out.print(rColBit[i]);
        }
        System.out.println();

        String code[] = new String[dataWord.length+1];
        String codeWord = "";

        for(int i = 0 ; i<code.length ; i++)
        {
            if( i == dataWord.length)
            {
                code[i] = ColBit;
            }
            else
            {
                code[i] = dataWord[i];
            }
        }
        System.out.print("Codeword: ");
        for(int i = 0 ; i<code.length ; i++)
        {
            System.out.print(code[i] + " ");
            codeWord += code[i];
        }

        String[] CodeWord = new String[3];
        for(int i = 0 ; i<3 ; i++)
        {
            switch (i) {
                case 0:
                    CodeWord[i] = codeWord;
                    break;
                case 1:
                    CodeWord[i] = RowBit;
                    break;
                default:
                    CodeWord[i] = ColBit;
                    break;
            }
        }
        return CodeWord;
    }

    public static void checkError(String[] codeWord, String[] ReCodeWord)
    {
        int count = 0;
        char rRowBit[] = new char[ReCodeWord.length];
        while(count<ReCodeWord.length)
        {
            rRowBit[count] = ReCodeWord[count].charAt(0);
            for(int i = 1 ; i < ReCodeWord[count].length() ; i++)
            {
                if(rRowBit[count] == ReCodeWord[count].charAt(i))
                {
                    rRowBit[count] = '0';
                }
                else
                {
                    rRowBit[count] = '1';
                }
            }
            ReCodeWord[count] += rRowBit[count];
            count++;
        }
        System.out.print("Row parities: ");
        String RowBit = "";
        for(int i = 0 ; i<rRowBit.length ; i++)
        {
            RowBit += rRowBit[i];
            System.out.print(rRowBit[i]);
        }
        System.out.println();

        count = 0;
        char rColBit[] = new char[ReCodeWord[0].length()];
        String ColBit = "";
        while(count<ReCodeWord[0].length())
        {
            rColBit[count] = ReCodeWord[0].charAt(count);
            for(int i = 1 ; i < ReCodeWord.length ; i++)
            {
                //System.out.println(dataWord[i].charAt(count));
                if(rColBit[count] == ReCodeWord[i].charAt(count))
                {
                    rColBit[count] = '0';
                }
                else
                {
                    rColBit[count] = '1';
                }
            }
            count++;
        }
        System.out.print("Column parities: ");
        for(int i = 0 ; i<rColBit.length ; i++)
        {
            ColBit += rColBit[i];
            System.out.print(rColBit[i]);
        }
        System.out.println();

        if(codeWord[1].equals(RowBit) && codeWord[2].equals(ColBit))
        {
            System.out.println("***The codeword isn't in error");
        }
        else
        {
            System.out.println("***The codeword is in error \n\t Retransmission is needed!***");
        }
    }
}
