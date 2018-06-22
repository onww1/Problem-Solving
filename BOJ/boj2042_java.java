import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.util.Vector;
import java.util.Iterator;
import java.math.BigInteger;


public class boj2042_java{

	public static BufferedReader bf = new BufferedReader( new InputStreamReader( System.in ) );
	public static StringTokenizer st = null;

	public static void addNode(Vector<BigInteger> tree, int index, BigInteger value){
		tree.removeElementAt(index);
		tree.add(index, value);
	}

	public static BigInteger init(Vector<BigInteger> arr, Vector<BigInteger> tree, int node, int start, int end){
		if(start == end){;
			addNode(tree, node, tree.elementAt(node).add(arr.elementAt(start)));
		} else {
			addNode(tree, node, tree.elementAt(node).add(init(arr, tree, node*2, start, (start+end)/2).add(init(arr, tree, node*2+1, (start+end)/2 + 1, end))));
		}
		return tree.elementAt(node);
	}

	public static BigInteger sum(Vector<BigInteger> tree, int node, int start, int end, int left, int right){
		if(start > right || end < left){
			return new BigInteger("0");
		} else if(left <= start && end <= right){
			return tree.elementAt(node);
		}
		return sum(tree, node*2, start, (start+end)/2, left, right).add(sum(tree, node*2+1, (start+end)/2+1, end, left, right));
	}

	public static void update(Vector<BigInteger> tree, int node, int start, int end, int index, BigInteger diff){
		if(index < start || index > end) {
			return ;
		}
		addNode(tree, node, tree.elementAt(node).add(diff));
		if(start <= end) return;
		update(tree, node*2, start, (start+end)/2, index, diff);
		update(tree, node*2+1, (start+end)/2+1, end, index, diff);
	}

	public static void showTree(Vector<BigInteger> arr, Vector<BigInteger> tree){
		Iterator<BigInteger> it1 = arr.iterator();
		Iterator<BigInteger> it2 = tree.iterator();
		System.out.println("--------------------------------");
		System.out.print("arr :");
		while(it1.hasNext()){
			System.out.print(it1.next() + " ");
		}
		System.out.println();
		System.out.print("tree:");
		while(it2.hasNext()){
			System.out.print(it2.next() + " ");
		}
		System.out.println();
		System.out.println("--------------------------------");
	}

	public static void main(String[] args){
		int n, m, k, t1;
		double treeHeight, treeSize;
		BigInteger elem = null;
		Vector<BigInteger> arr = null;
		Vector<BigInteger> tree = null;
		try {
			st = new StringTokenizer( bf.readLine(), " ");
			n = Integer.parseInt(st.nextToken());
			m = Integer.parseInt(st.nextToken());
			k = Integer.parseInt(st.nextToken());

			treeHeight = Math.ceil(Math.log((double)n)/Math.log(2.0));
			treeSize = Math.pow(2.0, treeHeight + 1);
			tree = new Vector<BigInteger>((int)treeSize);
			arr = new Vector<BigInteger>(n);
			for(int i=0; i<treeSize; i++){
				tree.add(new BigInteger("0"));
			}
			for(int i=0; i<n; i++){
				arr.add(new BigInteger( bf.readLine() ));
			}

			init(arr, tree, 1, 0, n-1);

			showTree(arr, tree);

			int len = m + k;
			for(int i=0; i<len; i++){
				st = new StringTokenizer( bf.readLine(), " ");
				t1 = Integer.parseInt(st.nextToken());
				if(t1 == 1){
					int t2 = Integer.parseInt(st.nextToken());
					BigInteger t3 = new BigInteger(st.nextToken());
					t2 -= 1;
					BigInteger diff = t3.subtract(arr.elementAt(t2));
					update(tree, 1, 0, n-1, t2, diff);
				} else if(t1 == 2){
					int t2 = Integer.parseInt(st.nextToken());
					int t3 = Integer.parseInt(st.nextToken());
					BigInteger result = sum(tree, 1, 0, n-1, t2-1, t3-1);
					System.out.println(result);
				}
				showTree(arr, tree);
			}
		} catch(IOException e){
			e.printStackTrace();
		}
	}
}