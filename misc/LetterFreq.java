import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;

class LetterFreq {
    public static void main(String[] args) {
        int N[] = new int[26];
        final int LAST = 26;
        double count = 0.0;
        try {
            double sum = 0;
            // initialize each count of letter
            for (int i = 0; i < LAST; i++) {
                N[i] = 0;
            }
            FileReader fr = new FileReader("random.txt");
            int ch;
            int letter;
            while ((ch = fr.read()) != -1) {
                if (ch != 32) {
                    count++;
                    letter = ch - 65;
                    N[letter]++;
                }
            }
            char chara;

            // Create a PrintWriter to write to a text file
            PrintWriter output = new PrintWriter(new FileWriter("output.txt"));

            // Prints out the frequency distribution of letters to the file
            for (int i = 0; i < LAST; i++) {
                ch = i + 65;
                chara = (char) ch;
                output.println(chara + " : " + N[i] / count * 100);
            }
            // Perform the summation of n[i](n[i] - 1) from 0 to 25
            output.println("Total characters: " + count);
            for (int i = 0; i < LAST; i++) {
                sum = sum + N[i] * (N[i] - 1);
            }
            double I = (1 / (count * count - 1)) * sum;
            if (I < 0.065 && I > 0.0385) {
                output.println("Polyalphabetic cipher used.");
                double k = ((0.0265 * count) / ((0.065 - I) + count * (I - 0.0385)));
                output.println("Key Length = " + Math.round(k));
            } else {
                output.println("Monoalphabetic Substitution Cipher used.");
            }
            output.println("I = " + I);

            // Close the PrintWriter
            output.close();
            fr.close();

        } catch (Exception e) {
            System.out.println("Error");
        }
    }
}
