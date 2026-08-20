import java.util.*;
import java.lang.Integer;

public class Postfix {

    public static int calculate(int a, int b, char operator) {
        switch(operator) {
            case('+'): return a + b;
            case('-'): return a - b;
            case('*'): return a * b;
            case('/'): return (b == 0) ? 0 : (int)(a / b);
            case('%'): return a % b;
            case('^'): return (int)Math.pow(a, b);
            default: return 0;
        }
    }

    public static int evaluatePostfix(String[] tokens) {
        
        Stack<Integer> numbers = new Stack<>();

        for(String token : tokens) {

            if(token.matches("[0-9]+")) {
                numbers.push(Integer.parseInt(token));
            }
            else {

                if(token.equals(" ")) {
                    continue;
                }
                
                if(numbers.size() < 2) {
                    return 0;
                }

                int b = numbers.pop();
                int a = numbers.pop();
                int result = calculate(a, b, token.charAt(0));
                numbers.push(result);
            }
        }

        return (numbers.size() == 1) ? numbers.pop() : 0;
    }

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        String expression = sc.nextLine();
        
        String[] tokens = expression.split(" ");

        int result = evaluatePostfix(tokens);
        System.out.println(result);
        
    }
}