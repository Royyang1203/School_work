import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class hw2 {
    public static void main(String[] args) throws Exception {
        List<List<String>> records = new ArrayList<>();
        try (Scanner scanner = new Scanner(new File("./HW2data.csv"));) {
            while (scanner.hasNextLine()) {
                records.add(getRecordFromLine(scanner.nextLine()));
            }
        }

        records.get(0).add("grade");
        records.get(0).add("level");

        for (int i = 1; i < records.size(); i++) {
            Double HW1 = Double.parseDouble(records.get(i).get(3));
            Double HW2 = Double.parseDouble(records.get(i).get(4));
            Double HW3 = Double.parseDouble(records.get(i).get(5));
            Double MID = Double.parseDouble(records.get(i).get(6));
            Double FIN = Double.parseDouble(records.get(i).get(7));
            int grade = (int)Math.round(HW1 * 0.1 + HW2 * 0.1 + HW3 * 0.1 + MID * 0.3 + FIN * 0.4);
            records.get(i).add(Integer.toString(grade));
            if (grade >= 0 && grade <= 49) {
                records.get(i).add("E");
            } else if (grade >= 50 && grade <= 59) {
                records.get(i).add("D");
            }  else if (grade >= 60 && grade <= 62) {
                records.get(i).add("C-");
            } else if (grade >= 63 && grade <= 66) {
                records.get(i).add("C");
            } else if (grade >= 67 && grade <= 69) {
                records.get(i).add("C+");
            } else if (grade >= 70 && grade <= 72) {
                records.get(i).add("B-");
            } else if (grade >= 73 && grade <= 76) {
                records.get(i).add("B");
            } else if (grade >= 77 && grade <= 79) {
                records.get(i).add("B+");
            } else if (grade >= 80 && grade <= 84) {
                records.get(i).add("A-");
            } else if (grade >= 85 && grade <= 89) {
                records.get(i).add("A");
            } else if (grade >= 90 && grade <= 100) {
                records.get(i).add("A+");
            }
        }

        writeCSV(records);
    }

    private static List<String> getRecordFromLine(String line) {
        List<String> values = new ArrayList<String>();
        try (Scanner rowScanner = new Scanner(line)) {
            rowScanner.useDelimiter(",");
            while (rowScanner.hasNext()) {
                values.add(rowScanner.next());
            }
        }
        return values;
    }


    private static void writeCSV(List<List<String>> data) throws Exception {
        File csvFile = new File("result_java.csv");
        try (PrintWriter out = new PrintWriter(csvFile)) {
            for (List<String> d : data) {
                String w = String.join(",", d);
                System.out.println(w);
                out.println(w);
            }
        }
    }
}
