import java.util.Scanner;
class CRYPTOGRAPHY {
    public static void main(String[] args) {
        String str;
        int a, b;
        char ch, new_ch, base;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the text: ");
        str = sc.nextLine();
        System.out.println("Enter the value you the characters to shift by: ");
        int shift = sc.nextInt();
        a = str.length();
        for (int i = 0; i <= a - 1; i++) {
            ch = str.charAt(i);
            base = Character.isLowerCase(ch) ? 'a' : 'A';
            b = (base + (ch - base + shift) % 26);
            new_ch = (char) b;
            if (ch == ' ') {
                System.out.print(" ");
            } 
            else {
                System.out.print(new_ch);
            }
        }
    }
}
