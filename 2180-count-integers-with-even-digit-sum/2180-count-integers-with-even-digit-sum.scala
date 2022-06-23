object Solution {
    def countEven(num: Int): Int = {
        var i:Int = 1;
        var e:Int = 0;
        var o:Int = 0;
        var ans:Int=0;
        while(i<=num){
            var j:Int = i;
            e=0;
            o=0;
            while(j>0){
                if((j%10)%2==0) e+=1;
                 else o+=1;
                j=j/10;
            }
            if(o%2==0) ans+=1;
            i+=1;
        }
        return ans;
    }
}