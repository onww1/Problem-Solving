import java.util.Scanner;
import java.util.Stack;

class Main {

    // Implement this class.
    // Please use stack only.
    static class Queue {

        /*
         * Description:
         * Time complexity:
         * Space complexity:
         */
				private Stack<Integer> enqStack = new Stack<Integer>();
				private Stack<Integer> deqStack = new Stack<Integer>();
			
        public void enqueue(int v) 
				{
					enqStack.push(v);
				}

        /*
         * Description:
         * Time complexity:
         * Space complexity:
         */
        public int dequeue() 
				{
						if(deqStack.isEmpty())
						{
							int size = enqStack.size();
							for(int i=0; i<size; i++)
							{
								deqStack.push(enqStack.pop());	
							}
						}
					
            return deqStack.pop();
        }
    }

    public static void main(String[] args) throws Exception {
        Scanner scan = new Scanner(System.in);

        Queue queue = new Queue();
        String input = scan.nextLine();
        int count = Integer.parseInt(input);

        for (int i = 0; i < count; ++ i) {
            String[] token = scan.nextLine().split(" ");
            if ("ENQUEUE".equals(token[0])) {
                queue.enqueue(Integer.parseInt(token[1]));
            } else if ("DEQUEUE".equals(token[0])) {
                System.out.println(queue.dequeue());
            }
        }

        scan.close();
    }

}

