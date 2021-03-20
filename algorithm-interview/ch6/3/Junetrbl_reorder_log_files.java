import java.util.Arrays;
import java.util.Comparator;

class Solution {
    public String[] reorderCharLogFiles(String[] logs) {
        /*
        Runtime: 4 ms
        Memory Usage: 39.4 MB
        */
        Comparator<String> comparator = new Comparator<String>() {
            @Override
            public int compare(String a, String b) {
                char identA = a.charAt(a.length() - 1);
                char identB = b.charAt(b.length() - 1);

                if (identB <= '9'){
                    if (identA <= '9'){
                        return 0;
                    } return -1;
                }
                if (identA <= '9') {
                    return 1;
                }

                if (b.split(" ", 2)[1].compareTo(a.split(" ", 2)[1]) < 0) {
                    return 1;
                } else if (b.split(" ", 2)[1].equals(a.split(" ", 2)[1])){
                    if (b.split(" ", 2)[0].compareTo(a.split(" ", 2)[0]) < 0){
                        return 1;
                    } else {return -1;}
                }
                return -1;
            }
        };

        Arrays.sort(logs, comparator);

        return logs;
    }

    public String[] reorderLogFiles(String[] logs) {
        /*
        Runtime: 5 ms
        Memory Usage: 39.5 MB
        */
        Comparator<String> comparator = new Comparator<String>() {
            @Override
            public int compare(String a, String b) {
                String[] splitA = a.split(" ", 2);
                String[] splitB = b.split(" ", 2);

                boolean isDigitA = Character.isDigit(splitA[1].charAt(0));
                boolean isDigitB = Character.isDigit(splitB[1].charAt(0));

                if (isDigitA && isDigitB){
                    return 0;
                } else if (isDigitA && !isDigitB){
                    return 1;
                } else if (!isDigitA && isDigitB){
                    return -1;
                } else{
                    if (splitB[1].compareTo(splitA[1]) < 0) {
                        return 1;
                    } else if (splitB[1].equals(splitA[1])){
                        if (splitB[0].compareTo(splitA[0]) < 0){
                            return 1;
                        } else {
                            return -1;
                        }
                    }
                    return -1;
                }
            }
        };

        Arrays.sort(logs, comparator);

        return logs;
    }
}