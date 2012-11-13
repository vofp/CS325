int n =0;
int c = 1;
int[] array_x = new int[300];
int[] array_y = new int[300];
int[] array_idx = new int[300];
int[] array_id = new int[300];

void setup() {
        size(1500, 1000);
        translate(1500, 1000);
        rotate(radians(180));
        scale(5);
	try{
  ///home/francis/CS325/Project4/test/
	  BufferedReader in = new BufferedReader(new FileReader("example-input-2.txt")); 
	  String text;
	  while ((text = in.readLine()) != null)   {
		// Print the content on the console
		//println(text);
		
		StringTokenizer tokenizer = new StringTokenizer(text," "); 
		int id = Integer.parseInt(tokenizer.nextToken()); 
		int x = 300 - Integer.parseInt(tokenizer.nextToken()); 
		int y = Integer.parseInt(tokenizer.nextToken());
		point(x,y);
		//println(x + " " + y);
		array_x[id] = x;
		array_y[id] = y;
		n++;
	  }
	  in.close();
	}catch (Exception ex){
	  System.out.println("f2: Oops, FileNotFoundException caught");
	}


	try{
	  BufferedReader in = new BufferedReader(new FileReader("output2.txt")); 
	  String text;
	  text = in.readLine();
	  StringTokenizer tokenizer = new StringTokenizer(text," "); 
	  int idx = Integer.parseInt(tokenizer.nextToken());
	  int id = Integer.parseInt(tokenizer.nextToken());
	  array_idx[0] = idx;
	  array_id[0] = id;
	  int i =1;
	  //myArr.add(idx,id);
	  while ((text = in.readLine()) != null)   {
		// Print the content on the console
		//println(text);
		
		tokenizer = new StringTokenizer(text," "); 
		idx = Integer.parseInt(tokenizer.nextToken());
		id = Integer.parseInt(tokenizer.nextToken());
		array_idx[i] = idx;
		array_id[i] = id;
		i++;
		//myArr.add(idx,id);
		//line(prevX, prevY, array_x[id], array_y[id]);
		//prevX = array_x[id];
		//prevY = array_y[id];
		}
		in.close();
	}catch (Exception ex){
		System.out.println("f2: Oops, FileNotFoundException caught");
	}

}

void draw() {
        background(102);
        size(1500, 1000);
        translate(1500, 1000);
        rotate(radians(180));
        scale(5);
  //c = n;
        for(int i = 0; i < n; i++){
           point(array_x[i],array_y[i]); 
        }
        ArrayList<Integer> myArr = new ArrayList<Integer>();
       for(int i = 0; i < n && i < c; i++){
           myArr.add(array_idx[i],array_id[i]);
       }
        int prevX = array_x[myArr.get(myArr.size()-1)];
        int prevY = array_y[myArr.get(myArr.size()-1)];
	for(int i = 0; i < myArr.size(); i++){
		//println(myArr.get(i)); 
            int x = array_x[myArr.get(i)];
            int y = array_y[myArr.get(i)];
            line(prevX, prevY, x, y);
            prevX = x;
            prevY = y;
            //println(myArr.get(i) + " " + x + " " + y);
	}
}

void keyPressed() {
	if(key == 'a'){
		//println("a");
                c--;
                if(c < 1){
                   c = 1; 
                }
	}
	if(key == 'd'){
                c++;
                if(c > n){
                   c = n;
                }
		//println("d");
	}
}
