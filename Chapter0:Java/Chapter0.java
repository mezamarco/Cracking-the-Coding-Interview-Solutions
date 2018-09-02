package Chapter0;
import java.util.*;


public class Chapter0 {

	//Remove a all instances of a specific element from a vector
		void removeElement(Vector<Integer> myVect, int num) {
			if (myVect.isEmpty())
				return;

			int i = 0;
			int k = 0;
			while (i < myVect.size()) {
				if (myVect.get(i) != num) {
					//At index k place the following value
					myVect.add(k, myVect.get(i));
					++k;
				}
				++i;
			}
			return;

		} 



		//Find the index of two element that will sum to the target element
		//Solve this problem in O(n) runtime
		boolean targetSum(Vector<Integer> myVect, int target) {

			HashMap<Integer, Integer> myMap = new HashMap<Integer, Integer>();
			
			for (int i = 0; i < myVect.size(); i++) {
				int complement = target - myVect.get(i);

				if (myMap.containsKey(complement)) {
					//We found  a pair that give us the target sum
					int m = myMap.get(complement);
					int n = i;
					System.out.println("The index values are: " + m  + " , " + n);
					return true;
				}
				myMap.put(myVect.get(i), i);
			}
			return false;
		}




		//Do we have valid opening and closing parentheses,
		//Example: valid:  {}{}()[][], valid : {[()]}, invalid: ({[}])
		boolean validParentheses(String word) {

			if (word.length() % 2 != 0) {
				return false;
			}

			Stack<Character> myStack = new Stack<>();

			for (char ch : word.toCharArray() ) {

				if (ch == '(' || ch == '[' || ch == '{')
				{
					myStack.push(ch);
				}
				else if (myStack.empty()) {
					return false;
				}
				else if (ch == ')' && myStack.peek() == '('  || 
					 ch == '}' && myStack.peek() == '{'  || 
					 ch == ']' && myStack.peek() == '['  )
				{
					myStack.pop();
				}
				else {
					return false;
				}
			}
			return true;
		}




		//Recursive sum: n + n-1 + n-2 + .... + 2 + 1
		int recursiveSum(int n) {
			if (n <= 0) {
				return 0;
			}
			else {
				return n + recursiveSum(n - 1);
			}
		}

		//Reverse a vector
		void reverseVector(Vector<Integer> myVect) {
			if (myVect.isEmpty()) {
				return;
			}
			
			int i = 0;
			int j = myVect.size() - 1;

			while (i < j) {
				int temp = myVect.get(i);
				myVect.add( i , myVect.get(j) );
				myVect.add(j, temp);
			}
			return;
		}

		//Is the given number a prime number
		boolean isPrime(int num) {

			if (num < 2) {
				return false;
			}

			for (int i = 2; i <= Math.sqrt(num); num++) {
				if (num % i == 0) {
					return false;
				}
			}
			return true;
		}


		// a^(b) Power Algorithm
		int power(int a, int b)
		{
			if (b == 0) {
				return 1;
			}
			return a * power(a, b - 1);
		}

		// a % b  Mod Algorithm
		int mod(int a, int b)
		{
			if (b <= 0)
				return -1;

			int div = a / b;
			int rem = a - (b*div);
			return rem;
		}

		// a / b Division Algorithm
		int division(int a, int b) {

			if (b <= 0)
				return -1;

			int sum = b;
			int counter = 0;
			while (sum <= a) {
				++counter;
				sum = sum + b;
			}
			return counter;
		}




		//Get the sum of all the individual digits
		int sumDigits(int num) {

			int sum = 0;
			while (num > 0) {
				int digit = num % 10;
				sum = sum + digit;
				num = num / 10;
			}
			return sum;
		}



		//Get the number of common elements between the two given vectors
		int numCommon(Vector<Integer> a, Vector<Integer> b) {

			if (a.isEmpty() || b.isEmpty())
				return 0;

			//We will store all the elements from vector a into a HashMap
			HashMap<Integer, Integer> myMap = new HashMap<Integer, Integer>();

			for (int i = 0; i < a.size(); i++) {
				myMap.put(a.get(i),i);
			}

			//If an element of b is in the HashMap then increment counter
			int counter = 0;

			for (int y : b) {
				if (myMap.containsKey(y)) {
					++counter;
				}
			}
			return counter;
		}


	
	
	
	
	public static void main(String[] args) {
		//The solutions work, but we still have to display some test cases
		//(Do this later).
		System.out.println("Hello");
	    return;

	}

}
