import  java.lang.*;
class character_stuffing
{
    public static void main(String args[])
    {
        Scanner k =new Scanner (System.in);
        System.out.println("enter the string:- \t");
        String s=k.nextLine();
        String str1;
        String str2="";
        int i,m,j;
        m=s.length();
        System.out.println("original data     "+s);
        str1="dlestx";
        for(i=0;i<=m-1;i++)
        {
            if((s.charAt(i)=='d')&&(s.charAt(i+1)=='l')&&(s.charAt(i+2)=='e'))
            {
                str1=str1+"dle";
            }
            str1=str1+s.substring(i,i+1);
        }
        str1=str1+"dleetx";
        int p=str1.length();
        System.out.println("transmitted data      "+str1);
        for(i=6;i<p-6;i++)
        {
            if((str1.charAt(i)=='d')&&(str1.charAt(i+1)=='l')&&(str1.charAt(i+2)=='e')&&(str1.charAt(i+3)=='d')&&(str1.charAt(i+4)=='l')&&(str1.charAt(i+5)=='e'))
            {
                i=i+3;
            }
            str2=str2+str1.substring(i,i+1);
        }
        System.out.println("received data is         "+str2);
    }
}
