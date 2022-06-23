object Solution {
    def getLucky(st: String, k: Int): Int = {
        var s:String = "";
        var i:Int = 0;
        while(i!=st.length()){
            s= s+(st.charAt(i)-'a'+1).toString;
            i+=1;
        }
        // println(s);
        for(i<- 1 to k){
            var sum :Long = 0;
            var j:Int =0;
            while(j!=s.length()){
                // println(s.charAt(j).toString.toInt);
                sum = sum+ s.charAt(j).toString.toInt
                j+=1;
            }
            // println(sum);
           s=sum.toString;
        }
        return s.toInt;
   
    }
}